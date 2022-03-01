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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.2D1_.3D2_5.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -13 * c1 + 18, 9 * c1 + 7);
  }
  for (int c1 = 0; c1 <= 4; c1 += 1) {
    if (c1 >= 1) {
      for (int c3 = max(c1 - 4, -c1 + 1); c3 <= min(1, -c1 + 4); c3 += 1) {
        if (c1 + 2 * c3 >= 1) {
          if (c1 >= 2 && c1 <= 3 && c3 == 0) {
            fprintf(f, "x q[%u];\n", 19);
            if (c1 == 3) {
              fprintf(f, "cx q[%u], q[%u];\n", 19, 0);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c7);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 12, 5);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 13, 3 * c7);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 16, 14);
            } else {
              fprintf(f, "cx q[%u], q[%u];\n", 9, 19);
            }
          }
          if (c1 <= 2) {
            for (int c5 = 1; c5 <= min(-c1 + 3, c3 + 1); c5 += 1) {
              if (c1 == 1 && c3 == 1 && c5 == 2) {
                fprintf(f, "x q[%u];\n", 1);
              }
              if (c1 == 1 && c5 == c3 + 1) {
                for (int c7 = 0; c7 <= -c3 + 2; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c3 + c7 + 10);
                }
              } else if (c1 == 2 && c3 == 0) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 18, 4 * c7 + 15);
                }
              }
              if (c5 == 1) {
                for (int c7 = 0; c7 <= -c1 + 2; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c1 + 11 * c7 + 1);
                }
              }
            }
            if (c1 == 2 && c3 == 0) {
              for (int c5 = 2; c5 <= 4; c5 += 1) {
                if (c5 == 3) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 8, c7 + 13);
                  }
                } else {
                  fprintf(f, "x q[%u];\n", (-5 * c5 / 2) + 18);
                  if (c5 == 2) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 19, 17 * c7);
                    }
                  }
                }
              }
              for (int c5 = 5; c5 <= 6; c5 += 1) {
                if (c5 == 6) {
                  fprintf(f, "cx q[%u], q[%u];\n", 6, 11);
                } else {
                  fprintf(f, "x q[%u];\n", 11);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c7 + 6);
                  }
                }
              }
            } else if (c1 == 1 && c3 == 1) {
              fprintf(f, "x q[%u];\n", 2);
            }
          }
          if (c3 == 1 && (c1 + 1) % 2 == 0) {
            for (int c7 = 0; c7 < (c1 + 1) / 2; c7 += 1) {
              fprintf(f, "x q[%u];\n", -3 * c1 + 4 * c7 + 15);
            }
          } else if (c1 == 3 && c3 == 0) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 3 * c7);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 8, 2 * c7 + 13);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 5, 14);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 12 * c7 + 6, 12 * c7 + 2);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c7 + 8, 15 * c7);
            }
            fprintf(f, "x q[%u];\n", 9);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c7 + 8);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 13, 0);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c7 + 14);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 17, 5 * c7 + 4);
            }
          } else if (c1 == 4 && c3 == 0) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c7 + 3);
            }
          }
          if (c1 >= 2 && c3 >= 0 && c1 >= 2 * c3 + 1) {
            for (int c5 = max(max(c1 + 3, c3 + 6), -c1 + c1 / 2 + 8); c5 <= -c1 + c1 / 2 + 9; c5 += 1) {
              if (c3 == 0 && 2 * c1 + c5 == 12) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c1 + 2 * c7 - 15);
                }
                if (c1 == 3) {
                  fprintf(f, "cx q[%u], q[%u];\n", 8, 19);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 13, 2 * c7);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", -4 * c7 + 16);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                }
              } else if (c1 == 3 && c3 == 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 6, 2);
              } else {
                if (c1 == 3) {
                  fprintf(f, "cx q[%u], q[%u];\n", 7, 15);
                  fprintf(f, "cx q[%u], q[%u];\n", 17, 4);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", -3 * c7 + 12);
                  }
                }
                if (c1 >= 3) {
                  fprintf(f, "cx q[%u], q[%u];\n", -5 * c1 + 31, -11 * c1 + 47);
                  if (c1 == 3) {
                    fprintf(f, "cx q[%u], q[%u];\n", 1, 8);
                  }
                } else {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 11, 3 * c7 + 3);
                  }
                }
              }
            }
            if (c1 == 2 && c3 == 0) {
              fprintf(f, "x q[%u];\n", 3);
              fprintf(f, "cx q[%u], q[%u];\n", 6, 11);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 19 * c7);
              }
            } else if (c1 == 3 && c3 == 0) {
              for (int c5 = 8; c5 <= 10; c5 += 1) {
                if (c5 == 10) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 18, 12 * c7 + 7);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 12 * c7 + 4, 12 * c7 + 2);
                  }
                } else if (c5 == 9) {
                  fprintf(f, "cx q[%u], q[%u];\n", 17, 2);
                  fprintf(f, "x q[%u];\n", 7);
                  fprintf(f, "cx q[%u], q[%u];\n", 14, 1);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c7 + 4);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
                } else {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c7);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 4, 4 * c7 + 6);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
                  fprintf(f, "cx q[%u], q[%u];\n", 5, 16);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 7 * c7 + 1);
                  }
                }
              }
            }
            if (c1 <= 3 && c3 == 0) {
              if (c1 == 3) {
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
                fprintf(f, "x q[%u];\n", 15);
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c7 + 7);
                }
              } else {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 4, 5 * c7 + 6);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 11 * c7 + 8);
                }
              }
              if (c1 == 2) {
                fprintf(f, "cx q[%u], q[%u];\n", 1, 8);
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c7 + 6);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 4, 5 * c7 + 2);
                }
                fprintf(f, "x q[%u];\n", 6);
              }
            } else if (c1 == 3 && c3 == 1) {
              for (int c5 = 3; c5 <= 5; c5 += 2) {
                fprintf(f, "x q[%u];\n", 3 * c5 + 1);
              }
            }
            if (c1 == 2 && c3 == 0) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c7 + 5);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 6, 9 * c7 + 2);
              }
            }
          } else {
            if (c1 == 1 && c3 == 1) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", c7 + 11, 2 * c7 + 3);
              }
              for (int c5 = 8; c5 <= 9; c5 += 1) {
                if (c5 == 9) {
                  fprintf(f, "cx q[%u], q[%u];\n", 18, 7);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c7 + 3);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 13, 0);
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", 7, 10);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 11, 13 * c7 + 3);
                  }
                }
              }
              fprintf(f, "cx q[%u], q[%u];\n", 18, 14);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 13 * c7 + 3);
              }
              fprintf(f, "x q[%u];\n", 13);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 15, 6 * c7 + 3);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 12, 5);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c7 + 17, 12 * c7 + 2);
              }
            } else if (2 * c1 + c3 == 5) {
              fprintf(f, "x q[%u];\n", 9);
              if (c1 == 2) {
                fprintf(f, "x q[%u];\n", 19);
              }
            }
            if (c1 == 1 && c3 == 0) {
              for (int c5 = 2; c5 <= 11; c5 += 1) {
                if (c5 == 11) {
                  fprintf(f, "cx q[%u], q[%u];\n", 11, 3);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c7 + 4);
                  }
                  fprintf(f, "x q[%u];\n", 18);
                  fprintf(f, "cx q[%u], q[%u];\n", 5, 1);
                  fprintf(f, "x q[%u];\n", 14);
                } else if (c5 == 10) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c7 + 17, 13 * c7 + 2);
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c7 + 11);
                  }
                } else {
                  if (c5 == 9) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 17, 15 * c7 + 4);
                    }
                  } else if (c5 == 6) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", c7 + 17, 5 * c7 + 2);
                    }
                  } else if (c5 == 2) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c7);
                    }
                  }
                  if (c5 >= 6 && c5 % 3 == 0) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", (2 * c5 / 3) + 2 * c7 + 2);
                    }
                    if (c5 == 9) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -13 * c7 + 14, 4 * c7 + 7);
                      }
                    }
                  } else if (c5 == 7) {
                    fprintf(f, "x q[%u];\n", 13);
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", c7 + 14, 2 * c7 + 7);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", c7 + 10, 5 * c7 + 3);
                    }
                  }
                }
                if ((c5 - 1) % 5 == 0) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", ((c5 - 1) / 5) + 13 * c7);
                  }
                  if (c5 == 11) {
                    fprintf(f, "x q[%u];\n", 13);
                  } else if (c5 == 6) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -c7 + 13, 5 * c7);
                    }
                  }
                } else if (c5 == 4) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    for (int c8 = 0; c8 <= c7; c8 += 1) {
                      fprintf(f, "x q[%u];\n", -3 * c7 + 6 * c8 + 16);
                    }
                  }
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c7);
                  }
                } else {
                  if (c5 >= 5 && (c5 + 1) % 3 == 0) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", ((2 * c5 + 8) / 3) + 2 * c7);
                    }
                  }
                  if (c5 % 5 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", (-6 * c5 / 5) + 20, (12 * c5 / 5) - 11);
                    if (c5 == 10) {
                      fprintf(f, "cx q[%u], q[%u];\n", 1, 6);
                    }
                    if (c5 == 5) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 9 * c7 + 4, 17 * c7 + 2);
                      }
                    }
                  } else if (c5 == 9) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 12, 4 * c7 + 5);
                    }
                  } else if (c5 == 8) {
                    fprintf(f, "x q[%u];\n", 19);
                  }
                  if ((c5 + 2) % 5 == 0) {
                    for (int c7 = 0; c7 <= (-c5 + 8) / 5; c7 += 1) {
                      fprintf(f, "x q[%u];\n", ((9 * c5 - 17) / 5) + 11 * c7);
                    }
                    if (c5 == 8) {
                      fprintf(f, "x q[%u];\n", 13);
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c7 + 5);
                      }
                    } else if (c5 == 3) {
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "x q[%u];\n", 6 * c7);
                      }
                    }
                  }
                }
              }
            }
          }
          if (c1 <= 2) {
            if (c1 == 1 && c3 == 1) {
              fprintf(f, "x q[%u];\n", 5);
              fprintf(f, "cx q[%u], q[%u];\n", 6, 11);
              fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
              fprintf(f, "cx q[%u], q[%u];\n", 19, 0);
              fprintf(f, "cx q[%u], q[%u];\n", 2, 13);
            } else if (c1 == 1 && c3 == 0) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 4, 5 * c7 + 6);
              }
            }
            for (int c7 = 0; c7 <= -c1 + 2; c7 += 1) {
              fprintf(f, "x q[%u];\n", -3 * c1 + 5 * c3 + 3 * c7 + 12);
            }
            if (c1 == 1 && c3 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", 18, 7);
              fprintf(f, "x q[%u];\n", 19);
              fprintf(f, "x q[%u];\n", 14);
            }
            if (c1 == 1 && c3 == 1) {
              fprintf(f, "x q[%u];\n", 19);
              fprintf(f, "cx q[%u], q[%u];\n", 12, 5);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c7 + 8, 2 * c7);
              }
              for (int c5 = 14; c5 <= 15; c5 += 1) {
                if (c5 == 15) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c7 + 2);
                  }
                } else {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 17 * c7);
                  }
                }
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 15 * c7 + 2);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 7, 15);
              for (int c5 = 17; c5 <= 19; c5 += 1) {
                if (c5 == 19) {
                  fprintf(f, "x q[%u];\n", 7);
                } else if (c5 == 18) {
                  fprintf(f, "cx q[%u], q[%u];\n", 7, 15);
                } else {
                  fprintf(f, "x q[%u];\n", 7);
                }
              }
            }
            if (c1 == 2 && c3 == 0) {
              fprintf(f, "x q[%u];\n", 3);
            }
            if (c1 == 1 && c3 == 0) {
              for (int c5 = 13; c5 <= 19; c5 += 1) {
                if (c5 == 14) {
                  fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
                }
                if (c5 <= 14) {
                  fprintf(f, "cx q[%u], q[%u];\n", 8 * c5 - 96, 17 * c5 - 221);
                  if (c5 == 14) {
                    fprintf(f, "x q[%u];\n", 19);
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 4, 2 * c7 + 6);
                    }
                  } else if (c5 == 13) {
                    fprintf(f, "x q[%u];\n", 19);
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 3 * c7 + 9);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 3 * c7 + 1);
                    }
                  }
                  if (c5 == 14) {
                    fprintf(f, "cx q[%u], q[%u];\n", 7, 10);
                  }
                } else {
                  if (c5 == 19) {
                    fprintf(f, "x q[%u];\n", 19);
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c7 + 5);
                    }
                  } else if (c5 == 18) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 11 * c7 + 5, 3 * c7 + 14);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 4, 4 * c7 + 6);
                    }
                    fprintf(f, "x q[%u];\n", 19);
                    fprintf(f, "x q[%u];\n", 2);
                  } else if (c5 == 17) {
                    fprintf(f, "cx q[%u], q[%u];\n", 19, 0);
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 15 * c7 + 1);
                    }
                  } else if (c5 == 16) {
                    fprintf(f, "x q[%u];\n", 4);
                    fprintf(f, "x q[%u];\n", 12);
                    fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", c7 + 7);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 15 * c7 + 1, 8 * c7 + 6);
                    }
                    fprintf(f, "x q[%u];\n", 19);
                    fprintf(f, "cx q[%u], q[%u];\n", 2, 13);
                  } else {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 15 * c7 + 3);
                    }
                  }
                  if (c5 <= 17 && (c5 + 1) % 2 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", (3 * c5 - 37) / 2, 4 * c5 - 58);
                    if (c5 == 15) {
                      fprintf(f, "x q[%u];\n", 19);
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "x q[%u];\n", -11 * c7 + 17);
                      }
                      for (int c7 = 0; c7 <= 1; c7 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -c7 + 8, 10 * c7);
                      }
                    }
                  }
                }
                if ((c5 - 1) % 4 == 0) {
                  for (int c7 = 0; c7 < (c5 - 9) / 4; c7 += 1) {
                    fprintf(f, "x q[%u];\n", ((-11 * c5 + 207) / 4) + 10 * c7);
                  }
                  if (c5 == 17) {
                    fprintf(f, "x q[%u];\n", 2);
                    fprintf(f, "x q[%u];\n", 12);
                  } else if (c5 == 13) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c7 + 7);
                    }
                  }
                }
              }
            }
          } else {
            if (c1 == 4 && c3 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", 15, 11);
            } else if (c3 == 0) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 12 * c7 + 3);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 13, 19);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c7 + 12);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 13, 19 * c7);
              }
              for (int c5 = 14; c5 <= 15; c5 += 1) {
                if (c5 == 15) {
                  fprintf(f, "x q[%u];\n", 13);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 8, 2 * c7);
                  }
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", 13, 0);
                }
              }
              for (int c5 = 16; c5 <= 17; c5 += 1) {
                if (c5 == 17) {
                  fprintf(f, "cx q[%u], q[%u];\n", 16, 17);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c7 + 6);
                  }
                } else {
                  fprintf(f, "x q[%u];\n", 8);
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", c7 + 17);
                  }
                }
              }
            }
            if (c1 == 3 && c3 == -1) {
              fprintf(f, "x q[%u];\n", 9);
            }
          }
          if (c1 == 2 && c3 == 0) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 15 * c5 + 1, 6 * c5 + 11);
            }
          }
        } else {
          fprintf(f, "x q[%u];\n", 1);
        }
      }
    } else {
      fprintf(f, "x q[%u];\n", 19);
      for (int c7 = 0; c7 <= 1; c7 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 9 * c7 + 4, 17 * c7 + 2);
      }
    }
    if (c1 == 1) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 7 * c3 + 4);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 3);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 5);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 6 * c1 + 5);
  }
}
fclose(f);
return 0;
}