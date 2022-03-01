OPENQASM 2.0;
include "qelib1.inc";
qreg q[9];

h q[0];
h q[1];
h q[2];

x q[3];
x q[4];
x q[5];

h q[0];
h q[1];

y q[0];
y q[1];
y q[2];

h q[4];

h q[0];