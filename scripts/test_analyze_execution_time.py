from sys import argv
import os
import subprocess as sp
import re
from collections import defaultdict
import matplotlib.pyplot as plt
import numpy as np

def plot_data(all):
	x_qops = []
	y_recon = []
	y_sched = []

	all = sorted(all, key=lambda e: e[0])

	# Sort by number of qops
	for entry in all:
		x_qops.append(entry[0])
		y_recon.append(entry[1])
		y_sched.append(entry[2])

	x_qops = np.asarray(x_qops)
	y_recon = np.asarray(y_recon)
	y_sched = np.asarray(y_sched)

	fig, (ax1, ax2)  = plt.subplots(2, 1, sharex=True)
	fig.subplots_adjust(hspace=0.05)

	ax1.bar(x_qops-0.1, y_recon, color='cornflowerblue')
	ax1.bar(x_qops+0.1, y_sched, color='lightcoral')
	ax2.bar(x_qops-0.1, y_recon, color='cornflowerblue')
	ax2.bar(x_qops+0.1, y_sched, color='lightcoral')

	ax1.set_ylim(400, 19000)
	ax2.set_ylim(0, 200)

	ax1.spines['bottom'].set_visible(False)
	ax2.spines['top'].set_visible(False)
	ax1.xaxis.tick_top()
	ax1.tick_params(labeltop=False)
	ax2.xaxis.tick_bottom()

	plt.tight_layout()
	plt.savefig("./sched_scaling.pdf", format="pdf")


def killed(data):
	return data == "Killed" or data == ""

def get_qops_count(data):
	qops_line = re.search("Qops: \d*", data).group()
	number = int(re.search("\d+", qops_line).group())
	return number

def get_times(data):
	times = re.findall("\d+ms", data)
	recon = float(times[0].replace("ms", "")) * 0.001
	sched = float(times[1].replace("ms", "")) * 0.001
	return recon, sched

def get_result_files(input_dir, output_dir):
	all = []
	for file in os.scandir(input_dir):
		with open(file, 'r') as fh:
			if (file.stat().st_size > 0 and file.name.endswith(".txt")):
				data = fh.read()
				if (killed(data) == True): continue
				qops = get_qops_count(data)
				recon, sched = get_times(data)
				all.append((qops, recon, sched))
	return all

def input_phase(argv):
	if (len(argv) < 3):
		print("Please provide input and output directories")
		exit(1)
	else:
		return argv[1], argv[2]


input_dir, output_dir = input_phase(argv)
all = get_result_files(input_dir, output_dir)
plot_data(all)

out = open("./ibmqx-minfuse-timings.txt", "w")
for val in sorted(all, key=lambda e: e[0]):
	r = str(val[0]) + "," + str(round(val[1], 3)) + "," + str(round(val[2], 3)) + "\n"
	out.write(r)
out.close()
