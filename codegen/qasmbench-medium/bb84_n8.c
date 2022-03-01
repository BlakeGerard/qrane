#include "stdio.h"

#ifdef ceild
#undef ceild
#endif
#ifdef floord
#undef floord
#endif
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif
#define ceild(n,d)  (((n) < 0)? -((-(n))/(d)) : ((n)+(d)-1)/(d))
#define floord(x,y) (((x) < 0)? -((-(x)+(y)-1)/(y)) : (x)/(y))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

int main() {
FILE *f = fopen("codegen/qasmbench-medium/bb84_n8.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[8];\n");
for (int c0 = 0; c0 <= 1; c0 += 1) {
  if (c0 == 1) {
    for (int c1 = 1; c1 <= 2; c1 += 1) {
      if (c1 == 2) {
        fprintf(f, "measure q[%u], q[%u];\n", 7, 0);
        fprintf(f, "u q[%u];\n", 7);
        fprintf(f, "u q[%u];\n", 7);
      }
      fprintf(f, "measure q[%u], q[%u];\n", c1 + 5, 0);
      if (c1 == 1) {
        fprintf(f, "u q[%u];\n", 6);
        fprintf(f, "measure q[%u], q[%u];\n", 6, 0);
        fprintf(f, "measure q[%u], q[%u];\n", 0, 0);
        fprintf(f, "u q[%u];\n", 0);
        fprintf(f, "measure q[%u], q[%u];\n", 0, 0);
        fprintf(f, "measure q[%u], q[%u];\n", 3, 0);
        fprintf(f, "u q[%u];\n", 3);
        fprintf(f, "u q[%u];\n", 3);
        fprintf(f, "measure q[%u], q[%u];\n", 3, 0);
        fprintf(f, "measure q[%u], q[%u];\n", 1, 0);
        fprintf(f, "u q[%u];\n", 1);
        fprintf(f, "u q[%u];\n", 1);
        fprintf(f, "measure q[%u], q[%u];\n", 1, 0);
        fprintf(f, "measure q[%u], q[%u];\n", 2, 0);
        fprintf(f, "u q[%u];\n", 2);
        fprintf(f, "u q[%u];\n", 2);
        fprintf(f, "u q[%u];\n", 2);
        fprintf(f, "measure q[%u], q[%u];\n", 2, 0);
        fprintf(f, "measure q[%u], q[%u];\n", 4, 0);
        fprintf(f, "u q[%u];\n", 4);
        fprintf(f, "u q[%u];\n", 4);
        fprintf(f, "u q[%u];\n", 4);
        fprintf(f, "measure q[%u], q[%u];\n", 4, 0);
        fprintf(f, "measure q[%u], q[%u];\n", 5, 0);
        fprintf(f, "u q[%u];\n", 5);
        fprintf(f, "measure q[%u], q[%u];\n", 5, 0);
      }
    }
  } else {
    for (int c1 = -4; c1 <= 1; c1 += 1) {
      fprintf(f, "u q[%u];\n", -c1 + 1);
      if (c1 >= 0) {
        fprintf(f, "u q[%u];\n", 3 * c1 + 1);
        if (c1 == 1) {
          fprintf(f, "u q[%u];\n", 2);
        } else if (c1 == 0) {
          fprintf(f, "u q[%u];\n", 5);
        }
      }
    }
    fprintf(f, "u q[%u];\n", 7);
    fprintf(f, "u q[%u];\n", 7);
  }
}
fclose(f);
return 0;
}