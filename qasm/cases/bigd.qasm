OPENQASM 2.0;
include "qelib1.inc";
qreg q[20];
x q[5];
x q[4];
x q[9];
x q[18];
x q[6];
cx q[11], q[14];
cx q[12], q[1];
cx q[15], q[3];
cx q[10], q[8];
cx q[17], q[0];
x q[14];   
x q[17];  
x q[6];
x q[18];   
x q[15];  
x q[3];
x q[16];   
x q[0];
x q[4];
x q[19];