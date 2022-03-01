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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.5D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 3; c1 += 1) {
    if (c1 == 3) {
      for (int c3 = 5; c3 <= 6; c3 += 1) {
        if (c3 == 6) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 18, c5 + 10);
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 7, 5 * c5 + 11);
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 8, 5 * c5 + 11);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 10, 16 * c5 + 2);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 16, 2 * c5 + 2);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 3, 12 * c5 + 7);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 18, 9 * c5 + 2);
      }
      for (int c3 = 10; c3 <= 18; c3 += 1) {
        if (c3 == 18) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -11 * c5 + 19, 4 * c5 + 9);
          }
        } else if (c3 == 17) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", c5 + 7, 12 * c5 + 1);
          }
        } else if (c3 == 16) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 7, 18 * c5 + 1);
          }
        } else if (c3 == 15) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 4, 3 * c5 + 16);
          }
        } else if (c3 == 14) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 10 * c5 + 7, 8 * c5 + 11);
          }
        } else if (c3 == 13) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 14, 2 * c5 + 15);
          }
        } else if (c3 == 12) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -14 * c5 + 18, 14 * c5 + 2);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 19, 2 * c5 + 9);
          }
        } else if (c3 == 11) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 8, 6 * c5 + 13);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 + 10, 14 * c5 + 2);
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 18, c5 + 10);
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 15, 10 * c5 + 8);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 13, 18 * c5);
      }
    } else {
      if (c1 == 2) {
        fprintf(f, "cx q[%u], q[%u];\n", 17, 10);
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 5, 12 * c5);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 3, 1);
        fprintf(f, "cx q[%u], q[%u];\n", 9, 12);
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -11 * c5 + 19, 7 * c5 + 6);
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 18, c5 + 16);
        }
        for (int c3 = 2; c3 <= 8; c3 += 1) {
          if (c3 == 8) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 16, 2 * c5 + 2);
            }
          } else if (c3 == 7) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 11, c5 + 17);
            }
          }
          if (c3 >= 7) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c3 - 6, 6 * c3 - 29);
            if (c3 == 8) {
              fprintf(f, "cx q[%u], q[%u];\n", 13, 0);
            }
          } else if (c3 == 6) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 11, 3 * c5 + 10);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -15 * c5 + 18, 5 * c5 + 2);
            }
          }
          if (c3 >= 6 && c3 % 2 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", (11 * c3 / 2) - 29, (-5 * c3 / 2) + 31);
          }
          if (c3 >= 7) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c3 + 59, -9 * c3 + 79);
          } else {
            if (c3 <= 3) {
              fprintf(f, "cx q[%u], q[%u];\n", -11 * c3 + 39, -7 * c3 + 33);
              if (c3 == 3) {
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 3, 11 * c5 + 7);
                }
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 19, 2 * c5 + 9);
                }
              } else if (c3 == 2) {
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 + 1, 2 * c5 + 4);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
              }
            } else {
              if (c3 == 5) {
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 9 * c5 + 7, c5 + 1);
                }
              } else if (c3 == 4) {
                for (int c5 = 0; c5 <= 1; c5 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 9, 5 * c5 + 6);
                }
              }
              if (c3 <= 5) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c3 - 29, 3 * c3 - 5);
              }
            }
            if ((c3 + 1) % 3 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", (2 * c3 + 17) / 3, -4 * c3 + 26);
            }
          }
        }
      } else if (c1 == 1) {
        for (int c3 = 7; c3 <= 8; c3 += 1) {
          if (c3 == 8) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 17, c5);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 17, 16 * c5);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 14, 15 * c5 + 3);
            }
          }
        }
      }
      if (c1 >= 1) {
        if (c1 == 2) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 17, 5 * c5);
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 15, 6 * c5 + 11);
          }
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 13 * c5 + 3, c5 + 1);
        }
        if (c1 == 2) {
          for (int c3 = 10; c3 <= 11; c3 += 1) {
            if (c3 == 11) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 13, 3 * c5 + 5);
              }
            } else {
              fprintf(f, "cx q[%u], q[%u];\n", 16, 2);
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 13, 17 * c5);
              }
            }
          }
          for (int c3 = 12; c3 <= 17; c3 += 1) {
            if (c3 == 17) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c5 + 13, 13 * c5 + 5);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c5 + 9, 6 * c5 + 6);
              }
            } else if (c3 == 16) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 19, 3 * c5 + 9);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
              fprintf(f, "cx q[%u], q[%u];\n", 18, 10);
            } else if (c3 == 15) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -11 * c5 + 19, 7 * c5 + 6);
              }
            } else if (c3 == 14) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c5 + 8, 8 * c5 + 11);
              }
            } else if (c3 == 13) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 19, c5 + 9);
              }
            } else {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 15, 8 * c5 + 11);
              }
            }
          }
        } else {
          for (int c3 = 10; c3 <= 11; c3 += 1) {
            if (c3 == 11) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 8, 3 * c5 + 13);
              }
            } else {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 3, 6 * c5 + 1);
              }
            }
          }
        }
      } else {
        for (int c3 = 10; c3 <= 11; c3 += 1) {
          if (c3 == 11) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 8, c5 + 11);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 19, 11 * c5 + 6);
            }
          }
        }
      }
      if (c1 <= 1) {
        if (c1 == 1) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 5, 16 * c5);
          }
        }
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -c1 - 4 * c5 + 19, -4 * c1 + c5 + 6);
        }
      }
      if (c1 >= 1) {
        for (int c3 = max(13, 11 * c1 - 4); c3 <= min(19, -10 * c1 + 38); c3 += 1) {
          if (c1 == 1 && c3 == 19) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 1, 3 * c5 + 4);
            }
          } else if (c1 == 2 && c3 == 18) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 7, 5 * c5 + 11);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 6, 12);
            fprintf(f, "cx q[%u], q[%u];\n", 14, 15);
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 18, 15 * c5 + 2);
            }
          } else if (c3 == 18) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 8, 5 * c5 + 13);
            }
          } else if (c3 == 17) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 16, 11 * c5 + 2);
            }
          } else if (c3 == 16) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c5 + 3, 10 * c5 + 7);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 16, 6 * c5 + 2);
            }
          } else if (c3 == 15) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 18, 17 * c5 + 2);
            }
          } else if (c3 == 14) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 11 * c5 + 7, 15 * c5 + 1);
            }
          } else {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 16, 5 * c5 + 2);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 17 * c5, 10 * c5 + 9);
            }
          }
        }
        if (c1 == 2) {
          for (int c3 = 19; c3 <= 20; c3 += 1) {
            if (c3 == 20) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 17, 3 * c5);
              }
            } else {
              fprintf(f, "cx q[%u], q[%u];\n", 6, 12);
              fprintf(f, "cx q[%u], q[%u];\n", 17, 0);
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -13 * c5 + 14, 15 * c5 + 3);
              }
            }
          }
        }
      }
    }
    if (c1 % 3 == 0) {
      if (c1 == 0) {
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 14, c5 + 15);
        }
      }
      for (int c5 = 0; c5 <= (-c1 / 3) + 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 18, (14 * c1 / 3) + 3 * c5 + 2);
      }
      if (c1 == 0) {
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 8, 3 * c5 + 13);
        }
      }
    } else if (c1 == 1) {
      for (int c3 = 20; c3 <= 27; c3 += 1) {
        if (c3 == 27) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 13, 4 * c5);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -c5 + 11, 2 * c5 + 17);
          }
        } else if (c3 == 26) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -2 * c5 + 13, 19 * c5);
          }
        } else if (c3 == 25) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -6 * c5 + 19, 5 * c5 + 12);
          }
        } else if (c3 == 24) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -12 * c5 + 15, 10 * c5 + 8);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 + 5, 12 * c5);
          }
        } else if (c3 == 23) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", c5 + 2, c5 + 6);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 13, 16 * c5);
          }
        } else if (c3 == 22) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 10 * c5, 10 * c5 + 9);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 1, 14 * c5 + 4);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 13, 2 * c5 + 5);
          }
        } else if (c3 == 21) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 13, 16 * c5);
          }
        } else {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 13, 3 * c5 + 5);
          }
        }
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 3, 6 * c5 + 7);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 11, c5 + 17);
      }
      for (int c5 = 0; c5 <= 1; c5 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 14, c5 + 15);
      }
    }
    if (c1 == 2) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -9 * c3 + 14, 2 * c3 + 15);
      }
    } else if (c1 == 0) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 2 * c3 + 7, 5 * c3 + 1);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 2 * c1 + 13, 11 * c1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -9 * c1 + 17, 11 * c1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -5 * c1 + 13, 7 * c1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 4 * c1 + 13, 10 * c1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 4 * c1 + 13, 5 * c1 + 5);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -3 * c1 + 14, 4 * c1 + 15);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 3 * c1 + 14, 7 * c1 + 3);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -6 * c1 + 11, 7 * c1 + 10);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 4 * c1 + 10, c1 + 2);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 4 * c1 + 15, 4 * c1 + 8);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -4 * c1 + 5, 4 * c1);
  }
}
fclose(f);
return 0;
}