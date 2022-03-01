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
FILE *f = fopen("codegen/qasmbench-large/ghz_state_n23.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[23];\n");
{
  fprintf(f, "u q[%u];\n", 0);
  for (int c0 = 0; c0 <= 21; c0 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c0, c0 + 1);
  }
}
fclose(f);
return 0;
}