OPENQASM 2.0;
include "qelib1.inc";

qreg q[3];

h q[1];
x q[1];
cx q[1],q[2];
x q[1];
h q[1];
cp(pi/2) q[2],q[1];
p(pi) q[1];
h q[2];
x q[2];
p(2*pi) q[2];
cx q[2],q[0];
cx q[1],q[0];
p(2*pi) q[0];
cx q[1],q[0];
cx q[2],q[0];
x q[2];
h q[2];
cp(pi/2) q[2],q[1];
h q[1];