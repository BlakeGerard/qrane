OPENQASM 2.0;
include "qelib1.inc";
qreg q[9];

h q[0];
h q[1];
h q[2];
x q[0];
x q[1];
x q[2];

h q[0];
h q[1];
x q[0];
x q[1];

h q[0];
x q[0];