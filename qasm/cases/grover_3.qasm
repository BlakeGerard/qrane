OPENQASM 2.0;
include "qelib1.inc";
qreg q[3];
h q[0]; // S0
h q[1]; // S0
h q[2]; // S0
x q[1]; // S1
ccx q[0],q[1],q[2]; // S2
x q[1]; // S3
h q[0]; // S0
h q[1]; // S0
x q[0]; // S3
x q[1]; // S5
h q[1]; // S6
cx q[0],q[1]; // S7
x q[0];	// S5
h q[1];
h q[0];
x q[1];
h q[1];