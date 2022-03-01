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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.2D2_0.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 2; c1 += 1) {
    if (c1 == 0) {
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 6, 4 * c4 + 5);
      }
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 19, 7 * c4 + 8);
      }
    }
    if (c1 <= 1) {
      for (int c4 = 0; c4 <= c1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 13, c1 + 5 * c4 + 9);
      }
      if (c1 == 1) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -c4 + 4, c4 + 9);
        }
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 13, 7 * c4 + 10);
        }
        for (int c2 = 2; c2 <= 10; c2 += 1) {
          if (c2 == 8) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 7 * c4 + 10, 9 * c4 + 6);
            }
          } else if (c2 == 7) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              for (int c5 = 0; c5 <= -c4 + 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c4 - 10 * c5 + 11, 4 * c4 + 3 * c5 + 13);
              }
            }
          } else if (c2 == 5) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 13, 9 * c4 + 10);
            }
          } else {
            if (c2 == 4) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 14, 9 * c4 + 7);
              }
            } else if ((c2 + 2) % 4 == 0) {
              for (int c4 = 0; c4 <= (-c2 + 6) / 4; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", (5 * c2 / 2) + 10 * c4 - 5, ((3 * c2 + 6) / 4) + 5 * c4);
              }
            }
            if ((c2 + 1) % 5 == 0) {
              for (int c4 = 0; c4 <= (-c2 + 9) / 5; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((-3 * c2 + 77) / 5) - 11 * c4, ((-4 * c2 + 66) / 5) + 9 * c4);
              }
            } else if ((c2 - 3) % 7 == 0) {
              for (int c4 = 0; c4 <= (-c2 + 10) / 7; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((-9 * c2 + 111) / 7) + 7 * c4, ((2 * c2 + 50) / 7) + 2 * c4);
              }
            }
          }
        }
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 7, 5 * c4 + 3);
        }
        for (int c2 = 12; c2 <= 16; c2 += 1) {
          if (c2 == 16) {
            fprintf(f, "cx q[%u], q[%u];\n", 6, 5);
          } else if (c2 == 15) {
            fprintf(f, "cx q[%u], q[%u];\n", 6, 5);
          } else if (c2 == 14) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              for (int c5 = 0; c5 <= -c4 + 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 - 2 * c5 + 4, -3 * c4 + 3 * c5 + 9);
              }
            }
          } else if (c2 == 13) {
            fprintf(f, "cx q[%u], q[%u];\n", 10, 8);
          } else {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              for (int c5 = 0; c5 <= -c4 + 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c4 - 9 * c5 + 11, -c4 + 10 * c5 + 9);
              }
            }
          }
        }
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 17, c4 + 5);
        }
        for (int c2 = 18; c2 <= 19; c2 += 1) {
          if (c2 == 19) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 12 * c4 + 7, 8 * c4);
            }
          } else {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 6, 14 * c4 + 5);
            }
          }
        }
        for (int c2 = 20; c2 <= 23; c2 += 1) {
          if (c2 == 23) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 14, 6 * c4);
            }
          } else if (c2 == 22) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 17 * c4, 12 * c4 + 3);
            }
          } else if (c2 == 21) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 10, 11 * c4 + 8);
            }
          } else {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c4, 3 * c4 + 3);
            }
          }
        }
      }
    }
    if (c1 >= 1) {
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 16 * c4 + 1, c4 + 14);
      }
      if (c1 == 2) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 1, c4 + 16);
        }
        for (int c2 = 0; c2 <= 10; c2 += 1) {
          if (c2 == 3) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 14, 16 * c4 + 3);
            }
          }
          if (c2 >= 2 && c2 <= 3) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c2 + 20, 9 * c2 - 18);
            if (c2 == 2) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 13, 2 * c4 + 9);
              }
            }
          } else {
            if (c2 == 6) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 17, 4 * c4 + 5);
              }
            }
            if (c2 >= 6 && c2 <= 7) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c2 - 20, -c2 + 12);
              if (c2 == 7) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 3, 4 * c4 + 10);
                }
              }
            } else {
              if (c2 == 10) {
                fprintf(f, "cx q[%u], q[%u];\n", 19, 6);
              } else if (c2 == 9) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 6 * c4 + 6, 3 * c4 + 5);
                }
              } else if (c2 == 8) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 7, 2 * c4 + 3);
                }
              }
              if (c2 == 5) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 13 * c4 + 6, 3 * c4 + 5);
                }
              } else if (c2 == 4) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -15 * c4 + 19, 7 * c4 + 6);
                }
              }
            }
            if (c2 == 1) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 4, c4 + 13);
              }
            } else if (c2 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 3, 3 * c4 + 13);
              }
            }
          }
        }
        fprintf(f, "cx q[%u], q[%u];\n", 8, 6);
        for (int c2 = 18; c2 <= 19; c2 += 1) {
          if (c2 == 19) {
            fprintf(f, "cx q[%u], q[%u];\n", 10, 6);
          } else {
            fprintf(f, "cx q[%u], q[%u];\n", 8, 6);
          }
        }
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 14 * c1 + 1, 2 * c1 + 16);
  }
}
fclose(f);
return 0;
}