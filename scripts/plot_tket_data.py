from re import sub
from sys import argv
from collections import defaultdict
from numpy import linspace, arange
import matplotlib.pyplot as plt
from more_itertools import grouper

plt.rcParams.update({'font.size': 11})

title = "Queko BIGD with Minfuse on Tket"
arch = "ibmq_brooklyn"
out_name = "queko-bigd-minfuse-tket.pdf"


# gates   three lines per graph
#         l1 = all gate values
#
# depths
#
# times
def plot_data(data, arch, out_name):
	global title
	metrics = 3
	labels = ['minfuse + tket baseline', 'minfuse + tket optimizations', 'original + tket optimizations']
	metric_titles = ['Gate Delta', 'Circuit Depth', 'Compilation Time in Seconds']
	metric_labels = ['Gate Delta (gates)', 'Circuit Depth (gates)', 'Compilation Time (sec)']

	fig, axes = plt.subplots(3, 1, sharex=True, figsize=(10,10))
	x = list(range(0, len(data)))

	gates_c1 = []
	gates_c2 = []
	gates_c3 = []

	# For each configuration
	for circ in data:
		gates_c1.append(data[circ]['qrane_baseline'][0])
		gates_c2.append(data[circ]['qrane_fancy'][0])
		gates_c3.append(data[circ]['qasm_fancy'][0])
	l1 = axes[0].plot(x, gates_c1, '-', label=labels[0], color='purple')
	l2 = axes[0].plot(x, gates_c2, '-', label=labels[1], color='green')
	l3 = axes[0].plot(x, gates_c3, '-', label=labels[2], color='orange')
	axes[0].set_title(metric_titles[0])
	axes[0].set_xlabel('Circuits')
	axes[0].set_ylabel(metric_labels[0])
	axes[0].grid()

	gates_c1.clear()
	gates_c2.clear()
	gates_c3.clear()

	for circ in data:
		gates_c1.append(data[circ]['qrane_baseline'][1])
		gates_c2.append(data[circ]['qrane_fancy'][1])
		gates_c3.append(data[circ]['qasm_fancy'][1])
	l1 = axes[1].plot(x, gates_c1, '-', label=labels[0], color='purple')
	l2 = axes[1].plot(x, gates_c2, '-', label=labels[1], color='green')
	l3 = axes[1].plot(x, gates_c3, '-', label=labels[2], color='orange')
	axes[1].set_title(metric_titles[1])
	axes[1].set_xlabel('Circuits')
	axes[1].set_ylabel(metric_labels[1])
	axes[1].grid()


	gates_c1.clear()
	gates_c2.clear()
	gates_c3.clear()

	l1 = ""
	l2 = ""
	l3 = ""
	for circ in data:
		gates_c1.append(data[circ]['qrane_baseline'][2])
		gates_c2.append(data[circ]['qrane_fancy'][2])
		gates_c3.append(data[circ]['qasm_fancy'][2])
	l1 = axes[2].plot(x, gates_c1, '-', label=labels[0], color='purple')
	l2 = axes[2].plot(x, gates_c2, '-', label=labels[1], color='green')
	l3 = axes[2].plot(x, gates_c3, '-', label=labels[2], color='orange')
	axes[2].set_title(metric_titles[2])
	axes[2].set_xlabel('Circuits')
	axes[2].set_ylabel(metric_labels[2])
	axes[2].grid()

	fig.tight_layout()
	fig.legend([l1, l2, l3], labels=labels, title='Configuration')
	plt.savefig(out_name, format='pdf')

def pretty_print_data(data):
	for circ in data:
		print(circ + " := {")
		for config in data[circ]:
			print("\t" + config, data[circ][config])
		print("}")


def group_data(file):
	'''
	Read data from asplos2022/new-experiments/all_tket_data/
	'''
	content = open(file, "r").readlines()
	data = defaultdict(lambda: defaultdict(list))
	for line in content:
		line = line.split(':')
		circ_name = line[0]
		data[circ_name]['qrane_baseline'] = [int(line[1]), int(line[2]), float(line[3])]
		data[circ_name]['qrane_fancy']    = [int(line[5]), int(line[6]), float(line[7])]
		data[circ_name]['qasm_fancy']   = [int(line[9]), int(line[10]), float(line[11])]
	return data

def input_phase(argv):
	if (len(argv) < 2):
		print("Must input data file.")
		exit(1)

input_phase(argv)
file = argv[1]
data = group_data(file)
pretty_print_data(data)
plot_data(data, arch, out_name)
