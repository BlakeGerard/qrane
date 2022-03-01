from sys import argv
import os
import subprocess as sp
import re

qrane_invocation = "./qrane --qasm={} --chunk=2000"

def remove_qasm_extension(file_name):
	return file_name.rstrip(".qasm")

def get_register_size(file_name):
	reg_str = re.match("\d+", file_name).group()
	return int(reg_str)

def run_qrane(input_dir, file_name):
	command = qrane_invocation.format(input_dir + file_name)
	print(command)
	output_str = ""
	try:
		result = sp.run(command, shell=True, capture_output=True)
		output_str = str(result.stdout, 'utf-8')
	except:
		output_str = "Killed"

	return output_str

def collect_and_store_output(input_dir, output_dir):
	for entry in sorted(os.scandir(input_dir), key=lambda e: os.path.getsize(e.path)):
		if ("fqm" in entry.name): continue
		name = remove_qasm_extension(entry.name)
		output_str = run_qrane(input_dir, entry.name)
		output_file = output_dir + name + ".substr.txt"
		write_handle = open(output_file, 'w')
		write_handle.write(output_str)
		write_handle.close()

def input_phase(argv):
	if (len(argv) < 3):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2]

input_dir, output_dir = input_phase(argv)
collect_and_store_output(input_dir, output_dir)
