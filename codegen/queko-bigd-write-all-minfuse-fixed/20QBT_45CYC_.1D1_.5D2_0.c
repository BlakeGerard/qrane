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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.1D1_.5D2_0.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 3; c1 += 1) {
    if (c1 == 0) {
      for (int c7 = 0; c7 <= 2; c7 += 1) {
        fprintf(f, "x q[%u];\n", c7 + 17);
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 5, 9 * c7 + 4);
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -12 * c7 + 15, 5 * c7 + 11);
      }
      for (int c5 = 10; c5 <= 15; c5 += 1) {
        if (c5 == 14) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 6, 5 * c7 + 2);
          }
        } else if (c5 == 13) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 9, 3 * c7 + 5);
          }
        } else if (c5 == 12) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 9, 2 * c7 + 5);
          }
        } else if (c5 == 11) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 13, c7 + 3);
          }
        } else {
          for (int c7 = 0; c7 <= (-c5 / 5) + 3; c7 += 1) {
            fprintf(f, "x q[%u];\n", (3 * c5 / 5) + 13 * c7 - 3);
          }
        }
      }
      for (int c5 = 15; c5 <= 18; c5 += 1) {
        if (c5 >= 17) {
          fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 181, 3 * c5 - 41);
          if (c5 == 18) {
            fprintf(f, "x q[%u];\n", 4);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              for (int c8 = 0; c8 <= -c7 + 1; c8 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c7 + 5 * c8 + 14);
              }
            }
          }
        } else {
          fprintf(f, "cx q[%u], q[%u];\n", c5 - 14, 10 * c5 - 143);
        }
        if ((c5 + 1) % 2 == 0) {
          fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 120, -2 * c5 + 41);
          if (c5 == 17) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 8, 3 * c7 + 15);
            }
          }
          if (c5 == 15) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 2, 4 * c7 + 8);
            }
          }
        } else {
          if (c5 == 16) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 9 * c7 + 10);
            }
          }
          fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 47, -4 * c5 + 82);
        }
        if (c5 >= 16 && c5 <= 17) {
          fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 172, 16 * c5 - 255);
        }
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 8 * c7 + 7, 10 * c7 + 8);
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 16, 10 * c7 + 4);
      }
      fprintf(f, "x q[%u];\n", 7);
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 8, 4 * c7 + 15);
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 4, c7 + 18);
      }
      fprintf(f, "x q[%u];\n", 19);
      fprintf(f, "x q[%u];\n", 19);
    }
    if (c1 >= 2) {
      fprintf(f, "x q[%u];\n", 12 * c1 - 24);
      if (c1 == 2) {
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", 9 * c7);
        }
      }
      if (c1 == 2) {
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 13, 9 * c7 + 9);
        }
      } else {
        for (int c5 = 3; c5 <= 4; c5 += 1) {
          if (c5 == 4) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -13 * c7 + 14, 7 * c7 + 6);
            }
          } else {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 6, 2 * c7 + 2);
            }
          }
        }
      }
      if (c1 == 2) {
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", -7 * c7 + 9);
        }
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 5 * c1 + 4 * c7 - 3, -14 * c1 + 3 * c7 + 43);
      }
      if (c1 == 2) {
        for (int c5 = 6; c5 <= 13; c5 += 1) {
          if (c5 == 8) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 15 * c7);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 3, 5 * c7 + 4);
            }
          }
          if (c5 >= 8 && c5 <= 9) {
            fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 72, 3 * c5 - 8);
            if (c5 == 9) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c7 + 6);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 16, 2 * c7 + 15);
              }
            } else {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c7 + 18, c7 + 10);
              }
            }
          } else {
            if (c5 == 13) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 13, 9 * c7 + 9);
              }
            } else if (c5 == 11) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c7, 3 * c7 + 12);
              }
            } else if (c5 == 10) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 16, 6 * c7 + 4);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 15 * c7);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 7, 9 * c7 + 8);
              }
            }
            if ((c5 - 2) % 5 == 0) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 13, 14 * c7 + 3);
              }
              if (c5 == 7) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 14, c7 + 6);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 16 * c7);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 19, 9 * c7 + 1);
                }
              }
            } else if (c5 == 6) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 7, 3 * c7 + 16);
              }
            }
          }
        }
      } else {
        for (int c5 = 6; c5 <= 7; c5 += 1) {
          if (c5 == 7) {
            for (int c7 = 0; c7 <= 2; c7 += 1) {
              fprintf(f, "x q[%u];\n", c7 + 12);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 + 7, 2 * c7 + 8);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 6, 2 * c7 + 2);
            }
          } else {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 11, 6 * c7 + 10);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c7 + 13, 5 * c7 + 9);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 5, 13 * c7 + 4);
            }
          }
        }
      }
    } else if (c1 == 1) {
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "x q[%u];\n", -2 * c7 + 19);
      }
    }
    if (c1 % 3 <= 1) {
      if (c1 == 0) {
        fprintf(f, "x q[%u];\n", 19);
        fprintf(f, "x q[%u];\n", 11);
        fprintf(f, "x q[%u];\n", 1);
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 11 * c7 + 2, c7 + 8);
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -15 * c7 + 15, 9 * c7 + 10);
        }
        fprintf(f, "x q[%u];\n", 3);
      }
      if (c1 % 3 == 0) {
        if (c1 == 0) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 7, 4 * c7 + 15);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 6, 2 * c7 + 8);
          }
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", (4 * c1 / 3) + c7 + 3, (-c1 / 3) + 2 * c7 + 16);
        }
        if (c1 == 0) {
          fprintf(f, "cx q[%u], q[%u];\n", 14, 1);
        }
        if (c1 == 0) {
          for (int c5 = 9; c5 <= 15; c5 += 1) {
            if (c5 == 11) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 6, 7 * c7 + 2);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 1, 11 * c7 + 7);
              }
            }
            if (c5 >= 11 && c5 <= 12) {
              fprintf(f, "cx q[%u], q[%u];\n", 9 * c5 - 94, -3 * c5 + 37);
            }
            if (c5 >= 12 && c5 <= 13) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 28, 6 * c5 - 67);
              if (c5 == 13) {
                fprintf(f, "cx q[%u], q[%u];\n", 7, 16);
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 13 * c7 + 1, 3 * c7 + 3);
                }
              } else {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 8, 3 * c7 + 15);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c7 + 12);
                }
              }
            } else {
              if (c5 == 15) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 15, 3 * c7 + 11);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -16 * c7 + 18, 7 * c7 + 10);
                }
              } else if (c5 == 14) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 3, 9 * c7 + 4);
                }
              }
              if (c5 >= 14) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 - 44, -2 * c5 + 35);
                if (c5 == 14) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", -3 * c7 + 9);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 11, 7 * c7 + 10);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 16, 5);
                }
              }
              if (c5 == 11) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -11 * c7 + 19, 12 * c7 + 3);
                }
              } else if (c5 == 10) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c7 + 12, 3 * c7 + 7);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 9, 10 * c7 + 5);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 13 * c7);
                }
              } else if (c5 == 9) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 19 * c7);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 13, 7 * c7 + 9);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 16 * c7 + 1, 4 * c7 + 7);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 16 * c7 + 2);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 3, 5);
              }
            }
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 7 * c7 + 3);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 12, 4 * c7 + 1);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 8, c7 + 17);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 9 * c7 + 7);
          }
          for (int c5 = 17; c5 <= 20; c5 += 1) {
            if (c5 == 20) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", c7 + 14, 5 * c7 + 6);
              }
            } else if (c5 == 19) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 5, 10 * c7 + 4);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 18, 10);
            } else if (c5 == 18) {
              fprintf(f, "cx q[%u], q[%u];\n", 4, 18);
              for (int c7 = 0; c7 <= 2; c7 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c7 + 5);
              }
            } else {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 2, 10 * c7 + 8);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 3, 4 * c7 + 5);
              }
            }
          }
          for (int c5 = 21; c5 <= 22; c5 += 1) {
            if (c5 == 22) {
              fprintf(f, "cx q[%u], q[%u];\n", 12, 7);
            } else {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 11, 5 * c7 + 10);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c7 + 12);
              }
            }
          }
        }
      }
      if (c1 == 1) {
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          if (c5 == 1) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", -8 * c7 + 19);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 1, 13);
          } else {
            fprintf(f, "cx q[%u], q[%u];\n", 19, 1);
          }
        }
        fprintf(f, "cx q[%u], q[%u];\n", 19, 3);
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c7 + 6);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 16, 15);
        for (int c5 = 3; c5 <= 5; c5 += 1) {
          if (c5 == 5) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 15, 6 * c7 + 10);
            }
          } else if (c5 == 4) {
            fprintf(f, "cx q[%u], q[%u];\n", 6, 2);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 16, 11 * c7 + 4);
            }
          }
          if ((c5 + 1) % 2 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", (c5 - 1) / 2, 7 * c5 - 18);
            if (c5 == 5) {
              fprintf(f, "x q[%u];\n", 8);
              fprintf(f, "cx q[%u], q[%u];\n", 13, 9);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", -3 * c7 + 6);
              }
            }
            if (c5 == 3) {
              fprintf(f, "cx q[%u], q[%u];\n", 16, 15);
              fprintf(f, "cx q[%u], q[%u];\n", 6, 2);
            }
          } else {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 3, 8 * c7 + 5);
            }
          }
        }
        for (int c5 = 6; c5 <= 19; c5 += 1) {
          if (c5 == 17) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 11 * c7 + 3, c7 + 5);
            }
          } else if (c5 == 10) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 6 * c7 + 2);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -15 * c7 + 15, 9 * c7 + 10);
            }
          } else {
            if ((c5 + 1) % 10 == 0) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((2 * c5 - 8) / 5) + 5 * c7, ((-3 * c5 + 67) / 5) + 8 * c7);
              }
            }
            if (c5 >= 9 && c5 <= 11 && (c5 + 1) % 2 == 0) {
              fprintf(f, "x q[%u];\n", (-15 * c5 + 165) / 2);
            }
            if (c5 >= 8 && c5 <= 9) {
              fprintf(f, "cx q[%u], q[%u];\n", 11 * c5 - 81, -5 * c5 + 55);
              if (c5 == 8) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c7 + 4);
                }
              }
            } else {
              if (c5 == 15) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c7 + 14, 2 * c7 + 1);
                }
              } else if (c5 == 14) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 1, 3 * c7 + 13);
                }
              }
              if (c5 == 7) {
                fprintf(f, "cx q[%u], q[%u];\n", 3, 5);
                fprintf(f, "x q[%u];\n", 19);
              }
              if (c5 <= 7) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 57, -c5 + 24);
                if (c5 == 7) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -15 * c7 + 15, 2 * c7 + 10);
                  }
                }
                fprintf(f, "x q[%u];\n", -6 * c5 + 46);
                if (c5 == 6) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 16, 4 * c7 + 4);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 9, 14 * c7 + 5);
                  }
                }
              } else if (c5 == 18) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c7 + 6);
                }
              } else if (c5 == 16) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 16 * c7 + 3, 9 * c7 + 4);
                }
              } else if (c5 == 14) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", c7 + 11, 4 * c7 + 10);
                }
              } else if (c5 == 13) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 19, 13 * c7 + 1);
                }
              } else if (c5 == 12) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 14, 12 * c7 + 1);
                }
              } else if (c5 == 11) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 19, 4 * c7 + 1);
                }
              }
            }
          }
        }
        fprintf(f, "x q[%u];\n", 0);
      }
      if (c1 == 3) {
        fprintf(f, "cx q[%u], q[%u];\n", 8, 17);
      }
      if (c1 == 0) {
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 14, 11 * c7 + 7);
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 14, c7 + 7);
        }
      }
    } else {
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 6, 5 * c7 + 2);
      }
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "x q[%u];\n", 12 * c7);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 5, 3 * c5 + 4);
      }
    }
    if (c1 == 2) {
      fprintf(f, "x q[%u];\n", 12);
    } else if (c1 <= 1) {
      for (int c3 = 2; c3 <= c1 + 3; c3 += 1) {
        fprintf(f, "x q[%u];\n", -19 * c1 + 19);
        if (c1 == 1 && c3 == 4) {
          fprintf(f, "x q[%u];\n", 0);
        } else if (c1 == 0 && c3 == 3) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", -2 * c7 + 19);
          }
        }
      }
    }
    if (c1 == 2) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 11 * c3 + 3, c3 + 5);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -13 * c3 + 19, 16 * c3 + 1);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 13 * c3 + 3, 11 * c3 + 4);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 14 * c3 + 3, 6 * c3 + 5);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -c3 + 19, 7 * c3 + 3);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 7 * c3 + 8);
      }
    } else if (c1 == 1) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c3 + 12, 16 * c3 + 1);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 8 * c1 + 3, 5 * c1 + 5);
  }
  fprintf(f, "x q[%u];\n", 4);
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 3 * c1, 4 * c1 + 12);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -14 * c1 + 19, c1 + 3);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -5 * c1 + 6, 5 * c1 + 2);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -3 * c1 + 18, c1 + 10);
  }
}
fclose(f);
return 0;
}