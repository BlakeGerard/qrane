OPENQASM 2.0;
include "qelib1.inc";
qreg q[11];
u q[0];
u q[9];
u q[0];
cx q[0], q[6];
u3 q[6];
cx q[0], q[3];
u3 q[3];
cx q[0], q[3];
u3 q[3];
u q[3];
u q[3];
cx q[3], q[4];
u3 q[4];
cx q[0], q[6];
u q[0];
cx q[9], q[10];
u3 q[6];
u q[6];
u q[0];
u q[6];
cx q[3], q[4];
cx q[0], q[9];
cx q[0], q[1];
cx q[6], q[7];
u3 q[1];
u3 q[7];
u3 q[4];
cx q[0], q[1];
cx q[6], q[7];
u3 q[1];
u3 q[7];
cx q[0], q[2];
cx q[6], q[8];
u3 q[2];
u3 q[8];
cx q[0], q[2];
cx q[6], q[8];
u q[0];
measure q[0], q[0];
measure q[9], q[9];
u3 q[2];
u3 q[8];
cx q[6], q[7];
cx q[6], q[8];
u3 q[7];
u3 q[8];
cx q[3], q[4];
cx q[6], q[7];
u3 q[4];
u3 q[7];
cx q[3], q[4];
cx q[6], q[8];
u3 q[4];
u3 q[6];
u3 q[8];
cx q[3], q[5];
cx q[7], q[6];
u3 q[5];
u3 q[6];
cx q[3], q[5];
cx q[8], q[6];
u3 q[5];
u3 q[6];
cx q[3], q[5];
cx q[7], q[6];
u3 q[5];
u3 q[6];
u3 q[7];
cx q[8], q[6];
cx q[8], q[7];
u3 q[6];
u3 q[7];
u3 q[8];
cx q[3], q[5];
cx q[8], q[7];
u3 q[3];
u3 q[5];
cx q[4], q[3];
cx q[9], q[10];
u3 q[3];
u3 q[10];
cx q[5], q[3];
cx q[0], q[10];
u3 q[3];
u3 q[10];
cx q[10], q[1];
cx q[10], q[2];
u3 q[1];
u3 q[2];
cx q[10], q[2];
cx q[4], q[3];
u3 q[6];
u3 q[2];
u3 q[3];
u3 q[4];
cx q[5], q[3];
cx q[5], q[4];
u q[6];
u3 q[6];
u3 q[3];
u3 q[3];
cx q[10], q[1];
u q[3];
u3 q[4];
u3 q[5];
cx q[5], q[4];
u3 q[3];
u3 q[1];
cx q[7], q[6];
u3 q[6];
u3 q[10];
cx q[2], q[10];
u3 q[10];
cx q[1], q[10];
u3 q[10];
cx q[2], q[10];
u3 q[2];
cx q[1], q[2];
cx q[4], q[3];
u3 q[3];
u3 q[2];
cx q[5], q[3];
u3 q[10];
u3 q[3];
cx q[1], q[10];
u3 q[1];
cx q[1], q[2];
u3 q[10];
u3 q[10];
u q[10];
u3 q[10];
cx q[4], q[3];
u3 q[3];
cx q[5], q[3];
u3 q[3];
u3 q[4];
cx q[2], q[10];
u3 q[10];
cx q[1], q[10];
cx q[5], q[4];
u3 q[5];
u3 q[4];
u3 q[3];
u q[3];
u3 q[10];
cx q[5], q[4];
cx q[2], q[10];
u3 q[10];
cx q[1], q[10];
u3 q[10];
u3 q[2];
cx q[1], q[2];
u3 q[1];
u3 q[2];
cx q[1], q[2];
cx q[8], q[6];
u3 q[6];
u3 q[10];
u q[10];
u q[10];
u q[10];
u q[3];
u q[3];
cx q[10], q[3];
u3 q[3];
cx q[7], q[6];
u3 q[7];
u3 q[6];
cx q[8], q[6];
u3 q[6];
u3 q[6];
u q[6];
u q[6];
u q[6];
cx q[10], q[3];
u3 q[3];
cx q[8], q[7];
u3 q[7];
cx q[10], q[6];
u3 q[6];
cx q[10], q[6];
u3 q[6];
u3 q[8];
cx q[8], q[7];
u3 q[10];
cx q[6], q[10];
u3 q[10];
cx q[3], q[10];
u3 q[10];
cx q[6], q[10];
u3 q[6];
u3 q[10];
cx q[3], q[6];
cx q[3], q[10];
u3 q[10];
u3 q[3];
u3 q[6];
cx q[3], q[6];
u3 q[10];
u q[10];
u3 q[10];
cx q[6], q[10];
u3 q[10];
cx q[3], q[10];
u3 q[10];
cx q[6], q[10];
u3 q[6];
cx q[3], q[6];
u3 q[6];
u3 q[10];
cx q[3], q[10];
u3 q[3];
cx q[3], q[6];
u3 q[10];
u3 q[10];
u q[10];
u q[10];
u q[10];