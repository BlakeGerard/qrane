from qiskit import IBMQ
from pytket import Circuit, OpType
from pytket import *
from pytket.routing import LinePlacement, GraphPlacement, NoiseAwarePlacement, place_with_map, route, Architecture
from pytket.qasm import circuit_from_qasm, circuit_to_qasm_str
from pytket.backends.backendinfo import BackendInfo
from pytket.predicates import CompilationUnit
import pytket.passes as tpasses
import pytket.predicates as tpredicates
import pytket.circuit as tc
import os
import re
import sys
from time import perf_counter
from collections import defaultdict
import copy
import ast
import matplotlib.pyplot as plt
from dot_to_tket_arch import get_arch_from_dot, get_error_map_from_csv, get_node_error_map_from_csv
from multiprocessing import Pool, current_process
from pebble import ProcessPool, ProcessExpired
sys.settrace

# fqm-baseline, fqm-fancy, qasm-fancy
# qasm:gate_delta:depth_delta:compile_time:---: ...
def write_out(data, output_file):
    with open(output_file, 'w+') as out:
        for entry in data:
            line = entry[0] + ":"

            for triple in entry[1]:
                line += str(triple[0]) + ":"
                line += str(triple[1]) + ":"
                line += str(triple[2]) + ":"
                line += "---:"
            line += "\n"
            out.write(line)

def identity_mapping(arch):
    qmap = {}
    nodes = arch.nodes
    count = 0
    for node in nodes:
        left = tc.Qubit(count)
        right = node
        qmap.update({left: right})
        count += 1
    return qmap

def write_out_single(entry, pid):
    dst = "./temp/" + pid + ".txt"
    print(dst)
    with open(dst, 'w') as out:
        line = entry[0] + ":"
        for triple in entry[1]:
            line += str(triple[0]) + ":"
            line += str(triple[1]) + ":"
            line += str(triple[2]) + ":"
            line += "---:"
        line += "\n"
        out.write(line)

def run_tests_helper(pair):
	'''
	Helper function for the parallel testing.
	This function takes as input a single data point
	and runs all three testing configurations.

	Return:  a tuple (file_name, (a, b, c))
	where a, b, c are the results of each configuration.
	'''
	global arch, node_errors, edge_errors

	try:
		name = pair[1][pair[1].rindex("/")+1:]		# Get the file name
		fqm_circuit = circuit_from_qasm(pair[0])	# tket fqm circuit
		qasm_circuit = circuit_from_qasm(pair[1])	# tket qasm circuit
	except Exception as e:
		print(e)
		return ("", (0, 0, 0))


	print(os.getpid(), "working on", name)
	try:
		a = run_baseline_tket(fqm_circuit, arch)				# Run fqm + baseline
	except Exception as e:
		print("a failed on ", name)
		print(e)
		return (name, (0,0,0))

	try:
		b = run_fancy_tket(fqm_circuit, name, arch, node_errors, edge_errors, False)  # Run fqm + fancy
	except Exception as e:
		print("b failed on ", name)
		return (name, (0,0,0))

	try:
		c = run_fancy_tket(qasm_circuit, name, arch, node_errors, edge_errors, True)  # Run qasm + fancy
	except:
		print("c failed on ", name)
		return (name, (0,0,0))

	print(os.getpid(), "completed", name)
	entry = (name, (a, b, c))
	return entry

def run_tests_parallel(fqm_qasm_pairs):
	'''
	This is where the parallel processing is done.
	Initialize a Pool of processes of size os.cpu_count()
	Distribute fqm_qasm_pairs across the pool of workers
	and apply run_tests_helper to each input.

	Return: List of outputs for each call to run_tests_helper
	'''
	global arch, node_errors, edge_errors
	results = []
	with ProcessPool() as pool:
		future = pool.map(run_tests_helper, fqm_qasm_pairs, timeout=3600)
		iterator = future.result()
		while True:
			try:
				result = next(iterator)
			except StopIteration:
				break
			except TimeoutError as error:
				print("function took longer than %d seconds" % error.args[1])
				continue
			except ProcessExpired as error:
				print("%s. Exit code: %d" % (error, error.exitcode))
				continue
			except Exception as error:
				continue
				#print("function raised %s" % error)
				#print(error.traceback)  # Python's traceback of remote process
			results.append(result)
	return results

def run_baseline_tket(circ_before, arch):
    circ_after = circ_before.copy()
    #device = Device(architecture=arch)
    device = BackendInfo("device", "device", "", gate_set = {}, architecture=arch)

    # Baseline passes
    identity_map = identity_mapping(arch)
    routing_pass = tpasses.RoutingPass(arch)			# Routing
    rebase_pass = tpasses.RebaseIBM()				# Rebase to IBM
    validity_pass = tpredicates.ConnectivityPredicate(
        arch)  							# Connectivity check

    # Run all passes
    begin = perf_counter()  					# Start timer
    pytket.routing.place_with_map(circ_after, identity_map)  	# Placement
    routing_pass.apply(circ_after)  				# Routing
    rebase_pass.apply(circ_after)  				# Rebase to IBM
    end = perf_counter()  					# End timer

    valid = validity_pass.verify(circ_after)			# Check validity
    if (valid == False):
        return (9999999, 9999999, 9999999)

    # Collect metrics
    gate_delta = circ_after.n_gates - circ_before.n_gates
    depth_delta = Circuit.depth(circ_after)
    compile_time = end - begin
    return (gate_delta, depth_delta, compile_time)

def run_fancy_tket(circ_before, name, arch, node_errors, edge_errors, do_place):
    try:
        circ_after = circ_before.copy()
        #device = Device(node_errors, edge_errors, arch)
        device = BackendInfo("device", "device", "", gate_set={}, architecture=arch, all_node_gate_errors=node_errors, all_edge_gate_errors=edge_errors)

    # Fancy passes
        identity_map = identity_mapping(arch)
        placement_pass = tpasses.PlacementPass(NoiseAwarePlacement(arch, node_errors=node_errors, link_errors=edge_errors))	# Placement
        #placement_pass = tpasses.PlacementPass(GraphPlacement(device))
        #placement_pass = tpasses.PlacementPass(LinePlacement(device))
        o2_pass = tpasses.O2Pass()  					# O2
        optimization_pass = tpasses.FullPeepholeOptimise()  		# FullPeepholeOptimize
        routing_pass = tpasses.RoutingPass(arch)  			# Routing
        rebase_pass = tpasses.RebaseIBM()  					# Rebase to IBM
        validity_pass = tpredicates.ConnectivityPredicate(
            arch)
    except Exception as e:
        print("Couldn't initialize passes")
        print(e)
        return (9999999, 9999999, 9999999)  								# Connectivity check

    #print(circ_after, "init")

    # Run all passes
    begin = perf_counter()  						# Start timer

    try:
        if (do_place):
            placement_pass.apply(circ_after)                                # GraphPlacement if qasm
        else:
            pytket.routing.place_with_map(circ_after, identity_map)  	# IdentityPlacement if fqm
    except:
        print("Placement failed")
        return (9999999, 9999999, 9999999)

    #print(circ_after, "placement done")

    try:
        optimization_pass.apply(circ_after)  				# FullPeepholeOptimize
    except:
        print("Opt failed")
        return (9999999, 9999999, 9999999)

    #print(circ_after, "opt done")

    try:
        routing_pass.apply(circ_after)  					# Routing
    except Exception as e:
        print("Routing failed:", e)
        return (9999999, 9999999, 9999999)

    #print(circ_after, "routing done")

    rebase_pass.apply(circ_after)  					# Rebase to IBM
    end = perf_counter()  						# End timer

    valid = validity_pass.verify(circ_after)				# Check validity
    if (valid == False):
        return (9999999, 9999999, 9999999)

    #print(circ_after, "check done")

    # Collect metrics
    try:
        gate_delta = circ_after.n_gates - circ_before.n_gates
        depth_delta = Circuit.depth(circ_after)
        compile_time = end - begin
    except:
        print("Couldn't collect metrics")
        return (9999, 9999, 9999)
    collected = (gate_delta, depth_delta, compile_time)

    return collected

def get_valid_qasm_fqm_pairs(qasm_path):
	'''
	Scan the input directory for files with both
	.fqm.qasm and .qasm versions.

	Return: List of ("/path/to/*.fqm.qasm", "/path/to/*.qasm)
	'''
	pairs = []
	for fqm in os.scandir(qasm_path):
		if (fqm.is_file() and
		fqm.stat().st_size > 0 and
		fqm.name.endswith(".qrane.qasm")):
			no_fqm = fqm.name.replace(".qrane", "")
			for qasm in os.scandir(qasm_path):
                		if (qasm.name == no_fqm):
                    			pairs.append((fqm.path, qasm.path))
	print(pairs)
	return pairs


# Modify these four variables to change testing file
qasm_path = "./codegen/queko-bigd-minfuse/"
calibration_path = "./topologies/ibmq_brooklyn_calibrations.csv"
arch_path = "./topologies/ibmq_brooklyn_calibrations.csv.dot"
output_file = "./results_compilation/tket-queko-bigd-minfuse-brooklyn.txt"

# Parse architecture-specific error rates
node_errors = get_node_error_map_from_csv(calibration_path)
edge_errors = get_error_map_from_csv(calibration_path)
arch = Architecture(get_arch_from_dot(arch_path))

# Run the tests
qasm_fqm_pairs = get_valid_qasm_fqm_pairs(qasm_path)
data = run_tests_parallel(qasm_fqm_pairs)
print("Data processed. Writing.")
write_out(data, output_file)
