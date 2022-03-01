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
FILE *f = fopen("check.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[9];\n");
{
  for (int c0 = 0; c0 <= 7; c0 += 1) {
    if (c0 == 5 || c0 == 3 || c0 == 1) {
      fprintf(f, "x q[%u];\n", (c0 + 1) / 2);
    } else {
      fprintf(f, "h q[%u];\n", c0 == 0 ? 0 : c0 == 2 ? 1 : c0 == 4 ? 2 : c0 - 6);
    }
  }
  for (int c0 = 8; c0 <= 10; c0 += 1) {
    fprintf(f, "y q[%u];\n", c0 - 8);
  }
  fprintf(f, "h q[%u];\n", 0);
}
fclose(f);
return 0;
}