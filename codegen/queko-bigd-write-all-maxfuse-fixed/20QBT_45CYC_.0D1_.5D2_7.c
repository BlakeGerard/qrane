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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.0D1_.5D2_7.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -7 * c1 + 13, 4 * c1 + 7);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -2 * c1 + 5, 6 * c1 + 6);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c1 + 18, 4 * c1 + 12);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -c1 + 15, 7 * c1 + 9);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 13 * c1 + 2, 9 * c1 + 1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 2 * c1 + 9, 7 * c1 + 1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    for (int c2 = c1; c2 <= -16 * c1 + 33; c2 += 1) {
      if (c1 == 1 && c2 >= 14 && c2 <= 15) {
        fprintf(f, "cx q[%u], q[%u];\n", -14 * c2 + 215, -10 * c2 + 156);
      } else if (c1 == 0 && c2 == 29) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 8 * c4, 6 * c4 + 12);
        }
      } else if (c1 == 1 && c2 == 13) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 4, 3 * c4 + 13);
        }
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 9, 4 * c4 + 1);
        }
      }
      if (c1 == 1 && c2 >= 14 && c2 % 2 == 0) {
        fprintf(f, "cx q[%u], q[%u];\n", -3 * c2 + 56, 8 * c2 - 110);
      }
      if (c2 == 7 * c1 + 9) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 13 * c1 + 6 * c4, -5 * c1 + 7 * c4 + 12);
        }
      } else {
        if (c1 == 1 && c2 <= 2) {
          fprintf(f, "cx q[%u], q[%u];\n", 15 * c2 - 13, -3 * c2 + 21);
        }
        if (32 * c1 + c2 == 33) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 11, 2 * c4 + 8);
          }
        } else {
          if (c1 == 1 && c2 >= 8 && c2 <= 9) {
            fprintf(f, "cx q[%u], q[%u];\n", 2 * c2 - 16, 6 * c2 - 36);
            if (c2 == 8) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -17 * c4 + 18, 4 * c4 + 3);
              }
            }
          } else if (c1 == 0 && c2 >= 27 && c2 <= 28) {
            fprintf(f, "cx q[%u], q[%u];\n", 8 * c2 - 214, -9 * c2 + 261);
            if (c2 == 27) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 11, 5 * c4 + 9);
              }
            }
          } else {
            if (c1 == 0 && c2 >= 22 && c2 <= 23) {
              fprintf(f, "cx q[%u], q[%u];\n", 9 * c2 - 197, 2 * c2 - 37);
            }
            if (c1 == 0 && c2 >= 22 && c2 <= 26 && (c2 + 2) % 4 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c2 - c4 + 84, -c2 + 3 * c4 + 34);
              }
              if (c2 == 22) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 10, 2 * c4 + 9);
                }
              }
            } else if (c1 == 0 && c2 == 17) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -18 * c4 + 19, 11 * c4 + 2);
              }
            } else if (c1 == 0 && c2 == 13) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 9, 7 * c4 + 7);
              }
            }
          }
          if (16 * c1 + c2 == 24) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 11 * c4 + 8, 12 * c4 + 2);
            }
          } else if (c1 + c2 == 8) {
            for (int c4 = 0; c4 <= -c1 + 2; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c4 + 8, 5 * c4 + 2);
            }
          } else if (c2 == 8 * c1 + 2) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -4 * c1 - c4 + 5, -c1 + 5 * c4 + 8);
            }
            if (c1 == 1) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 14, 3 * c4 + 16);
              }
            }
          } else {
            if (c1 == 0 && c2 == 1) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c4 + 11, c4 + 8);
              }
            } else if (c1 == 0 && c2 <= 5 && c2 % 5 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", (13 * c2 / 5) + 2 * c4, -c2 + 4 * c4 + 12);
              }
            }
            if (c1 == 0 && c2 <= 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 8, 11 * c2 + 1);
              if (c2 == 1) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 16, 2 * c4);
                }
              }
            } else {
              if (c1 == 1 && c2 >= 11 && c2 <= 12) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c2 + 113, -10 * c2 + 126);
              } else if (c1 == 0 && c2 >= 19 && c2 <= 20) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c2 - 147, -4 * c2 + 87);
                if (c2 == 19) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 8, 12 * c4 + 1);
                  }
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -7 * c4 + 16, 7 * c4);
                  }
                }
              } else {
                if (c1 == 0 && c2 == 31) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9 * c4 + 2, 7 * c4 + 1);
                  }
                }
                if (c1 == 1 && c2 == 15) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 16, 12 * c4);
                  }
                } else {
                  if (c1 == 0 && c2 == 15) {
                    for (int c4 = 0; c4 <= 1; c4 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 16, 8 * c4);
                    }
                  }
                  if (c1 == 0 && c2 >= 14 && c2 <= 15) {
                    fprintf(f, "cx q[%u], q[%u];\n", 8 * c2 - 103, 2 * c2 - 15);
                  }
                }
                if (c2 == 15) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 14, 11 * c4 + 2);
                  }
                } else if (2 * c1 + c2 == 11) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 14, 3 * c4 + 16);
                  }
                } else if (c1 == 0 && c2 == 32) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 6 * c4 + 5, 2 * c4 + 8);
                  }
                } else if (c1 == 0 && c2 == 28) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 14, 10 * c4 + 2);
                  }
                } else if (c1 == 0 && c2 == 21) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 11, 4 * c4 + 9);
                  }
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 19, 13 * c4 + 2);
                  }
                } else if (c1 == 0 && c2 == 18) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 11, 6 * c4 + 10);
                  }
                } else if (c1 == 1 && c2 == 17) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 14, 3 * c4 + 2);
                  }
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 6 * c4 + 13, 9 * c4 + 7);
                  }
                } else if (c1 == 0 && c2 == 16) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -c4 + 10, 9 * c4 + 4);
                  }
                } else if (c1 == 1 && c2 == 14) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -16 * c4 + 17, 13 * c4 + 5);
                  }
                } else if (c1 == 0 && c2 == 14) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 18, 8 * c4 + 3);
                  }
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 8, 10 * c4 + 2);
                  }
                } else if (c1 == 0 && c2 == 13) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 18, 13 * c4);
                  }
                }
              }
              if (c1 == 0 && c2 <= 10 && (c2 + 2) % 6 == 0) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", ((2 * c2 + 19) / 3) + 6 * c4, c2 + 9 * c4 - 3);
                }
              } else {
                if (c1 == 0 && c2 >= 23 && c2 <= 25 && (c2 + 1) % 2 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c2 + 65, -2 * c2 + 60);
                  if (c2 == 25) {
                    for (int c4 = 0; c4 <= 1; c4 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 19, 6 * c4 + 2);
                    }
                  }
                } else if (c1 == 0 && c2 == 17) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 17, 13 * c4 + 5);
                  }
                } else if (c1 == 1 && c2 == 12) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 9, 5 * c4 + 7);
                  }
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 18 * c4 + 1, c4 + 13);
                  }
                }
                if (c1 == 0 && c2 >= 23 && (c2 - 2) % 7 == 0) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 5, 4 * c4 + 8);
                  }
                }
                if (c1 == 0 && c2 >= 20 && c2 <= 23 && (c2 + 1) % 3 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", (-4 * c2 + 131) / 3, (2 * c2 - 25) / 3);
                }
              }
              if (c1 == 0 && c2 >= 10 && c2 <= 12 && c2 % 2 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c2 + 41, -2 * c2 + 30);
                if (c2 == 12) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 2 * c4, 4 * c4 + 12);
                  }
                }
              } else if (c1 == 1 && c2 == 11) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 4, 6 * c4 + 13);
                }
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 9 * c4, 4 * c4 + 3);
                }
              }
            }
            if (c1 == 0 && c2 == 10) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -17 * c4 + 17, 7 * c4 + 5);
              }
            } else if (c1 == 1 && c2 == 6) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c4, 15 * c4 + 3);
              }
            } else if (c1 == 1 && c2 == 5) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -17 * c4 + 18, 10 * c4 + 3);
              }
            } else if (c1 == 1 && c2 == 3) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 13 * c4 + 5, c4 + 11);
              }
            } else if (c1 == 0 && c2 <= 18 && (c2 + 4) % 11 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 18, ((-12 * c2 + 216) / 11) + c4);
              }
              if (c2 == 18) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 17, 8 * c4 + 5);
                }
              }
            } else if (c1 == 0 && c2 >= 15 && c2 <= 17 && (c2 + 1) % 2 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 85, -3 * c2 + 54);
            }
          }
        }
      }
      if (c1 == 0 && c2 >= 9 && c2 <= 11 && (c2 + 1) % 2 == 0) {
        fprintf(f, "cx q[%u], q[%u];\n", (-11 * c2 + 127) / 2, -2 * c2 + 34);
        if (c2 == 11) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 18, 11 * c4);
          }
        }
      } else if (c1 == 1 && c2 == 4) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -12 * c4 + 18, 16 * c4 + 3);
        }
      } else if (c1 == 1 && c2 == 2) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 18, 11 * c4);
        }
      } else if (c1 == 1 && c2 >= 7 && c2 <= 9 && (c2 + 1) % 2 == 0) {
        fprintf(f, "cx q[%u], q[%u];\n", (11 * c2 - 77) / 2, (5 * c2 - 29) / 2);
        if (c2 == 9) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 9, 11 * c4 + 1);
          }
        }
      } else if (c1 == 0 && c2 == 5) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 10, 8 * c4 + 4);
        }
      } else if (c1 == 0 && c2 == 3) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 5, 5 * c4 + 8);
        }
      } else if (c1 == 0 && c2 >= 20 && c2 <= 24 && c2 % 4 == 0) {
        fprintf(f, "cx q[%u], q[%u];\n", 2 * c2 - 38, (-7 * c2 / 2) + 88);
        if (c2 == 24) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 17 * c4, 12 * c4 + 3);
          }
        } else {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 6 * c4, 8 * c4 + 3);
          }
        }
      } else if (c1 == 0 && c2 == 16) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -14 * c4 + 14, c4 + 2);
        }
      } else if (c1 == 0 && c2 == 6) {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 7, 10 * c4 + 3);
        }
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 12 * c4 + 5, 4 * c4 + 11);
        }
      }
    }
    if (c1 == 1) {
      for (int c2 = 18; c2 <= 20; c2 += 1) {
        if (c2 == 20) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c4 + 5, 3 * c4 + 6);
          }
        } else if (c2 == 19) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c4 + 10, 15 * c4 + 4);
          }
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -15 * c4 + 16, 18 * c4);
          }
        } else {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 1, 6 * c4 + 7);
          }
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", c4 + 14, 7 * c4 + 2);
          }
        }
      }
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 9, 7 * c4 + 7);
      }
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 17 * c4, 2 * c4 + 3);
      }
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 17, 13 * c4 + 5);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -10 * c1 + 11, 3 * c1 + 10);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 16 * c1 + 2, 2 * c1 + 1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 10 * c1 + 5, 2 * c1 + 8);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c1 + 13, 9 * c1 + 7);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 6 * c1 + 11, 7 * c1 + 8);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 5 * c1 + 1, 12 * c1 + 7);
  }
}
fclose(f);
return 0;
}