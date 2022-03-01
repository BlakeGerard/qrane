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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.2D2_3.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    if (c1 == 1) {
      for (int c2 = 0; c2 <= 3; c2 += 1) {
        if (c2 == 3) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 8, 4 * c4);
          }
        } else if (c2 == 2) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 4, 10 * c4 + 5);
          }
        } else if (c2 == 1) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 12, 9 * c4 + 6);
          }
        } else {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c4 + 19, c4 + 5);
          }
        }
      }
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 4, 9 * c4 + 5);
      }
      for (int c2 = 5; c2 <= 36; c2 += 1) {
        if (c2 == 36) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 14, 16 * c4 + 3);
          }
        } else if (c2 == 35) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 14, 2 * c4 + 2);
          }
        } else if (c2 == 34) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 10, 2 * c4 + 1);
          }
        } else if (c2 == 33) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -12 * c4 + 13, 13 * c4 + 2);
          }
        } else if (c2 == 32) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c4 + 5, c4);
          }
        } else if (c2 == 31) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 10, 4 * c4 + 1);
          }
        } else if (c2 == 29) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c4, 4 * c4 + 11);
          }
        } else if (c2 == 28) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 10, 5 * c4 + 4);
          }
        } else if (c2 == 27) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 4, 7 * c4 + 5);
          }
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 6 * c4 + 13, 13 * c4 + 3);
          }
        } else if (c2 == 26) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 17, 13 * c4 + 6);
          }
        } else if (c2 == 25) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 8, 13 * c4 + 6);
          }
        } else if (c2 == 24) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -c4 + 16, c4 + 18);
          }
        } else if (c2 == 23) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 11, 13 * c4 + 3);
          }
        } else if (c2 == 22) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 6, 18 * c4);
          }
        } else if (c2 == 21) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 17 * c4 + 1, 3 * c4 + 8);
          }
        } else if (c2 == 20) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -c4 + 1, 11 * c4 + 7);
          }
        } else if (c2 == 19) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", c4 + 6, 12 * c4);
          }
        } else if (c2 == 18) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -11 * c4 + 12, c4 + 6);
          }
        } else if (c2 == 17) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -11 * c4 + 12, c4 + 6);
          }
        } else if (c2 == 16) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 17, 3 * c4 + 9);
          }
        } else if (c2 == 15) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 12, 7 * c4 + 6);
          }
        } else if (c2 == 9) {
          fprintf(f, "cx q[%u], q[%u];\n", 6, 9);
        } else if (c2 == 6) {
          fprintf(f, "cx q[%u], q[%u];\n", 6, 9);
        } else {
          if (c2 <= 14 && (c2 + 1) % 3 == 0) {
            for (int c4 = 0; c4 < (c2 - 8) / 3; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", ((c2 + 25) / 3) - 6 * c4, ((-7 * c2 + 104) / 3) + 10 * c4);
            }
            if (c2 == 5) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 6, 2 * c4 + 9);
              }
            }
          } else {
            if (c2 <= 13 && (c2 - 1) % 3 == 0) {
              for (int c4 = 0; c4 < (c2 - 7) / 3; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((7 * c2 - 52) / 3) - 6 * c4, -2 * c2 + 5 * c4 + 29);
              }
              if (c2 == 7) {
                fprintf(f, "cx q[%u], q[%u];\n", 17, 6);
              }
            }
            if ((c2 + 10) % 20 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((3 * c2 + 110) / 20) + 8 * c4, (-2 * c2 / 5) + 7 * c4 + 16);
              }
            }
          }
          if (c2 <= 12 && c2 % 4 == 0) {
            for (int c4 = 0; c4 < (c2 / 4) - 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", (-5 * c2 / 2) + 2 * c4 + 37, (3 * c2 / 4) + c4 + 3);
            }
          }
        }
      }
    }
    for (int c4 = 0; c4 <= -c1 + 1; c4 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 6 * c1 - 7 * c4 + 13, 13 * c1 + 11 * c4 + 3);
    }
    if (c1 == 1) {
      for (int c2 = 38; c2 <= 46; c2 += 1) {
        if (c2 == 46) {
          fprintf(f, "cx q[%u], q[%u];\n", 4, 5);
        } else if (c2 == 45) {
          fprintf(f, "cx q[%u], q[%u];\n", 5, 0);
        } else if (c2 == 44) {
          fprintf(f, "cx q[%u], q[%u];\n", 5, 0);
        } else if (c2 == 43) {
          fprintf(f, "cx q[%u], q[%u];\n", 5, 0);
        } else if (c2 == 42) {
          fprintf(f, "cx q[%u], q[%u];\n", 5, 0);
        } else if (c2 == 41) {
          fprintf(f, "cx q[%u], q[%u];\n", 5, 0);
        } else if (c2 == 40) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 4, 13 * c4 + 5);
          }
        } else if (c2 == 39) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 5, 19 * c4);
          }
        } else {
          fprintf(f, "cx q[%u], q[%u];\n", 19, 5);
        }
      }
    } else {
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 4, 9 * c4 + 5);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -7 * c1 + 14, 6 * c1 + 2);
  }
}
fclose(f);
return 0;
}