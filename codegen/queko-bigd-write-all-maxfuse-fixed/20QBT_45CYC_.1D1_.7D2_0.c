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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.1D1_.7D2_0.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 2; c1 += 1) {
    if (c1 >= 1) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        if (c3 == 0) {
          fprintf(f, "x q[%u];\n", 8);
          if (c1 == 2) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 6 * c7 + 8);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -11 * c7 + 11, 7 * c7 + 7);
            }
          } else if (c1 == 1) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 8, 6 * c7);
            }
          }
        } else {
          if (c1 == 1) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 6, 13 * c7 + 5);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 + 1, 2 * c7 + 17);
            }
          }
          for (int c5 = 4; c5 <= -c1 + 6; c5 += 1) {
            if (c1 == 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 - 11, -17 * c5 + 87);
            }
            if (c5 == 4) {
              fprintf(f, "x q[%u];\n", 17);
            }
          }
          if (c1 == 2) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 8 * c7 + 1, 2 * c7 + 5);
            }
            fprintf(f, "x q[%u];\n", 7);
            for (int c5 = 14; c5 <= 17; c5 += 3) {
              fprintf(f, "cx q[%u], q[%u];\n", (-8 * c5 + 145) / 3, -2 * c5 + 35);
            }
            for (int c5 = 18; c5 <= 19; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 71, 3 * c5 - 45);
              if (c5 == 18) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 13, 9 * c7 + 3);
                }
              }
            }
          }
        }
        if (c1 >= c3 + 1) {
          if (c1 == 1 && c3 == 0) {
            for (int c5 = 15; c5 <= 16; c5 += 1) {
              if (c5 == 16) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 18, c7 + 5);
                }
                for (int c7 = 0; c7 <= 2; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 4, 5 * c7 + 2);
                }
              } else {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 13, 4 * c7 + 3);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 10 * c7, 4 * c7 + 14);
                }
              }
            }
            for (int c5 = 17; c5 <= 18; c5 += 1) {
              if (c5 == 18) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 19, 5 * c7 + 7);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 13, 5 * c7 + 1);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c7 + 2);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 17, 9);
              } else {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 1, 13 * c7 + 5);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 16, 8 * c7 + 11);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 10, 4 * c7);
                }
              }
            }
          }
          if (c3 + 1 == c1) {
            if (c1 == 1) {
              fprintf(f, "x q[%u];\n", 6);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -12 * c7 + 13, 14 * c7 + 3);
            }
            if (c1 == 1) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 4, 5 * c7 + 2);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 18, 12);
            }
            if (c1 == 1) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 13, 4 * c7 + 3);
              }
            }
          }
          if (c3 == 0) {
            for (int c5 = -3 * c1 + 24; c5 <= 21; c5 += 1) {
              if (c5 == 21) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -15 * c7 + 15, 4 * c7 + 10);
                }
              } else {
                if (c5 == 19) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9 * c7 + 3, 15 * c7 + 1);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 8, 10 * c7);
                  }
                }
                if (c5 <= 19) {
                  fprintf(f, "cx q[%u], q[%u];\n", c5 - 13, 3 * c5 - 38);
                }
              }
              if (3 * c1 + c5 == 24) {
                fprintf(f, "cx q[%u], q[%u];\n", 6 * c1 - 4, -7 * c1 + 20);
                if (c1 == 1) {
                  fprintf(f, "x q[%u];\n", 7);
                }
              } else if (c5 == 20) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c7);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 16, 8 * c7 + 11);
                }
              }
            }
            if (c1 == 1) {
              for (int c5 = 22; c5 <= 25; c5 += 1) {
                if (c5 == 25) {
                  fprintf(f, "x q[%u];\n", 4);
                } else if (c5 == 23) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 15, 12 * c7 + 4);
                  }
                } else if (c5 == 22) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 10, 16 * c7);
                  }
                }
              }
            }
          }
          if (c1 == 2 && c3 == 1) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 15, 15 * c5 + 4);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c5 + 10);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 2, c5 + 6);
            }
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 4, 12 * c5 + 6);
            }
          } else if (c1 == 2 && c3 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", 8, 0);
          } else if (c1 == 1 && c3 == 0) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c5 + 17, 2 * c5 + 9);
            }
          }
        }
      }
      if (c1 == 2) {
        fprintf(f, "x q[%u];\n", 16);
        for (int c5 = 0; c5 <= 1; c5 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 12 * c5 + 6, 11 * c5 + 5);
        }
      } else {
        for (int c3 = 3; c3 <= 4; c3 += 1) {
          if (c3 == 4) {
            fprintf(f, "x q[%u];\n", 8);
          } else {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 2 * c7 + 2);
            }
            fprintf(f, "x q[%u];\n", 9);
          }
        }
      }
    } else {
      for (int c3 = 0; c3 <= 4; c3 += 1) {
        if (c3 == 0) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c7 + 3);
          }
          for (int c5 = 15; c5 <= 27; c5 += 1) {
            if (c5 == 26) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c7 + 10, 9 * c7);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 13, 15 * c7 + 3);
              }
              fprintf(f, "x q[%u];\n", 15);
            } else {
              if (c5 == 25) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 17 * c7 + 2, 5 * c7 + 6);
                }
              } else if (c5 == 24) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 6, 10 * c7 + 1);
                }
                for (int c7 = 0; c7 <= 2; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 4, 5 * c7 + 2);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 13, 2 * c7 + 17);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -15 * c7 + 15, 8 * c7 + 10);
                }
              } else if (c5 == 23) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 4, 6 * c7 + 6);
                }
                fprintf(f, "x q[%u];\n", 2);
              } else if (c5 == 22) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 15 * c7 + 4, c7 + 8);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 2, 12 * c7 + 6);
                }
              } else if (c5 == 21) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", c7 + 2, 9 * c7 + 8);
                }
              }
              if ((c5 - 1) % 6 == 0) {
                for (int c7 = 0; c7 < (c5 - 13) / 6; c7 += 1) {
                  fprintf(f, "x q[%u];\n", ((-c5 + 52) / 3) + 3 * c7);
                }
                if (c5 == 25) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 15, 7 * c7 + 10);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c7 + 8);
                  }
                }
                if (c5 == 19) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 14, 4 * c7 + 12);
                  }
                }
              } else {
                if (c5 == 23) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -17 * c7 + 18, 12 * c7 + 5);
                  }
                } else if (c5 == 21) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 4, 12 * c7 + 6);
                  }
                } else if (c5 == 20) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 11, 10 * c7 + 7);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 10, 8 * c7);
                  }
                  fprintf(f, "x q[%u];\n", 9);
                }
                if (c5 == 18) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 3, 6 * c7 + 1);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 8 * c7 + 5, 5 * c7 + 12);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 10, 19 * c7);
                  }
                } else if (c5 == 17) {
                  fprintf(f, "x q[%u];\n", 14);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 10, 6 * c7);
                  }
                } else if (c5 == 16) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 16 * c7 + 3, 8 * c7 + 1);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 18, 5 * c7 + 12);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c7 + 15, c7 + 10);
                  }
                } else if ((c5 - 3) % 12 == 0) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 14 * c7 + 4, 4 * c7 + 8);
                  }
                }
              }
              if ((c5 + 5) % 10 == 0) {
                for (int c7 = 0; c7 < (c5 - 5) / 10; c7 += 1) {
                  fprintf(f, "x q[%u];\n", -c5 + 7 * c7 + 32);
                }
              }
              if (c5 <= 20 && c5 % 5 == 0) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", (-4 * c5 / 5) + 10 * c7 + 18, c5 + 10 * c7 - 14);
                }
                if (c5 == 15) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 2, c7 + 13);
                  }
                }
              } else {
                if (c5 >= 17 && c5 <= 19 && (c5 + 1) % 2 == 0) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 13, 8 * c7 + 1);
                  }
                  if (c5 == 17) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 5, 6 * c7 + 12);
                    }
                  }
                }
                if (c5 >= 19 && c5 <= 21 && (c5 + 1) % 2 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 - 23, (3 * c5 - 49) / 2);
                }
              }
            }
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c5 + 10);
          }
        } else {
          if ((c3 + 1) % 2 == 0) {
            if (c3 == 3) {
              for (int c5 = 2; c5 <= 20; c5 += 1) {
                if (c5 == 20) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 10 * c7 + 7);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c7 + 11);
                  }
                } else {
                  if (c5 >= 14 && (c5 + 1) % 3 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", (-8 * c5 + 139) / 3, -2 * c5 + 39);
                    if (c5 == 17) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "x q[%u];\n", -9 * c7 + 12);
                      }
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 11, 2 * c7 + 7);
                      }
                    }
                  } else if (c5 == 16) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c7 + 12);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 3, 4 * c7 + 1);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 4, 5 * c7 + 8);
                    }
                  }
                  if (c5 >= 16 && c5 <= 17) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 83, -5 * c5 + 89);
                  } else if (c5 == 15) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c7 + 9);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 8, 12 * c7 + 6);
                    }
                  } else {
                    if (c5 == 13) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 8, 12 * c7 + 6);
                      }
                    }
                    if (c5 >= 13 && c5 <= 14) {
                      fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 104, -16 * c5 + 225);
                      if (c5 == 14) {
                        for (int c7 = 0; c7 <= 1; c7 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", c7 + 2, 9 * c7 + 8);
                        }
                      }
                    } else {
                      if (c5 == 19) {
                        for (int c7 = 0; c7 <= 1; c7 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 8 * c7 + 8, 11 * c7);
                        }
                      } else if (c5 == 18) {
                        for (int c7 = 0; c7 <= 1; c7 += 1) {
                          fprintf(f, "x q[%u];\n", 11 * c7 + 4);
                        }
                      }
                      if (c5 == 12) {
                        for (int c7 = 0; c7 <= 1; c7 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -13 * c7 + 18, 4 * c7 + 12);
                        }
                        for (int c7 = 0; c7 <= 1; c7 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 19, 2 * c7 + 7);
                        }
                      } else if (c5 == 11) {
                        for (int c7 = 0; c7 <= 1; c7 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 19, 5 * c7 + 7);
                        }
                      } else if ((c5 - 2) % 16 == 0) {
                        fprintf(f, "x q[%u];\n", (-9 * c5 + 210) / 16);
                        if (c5 == 18) {
                          for (int c7 = 0; c7 <= 1; c7 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 11, 10 * c7 + 7);
                          }
                        }
                      }
                    }
                  }
                }
              }
            } else {
              for (int c5 = 0; c5 <= 11; c5 += 1) {
                if (c5 >= 4 && c5 <= 5) {
                  fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 - 12, -17 * c5 + 86);
                  if (c5 == 5) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 2, 5 * c7 + 13);
                    }
                  } else {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", -6 * c7 + 10);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 5, c7 + 16);
                    }
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 - 30, -5 * c5 + 33);
                } else {
                  if (c5 == 6) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 13, 8 * c7 + 3);
                    }
                  } else if (c5 == 2) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c7, 4 * c7 + 14);
                    }
                    fprintf(f, "x q[%u];\n", 15);
                  }
                  if (c5 >= 3 && c5 <= 6 && c5 % 3 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 - 9, 3 * c5 - 8);
                    if (c5 == 3) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 15, 12 * c7 + 4);
                      }
                    }
                  }
                  if (c5 >= 2 && c5 <= 3) {
                    fprintf(f, "cx q[%u], q[%u];\n", -5 * c5 + 23, 17 * c5 - 33);
                  } else if (c5 == 11) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 15, 2 * c7 + 4);
                    }
                  }
                  if (c5 == 10) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 8, 13 * c7);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 14 * c7 + 4, 10 * c7 + 6);
                    }
                  } else if (c5 == 7) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 3, 2 * c7 + 17);
                    }
                  } else if (c5 == 1) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 9 * c7 + 8, 9 * c7);
                    }
                  } else if (c5 % 8 == 0) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", c7 + 2, 11 * c7 + 6);
                    }
                  } else if (c5 >= 9 && (c5 + 1) % 2 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", -7 * c5 + 79, c5 + 2);
                    if (c5 == 9) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 + 4, 4 * c7 + 2);
                      }
                    }
                  }
                }
              }
            }
            if (c3 == 1) {
              fprintf(f, "x q[%u];\n", 13);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c7 + 2, 2 * c7 + 6);
              }
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", ((7 * c3 + 17) / 2) - 3 * c7);
            }
            if (c3 == 3) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 10, 9 * c7 + 8);
              }
            }
            if (c3 == 3) {
              for (int c5 = 22; c5 <= 25; c5 += 1) {
                if (c5 == 25) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -12 * c7 + 18, 7 * c7 + 12);
                  }
                }
                if (c5 >= 24) {
                  fprintf(f, "cx q[%u], q[%u];\n", -18 * c5 + 451, -2 * c5 + 55);
                  if (c5 == 25) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 4, 5 * c7 + 8);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 11, 2 * c7 + 7);
                    }
                  }
                } else if (c5 == 23) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c7 + 9, 12 * c7 + 7);
                  }
                }
                if (c5 >= 23 && c5 <= 24) {
                  fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 - 159, 5 * c5 - 109);
                  if (c5 == 24) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 6, c7 + 1);
                    }
                  }
                } else if (c5 == 22) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c7 + 18, 4 * c7 + 5);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", -6 * c7 + 16);
                  }
                }
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 19, 6 * c7 + 11);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 4, 10 * c7 + 2);
              }
            } else {
              for (int c5 = 13; c5 <= 26; c5 += 1) {
                if (c5 >= 14 && c5 <= 15) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 60, -12 * c5 + 184);
                  if (c5 == 15) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c7 + 12);
                    }
                  }
                } else {
                  if (c5 == 26) {
                    fprintf(f, "x q[%u];\n", 12);
                  } else if (c5 == 21) {
                    fprintf(f, "cx q[%u], q[%u];\n", 19, 7);
                  } else if (c5 == 20) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 9, 7 * c7 + 7);
                    }
                  } else if (c5 == 19) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -13 * c7 + 13, 15 * c7 + 3);
                    }
                  } else if (c5 == 18) {
                    fprintf(f, "cx q[%u], q[%u];\n", 19, 11);
                  } else if (c5 == 17) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c7, 4 * c7 + 14);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 6 * c7 + 3, 10 * c7 + 1);
                    }
                  } else if (c5 == 16) {
                    fprintf(f, "x q[%u];\n", 4);
                  }
                  if (c5 == 13) {
                    for (int c7 = 0; c7 <= 2; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 4, 5 * c7 + 8);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 19, 5 * c7 + 7);
                    }
                  }
                }
                if (c5 <= 18 && c5 % 3 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", (14 * c5 / 3) - 69, (5 * c5 / 3) - 20);
                  if (c5 == 18) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 3, 13 * c7 + 1);
                    }
                  }
                } else if (c5 == 14) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 11 * c7 + 4, 8 * c7 + 2);
                  }
                }
                if (c5 >= 14 && c5 <= 15) {
                  fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 - 42, 4 * c5 - 44);
                } else if (c5 >= 16 && c5 <= 19 && (c5 - 1) % 3 == 0) {
                  fprintf(f, "x q[%u];\n", 3 * c5 - 47);
                  if (c5 == 16) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c7, 4 * c7 + 14);
                    }
                  }
                }
              }
            }
            if (c3 == 3) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 12 * c5 + 6, 11 * c5 + 5);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c5 + 12);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "x q[%u];\n", -7 * c5 + 18);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 15 * c5 + 4, 7 * c5 + 2);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "x q[%u];\n", -2 * c5 + 10);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 8, 8 * c5 + 6);
              }
            } else if (c3 == 1) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "x q[%u];\n", -3 * c5 + 14);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c5 + 9, 4 * c5 + 7);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 9, 8 * c5 + 11);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 13 * c5 + 6, 6 * c5 + 5);
              }
            }
          }
          if (c3 % 2 == 0) {
            if (c3 == 2) {
              fprintf(f, "x q[%u];\n", 12);
            }
            fprintf(f, "x q[%u];\n", (-9 * c3 / 2) + 21);
            if (c3 == 4) {
              for (int c5 = 3; c5 <= 6; c5 += 1) {
                if (c5 == 4) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 18 * c7 + 1, 6 * c7 + 5);
                  }
                } else if (c5 % 3 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 - 9, 3 * c5 - 8);
                }
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -2 * c7 + 15, 13 * c7 + 4);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 8, 3 * c7);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c7 + 14);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 15, 3 * c7 + 4);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", c7 + 1, c7 + 5);
              }
              for (int c7 = 0; c7 <= 2; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 2, 6 * c7 + 6);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c7 + 15, 8 * c7 + 4);
              }
              fprintf(f, "x q[%u];\n", 8);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", c7 + 14);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -15 * c7 + 16, 8 * c7 + 11);
              }
            }
          }
        }
      }
    }
    if (c1 == 1) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 2 * c3 + 13, 7 * c3 + 3);
      }
    } else if (c1 == 0) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 6 * c3 + 6, 11 * c3 + 5);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -7 * c3 + 10, 17 * c3);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -2 * c3 + 2, 5 * c3 + 13);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 9 * c3 + 1);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -8 * c3 + 10, 13 * c3);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 10 * c3 + 2);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 12 * c3 + 6, 4 * c3 + 1);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -10 * c3 + 19, 4 * c3 + 7);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -4 * c3 + 5, 3 * c3 + 16);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 4 * c3 + 9, 6 * c3 + 11);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -6 * c3 + 9, 6 * c3 + 11);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -7 * c3 + 19, 7 * c3 + 9);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -13 * c1 + 14, 7 * c1 + 12);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 6 * c1 + 11, 2 * c1 + 7);
  }
}
fclose(f);
return 0;
}