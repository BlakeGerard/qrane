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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.0D1_.5D2_6.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    if (c1 == 0) {
      for (int c2 = 0; c2 <= 52; c2 += 1) {
        if (c2 >= 24 && c2 <= 25) {
          fprintf(f, "cx q[%u], q[%u];\n", 7 * c2 - 165, 5 * c2 - 116);
        } else {
          if (c2 == 34) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 1, 2 * c4 + 16);
            }
          }
          if (c2 >= 34 && c2 <= 35) {
            fprintf(f, "cx q[%u], q[%u];\n", 12 * c2 - 408, -7 * c2 + 255);
          }
        }
        if (c2 >= 25 && c2 <= 26) {
          fprintf(f, "cx q[%u], q[%u];\n", 15 * c2 - 373, 18 * c2 - 449);
          fprintf(f, "cx q[%u], q[%u];\n", 6 * c2 - 144, 7 * c2 - 172);
        } else {
          if (c2 == 21) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 12, 2 * c4);
            }
          } else if (c2 == 5) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -c4 + 18, 18 * c4 + 1);
            }
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -12 * c4 + 15, 4 * c4);
            }
          } else if (c2 == 3) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 9 * c4 + 1, 4 * c4 + 5);
            }
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 18, 15 * c4 + 2);
            }
          } else {
            if (c2 >= 41 && (c2 + 4) % 9 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 9, 10 * c4 + 2);
              }
            }
            if (c2 >= 50 && c2 <= 51) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c2 + 267, -6 * c2 + 316);
            } else {
              if ((c2 - 12) % 28 == 0) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", ((-c2 + 516) / 28) - 5 * c4, ((-c2 + 68) / 28) + 9 * c4);
                }
                if (c2 == 40) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 11 * c4, 11 * c4 + 7);
                  }
                }
              } else if (c2 >= 19 && c2 <= 35 && (c2 - 3) % 16 == 0) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", ((c2 + 17) / 4) + 3 * c4, ((9 * c2 - 139) / 16) + 8 * c4);
                }
                if (c2 == 19) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 14 * c4 + 1, 12 * c4 + 5);
                  }
                }
              } else if (c2 >= 31 && c2 <= 33 && (c2 + 1) % 2 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", (-11 * c2 + 373) / 2, (-15 * c2 + 503) / 2);
              } else if (c2 >= 37 && c2 <= 42 && (c2 - 2) % 5 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", -c2 + 47, (8 * c2 - 266) / 5);
                if (c2 == 37) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 3, 14 * c4 + 4);
                  }
                }
              } else if (c2 == 34) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 9, 8 * c4 + 2);
                }
              }
              if (c2 <= 12 && c2 % 12 == 0) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 7 * c4 + 3, 5 * c4 + 4);
                }
              } else {
                if (c2 >= 24 && c2 <= 27 && c2 % 3 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", (8 * c2 / 3) - 63, (-13 * c2 / 3) + 123);
                }
                if (c2 <= 27 && (c2 + 5) % 16 == 0) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", ((-c2 + 187) / 16) - 10 * c4, ((c2 - 11) / 8) + 16 * c4);
                  }
                }
                if (c2 >= 27 && c2 <= 30 && c2 % 3 == 0) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3 * c2 + 3 * c4 - 80, -c2 + 9 * c4 + 32);
                  }
                  if (c2 == 30) {
                    for (int c4 = 0; c4 <= 1; c4 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 3, 3 * c4 + 14);
                    }
                  }
                } else if (c2 <= 23 && (c2 - 7) % 16 == 0) {
                  for (int c4 = 0; c4 <= 1; c4 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", ((c2 + 73) / 16) + 2 * c4, ((-c2 + 71) / 16) + 13 * c4);
                  }
                  if (c2 == 7) {
                    for (int c4 = 0; c4 <= 1; c4 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -5 * c4 + 13, 5 * c4 + 11);
                    }
                  }
                } else {
                  if (c2 >= 29 && (c2 + 3) % 16 == 0) {
                    for (int c4 = 0; c4 <= 1; c4 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", ((-5 * c2 + 297) / 8) - 8 * c4, ((-c2 + 61) / 8) + 14 * c4);
                    }
                  } else if (c2 >= 31 && c2 <= 34 && (c2 - 1) % 3 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", (-7 * c2 + 253) / 3, -2 * c2 + 72);
                  }
                  if (c2 >= 29 && c2 <= 31 && (c2 + 1) % 2 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", 2 * c2 - 56, -c2 + 34);
                    if (c2 == 31) {
                      for (int c4 = 0; c4 <= 1; c4 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 13, 3 * c4 + 15);
                      }
                    }
                  } else if (c2 == 22) {
                    for (int c4 = 0; c4 <= 1; c4 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 18, 8 * c4 + 1);
                    }
                  } else {
                    if ((c2 - 8) % 27 == 0) {
                      for (int c4 = 0; c4 <= 1; c4 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", ((-7 * c2 + 299) / 27) - 2 * c4, ((-c2 + 170) / 27) + 2 * c4);
                      }
                    }
                    if (c2 >= 8 && c2 <= 9) {
                      fprintf(f, "cx q[%u], q[%u];\n", -7 * c2 + 73, 8 * c2 - 63);
                    } else {
                      if (c2 == 16) {
                        for (int c4 = 0; c4 <= 1; c4 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -16 * c4 + 18, c4 + 5);
                        }
                      }
                      if (c2 >= 15 && c2 <= 16) {
                        fprintf(f, "cx q[%u], q[%u];\n", -18 * c2 + 288, 5 * c2 - 73);
                      } else {
                        if (c2 == 43) {
                          for (int c4 = 0; c4 <= 1; c4 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", 12 * c4, 3 * c4 + 7);
                          }
                        }
                        if (c2 >= 43 && c2 <= 44) {
                          fprintf(f, "cx q[%u], q[%u];\n", 12 * c2 - 515, -c2 + 59);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if (c2 >= 20 && c2 <= 21) {
            fprintf(f, "cx q[%u], q[%u];\n", 9 * c2 - 179, -13 * c2 + 279);
            if (c2 == 20) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 12, 6 * c4);
              }
            }
          } else {
            if (c2 == 49) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 5, 12 * c4 + 3);
              }
            } else if (c2 == 46) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 17, 17 * c4 + 1);
              }
            } else if (c2 == 28) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 10, 11 * c4 + 6);
              }
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", c4 + 18, 3 * c4 + 1);
              }
            } else if (c2 == 15) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", c4 + 12, 11 * c4);
              }
            } else if (c2 == 11) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c4 + 6, 11 * c4 + 3);
              }
            } else if (c2 == 9) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c4 + 6, 13 * c4 + 3);
              }
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c4 + 7, c4 + 17);
              }
            } else if (c2 == 6) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 13, c4 + 15);
              }
            } else if (c2 == 4) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 15, 5 * c4);
              }
            } else if (c2 == 2) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c4 + 9, 5 * c4 + 2);
              }
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c4 + 1, 13 * c4 + 5);
              }
            } else if (c2 >= 32 && c2 % 16 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 11 * c4 + 2, (-c2 / 4) + 10 * c4 + 13);
              }
              if (c2 == 32) {
                for (int c4 = 0; c4 <= 1; c4 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -11 * c4 + 12, 16 * c4);
                }
              }
            } else if (c2 == 29) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c4 + 6, 14 * c4 + 3);
              }
            }
            if (c2 == 13) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 13, 5 * c4 + 11);
              }
            } else if (c2 <= 10 && (c2 - 1) % 9 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((-17 * c2 + 170) / 9) + c4, ((17 * c2 - 8) / 9) + c4);
              }
            }
          }
        }
        if (c2 >= 25 && (c2 - 1) % 24 == 0) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", ((-3 * c2 + 219) / 8) - c4, ((-c2 + 65) / 8) + 14 * c4);
          }
        } else {
          if ((c2 + 2) % 19 == 0) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 2 * c4 + 5, 4 * c4 + 4);
            }
          } else if (c2 <= 21 && (c2 - 4) % 17 == 0) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 9 * c4 + 8, 3 * c4 + 16);
            }
          } else {
            if (c2 >= 38 && c2 <= 43 && (c2 + 2) % 5 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", -c2 + 47, (8 * c2 - 274) / 5);
            }
            if ((c2 + 2) % 20 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((-3 * c2 + 234) / 10) - 9 * c4, ((-c2 + 38) / 10) + 4 * c4);
              }
            } else if (c2 <= 14 && (c2 + 2) % 8 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", ((9 * c2 - 6) / 8) - 2 * c4, ((-3 * c2 + 42) / 8) + 11 * c4);
              }
            } else {
              if (c2 >= 24 && c2 <= 26 && c2 % 2 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", (9 * c2 / 2) - 108, (-11 * c2 / 2) + 149);
              }
              if (c2 >= 23 && c2 <= 24) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c2 + 226, 2 * c2 - 42);
              }
            }
          }
          if (c2 >= 17 && c2 <= 18) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c2 + 131, -14 * c2 + 256);
          } else if (c2 == 52) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c4 + 12, 9 * c4 + 10);
            }
          } else if (c2 == 51) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 15 * c4 + 2, 13 * c4 + 6);
            }
          } else if (c2 == 47) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c4 + 17, 4 * c4 + 1);
            }
          } else if (c2 == 44) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -17 * c4 + 18, 17 * c4 + 2);
            }
          } else if (c2 == 43) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 13 * c4 + 2, 11 * c4 + 6);
            }
          } else if (c2 == 42) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 9, 12 * c4 + 6);
            }
          } else if (c2 == 41) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -18 * c4 + 18, 2 * c4 + 5);
            }
          } else {
            if (c2 == 39) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 2, 3 * c4 + 6);
              }
            } else if (c2 == 33) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -2 * c4 + 12, 9 * c4);
              }
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -10 * c4 + 18, 15 * c4 + 1);
              }
            } else if (c2 == 26) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 18, 12 * c4 + 2);
              }
            } else if (c2 == 23) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 2, 13 * c4 + 1);
              }
            } else if (c2 == 22) {
              for (int c4 = 0; c4 <= 2; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 3, 4 * c4 + 4);
              }
            } else if (c2 == 21) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8 * c4 + 5, c4 + 14);
              }
            } else if (c2 == 13) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", c4, c4 + 18);
              }
            } else if (c2 == 1) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 12, 4 * c4 + 10);
              }
            } else if (c2 <= 20 && (c2 - 2) % 18 == 0) {
              for (int c4 = 0; c4 <= 1; c4 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c4 + 10, ((-2 * c2 + 58) / 9) + 9 * c4);
              }
            } else if (c2 >= 8 && c2 <= 10 && c2 % 2 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", (5 * c2 / 2) - 20, (-15 * c2 / 2) + 78);
            }
            if (c2 >= 36 && c2 <= 39 && c2 % 3 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", (c2 / 3) - 2, -2 * c2 + 78);
            }
          }
        }
      }
    }
    for (int c4 = 0; c4 <= 1; c4 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -7 * c1 - 7 * c4 + 19, -4 * c1 + 14 * c4 + 4);
    }
    if (c1 == 0) {
      for (int c2 = 54; c2 <= 56; c2 += 1) {
        if (c2 == 56) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c4 + 9, 5 * c4 + 6);
          }
        } else if (c2 == 55) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -12 * c4 + 13, 8 * c4 + 11);
          }
        } else {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 12 * c4 + 4, 5 * c4 + 14);
          }
        }
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 5 * c1 + 10, 15 * c1 + 2);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 2 * c1 + 11, 3 * c1 + 12);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -5 * c1 + 5, 3 * c1 + 4);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -2 * c1 + 2, 16 * c1 + 1);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 7 * c1 + 5, 7 * c1 + 3);
  }
}
fclose(f);
return 0;
}