import pytket
from pytket.utils import Graph
from pytket.qasm import circuit_from_qasm
import networkx
from networkx import is_isomorphic
import os
import subprocess
from collections import defaultdict

def check_iso(benchmark, path1, path2):
	full = ["./test", "--qasm={}".format(path1), "--check_qasm={}".format(path2)]
	proc = subprocess.run(full, capture_output=True)
	res = str(proc.stdout, 'UTF-8')
	return res

def qasm_path_pairs(path):
	pairs = defaultdict(list)
	for entry in os.scandir(path):
		key = entry.name
		fixed = entry.path
		if (".maxfuse.qasm" in entry.name):
			key = key.replace(".maxfuse.qasm", "")
		elif (".qasm" in entry.name):
			key = key.replace(".qasm", "")

		pairs[key].append(fixed)
	return pairs

path = "/home/blake/blake-aqcsl/qrane/codegen/queko-bigd-write-all-maxfuse-fixed/"
pairs = qasm_path_pairs(path)

with open("maxfuse_isomorphism.txt", 'w') as fh:
	for benchmark in pairs:
		if (len(pairs[benchmark]) > 1):
			res = check_iso(benchmark, pairs[benchmark][0], pairs[benchmark][1])
			line = benchmark + " maxfuse " + res + "\n"
			fh.write(line)
