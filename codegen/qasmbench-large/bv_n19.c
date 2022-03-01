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
FILE *f = fopen("codegen/qasmbench-large/bv_n19.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg qr[19];\n");
for (int c0 = 0; c0 <= 9; c0 += 1) {
  if (c0 == 0) {
    for (int c1 = -18; c1 < 0; c1 += 1) {
      fprintf(f, "u q[%u];\n", -c1);
    }
  }
  if (c0 == 0) {
    fprintf(f, "u q[%u];\n", 18);
  }
  fprintf(f, "u q[%u];\n", c0);
  if (c0 == 0) {
    for (int c1 = 0; c1 <= 17; c1 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", c1, 18);
      if (c1 >= 10) {
        fprintf(f, "u q[%u];\n", c1);
      } else if (c1 == 0) {
        fprintf(f, "u q[%u];\n", 0);
      }
    }
  }
}
fclose(f);
return 0;
}