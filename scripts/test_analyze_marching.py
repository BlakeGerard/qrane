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
	'size' : 5}
matplotlib.rc('font', **font)

def plot_data(all):
	num_plots = 10
	fig, axes = plt.subplots(2, 5)
	i, j = 0, 0
	suptitle = "Look-Ahead Depth Study for QUEKO-BSS"

	all_keys_sorted = sorted(all)
	for depth_class in all_keys_sorted:
		lookaheads_keys_sorted = sorted(all[depth_class])

		if (depth_class == "100CYC" or depth_class == "200CYC" or depth_class == "300CYC" or depth_class == "400CYC" or depth_class == "500CYC"): i = 0
		else: i = 1

		x = [] # Lookahead depths
		y = [] # Average domain count across QSE_0, ..., QSE_9 for the current CYC

		for lookahead_depth in lookaheads_keys_sorted:
			x.append(lookahead_depth)
			y.append(all[depth_class][lookahead_depth])

		print(x, y)

		axes[i][j].set_title(depth_class)
		axes[i][j].set_xlabel("Look-ahead Depth (gates)")
		axes[i][j].set_ylabel("Total Number of Domains")
		axes[i][j].bar(x, y)
		axes[i][j].set_xticks(x)
		j += 1
		if (j > 4): j = 0

	fig.delaxes(axes[1][4])
	fig.suptitle(suptitle)
	plt.tight_layout()
	plt.savefig("./lookahead-depth-study.pdf", format="pdf")

# { Card : Count }
def get_card_count_profile(data):
	card_count_profile = defaultdict(int)
	dims_size = re.findall("\d+ : \d+", data)
	for val in dims_size:
		left = int(val[:val.index(':')].strip())
		right = int(val[val.index(':')+1:].strip())
		card_count_profile[left] += right

	return card_count_profile

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

def get_total_domain_count(data):
	total_str = re.search("Total: \d+ domains", data)
	total_cnt = int((re.search("\d+", total_str[0]))[0])
	return(total_cnt)

def get_file_name_information(file_name):
	file_name = file_name[0:]
	fields = file_name.split('.')

	depth_class = (fields[0].split("_"))[1]
	lookahead_depth = int(fields[1].replace('d', ''))

	return depth_class, lookahead_depth

def get_result_files(input_dir, output_dir):
	all = defaultdict(lambda: defaultdict(int))

	# For each results directory (containing results for a specific benchmark)
	for f in os.scandir(input_dir):
		if (f.name.endswith('.txt') == False): continue
		with open(f, 'r') as fh:
			contents = fh.read()
			depth_class, lookahead_depth = get_file_name_information(f.name)
			all[depth_class][lookahead_depth] += get_total_domain_count(contents)

	print(all)

	# We have to divide each total_domain_count by 10 to get the average across QSE_0, ... QSE_9
	for depth_class in all:
		for lookahead_depth in all[depth_class]:
			all[depth_class][lookahead_depth] /= 10

	return all

def compute_averages_per_depth(all):
	averages = defaultdict(list)

def input_phase(argv):
	if (len(argv) < 3):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2]


input_dir, output_dir = input_phase(argv)
all = get_result_files(input_dir, output_dir)
plot_data(all)
