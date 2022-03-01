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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.3D2_7.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 3; c0 += 1) {
  if (c0 >= 2) {
    if (c0 == 3) {
      for (int c4 = 12; c4 <= 13; c4 += 1) {
        if (c4 == 13) {
          for (int c6 = 0; c6 <= 1; c6 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -10 * c6 + 18, 17 * c6 + 2);
          }
          for (int c6 = 0; c6 <= 1; c6 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 10 * c6 + 1, 10 * c6 + 4);
          }
        } else {
          for (int c6 = 0; c6 <= 1; c6 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -6 * c6 + 17, 5 * c6 + 8);
          }
        }
      }
    }
    for (int c4 = -c0 + 17; c4 <= 15; c4 += 1) {
      if (c0 == 3 && c4 == 15) {
        for (int c6 = 0; c6 <= 1; c6 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -8 * c6 + 19, 4 * c6 + 9);
        }
      }
      if (c4 == 15) {
        for (int c6 = 0; c6 <= 1; c6 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 4 * c0 + 11 * c6 - 8, -2 * c0 + 4 * c6 + 14);
        }
      } else {
        for (int c6 = 0; c6 <= 1; c6 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", c6 + 14, 4 * c6);
        }
      }
    }
    if (c0 == 2) {
      for (int c4 = 16; c4 <= 23; c4 += 1) {
        if (c4 >= 18 && c4 <= 19) {
          fprintf(f, "cx q[%u], q[%u];\n", -7 * c4 + 137, 5 * c4 - 76);
          if (c4 == 19) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 14 * c6 + 1, c6 + 11);
            }
          } else {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c6 + 5, 16 * c6 + 3);
            }
          }
        } else {
          if (c4 == 23) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -6 * c6 + 17, 5 * c6 + 8);
            }
          } else if (c4 == 22) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c6 + 15, 12 * c6 + 1);
            }
          } else if (c4 == 21) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c6 + 15, 2 * c6 + 12);
            }
          } else if (c4 == 20) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 14 * c6 + 1, c6 + 11);
            }
          }
          if (c4 == 17) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c6 + 4, 3 * c6 + 8);
            }
          } else if (c4 == 16) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 9 * c6 + 3, 3 * c6 + 1);
            }
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 11 * c6, 8 * c6 + 6);
            }
          }
        }
      }
    }
    if (c0 == 3) {
      for (int c6 = 0; c6 <= 1; c6 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -6 * c6 + 14, 9 * c6 + 10);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 14, 0);
    }
  } else {
    for (int c2 = 0; c2 <= c0; c2 += 1) {
      if (c0 == 1) {
        for (int c4 = 0; c4 <= -c2 + 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 11 * c2 + 2 * c4 + 1, -3 * c2 + 10 * c4 + 4);
        }
      }
      if (c2 == 0) {
        for (int c4 = -c0 + 1; c4 <= 6; c4 += 1) {
          if (c4 == 6) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 12 * c0 + 5 * c6 + 2, -9 * c0 + 7 * c6 + 9);
            }
          } else if (c4 == 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c0 + 9, -2 * c0 + 16);
            if (c0 == 1) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 17 * c6 + 1, 4 * c6 + 4);
              }
            }
          } else {
            if (c0 == 1 && c4 == 5) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c6 + 8, 2 * c6);
              }
            } else if (c0 == 1 && c4 == 4) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c6 + 6, 9 * c6 + 10);
              }
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c6 + 8, 12 * c6 + 2);
              }
            } else if (c0 == 1 && c4 == 3) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -10 * c6 + 13, 8 * c6 + 6);
              }
            }
            if (c0 == 1 && c4 <= 2 && c4 % 2 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", (c4 / 2) + 11, (5 * c4 / 2) + 13);
              if (c4 == 2) {
                for (int c6 = 0; c6 <= 1; c6 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 6 * c6 + 8, 6 * c6);
                }
              }
            }
          }
        }
        for (int c4 = 7; c4 <= 18 * c0 + 7; c4 += 1) {
          if (c4 == 18 * c0 + 7) {
            for (int c6 = 0; c6 <= -c0 + 1; c6 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c0 - 10 * c6 + 14, -5 * c0 + 13 * c6 + 6);
            }
          } else if (c4 >= 13 && c4 <= 14) {
            fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 34, -9 * c4 + 136);
            if (c4 == 14) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 16 * c6 + 3, 2 * c6 + 14);
              }
            } else {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c6 + 14, 10 * c6 + 6);
              }
            }
          } else {
            if (c4 >= 11 && c4 <= 12) {
              fprintf(f, "cx q[%u], q[%u];\n", -c4 + 23, 12 * c4 - 131);
            } else if (c4 == 16) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c6 + 5, 11 * c6 + 3);
              }
            } else if (c4 == 15) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c6 + 19, 4 * c6 + 9);
              }
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c6 + 4, 2 * c6 + 8);
              }
            } else {
              if (c4 == 9) {
                for (int c6 = 0; c6 <= 1; c6 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -11 * c6 + 13, 3 * c6 + 6);
                }
              }
              if (c4 >= 9 && c4 <= 10) {
                fprintf(f, "cx q[%u], q[%u];\n", -18 * c4 + 180, -11 * c4 + 116);
              } else if (c4 == 24) {
                for (int c6 = 0; c6 <= 1; c6 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -5 * c6 + 12, 15 * c6 + 1);
                }
              } else if (c4 == 23) {
                for (int c6 = 0; c6 <= 1; c6 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c6 + 15, 5 * c6 + 1);
                }
              } else if (c4 >= 20 && c4 % 2 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", -c4 + 30, (-7 * c4 / 2) + 77);
                if (c4 == 22) {
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c6 + 10, 4 * c6 + 7);
                  }
                }
                if (c4 == 20) {
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c6 + 4, 14 * c6);
                  }
                }
              } else {
                if (c4 == 21) {
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c6 + 8, 19 * c6);
                  }
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c6 + 15, 15 * c6 + 1);
                  }
                }
                if (c4 == 19) {
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c6, 4 * c6 + 10);
                  }
                } else if (c4 == 18) {
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -5 * c6 + 6, 4 * c6 + 10);
                  }
                } else if (c4 == 17) {
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9 * c6 + 5, 3 * c6 + 3);
                  }
                }
              }
            }
            if (c4 == 12) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 11 * c6 + 3, 5 * c6 + 1);
              }
            } else if (c4 == 11) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c6 + 14, 10 * c6 + 6);
              }
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c6 + 18, 11 * c6 + 2);
              }
            } else if (c4 == 10) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c6 + 14, 7 * c6 + 10);
              }
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c6 + 12, 18 * c6 + 1);
              }
            } else if (c4 == 9) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c6 + 1, 4 * c6 + 11);
              }
            } else if (c4 == 8) {
              fprintf(f, "cx q[%u], q[%u];\n", 15, 4);
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c6 + 14, 11 * c6 + 6);
              }
            } else if (c4 == 7) {
              for (int c6 = 0; c6 <= 1; c6 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c6 + 14, 16 * c6);
              }
            }
          }
        }
        if (c0 == 0) {
          fprintf(f, "cx q[%u], q[%u];\n", 13, 6);
        }
      }
    }
  }
  if (c0 == 2) {
    for (int c4 = 0; c4 <= 1; c4 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 12, 10 * c4 + 1);
    }
    for (int c4 = 0; c4 <= 1; c4 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 14, 9 * c4 + 10);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -16 * c2 + 19, 5 * c2 + 9);
      fprintf(f, "cx q[%u], q[%u];\n", 3 * c2 + 15, 4 * c2 + 4);
      fprintf(f, "cx q[%u], q[%u];\n", -11 * c2 + 15, 7 * c2 + 12);
    }
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 19, c2 + 9);
      fprintf(f, "cx q[%u], q[%u];\n", 11 * c2 + 3, 9 * c2 + 1);
      fprintf(f, "cx q[%u], q[%u];\n", 9 * c2 + 5, 7 * c2 + 3);
    }
  }
}
fclose(f);
return 0;
}