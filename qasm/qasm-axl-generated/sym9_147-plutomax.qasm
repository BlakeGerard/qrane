OPENQASM 2.0;
include "qelib1.inc";
qreg qureg[12];
ccx qureg[0],qureg[1],qureg[9];
ccx qureg[2],qureg[9],qureg[10];
ccx qureg[3],qureg[10],qureg[11];
cx qureg[0],qureg[1];
ccx qureg[1],qureg[2],qureg[9];
cx qureg[1],qureg[2];
ccx qureg[3],qureg[9],qureg[10];
ccx qureg[4],qureg[10],qureg[11];
ccx qureg[2],qureg[3],qureg[9];
cx qureg[2],qureg[3];
ccx qureg[4],qureg[9],qureg[10];
ccx qureg[5],qureg[10],qureg[11];
ccx qureg[3],qureg[4],qureg[9];
cx qureg[3],qureg[4];
ccx qureg[5],qureg[9],qureg[10];
ccx qureg[6],qureg[10],qureg[11];
ccx qureg[4],qureg[5],qureg[9];
cx qureg[4],qureg[5];
ccx qureg[6],qureg[9],qureg[10];
ccx qureg[7],qureg[10],qureg[11];
ccx qureg[5],qureg[6],qureg[9];
cx qureg[5],qureg[6];
ccx qureg[7],qureg[9],qureg[10];
ccx qureg[8],qureg[10],qureg[11];
ccx qureg[6],qureg[7],qureg[9];
cx qureg[6],qureg[7];
ccx qureg[8],qureg[9],qureg[10];
cx qureg[10],qureg[11];
