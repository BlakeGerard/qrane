from sys import argv
import os
import subprocess as sp
import re
from multiprocessing import Pool

input_dir = ""
stats_dir = ""
codegen_dir = ""

def run_qrane(file_name):
	command = ["./qrane", "--qasm={}".format(input_dir + file_name), "--circuit"]

	print(command)
	output_str = ""
	try:
		result = sp.run(command, capture_output=True)
		output_str = str(result.stdout, 'utf-8')
	except:
		output_str = "Timeout"

	benchmark = file_name.rstrip(".qasm")
	out_file = open(stats_dir + benchmark + ".plinko.txt", "w")
	out_file.write(output_str)
	out_file.close()

def collect_and_store_output():
	all_files = os.listdir(input_dir)
	p = Pool(4)
	p.map(run_qrane, all_files)

def input_phase(argv):
	if (len(argv) < 4):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2], argv[3]

input_dir, stats_dir, codegen_dir = input_phase(argv)
collect_and_store_output()
