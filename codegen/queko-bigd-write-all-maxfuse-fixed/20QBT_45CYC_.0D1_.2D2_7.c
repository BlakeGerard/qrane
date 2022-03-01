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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.2D2_7.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 3; c0 += 1) {
  if (c0 == 1) {
    for (int c2 = 1; c2 <= 2; c2 += 1) {
      if (c2 == 2) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 17, 8 * c4 + 2);
        }
      } else {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 10, 14 * c4 + 4);
        }
      }
    }
    fprintf(f, "cx q[%u], q[%u];\n", 8, 14);
    for (int c4 = 0; c4 <= 1; c4 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 19, 8 * c4 + 10);
    }
    for (int c2 = 4; c2 <= 5; c2 += 1) {
      if (c2 == 5) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -18 * c4 + 19, 6 * c4 + 4);
        }
      } else {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -11 * c4 + 19, 10 * c4 + 4);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 5, 18);
      }
    }
    for (int c2 = 6; c2 <= 8; c2 += 1) {
      if (c2 == 8) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 4, 11 * c4);
        }
      } else if (c2 == 7) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 14, 19 * c4);
        }
      } else {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -c4 + 10, 5 * c4 + 14);
        }
      }
    }
  }
  for (int c4 = 0; c4 <= -c0 + 1; c4 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 9 * c0 + c4, 4 * c0 + 7 * c4 + 7);
  }
  if (c0 == 0) {
    for (int c2 = 4; c2 <= 8; c2 += 1) {
      if (c2 == 7) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 14, 19 * c4);
        }
      } else if (c2 == 6) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 11 * c4, 7 * c4 + 12);
        }
      } else if (c2 == 5) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -17 * c4 + 17, c4 + 11);
        }
      } else {
        for (int c4 = 0; c4 <= (-c2 / 4) + 2; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", (c2 / 2) + 3 * c4 + 2, (11 * c2 / 4) + 12 * c4 - 11);
        }
      }
    }
  }
  for (int c4 = 0; c4 <= -c0 + 1; c4 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -6 * c0 - 4 * c4 + 15, 5 * c0 + 10 * c4 + 6);
  }
  if (c0 == 1) {
    for (int c2 = 11; c2 <= 18; c2 += 1) {
      if (c2 >= 16 && c2 <= 17) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 96, 6 * c2 - 83);
        if (c2 == 17) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 16, 5 * c4 + 13);
          }
        } else {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -c4 + 11, 3 * c4 + 2);
          }
        }
      } else {
        if (c2 == 18) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -5 * c4 + 16, 6 * c4 + 13);
          }
        }
        if (c2 == 15) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 15 * c4 + 2, 11 * c4 + 5);
          }
        } else if (c2 == 14) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 16, 5 * c4 + 13);
          }
        } else if (c2 == 13) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 14 * c4 + 2, 10 * c4 + 3);
          }
        } else if (c2 == 12) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 7 * c4 + 9, c4 + 1);
          }
        } else if (c2 == 11) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 11, 17 * c4 + 2);
          }
        }
      }
    }
  }
  if (c0 >= 1 && c0 <= 2) {
    for (int c2 = -c0 + 20; c2 <= 20; c2 += 1) {
      if (2 * c0 + c2 == 22) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", c4 + 10, 2 * c4 + 14);
        }
      } else if (c2 == 19) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c0 - c4 + 14, -6 * c0 + 4 * c4 + 19);
        }
      } else {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -c4 + 16, 4 * c4 + 13);
        }
      }
    }
  }
  for (int c2 = -22 * c0 + 65; c2 <= -21 * c0 + 63; c2 += 1) {
    if (22 * c0 + c2 == 65) {
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 17, 10 * c4 + 2);
      }
    } else {
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -15 * c4 + 17, 2 * c4 + 16);
      }
    }
  }
  if (c0 == 3) {
    for (int c2 = 1; c2 <= 5; c2 += 1) {
      if (c2 == 5) {
        fprintf(f, "cx q[%u], q[%u];\n", 17, 16);
      } else if (c2 == 4) {
        fprintf(f, "cx q[%u], q[%u];\n", 17, 16);
      } else if (c2 == 3) {
        fprintf(f, "cx q[%u], q[%u];\n", 16, 13);
      } else if (c2 == 2) {
        fprintf(f, "cx q[%u], q[%u];\n", 16, 13);
      } else {
        fprintf(f, "cx q[%u], q[%u];\n", 11, 16);
      }
    }
  } else if (c0 == 0) {
    for (int c2 = 10; c2 <= 12; c2 += 1) {
      if (c2 == 12) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 19, 8 * c4 + 10);
        }
      } else if (c2 == 11) {
        fprintf(f, "cx q[%u], q[%u];\n", 19, 5);
      } else {
        fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
      }
    }
  }
  if (c0 == 2) {
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -16 * c2 + 17, 8 * c2 + 2);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 6 * c2 + 9, 16 * c2 + 1);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -12 * c2 + 15, c2 + 17);
    }
  } else if (c0 == 1) {
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 9 * c2 + 2, 16 * c2 + 3);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 8 * c2 + 1, 5 * c2 + 14);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -7 * c2 + 18, 9 * c2 + 7);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -2 * c2 + 19, 12 * c2 + 4);
    }
  }
}
fclose(f);
return 0;
}