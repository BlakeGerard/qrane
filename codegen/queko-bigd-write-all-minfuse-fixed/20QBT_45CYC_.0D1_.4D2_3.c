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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.0D1_.4D2_3.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -2 * c1 + 10, c1 + 17);
  }
  for (int c1 = 0; c1 <= 2; c1 += 1) {
    if (c1 == 1) {
      for (int c3 = 0; c3 <= 5; c3 += 1) {
        if (c3 == 4) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 16 * c5, 8 * c5 + 3);
          }
        }
        if (c3 >= 4) {
          fprintf(f, "cx q[%u], q[%u];\n", 4 * c3 - 3, 6 * c3 - 14);
          if (c3 == 5) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 10, 11 * c5);
            }
          }
        } else if (c3 == 3) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 10, 15 * c5 + 4);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 9 * c5 + 2, c5 + 8);
          }
        } else {
          if (c3 == 2) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 15, c5 + 11);
            }
          }
          if (c3 % 2 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", (-9 * c3 / 2) + 17, -7 * c3 + 19);
            if (c3 == 2) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c5 + 10, 13 * c5 + 4);
              }
            }
            if (c3 == 0) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c5 + 6, 10 * c5 + 1);
              }
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 19, 14 * c5 + 3);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c5 + 5, 7 * c5 + 11);
            }
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 13, 4 * c5 + 10);
      }
      for (int c3 = 7; c3 <= 18; c3 += 1) {
        if (c3 == 17) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 + 2, 11 * c5 + 6);
          }
        } else if (c3 == 16) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", c5 + 17, 5 * c5);
          }
        }
        if (c3 >= 16 && c3 <= 17) {
          fprintf(f, "cx q[%u], q[%u];\n", 8 * c3 - 118, -3 * c3 + 52);
          if (c3 == 16) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 19, 8 * c5 + 3);
            }
          }
        } else {
          if (c3 == 18) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 10, 7 * c5 + 4);
            }
          }
          if (c3 == 15) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 12, 14 * c5 + 5);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -14 * c5 + 18, 16 * c5 + 1);
            }
          } else if (c3 == 14) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 12, 9 * c5 + 5);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 11 * c5 + 6, c5 + 18);
            }
          } else if (c3 == 13) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 18, 10 * c5 + 5);
            }
          } else if (c3 == 12) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 6, 10 * c5 + 1);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 10, 14 * c5 + 4);
            }
          } else if (c3 == 11) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 13, 7 * c5 + 10);
            }
          } else if (c3 == 10) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 13, 18 * c5 + 1);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c5, 8 * c5 + 3);
            }
          } else if (c3 == 9) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 3, 8 * c5 + 9);
            }
          } else if (c3 == 8) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 17, 14 * c5);
            }
          } else if (c3 == 7) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c5 + 16, 4 * c5 + 15);
            }
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 17, 4 * c5);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", c5 + 5, 7 * c5 + 11);
      }
      for (int c5 = 0; c5 <= 2; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -6 * c5 + 18, 6 * c5 + 1);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -11 * c5 + 15, 6 * c5 + 11);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 6, c5 + 13);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -c5 + 17, 11 * c5);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 13 * c5, 7 * c5 + 3);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 16, 19);
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 2, 3 * c5 + 8);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 18, 8 * c5 + 1);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 13, 10);
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 19, 2 * c5 + 14);
      }
    } else if (c1 == 0) {
      for (int c3 = 8; c3 <= 9; c3 += 1) {
        if (c3 == 9) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", c5 + 2, 3 * c5 + 6);
          }
        } else {
          fprintf(f, "cx q[%u], q[%u];\n", 6, 1);
        }
      }
    } else {
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 10, 14 * c5 + 4);
      }
    }
    if (c1 >= 1) {
      for (int c3 = 24; c3 <= 25; c3 += 1) {
        if (c3 == 25) {
          fprintf(f, "cx q[%u], q[%u];\n", -3 * c1 + 22, 2 * c1 + 7);
        }
        if (c1 == 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -4 * c3 + 105, 2 * c3 - 34);
          if (c3 == 25) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 10, 14 * c5 + 4);
            }
          }
          if (c3 == 24) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 13, c5 + 18);
            }
          }
        } else if (c3 == 24) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 8, 11 * c5 + 5);
          }
        }
      }
    }
    if (c1 <= 1) {
      if (c1 == 0) {
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -c5 + 2, 11 * c5 + 6);
        }
      }
      for (int c5 = 0; c5 <= -c1 + 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 7 * c1 + 4 * c5 + 12, -4 * c1 + 12 * c5 + 7);
      }
      if (c1 == 0) {
        for (int c3 = 11; c3 <= 13; c3 += 1) {
          if (c3 == 13) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 6, 8 * c5 + 1);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 10, 7 * c5 + 4);
            }
          } else if (c3 == 12) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 16 * c5 + 1, 3 * c5 + 16);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -16 * c5 + 17, 16 * c5);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 19, 14);
          }
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 18, 8 * c5 + 1);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 8, 5);
        for (int c3 = 15; c3 <= 23; c3 += 1) {
          if (c3 == 23) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 6, 16 * c5 + 1);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 18, 4 * c5 + 12);
            }
          } else if (c3 == 22) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 1, 2 * c5 + 16);
            }
          } else if (c3 == 20) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -9 * c5 + 19, 3 * c5 + 14);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 6, 7 * c5 + 1);
            }
          } else {
            if (c3 == 15) {
              fprintf(f, "cx q[%u], q[%u];\n", 19, 3);
            } else if (c3 >= 19 && (c3 + 1) % 2 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", (11 * c3 - 193) / 2, -2 * c3 + 56);
              if (c3 == 21) {
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -9 * c5 + 10, 16 * c5);
                }
              }
            }
            if (c3 == 19) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 2, 8 * c5 + 6);
              }
            } else {
              if (c3 == 16) {
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -14 * c5 + 19, 7 * c5 + 9);
                }
              }
              if (c3 >= 16 && c3 <= 17) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c3 - 46, 7 * c3 - 104);
                if (c3 == 17) {
                  for (int c5 = 0; c5 <= 1; c5 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 17 * c5 + 2, c5 + 8);
                  }
                }
              } else {
                if (c3 == 18) {
                  for (int c5 = 0; c5 <= 1; c5 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -17 * c5 + 19, 5 * c5 + 3);
                  }
                }
                if (c3 == 15) {
                  for (int c5 = 0; c5 <= 1; c5 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c5 + 8, 9 * c5 + 5);
                  }
                }
              }
            }
          }
        }
        for (int c3 = 24; c3 <= 25; c3 += 1) {
          if (c3 == 24) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 13 * c5 + 5, c5 + 11);
            }
          }
          fprintf(f, "cx q[%u], q[%u];\n", -4 * c3 + 113, 2 * c3 - 32);
          if (c3 == 25) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 17, 7 * c5);
            }
          }
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 16, c5 + 11);
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 18, 4 * c5 + 5);
        }
        for (int c3 = 28; c3 <= 30; c3 += 1) {
          if (c3 == 30) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -9 * c5 + 15, 7 * c5 + 11);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 16, 19);
          } else if (c3 == 29) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 16, 3 * c5 + 15);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 8, 3 * c5 + 12);
            }
          }
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 13, 4 * c5 + 10);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 2, 6);
        for (int c3 = 32; c3 <= 35; c3 += 1) {
          if (c3 == 35) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 18, 11 * c5 + 1);
            }
          } else if (c3 == 34) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 13, 11 * c5 + 1);
            }
          } else if (c3 == 33) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 13, 4 * c5 + 1);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 8, 5 * c5 + 5);
            }
          }
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -6 * c5 + 18, 6 * c5 + 1);
        }
      }
    }
    if (c1 == 1) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -8 * c3 + 10, 2 * c3 + 4);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c3 + 17, 5 * c3);
      }
    } else if (c1 == 0) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -8 * c3 + 18, 16 * c3 + 1);
      }
    }
  }
}
fclose(f);
return 0;
}