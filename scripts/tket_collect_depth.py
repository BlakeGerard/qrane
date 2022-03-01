from pytket import Circuit, OpType
from pytket import *
from pytket.qasm import circuit_from_qasm, circuit_to_qasm_str
import os
import re
import sys

#
# Output format:
# circuit.qasm:depth
#
def write_depths(qasm_path, output_path):
	data_str = "{}:{}\n"
	results = []
	for fqm in sorted(os.scandir(qasm_path), key=lambda f: f.stat().st_size):
		if (fqm.is_file() and fqm.stat().st_size > 0 and fqm.name.endswith(".qasm")):
			circ = circuit_from_qasm(fqm.path)
			depth = len(circ.get_commands())
			formatted = data_str.format(fqm.name, depth)
			results.append(formatted)
			print(fqm.name, "done")

	with open(output_path + "queko-bigd-gates.txt", "w") as out:
		for string in results:
			out.write(string)

# Modify these four variables to change testing file
qasm_path = "qasm/queko-bigd/"
output_path = "./"

# Run the tests
write_depths(qasm_path, output_path)
