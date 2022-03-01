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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.3D2_0.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    if (c1 == 1) {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -11 * c5 + 14, 15 * c5 + 2);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 8, 3 * c5 + 11);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 5, 3);
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 12, 6 * c5 + 11);
      }
    }
    for (int c5 = 0; c5 <= -c1 + 1; c5 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -9 * c1 - 9 * c5 + 14, c1 + c5 + 2);
    }
    if (c1 == 1) {
      for (int c3 = 3; c3 <= 9; c3 += 1) {
        if (c3 >= 7 && c3 <= 8) {
          fprintf(f, "cx q[%u], q[%u];\n", 11 * c3 - 75, -4 * c3 + 38);
          if (c3 == 8) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 5, 7 * c5 + 3);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 17, 2 * c5 + 4);
            }
          }
        } else {
          if (c3 == 9) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 16, 5 * c5 + 5);
            }
          }
          if (c3 == 6) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 6, 17 * c5);
            }
          } else if (c3 == 5) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 13, 17 * c5);
            }
          } else if (c3 == 4) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 13, 8 * c5 + 6);
            }
          } else if (c3 == 3) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 5, 11 * c5 + 6);
            }
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 2, 2 * c5 + 8);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 5, 13 * c5 + 3);
      }
      for (int c3 = 11; c3 <= 13; c3 += 1) {
        if (c3 == 13) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 8, 15 * c5 + 4);
          }
        }
        if (c3 >= 12) {
          fprintf(f, "cx q[%u], q[%u];\n", 4 * c3 - 38, 9 * c3 - 100);
          if (c3 == 12) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 15, 2 * c5 + 2);
            }
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 13, 4 * c5);
          }
        }
      }
    }
    if (c1 == 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 9, 19);
    }
    for (int c5 = 0; c5 <= 1; c5 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 4 * c1 + 4 * c5, c1 + c5 + 10);
    }
    if (c1 == 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 10, 19);
      fprintf(f, "cx q[%u], q[%u];\n", 6, 15);
      fprintf(f, "cx q[%u], q[%u];\n", 17, 4);
      fprintf(f, "cx q[%u], q[%u];\n", 2, 8);
    } else {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -c5 + 10, 18 * c5 + 1);
      }
    }
    if (c1 == 1) {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 19, 17 * c5 + 1);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 3, 2);
      fprintf(f, "cx q[%u], q[%u];\n", 14, 17);
    } else {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 18, 6 * c5 + 9);
      }
    }
    for (int c5 = 0; c5 <= -c1 + 1; c5 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 12 * c1 + 5 * c5 + 3, 8 * c1 + 2 * c5 + 2);
    }
    if (c1 == 1) {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 10, 14 * c5 + 1);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 3, 17);
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -9 * c5 + 19, 7 * c5 + 1);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 14, c5 + 17);
      }
      for (int c3 = 19; c3 <= 20; c3 += 1) {
        if (c3 == 20) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 1, 3 * c5 + 12);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 6, 19 * c5);
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 9 * c5, 18 * c5 + 1);
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 5, 4 * c5 + 15);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 13, 6 * c5 + 6);
      }
      for (int c3 = 22; c3 <= 26; c3 += 1) {
        if (c3 == 26) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 + 2, 11 * c5 + 8);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 4, 12);
        } else if (c3 == 25) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 + 8, c5 + 4);
          }
        } else if (c3 == 24) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 10, 11 * c5 + 1);
          }
        } else if (c3 == 23) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 4, 4 * c5 + 12);
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 12 * c5 + 4, 3 * c5 + 12);
          }
        }
      }
    }
    if (c1 == 1) {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 15, 16 * c5 + 2);
      }
    }
    for (int c5 = 0; c5 <= 1; c5 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 + 8, 2 * c5 + 4);
    }
    if (c1 == 0) {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", c5 + 5, 12 * c5 + 3);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 18, 8 * c5 + 9);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 0, 1);
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -9 * c5 + 16, 7 * c5 + 6);
      }
      for (int c3 = 20; c3 <= 21; c3 += 1) {
        if (c3 == 21) {
          fprintf(f, "cx q[%u], q[%u];\n", 7, 16);
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 10, 3 * c5 + 1);
          }
        } else {
          fprintf(f, "cx q[%u], q[%u];\n", 16, 6);
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 10, 16 * c5 + 1);
          }
        }
      }
      fprintf(f, "cx q[%u], q[%u];\n", 8, 4);
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 16, 2 * c5 + 15);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -11 * c5 + 14, 15 * c5 + 2);
      }
    } else {
      for (int c3 = 28; c3 <= 30; c3 += 1) {
        if (c3 == 29) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 6, 19 * c5);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 15, 12 * c5 + 2);
          }
        } else {
          if (c3 == 28) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4 * c5, 10 * c5 + 1);
            }
          }
          fprintf(f, "cx q[%u], q[%u];\n", 5 * c3 - 135, -2 * c3 + 62);
          if (c3 == 28) {
            fprintf(f, "cx q[%u], q[%u];\n", 3, 2);
          }
        }
      }
    }
    if (c1 == 0) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c3 + 13, 5 * c3 + 6);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -10 * c3 + 14, 10 * c3 + 2);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c1 + 14, 8 * c1 + 2);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -12 * c1 + 15, 15 * c1 + 2);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -5 * c1 + 8, 13 * c1 + 4);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -6 * c1 + 15, 11 * c1 + 8);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -3 * c1 + 8, 4 * c1 + 11);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -9 * c1 + 13, 11 * c1);
  }
}
fclose(f);
return 0;
}