OPENQASM 2.0;
include "qelib1.inc";
qreg q[4];
h q[0];//0
h q[1];//0
y q[2];//1
cx q[2], q[0]; //2
h q[0];//3
z q[1];//4
h q[1];//3
h q[0];//4
z q[0];//4
h q[1];//3
