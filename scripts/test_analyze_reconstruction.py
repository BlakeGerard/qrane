import math
from sys import argv
import os
import subprocess as sp
import re
from collections import defaultdict
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

font = {'family' : 'normal',
	'size' : 6}
matplotlib.rc('font', **font)

total_qops_processed = 0


def plot_data(profile, name):
	num_plots = len(profile)	# One plot per dimension
	fig, axes = plt.subplots(2, 2)
	ax = 0
	for dim in profile:
		x = np.asarray(sorted(profile[dim].keys()))
		y = np.asarray([profile[dim][xv] for xv in x])
		i, j = 0, 0
		x_title = "Domain Cardinality (points)"
		y_title = "Number of Domains"
		if (ax == 0):
			title = "1D" 
			i,j = 0,0
		if (ax == 1): 
			title = "2D"
			i,j = 0,1
		if (ax == 2):
			title = "3D" 
			i,j = 1,0
		if (ax == 3):
			title = "4D" 
			i,j = 1,1
		if (ax == 4): break #i,j = 1,1

		axes[i][j].set_title(title)
		axes[i][j].set_xlabel(x_title)
		axes[i][j].set_ylabel(y_title)
		axes[i][j].bar(x, y)
		axes[i][j].set_xticks(x)
		ax += 1

	fig.suptitle(name + " Reconstruction Profile")
	plt.tight_layout()
	plt.savefig("./" + name + ".pdf", format="pdf")

def get_qops_count(data):
	global total_qops_processed
	qops_line = re.search("Qops: \d*", data).group()
	number = int(re.search("\d+", qops_line).group())
	total_qops_processed += number

# { Card : Count }
def get_domain_sizes(data):
	'''
	dims_size = re.findall("\d+ : \d+", data)
	for val in dims_size:
		left = int(val[:val.index(':')].strip())
		right = int(val[val.index(':')+1:].strip())
		domain_size_profile[left] += right
	'''

# { Dim : Count }
def get_domain_dims(data):
	'''
	global domain_dim_profile
	dims_prof = re.findall("\dD: \d+", data)
	for val in dims_prof:
		colon = val.index(':')
		dim = val[0:colon]
		count = int(val[colon+2:])
		domain_dim_profile[dim] += count
	'''

def get_reconstruction_profile(data):
	profile = defaultdict(lambda: defaultdict(lambda: 0))
	prof_lines = re.findall("\d -> {.+}", data)
	for line in prof_lines:
		line = line.replace(" ", "").split("->")
		dim = int(line[0])
		hist = line[1]
		hist = hist.strip("{}")
		buckets = hist.split(",")
		for bucket in buckets:
			if bucket != '':
				both = bucket.split(":")
				lhs = int(both[0])
				rhs = int(both[1])
				profile[dim][lhs] += rhs
	return profile

def get_result_files(input_dir, output_dir):

	# For each results directory (containing results for a specific benchmark)
	for result_dir in os.scandir(input_dir):
		if (result_dir.is_dir()):

			main_prof = defaultdict(lambda: defaultdict(lambda: 0))
			file_count = 0

			# Go through each result file and catalogue the results in the global variables
			for result_file in os.scandir(result_dir):
				with open(result_file, 'r') as file:	
					data = file.read()
					get_qops_count(data)
					main_prof.update(get_reconstruction_profile(data))
					file_count += 1

			print(main_prof)
			print(result_dir.name)
			plot_data(main_prof, result_dir.name)

def input_phase(argv):
	if (len(argv) < 3):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2]


input_dir, output_dir = input_phase(argv)
get_result_files(input_dir, output_dir)
