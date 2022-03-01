import re
from pytket.circuit import Node, OpType

def get_arch_from_dot(dot_path):
	lines = []
	topo = []

	with open(dot_path, 'r') as dp:
		lines = dp.readlines()
		lines.pop(0)
		lines.pop()

	for line in lines:
		vertices = line.split(" -- ")
		vertices[0] = vertices[0].replace('q', '')
		vertices[1] = vertices[1].replace('q', '')
		vertices[1] = vertices[1].replace(';\n', '')
		topo.append( (int(vertices[0]), int(vertices[1])) )

	return topo

# 1_4:9.659e-3; 1_2:1.282e-2; 1_0:9.665e-3,1_4:526.222; 1_2:568.889; 1_0:419.556
def get_error_map_from_csv(csv_path):
	error_map = {}
	pattern = "\d+_\d+:.+e-\d+"
	with open(csv_path, 'r') as csv:
		for line in csv:
			found = re.findall(pattern, line)
			if (len(found) > 0):
				res = found[0].split(';')
				for val in res:
					val = val.strip()
					components = val.split(":")
					lhs = int(components[0][:components[0].index("_")])
					rhs = int(components[0][components[0].index("_")+1:])
					error = float(components[1])
					error_map.update( {(Node(lhs), Node(rhs)) : error} )
	return error_map

def get_node_error_map_from_csv(csv_path):
	error_map = {}
	with open(csv_path, 'r') as csv:
		count = 0
		for line in csv:
			line = line.split(",")
			error_str = line[11].strip()
			if (error_str == 'Single-qubit Pauli-X error'): continue
			error = float(error_str)
			error_map.update( {Node(count) : error} )
			count += 1
	return error_map
