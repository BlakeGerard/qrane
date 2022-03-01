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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.3D1_.3D2_6.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 4; c1 += 1) {
    if (c1 >= 3) {
      for (int c3 = 0; c3 <= -c1 + 6; c3 += 1) {
        if (c1 == 3 && c3 == 1) {
          fprintf(f, "x q[%u];\n", 18);
          fprintf(f, "x q[%u];\n", 18);
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 18, 6 * c7 + 5);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 7, 12);
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            for (int c8 = 0; c8 <= c7; c8 += 1) {
              fprintf(f, "x q[%u];\n", -6 * c7 + 15 * c8 + 6);
            }
          }
        }
        if (c1 == 4 && c3 == 0) {
          for (int c5 = 4; c5 <= 6; c5 += 1) {
            if (c5 == 6) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 10, 3 * c7 + 5);
              }
            } else if (c5 == 5) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c7 + 10, 10 * c7 + 5);
              }
            } else {
              fprintf(f, "cx q[%u], q[%u];\n", 18, 5);
            }
          }
        }
        if (c3 == 0) {
          for (int c5 = -c1 + 11; c5 <= 8; c5 += 1) {
            if (c5 == 8) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", -3 * c1 + 5 * c7 + 17);
              }
            } else {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c7 + 3);
              }
            }
          }
        } else if (c1 == 3 && c3 == 2) {
          fprintf(f, "x q[%u];\n", 11);
        } else if (c1 == 4 && c3 == 1) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 6 * c7 + 1);
          }
          for (int c9 = -1; c9 <= 0; c9 += 1) {
            fprintf(f, "x q[%u];\n", -5 * c9 + 7);
          }
          for (int c5 = 4; c5 <= 6; c5 += 1) {
            if (c5 == 6) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c7 + 3);
              }
            } else if (c5 == 5) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 17, 4 * c7 + 14);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 3, 3 * c7 + 8);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c7 + 12);
              }
            } else {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 7 * c7, 5 * c7 + 1);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 8, 3 * c7 + 12);
              }
            }
          }
          for (int c5 = 7; c5 <= 8; c5 += 1) {
            if (c5 == 8) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c7 + 1);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c7 + 5);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c7 + 13);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c7 + 15, 14 * c7);
              }
            } else {
              fprintf(f, "x q[%u];\n", 1);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c7);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 16, 14 * c7 + 3);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c7 + 8);
              }
            }
          }
        } else if (c1 == 3 && c3 == 1) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            for (int c8 = c7 - 1; c8 <= c7; c8 += 1) {
              fprintf(f, "x q[%u];\n", -5 * c7 + 6 * c8 + 11);
              if (c7 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c8 + 14, c8 + 6);
              }
            }
            if (c7 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", 12, 6);
            }
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 5 * c7 + 8);
          }
          fprintf(f, "x q[%u];\n", 7);
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 16, 7 * c7 + 3);
          }
          fprintf(f, "x q[%u];\n", 5);
          fprintf(f, "x q[%u];\n", 7);
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 13 * c7 + 1);
          }
        }
        if (c1 + c3 == 4) {
          for (int c5 = 3 * c1 + 1; c5 <= 13; c5 += 1) {
            if (c5 == 13) {
              fprintf(f, "x q[%u];\n", 5 * c1 - 1);
            } else if (c5 == 11) {
              fprintf(f, "cx q[%u], q[%u];\n", 10, 19);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", -13 * c7 + 14);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 9, 4 * c7 + 2);
              }
            } else if (c5 == 10) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 + 15, 16 * c7 + 1);
              }
            }
            if (c1 == 3 && (c5 - 1) % 3 == 0) {
              fprintf(f, "x q[%u];\n", (10 * c5 - 82) / 3);
              if (c5 == 13) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  for (int c8 = 0; c8 <= 1; c8 += 1) {
                    fprintf(f, "x q[%u];\n", -9 * c7 + 7 * c8 + 11);
                  }
                }
              }
              if (c5 == 10) {
                fprintf(f, "cx q[%u], q[%u];\n", 9, 10);
              }
            } else if (c1 == 3 && c5 == 12) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -9 * c7 + 7 * c9 + 11);
                }
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 16, 6 * c7 + 8);
              }
              fprintf(f, "x q[%u];\n", 3);
            }
          }
          if (c1 == 4) {
            for (int c9 = -1; c9 <= 0; c9 += 1) {
              fprintf(f, "x q[%u];\n", -5 * c9 + 14);
            }
          }
          if (c1 == 3) {
            fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", -2 * c7 + 13);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c7 + 2);
            }
            for (int c5 = 15; c5 <= 17; c5 += 1) {
              if (c5 == 17) {
                fprintf(f, "x q[%u];\n", 11);
              } else if (c5 == 16) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 13 * c7 + 2);
                }
              } else {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c7 + 2);
                }
              }
            }
          }
        } else {
          if (c1 == 4 && c3 == 1) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 8, 3 * c7 + 12);
            }
            fprintf(f, "x q[%u];\n", 5);
            fprintf(f, "x q[%u];\n", 19);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 13 * c7 + 3);
            }
          } else if (c3 == 2) {
            for (int c5 = 5; c5 <= c1 + 2; c5 += 1) {
              if (c5 == 5) {
                fprintf(f, "x q[%u];\n", 12 * c1 - 29);
              } else {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 19, 15 * c7 + 1);
                }
              }
            }
          }
          if (c1 == 3 && c3 == 2) {
            fprintf(f, "x q[%u];\n", 3);
            fprintf(f, "x q[%u];\n", 3);
            fprintf(f, "cx q[%u], q[%u];\n", 0, 7);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 1, 5 * c7 + 7);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c7 + 3, 17 * c7);
            }
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c7);
            }
          }
        }
        if (c3 + 2 >= c1 && c3 <= 2) {
          for (int c5 = -4 * c1 - 8 * c3 + 39; c5 <= 8 * c1 - 8 * c3 + 3; c5 += 1) {
            if (c1 == 3 && 8 * c3 + c5 == 27) {
              fprintf(f, "x q[%u];\n", -11 * c3 + 26);
            } else if (c5 == 11) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 14 * c7);
              }
            } else if (c5 == 10) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 17 * c7);
              }
            } else if (c5 == 9) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c7 + 8, 3 * c7 + 12);
              }
            } else if ((c5 + 5) % 12 == 0) {
              fprintf(f, "x q[%u];\n", (3 * c5 - 19) / 2);
              if (c5 == 7) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 16, 10 * c7 + 8);
                }
              }
            }
          }
        }
        if (c1 == 3 && c3 >= 2) {
          fprintf(f, "x q[%u];\n", 4);
        } else if (c1 == 4 && c3 == 0) {
          fprintf(f, "cx q[%u], q[%u];\n", 17, 14);
        } else if (c1 == 4 && c3 == 1) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 6 * c7 + 12);
          }
        }
        if (c1 == 4 && c3 == 1) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 7 * c5 + 6, 4 * c5 + 11);
          }
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c5 + 12);
          }
        } else if (c1 == 4 && c3 == 0) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "x q[%u];\n", 13 * c5 + 4);
          }
        }
      }
    } else {
      if (c1 == 2) {
        fprintf(f, "x q[%u];\n", 0);
        fprintf(f, "x q[%u];\n", 0);
        fprintf(f, "cx q[%u], q[%u];\n", 0, 1);
        fprintf(f, "x q[%u];\n", 1);
      }
      if (c1 % 2 == 0) {
        if (c1 == 0) {
          for (int c7 = 0; c7 <= 2; c7 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c7 + 11);
          }
        }
        if (c1 == 2) {
          for (int c5 = -1; c5 <= 21; c5 += 1) {
            if (c5 == 1) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", c7 + 14);
              }
            } else if (c5 >= 2 && c5 <= 5 && (c5 + 1) % 3 == 0) {
              if (c5 == 5) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  for (int c9 = 0; c9 <= -c7 + 1; c9 += 1) {
                    if (c7 == 0) {
                      fprintf(f, "cx q[%u], q[%u];\n", 5 * c9, 11 * c9 + 8);
                      if (c9 == 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 10, 19);
                      }
                      fprintf(f, "x q[%u];\n", 9 * c9 + 1);
                    }
                    if (c9 == 0) {
                      fprintf(f, "x q[%u];\n", -9 * c7 + 19);
                    }
                  }
                }
              } else {
                fprintf(f, "cx q[%u], q[%u];\n", 1, 17);
              }
            }
            if (c5 >= 1 && c5 <= 2) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c5 + 23, -c5 + 2);
            } else if (c5 == 20) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 8, 4 * c7 + 12);
              }
            } else if (c5 == 19) {
              for (int c8 = 0; c8 <= 1; c8 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c8 + 15, c8);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c7 + 2);
              }
            } else if (c5 == 18) {
              fprintf(f, "cx q[%u], q[%u];\n", 1, 14);
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c7);
              }
            } else if (c5 == 17) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c7, 5 * c7 + 8);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c7 + 15);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 1, 14);
            } else {
              if (c5 == 16) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -9 * c7 + 19, 4 * c7 + 1);
                }
              } else if (c5 == 14) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c7 + 3);
                }
              } else if (c5 == 13) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 16 * c7 + 3);
                }
              } else if (c5 == 12) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 16 * c7 + 3);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c7 + 4);
                }
                fprintf(f, "x q[%u];\n", 16);
              } else if (c5 == 11) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c7 + 4);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -11 * c7 + 16, 16 * c7 + 3);
                }
              } else if (c5 == 10) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c7 + 4);
                }
              } else if (c5 == 9) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c7 + 4);
                }
              } else if (c5 == 7) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -12 * c7 + 16, 9 * c7 + 8);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 18 * c7, 4 * c7 + 1);
                }
              } else {
                if (c5 <= 8 && (c5 + 1) % 9 == 0) {
                  fprintf(f, "x q[%u];\n", (4 * c5 + 130) / 9);
                  if (c5 == 8) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 12 * c7 + 4);
                    }
                  }
                }
                if (c5 == -1) {
                  fprintf(f, "x q[%u];\n", 1);
                } else if ((c5 + 3) % 9 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", (-4 * c5 / 3) + 21, (-c5 + 141) / 9);
                  if (c5 == 15) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c7 + 3);
                    }
                  } else if (c5 == 6) {
                    fprintf(f, "x q[%u];\n", 17);
                  }
                } else if (c5 == 5) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c7 + 14);
                  }
                } else if (c5 == 3) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 18, 2 * c7 + 15);
                  }
                } else if (c5 == 0) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -14 * c7 + 15, 14 * c7);
                  }
                }
              }
              if ((c5 - 4) % 12 == 0) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 17, c7 + 14);
                }
              } else if ((c5 - 6) % 15 == 0) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", ((8 * c5 - 48) / 15) + 5 * c7);
                }
              }
            }
          }
        } else {
          for (int c5 = 5; c5 <= 23; c5 += 1) {
            if (c5 == 8) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -17 * c7 + 19, c7 + 14);
              }
            }
            if (c5 >= 8 && c5 <= 9) {
              fprintf(f, "cx q[%u], q[%u];\n", 18 * c5 - 143, 10 * c5 - 73);
              if (c5 == 9) {
                fprintf(f, "x q[%u];\n", 12);
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 7, 8 * c7 + 6);
                }
              } else {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -6 * c9 + 6);
                }
              }
              if (c5 == 8) {
                fprintf(f, "x q[%u];\n", 12);
              }
              if (c5 == 8) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c7 + 3);
                }
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", -2 * c5 + 13 * c7 + 20);
              }
              if (c5 == 9) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c7 + 4);
                }
              }
            } else {
              if (c5 == 21) {
                fprintf(f, "cx q[%u], q[%u];\n", 12, 11);
              } else if (c5 == 20) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", c7 + 11);
                }
              } else if (c5 == 19) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c7 + 13);
                }
              } else if (c5 == 14) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -15 * c9 + 16, 11 * c9 + 3);
                }
              }
              if ((c5 + 3) % 9 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", (-4 * c5 / 3) + 23, (-c5 + 15) / 9);
                if (c5 == 6) {
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 8);
                }
              } else if (c5 % 6 == 0) {
                if (c5 == 18) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    for (int c9 = 0; c9 <= -c7 + 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -2 * c7 + c9 + 9);
                      if (c7 == 0) {
                        fprintf(f, "x q[%u];\n", 9 * c9 + 9);
                      }
                    }
                    if (c7 == 0) {
                      fprintf(f, "cx q[%u], q[%u];\n", 13, 18);
                      for (int c9 = -1; c9 <= 0; c9 += 1) {
                        fprintf(f, "x q[%u];\n", -5 * c9 + 13);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", -6 * c9 + 11);
                        if (c9 == 0) {
                          fprintf(f, "x q[%u];\n", 11);
                          fprintf(f, "cx q[%u], q[%u];\n", 7, 11);
                          fprintf(f, "cx q[%u], q[%u];\n", 15, 7);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", -17 * c9 + 18, 12 * c9 + 5);
                      }
                    }
                  }
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", 14, 6);
                }
                if (c5 == 18) {
                  for (int c7 = 0; c7 <= 1; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c7 + 6);
                  }
                }
              } else {
                if (c5 >= 19) {
                  for (int c7 = 0; c7 <= -c5 + 20; c7 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c5 + 16 * c7 - 284);
                  }
                  if (c5 == 22) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 13 * c7 + 3);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -10 * c7 + 12, 7 * c7 + 6);
                    }
                  } else if (c5 == 21) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -11 * c7 + 16, c7 + 3);
                    }
                  } else if (c5 == 19) {
                    fprintf(f, "x q[%u];\n", 11);
                  }
                }
                if (c5 == 14) {
                  fprintf(f, "x q[%u];\n", 12);
                } else {
                  if (c5 == 7) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 7, 3 * c7 + 12);
                    }
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 + 6, 5 * c7 + 11);
                    }
                  }
                  if ((c5 + 5) % 12 == 0) {
                    fprintf(f, "x q[%u];\n", (3 * c5 - 21) / 2);
                  } else if ((c5 - 5) % 12 == 0) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", c5 + 7 * c7 - 5, ((5 * c5 - 13) / 12) + 11 * c7);
                    }
                    if (c5 == 17) {
                      fprintf(f, "cx q[%u], q[%u];\n", 0, 7);
                    }
                  } else if (c5 == 11) {
                    for (int c7 = 0; c7 <= 1; c7 += 1) {
                      fprintf(f, "x q[%u];\n", 14 * c7 + 4);
                    }
                  }
                }
              }
              if (c5 >= 11 && c5 <= 16 && (c5 - 1) % 5 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", (-c5 + 16) / 5, (c5 + 24) / 5);
                if (c5 == 16) {
                  fprintf(f, "x q[%u];\n", 3);
                  fprintf(f, "x q[%u];\n", 12);
                }
              } else if (c5 == 10) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", c7 + 9);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 7, 5 * c7 + 12);
                }
              }
              if (c5 == 23) {
                fprintf(f, "x q[%u];\n", 12);
              } else if (c5 % 5 == 0) {
                for (int c7 = 0; c7 < (c5 / 5) - 2; c7 += 1) {
                  fprintf(f, "x q[%u];\n", (-7 * c5 / 5) + 16 * c7 + 29);
                }
                if (c5 == 15) {
                  fprintf(f, "x q[%u];\n", 19);
                  fprintf(f, "x q[%u];\n", 12);
                }
              } else if (c5 == 13) {
                fprintf(f, "cx q[%u], q[%u];\n", 1, 14);
              } else if (c5 == 11) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c7 + 6);
                }
              }
              if (c5 >= 12 && c5 <= 17 && (c5 - 2) % 5 == 0) {
                fprintf(f, "x q[%u];\n", (7 * c5 - 79) / 5);
              }
            }
          }
        }
        if (c1 == 0) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 12 * c5 + 6, 4 * c5 + 11);
          }
        }
      } else {
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", 13 * c7 + 3);
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", 13 * c7 + 3);
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", c7 + 3);
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", c7 + 3);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", c9 + 3);
        }
        for (int c7 = 0; c7 <= 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", c7 + 3);
        }
        fprintf(f, "x q[%u];\n", 4);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 4);
        fprintf(f, "cx q[%u], q[%u];\n", 16, 8);
        for (int c5 = 11; c5 <= 14; c5 += 1) {
          if (c5 == 14) {
            fprintf(f, "x q[%u];\n", 0);
          } else if (c5 == 13) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 16 * c7);
            }
          } else if (c5 == 12) {
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              fprintf(f, "x q[%u];\n", 16 * c7);
            }
          } else {
            for (int c7 = 0; c7 <= 2; c7 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c7);
            }
          }
        }
        fprintf(f, "x q[%u];\n", 6);
      }
      if (c1 <= 1) {
        for (int c7 = 0; c7 <= -c1 + 1; c7 += 1) {
          fprintf(f, "x q[%u];\n", -5 * c1 + c7 + 9);
        }
        if (c1 == 0) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            for (int c9 = 0; c9 <= -c7 + 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", -2 * c7 + c9 + 9);
            }
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", c7 + 9);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 + 7, 5 * c7 + 6);
          }
          for (int c9 = -1; c9 <= 0; c9 += 1) {
            fprintf(f, "x q[%u];\n", -5 * c9 + 6);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", c7 + 9);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -6 * c7 + 18, 6 * c7 + 5);
          }
          fprintf(f, "x q[%u];\n", 10);
          for (int c5 = 5; c5 <= 9; c5 += 1) {
            if (c5 == 8) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 7, 7 * c7 + 11);
              }
            } else if (c5 == 6) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c7 + 7, 7 * c7 + 11);
              }
            } else {
              if (c5 >= 7 && (c5 + 1) % 2 == 0) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", ((5 * c5 - 31) / 2) + 11 * c7);
                }
              }
              for (int c7 = 0; c7 <= (-c5 + 7) / 2; c7 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c5 + 2 * c7 - 10);
              }
            }
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c7 + 9, 17 * c7 + 2);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 17 * c7 + 2);
          }
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c7 + 2);
          }
          for (int c5 = 12; c5 <= 17; c5 += 5) {
            fprintf(f, "x q[%u];\n", (7 * c5 - 74) / 5);
          }
        }
      }
      if (c1 % 2 == 0) {
        if (c1 == 0) {
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c7 + 10);
          }
        }
        if (c1 == 2) {
          fprintf(f, "x q[%u];\n", 2);
        } else {
          for (int c5 = 2; c5 <= 7; c5 += 5) {
            fprintf(f, "x q[%u];\n", (8 * c5 + 34) / 5);
            if (c5 == 2) {
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 + 9, 5 * c7 + 10);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c7 + 9);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c7 + 9);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c7 + 9);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                fprintf(f, "x q[%u];\n", c7 + 9);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 12, 11);
            }
          }
        }
        if (c1 == 2) {
          fprintf(f, "x q[%u];\n", 0);
          for (int c7 = 0; c7 <= 1; c7 += 1) {
            for (int c8 = 0; c8 <= c7; c8 += 1) {
              fprintf(f, "x q[%u];\n", -6 * c7 + 15 * c8 + 6);
            }
          }
          fprintf(f, "x q[%u];\n", 17);
        }
        if (c1 == 2) {
          fprintf(f, "x q[%u];\n", 2);
        }
      }
    }
    if (c1 == 3) {
      for (int c4 = 0; c4 <= 3; c4 += 1) {
        fprintf(f, "x q[%u];\n", 11);
      }
    } else if (c1 == 0) {
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "x q[%u];\n", 5 * c4 + 9);
      }
    }
  }
  fprintf(f, "x q[%u];\n", 1);
}
fclose(f);
return 0;
}