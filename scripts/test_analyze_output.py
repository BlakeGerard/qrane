from sys import argv
import os
import subprocess as sp
import re
from collections import defaultdict
import matplotlib.pyplot as plt
import numpy as np

total_qops_processed = 0
domain_dim_profile = {'1D':0, '2D':0, '3D':0, '4D':0, '5D':0, '6D':0, '7D':0, '8D':0, '9D':0, '10D':0}
domain_size_profile = defaultdict(lambda: 0)
substr_profile = [
	0, # num
	0, # max
	0, # avg size
	0  # avg occ
]

def print_data():
	print("Total Qops Processed,", total_qops_processed)

	for entry in sorted(domain_dim_profile):
		print(entry, ",", domain_dim_profile[entry])

	for entry in sorted(domain_size_profile):
		print(entry, ",", domain_size_profile[entry])

	print("---")
	for entry in substr_profile:
		print(substr_profile[0])
		print(substr_profile[1])
		print(substr_profile[2])
		print(substr_profile[3])

def plot_data():
	domain_size_x = []
	domain_size_y = []
	for entry in sorted(domain_size_profile, key=lambda e: domain_size_profile[e]):
		domain_size_x.append(entry)
		domain_size_y.append(domain_size_profile[entry])

	fig = plt.figure(figsize=[10,10])
	ax = fig.add_subplot(111)
	pie_wedges = ax.pie(domain_size_y, labels=domain_size_x, labeldistance=1.05)

	for wedge in pie_wedges[0]:
		wedge.set_edgecolor('white')

	plt.tight_layout()
	plt.show()


def killed(data):
	return data == "Killed" or data == ""

def get_qops_count(data):
	global total_qops_processed
	try:
		data.index("Qops:")
	except ValueError:
		return
	qops_line = re.search("Qops: \d*", data).group()
	number = int(re.search("\d+", qops_line).group())
	total_qops_processed += number

def get_domain_sizes(data):
	dims_size = re.findall("\d+ : \d+", data)
	for val in dims_size:
		left = int(val[:val.index(':')].strip())
		right = int(val[val.index(':')+1:].strip())
		domain_size_profile[left] += right

def get_domain_dims(data):
	global domain_dim_profile
	dims_prof = re.findall("\dD: \d+", data)
	for val in dims_prof:
		colon = val.index(':')
		dim = val[0:colon]
		count = int(val[colon+2:])
		domain_dim_profile[dim] += count
	
def get_substr_prof(data):
	global substr_profile
	try:
		data.index("--- Substr ---")
	except ValueError:
		return
	cnt = re.search("Num substr.+: \d+", data).group()
	cnt = int(re.search("\d+", cnt).group())
	substr_profile[0] += cnt

	max = re.search("Max substr size.+: \d+", data).group()
	max = int(re.search("\d+", max).group())
	if (max > substr_profile[1]): substr_profile[1] = max

	avg_size = re.search("Avg substr size.+: \d+", data).group()
	avg_size = int(re.search("\d+", avg_size).group())
	print(avg_size)
	substr_profile[2] += avg_size

	avg_occ = re.search("Avg substr occ.+: \d+", data).group()
	avg_occ = int(re.search("\d+", avg_occ).group())
	substr_profile[3] += avg_occ

def get_result_files(input_dir, output_dir):

	# For each results directory (containing results for a specific benchmark)
	for result_dir in os.scandir(input_dir):
		if (result_dir.is_dir()):

			file_count = 0

			# Go through each result file and catalogue the results in the global variables
			for result_file in os.scandir(result_dir):
				with open(result_file, 'r') as file:	
					data = file.read()
					if (killed(data) != True):
						file_count += 1
						get_qops_count(data)
						get_domain_dims(data)
						get_domain_sizes(data)
						get_substr_prof(data)
			
			print(result_dir.name, file_count)

	substr_profile[2] = substr_profile[2] / substr_profile[0]
	substr_profile[3] = substr_profile[3] / substr_profile[0]

def input_phase(argv):
	if (len(argv) < 3):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2]


input_dir, output_dir = input_phase(argv)
get_result_files(input_dir, output_dir)
print_data()
plot_data()
