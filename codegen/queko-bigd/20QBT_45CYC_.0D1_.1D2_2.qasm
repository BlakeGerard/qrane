OPENQASM 2.0;
include "qelib1.inc";
qreg q[20];
cx q[12], q[7];
cx q[11], q[12];
cx q[3], q[11];
cx q[2], q[11];
cx q[11], q[12];
cx q[2], q[12];
cx q[3], q[2];
cx q[11], q[13];
cx q[9], q[13];
cx q[16], q[9];
cx q[9], q[13];
cx q[11], q[17];
cx q[13], q[7];
cx q[2], q[12];
cx q[15], q[2];
cx q[13], q[7];
cx q[11], q[13];
cx q[1], q[15];
cx q[15], q[4];
cx q[4], q[18];
cx q[1], q[4];
cx q[1], q[4];
cx q[1], q[15];
cx q[15], q[4];
cx q[1], q[2];
cx q[2], q[4];
cx q[1], q[15];
cx q[10], q[17];
cx q[11], q[17];
cx q[15], q[2];
cx q[15], q[2];
cx q[15], q[4];
cx q[1], q[15];
cx q[15], q[4];
cx q[4], q[18];
cx q[2], q[4];
cx q[15], q[4];
cx q[1], q[15];
cx q[1], q[15];
cx q[1], q[2];
cx q[1], q[15];
cx q[1], q[15];
cx q[6], q[1];
cx q[6], q[1];
cx q[1], q[15];
