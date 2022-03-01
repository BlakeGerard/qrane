from sys import argv
import os
import subprocess as sp
import re
from multiprocessing import Pool

def input_phase(argv):
	if (len(argv) < 3):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2]

input_dir, output_dir = input_phase(argv)
qrane_invocation = "./qrane {} -q -d 1 -s {}"

def remove_qasm_extension(file_name):
	return file_name.rstrip(".qasm")

def get_register_size(file_name):
	reg_str = re.match("\d+", file_name).group()
	return int(reg_str)

def run_qrane(file_name):
	lims = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096]

	for lim in lims:
		command = qrane_invocation.format(input_dir + file_name, str(lim))
		output_str = ""
		try:
			result = sp.run(command, shell=True, capture_output=True)
			output_str = str(result.stdout, 'utf-8')
		except Exception as e:
			print(e)
			output_str = "Killed"

		my_output_file = output_dir + file_name + ".s" + str(lim) + ".txt"
		fh = open(my_output_file, "w")
		fh.write(output_str)
		fh.close()

def collect_and_store_output(input_dir, output_dir):
	files = os.listdir(input_dir)
	files = sorted(files, key=lambda f: os.stat(os.path.join(input_dir, f)).st_size)
	p = Pool()
	p.map(run_qrane, files)

collect_and_store_output(input_dir, output_dir)
