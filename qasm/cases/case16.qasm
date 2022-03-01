OPENQASM 2.0;
include "qelib1.inc";
qreg q[9];

z q[2];
h q[0];
h q[1];
h q[2];
h q[3];
z q[1];