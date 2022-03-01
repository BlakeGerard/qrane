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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.2D2_9.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 49; c0 += 1) {
  if (c0 >= 22 && c0 <= 23) {
    fprintf(f, "cx q[%u], q[%u];\n", 8 * c0 - 175, -3 * c0 + 85);
  }
  if (c0 >= 23 && c0 <= 24) {
    fprintf(f, "cx q[%u], q[%u];\n", 3 * c0 - 63, 16 * c0 - 367);
  } else {
    if (c0 >= 20 && c0 <= 21) {
      fprintf(f, "cx q[%u], q[%u];\n", 9 * c0 - 180, 10 * c0 - 194);
    }
    if (c0 >= 21 && c0 <= 22) {
      fprintf(f, "cx q[%u], q[%u];\n", -6 * c0 + 132, 15 * c0 - 314);
    } else if (c0 == 47) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", c2 + 8, 4 * c2 + 12);
      }
    } else if (c0 == 40) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 10 * c2 + 6, 4 * c2 + 13);
      }
    } else if (c0 == 39) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 7 * c2 + 1, 3 * c2 + 13);
      }
    } else if (c0 == 38) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 13, 6 * c2 + 10);
      }
    } else if (c0 == 37) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -6 * c2 + 6, 3 * c2 + 13);
      }
    } else if (c0 == 36) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", c2, 13 * c2 + 6);
      }
    } else if (c0 == 33) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 13 * c2 + 6, 10 * c2 + 1);
      }
    } else if (c0 == 31) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c2 + 10, 5 * c2 + 14);
      }
    } else if (c0 == 30) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c2 + 10, 8 * c2 + 11);
      }
    } else if (c0 == 29) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -12 * c2 + 13, 9 * c2 + 10);
      }
    } else if (c0 == 20) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 14 * c2 + 2, 2 * c2 + 15);
      }
    } else if (c0 == 19) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c2 + 2, 2 * c2 + 15);
      }
    } else if (c0 == 18) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -18 * c2 + 18, 2 * c2 + 4);
      }
    } else if (c0 == 17) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -8 * c2 + 9, 13 * c2);
      }
    } else if (c0 == 16) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -3 * c2 + 9, 13 * c2);
      }
    } else if ((c0 - 8) % 24 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 32) / 24; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((c0 - 8) / 24) + 19 * c2, ((13 * c0 + 40) / 24) + 5 * c2);
      }
    } else if ((c0 - 12) % 33 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 45) / 33; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((2 * c0 + 174) / 33) + 4 * c2, ((5 * c0 - 49) / 11) + 10 * c2);
      }
    } else if ((c0 - 9) % 25 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 34) / 25; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((-19 * c0 + 646) / 25) - 19 * c2, ((-c0 + 64) / 5) + 5 * c2);
      }
    } else if ((c0 - 2) % 23 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 25) / 23; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((4 * c0 + 38) / 23) + 11 * c2, ((c0 + 412) / 23) + c2);
      }
      if (c0 == 48) {
        for (int c2 = 0; c2 <= 1; c2 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 12, 3 * c2 + 5);
        }
      }
    } else if (c0 == 43) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c2 + 12, 11 * c2 + 5);
      }
    } else if ((c0 - 11) % 31 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 42) / 31; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((-c0 + 538) / 31) - 9 * c2, ((2 * c0 + 288) / 31) + 6 * c2);
      }
    } else if ((c0 + 14) % 29 == 0) {
      for (int c2 = 0; c2 <= 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((-c0 + 276) / 29) + c2, ((2 * c0 - 30) / 29) + 14 * c2);
      }
      if (c0 == 15) {
        for (int c2 = 0; c2 <= 1; c2 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -6 * c2 + 8, 6 * c2 + 12);
        }
      }
    } else if ((c0 - 3) % 23 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 26) / 23; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((11 * c0 + 13) / 23) + 11 * c2, ((15 * c0 + 47) / 23) + 15 * c2);
      }
    } else if ((c0 - 4) % 23 == 0) {
      for (int c2 = 0; c2 <= (-c0 + 27) / 23; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", ((-3 * c0 + 104) / 23) + 2 * c2, ((10 * c0 + 29) / 23) + 10 * c2);
      }
    }
    if (c0 % 7 == 0) {
      for (int c2 = 0; c2 <= (-c0 / 7) + 1; c2 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", (-c0 / 7) + 11 * c2 + 7, (10 * c0 / 7) + c2 + 9);
      }
    }
  }
  if ((c0 - 1) % 23 == 0) {
    for (int c2 = 0; c2 <= (-c0 + 24) / 23; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", ((-12 * c0 + 426) / 23) - 11 * c2, ((9 * c0 + 83) / 23) + 5 * c2);
    }
  } else if ((c0 - 10) % 25 == 0) {
    for (int c2 = 0; c2 <= (-c0 + 35) / 25; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", (-2 * c0 / 5) - 16 * c2 + 20, ((-11 * c0 + 410) / 25) + 5 * c2);
    }
  } else if ((c0 - 5) % 36 == 0) {
    for (int c2 = 0; c2 <= (-c0 + 41) / 36; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", ((c0 + 7) / 3) - 4 * c2, ((c0 + 7) / 4) + 3 * c2);
    }
  } else if ((c0 - 6) % 22 == 0) {
    for (int c2 = 0; c2 <= (-c0 + 28) / 22; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", ((-5 * c0 + 162) / 22) - 4 * c2, ((6 * c0 - 25) / 11) + 17 * c2);
    }
  } else if ((c0 - 14) % 35 == 0) {
    for (int c2 = 0; c2 <= (-c0 + 49) / 35; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 2 * c2 + 8, ((2 * c0 - 18) / 5) + 12 * c2);
    }
  } else if ((c0 - 13) % 33 == 0) {
    for (int c2 = 0; c2 <= (-c0 + 46) / 33; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", ((8 * c0 - 104) / 33) + 7 * c2, ((10 * c0 + 68) / 33) + 2 * c2);
    }
  }
}
fclose(f);
return 0;
}