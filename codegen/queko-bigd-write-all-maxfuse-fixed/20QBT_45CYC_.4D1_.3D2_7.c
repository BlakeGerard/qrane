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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.4D1_.3D2_7.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -10 * c1 + 13, 5 * c1 + 10);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    if (c1 == 1) {
      for (int c12 = 0; c12 <= 1; c12 += 1) {
        fprintf(f, "x q[%u];\n", 9 * c12 + 4);
      }
      fprintf(f, "x q[%u];\n", 4);
    } else {
      for (int c2 = -8; c2 <= 159; c2 += 1) {
        if (c2 >= 59 && c2 <= 99) {
          if (c2 == 59) {
            fprintf(f, "x q[%u];\n", 13);
            fprintf(f, "cx q[%u], q[%u];\n", 13, 17);
            for (int c5 = 1; c5 <= 2; c5 += 1) {
              fprintf(f, "x q[%u];\n", 17);
            }
          }
          if ((c2 - 19) % 40 == 0) {
            if (c2 == 99) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c12 + 11);
              }
            }
            if (c2 == 99) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                if (c5 == 1) {
                  fprintf(f, "x q[%u];\n", 11);
                  fprintf(f, "x q[%u];\n", 11);
                  fprintf(f, "x q[%u];\n", 11);
                } else {
                  fprintf(f, "x q[%u];\n", 4);
                  fprintf(f, "x q[%u];\n", 4);
                  fprintf(f, "x q[%u];\n", 4);
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 11);
                }
              }
            } else {
              fprintf(f, "x q[%u];\n", 12);
              fprintf(f, "x q[%u];\n", 10);
              fprintf(f, "cx q[%u], q[%u];\n", 13, 10);
              fprintf(f, "x q[%u];\n", 12);
            }
            for (int c5 = (c2 - 19) / 40; c5 <= (c2 + 21) / 40; c5 += 1) {
              if (c2 == 59) {
                if (c5 == 2) {
                  fprintf(f, "x q[%u];\n", 19);
                } else {
                  fprintf(f, "x q[%u];\n", 10);
                }
              } else if (c5 == 2) {
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 2);
                fprintf(f, "cx q[%u], q[%u];\n", 9, 2);
                fprintf(f, "cx q[%u], q[%u];\n", 7, 2);
                fprintf(f, "cx q[%u], q[%u];\n", 14, 7);
                fprintf(f, "cx q[%u], q[%u];\n", 9, 0);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 10 * c12 + 9, 16 * c12 + 2);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c12 + 2);
                }
              }
              if (c2 == 59) {
                for (int c10 = -1; c10 <= -19 * c5 + 37; c10 += 1) {
                  if (c10 == -1) {
                    fprintf(f, "x q[%u];\n", -3 * c5 + 15);
                  } else if (c10 == 18) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 7 * c12 + 2, 4 * c12 + 12);
                    }
                  } else if (c10 == 17) {
                    fprintf(f, "x q[%u];\n", 9);
                  } else if (c10 == 13) {
                    fprintf(f, "cx q[%u], q[%u];\n", 10, 17);
                  } else if (c10 == 12) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c12 + 6);
                    }
                  } else if (c10 == 11) {
                    fprintf(f, "x q[%u];\n", 6);
                  } else if (c10 == 10) {
                    fprintf(f, "cx q[%u], q[%u];\n", 11, 6);
                  } else if (c10 == 9) {
                    fprintf(f, "x q[%u];\n", 11);
                  } else if (c10 == 8) {
                    fprintf(f, "x q[%u];\n", 11);
                  }
                }
              }
              if (c2 == 59 && c5 == 2) {
                fprintf(f, "x q[%u];\n", 13);
              }
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", ((7 * c2 - 333) / 40) + 10 * c12);
              }
              if (c2 == 59 && c5 == 2) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c12 + 9);
                }
              }
              if (c2 == 59) {
                for (int c10 = -19 * c5 + 39; c10 <= -19 * c5 + 42; c10 += 1) {
                  if (c5 == 2 && c10 == 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 2);
                  }
                  if (c5 == 2 && c10 <= 3) {
                    fprintf(f, "x q[%u];\n", -2 * c10 + 15);
                    if (c10 >= 2) {
                      fprintf(f, "cx q[%u], q[%u];\n", 11 * c10 - 20, 7 * c10 - 4);
                    }
                    if (c10 <= 2) {
                      fprintf(f, "x q[%u];\n", -2 * c10 + 13);
                    }
                    if (c10 == 3) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c12 + 2);
                      }
                    } else if (c10 == 2) {
                      fprintf(f, "x q[%u];\n", 13);
                    }
                  } else if (c5 == 1 && c10 == 23) {
                    fprintf(f, "x q[%u];\n", 9);
                  } else if (c5 == 1 && c10 == 22) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 16);
                  } else if (c5 == 2 && c10 == 4) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c12 + 2);
                    }
                  }
                }
                if (c5 == 2) {
                  for (int c10 = 5; c10 <= 17; c10 += 1) {
                    if (c10 == 17) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 15 * c12 + 3);
                      }
                    } else if (c10 == 14) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 16 * c12);
                      }
                    } else if (c10 == 13) {
                      fprintf(f, "cx q[%u], q[%u];\n", 0, 16);
                    } else if (c10 == 9) {
                      fprintf(f, "x q[%u];\n", 12);
                    } else if (c10 == 7) {
                      fprintf(f, "x q[%u];\n", 2);
                    } else if (c10 == 6) {
                      fprintf(f, "x q[%u];\n", 9);
                      fprintf(f, "cx q[%u], q[%u];\n", 7, 2);
                    } else if (c10 == 5) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c12 + 2);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 7, 9);
                    }
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 19, 18);
                  fprintf(f, "cx q[%u], q[%u];\n", 3, 1);
                  for (int c10 = 19; c10 <= 20; c10 += 1) {
                    if (c10 == 20) {
                      fprintf(f, "x q[%u];\n", 19);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 16 * c12);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 3, 1);
                    } else {
                      fprintf(f, "x q[%u];\n", 19);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -3 * c12 + 3, 15 * c12 + 1);
                      }
                      fprintf(f, "x q[%u];\n", 18);
                    }
                  }
                }
              }
              if (c2 == 59 && c5 == 2) {
                fprintf(f, "x q[%u];\n", 19);
              }
              if (c2 == 99 && c5 == 2) {
                fprintf(f, "cx q[%u], q[%u];\n", 7, 2);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -11 * c12 + 14, 11 * c12 + 7);
                }
                fprintf(f, "x q[%u];\n", 7);
              } else if (c2 == 59 && c5 == 2) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c12 + 1);
                }
              }
            }
            if (c2 == 59) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 16 * c12);
              }
              fprintf(f, "x q[%u];\n", 0);
              fprintf(f, "cx q[%u], q[%u];\n", 0, 16);
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c12 + 16, 5 * c12 + 12);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 12, 19);
              fprintf(f, "x q[%u];\n", 19);
            }
            if (c2 == 99) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 15 * c12 + 3);
              }
              for (int c10 = 7; c10 <= 15; c10 += 1) {
                if (c10 == 12) {
                  fprintf(f, "cx q[%u], q[%u];\n", 4, 5);
                } else if (c10 == 11) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", c12 + 4);
                  }
                } else if (c10 == 10) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", c12 + 4);
                  }
                } else if (c10 == 9) {
                  fprintf(f, "x q[%u];\n", 4);
                } else if (c10 == 8) {
                  fprintf(f, "cx q[%u], q[%u];\n", 4, 5);
                } else if ((c10 + 1) % 8 == 0) {
                  fprintf(f, "x q[%u];\n", (-c10 + 47) / 8);
                }
              }
            } else {
              fprintf(f, "x q[%u];\n", 16);
            }
          }
          if (c2 == 80) {
            for (int c8 = 0; c8 <= 1; c8 += 1) {
              fprintf(f, "x q[%u];\n", c8 + 4);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 5, 9);
            fprintf(f, "x q[%u];\n", 5);
            fprintf(f, "x q[%u];\n", 17);
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", c12 + 16);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 7, 9);
            fprintf(f, "x q[%u];\n", 16);
            fprintf(f, "cx q[%u], q[%u];\n", 9, 16);
            fprintf(f, "x q[%u];\n", 16);
          } else if (c2 == 62) {
            fprintf(f, "cx q[%u], q[%u];\n", 4, 5);
            for (int c8 = 0; c8 <= 1; c8 += 1) {
              fprintf(f, "x q[%u];\n", c8 + 4);
            }
          }
          if (c2 <= 81 && (c2 + 9) % 18 == 0) {
            if (c2 == 81) {
              fprintf(f, "x q[%u];\n", 12);
            } else {
              fprintf(f, "x q[%u];\n", 11);
              fprintf(f, "x q[%u];\n", 13);
            }
            if (c2 == 81) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c5 + 15, 18 * c5 + 1);
              }
            } else {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 2, 3 * c5 + 10);
              }
            }
          }
        } else {
          if (c2 == 159) {
            fprintf(f, "x q[%u];\n", 19);
            fprintf(f, "x q[%u];\n", 19);
          } else if (c2 == 107) {
            fprintf(f, "x q[%u];\n", 19);
            fprintf(f, "x q[%u];\n", 16);
            for (int c8 = 0; c8 <= 1; c8 += 1) {
              fprintf(f, "x q[%u];\n", -6 * c8 + 16);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 16, 19);
            for (int c6 = -1; c6 <= 0; c6 += 1) {
              if (c6 == 0) {
                fprintf(f, "x q[%u];\n", 2);
                fprintf(f, "x q[%u];\n", 9);
                fprintf(f, "cx q[%u], q[%u];\n", 9, 2);
                fprintf(f, "cx q[%u], q[%u];\n", 14, 9);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", c12 + 1);
                }
                fprintf(f, "x q[%u];\n", 9);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", c12 + 1);
                }
              }
              for (int c10 = -c6 + 9; c10 <= c6 + 11; c10 += 1) {
                if (c10 == 10) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c6 + 15, -18 * c6 + 1);
                } else {
                  fprintf(f, "x q[%u];\n", (-13 * c10 + 145) / 2);
                }
              }
              if (c6 == -1) {
                fprintf(f, "x q[%u];\n", 16);
              }
            }
            fprintf(f, "x q[%u];\n", 14);
          }
          if (c2 == 55) {
            for (int c5 = 1; c5 <= 2; c5 += 1) {
              fprintf(f, "x q[%u];\n", 6);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 11, 6);
            fprintf(f, "x q[%u];\n", 6);
          } else if (c2 == 51) {
            fprintf(f, "x q[%u];\n", 5);
            fprintf(f, "x q[%u];\n", 5);
            fprintf(f, "x q[%u];\n", 5);
            fprintf(f, "x q[%u];\n", 5);
            fprintf(f, "cx q[%u], q[%u];\n", 5, 16);
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", 11 * c12 + 5);
            }
            for (int c5 = 2; c5 <= 3; c5 += 1) {
              if (c5 == 3) {
                fprintf(f, "x q[%u];\n", 14);
              }
              fprintf(f, "x q[%u];\n", 17 * c5 - 32);
              if (c5 == 3) {
                fprintf(f, "cx q[%u], q[%u];\n", 16, 19);
              }
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c5 + 29, 6 * c5 - 2);
              fprintf(f, "cx q[%u], q[%u];\n", 2 * c5 + 10, 17 * c5 - 32);
              if (c5 == 2) {
                fprintf(f, "cx q[%u], q[%u];\n", 7, 13);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 10 * c12 + 7, 13 * c12 + 2);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c12 + 7);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c12 + 7);
                }
              }
              for (int c10 = -c5 + 13; c10 <= c5 + 9; c10 += 1) {
                if (c5 == 3 && c10 >= 11) {
                  fprintf(f, "x q[%u];\n", 5 * c10 - 50);
                }
                if (c5 == 3 && c10 <= 11) {
                  fprintf(f, "x q[%u];\n", 5 * c10 - 45);
                }
                if (c10 >= 11) {
                  fprintf(f, "x q[%u];\n", 5 * c5 - 5 * c10 + 59);
                }
              }
              if (c5 == 2) {
                fprintf(f, "cx q[%u], q[%u];\n", 14, 7);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c12 + 7);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c12 + 7);
                }
                fprintf(f, "x q[%u];\n", 5);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c12 + 7);
                }
              }
            }
          } else if (c2 == 33) {
            for (int c6 = -1; c6 <= 0; c6 += 1) {
              if (c6 == 0) {
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -7 * c8 + 15, 16 * c8 + 1);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 16 * c12 + 1);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c12 + 8);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 17, 15);
              }
              for (int c8 = -c6; c8 <= 1; c8 += 1) {
                if (c8 == 1) {
                  fprintf(f, "x q[%u];\n", -4 * c6 + 11);
                  if (c6 == 0) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -18 * c12 + 18, 10 * c12 + 1);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", c12);
                    }
                    for (int c10 = 13; c10 <= 14; c10 += 1) {
                      fprintf(f, "x q[%u];\n", -11 * c10 + 154);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c12 + 11, 3 * c12 + 6);
                    }
                  }
                }
                if (c6 == 0) {
                  fprintf(f, "x q[%u];\n", -9 * c8 + 15);
                }
              }
            }
            fprintf(f, "x q[%u];\n", 0);
            fprintf(f, "cx q[%u], q[%u];\n", 3, 15);
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c12 + 3);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 3, 18);
          } else if (c2 == 28) {
            fprintf(f, "cx q[%u], q[%u];\n", 10, 3);
            fprintf(f, "x q[%u];\n", 3);
          } else if (c2 == 15) {
            fprintf(f, "x q[%u];\n", 13);
            for (int c10 = 12; c10 <= 13; c10 += 1) {
              fprintf(f, "x q[%u];\n", -11 * c10 + 148);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 9, 16);
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", 7 * c12 + 9);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 7, 9);
            fprintf(f, "cx q[%u], q[%u];\n", 7, 13);
            fprintf(f, "x q[%u];\n", 7);
            fprintf(f, "x q[%u];\n", 7);
          } else if (c2 == 3) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c5 + 4);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 12, 6);
            fprintf(f, "x q[%u];\n", 19);
            for (int c10 = 10; c10 <= 12; c10 += 1) {
              if (c10 >= 11) {
                fprintf(f, "x q[%u];\n", 5 * c10 - 41);
              }
              if (c10 <= 11) {
                fprintf(f, "x q[%u];\n", 5 * c10 - 36);
                if (c10 == 10) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c12 + 4);
                  }
                }
              }
            }
            for (int c5 = 3; c5 <= 4; c5 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c5 - 1);
            }
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", c12 + 18);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
            fprintf(f, "x q[%u];\n", 6);
            fprintf(f, "x q[%u];\n", 6);
          } else if (c2 <= -4 && c2 % 4 == 0) {
            fprintf(f, "x q[%u];\n", -c2 + 4);
          } else if (c2 <= 39 && (c2 - 1) % 38 == 0) {
            for (int c8 = 0; c8 <= (-c2 + 39) / 38; c8 += 1) {
              fprintf(f, "x q[%u];\n", ((-3 * c2 + 117) / 38) + 7 * c8);
            }
            if (c2 == 39) {
              for (int c8 = 0; c8 <= 1; c8 += 1) {
                fprintf(f, "x q[%u];\n", 17 * c8);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 10, 17);
            }
          }
          if (c2 >= 101 && c2 <= 109 && (c2 + 3) % 8 == 0) {
            if (c2 == 101) {
              fprintf(f, "x q[%u];\n", 19);
            }
            fprintf(f, "x q[%u];\n", (11 * c2 - 1095) / 8);
            if (c2 == 109) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c12 + 4);
              }
            }
          } else if (c2 >= 105 && c2 <= 117 && (c2 + 3) % 12 == 0) {
            if (c2 == 117) {
              fprintf(f, "x q[%u];\n", 1);
            }
            if (c2 == 117) {
              fprintf(f, "x q[%u];\n", 5);
            } else {
              for (int c5 = 0; c5 <= 2; c5 += 1) {
                if (c5 == 1) {
                  fprintf(f, "x q[%u];\n", 11);
                  fprintf(f, "x q[%u];\n", 11);
                  fprintf(f, "x q[%u];\n", 5);
                } else {
                  fprintf(f, "x q[%u];\n", -c5 + 7);
                  if (c5 == 0) {
                    fprintf(f, "x q[%u];\n", 7);
                  }
                }
              }
            }
            if (c2 == 117) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c12 + 1);
              }
            }
          } else if (c2 >= 103 && c2 <= 111 && (c2 + 1) % 8 == 0) {
            if (c2 == 111) {
              fprintf(f, "x q[%u];\n", 5);
              fprintf(f, "x q[%u];\n", 7);
            }
            for (int c5 = 0; c5 <= 2; c5 += 1) {
              if (c2 == 111) {
                if (c5 >= 1) {
                  fprintf(f, "x q[%u];\n", 17 * c5 - 17);
                  if (c5 == 1) {
                    fprintf(f, "x q[%u];\n", 15);
                    fprintf(f, "x q[%u];\n", 11);
                  }
                } else {
                  for (int c10 = 4; c10 <= 7; c10 += 3) {
                    if (c10 == 7) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 2 * c12 + 12, c12 + 6);
                      }
                    }
                    fprintf(f, "x q[%u];\n", (-10 * c10 + 76) / 3);
                    if (c10 == 7) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c12 + 6);
                      }
                    } else {
                      fprintf(f, "cx q[%u], q[%u];\n", 7, 2);
                    }
                    fprintf(f, "x q[%u];\n", (-10 * c10 + 76) / 3);
                    if (c10 == 4) {
                      fprintf(f, "cx q[%u], q[%u];\n", 12, 6);
                      fprintf(f, "x q[%u];\n", 2);
                    }
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", c12 + 6);
                  }
                  for (int c10 = 10; c10 <= 11; c10 += 1) {
                    fprintf(f, "x q[%u];\n", -5 * c10 + 62);
                    if (c10 == 10) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", c12 + 6);
                      }
                    }
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c12 + 10);
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 7 * c12 + 5, 10 * c12 + 9);
                  }
                }
                if (c5 <= 1) {
                  for (int c10 = -c5 + 13; c10 <= c5 + 15; c10 += 1) {
                    if (c10 == 15) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c5 + 12, -5 * c5 + 6);
                      if (c5 == 1) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 3 * c12 + 5, c12 + 9);
                        }
                      }
                    } else {
                      if (c10 == 13) {
                        fprintf(f, "cx q[%u], q[%u];\n", -10 * c5 + 10, -c5 + 12);
                      }
                      if (c5 == 1 && c10 == 14) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", c12 + 10);
                        }
                      } else if (c5 == 0 && c10 == 14) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 7 * c12 + 12, 15 * c12 + 3);
                        }
                      } else if (c5 == 1 && c10 % 4 == 0) {
                        fprintf(f, "x q[%u];\n", (5 * c10 / 2) - 30);
                      }
                    }
                  }
                  if (c5 == 0) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -9 * c12 + 12, 12 * c12 + 6);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 15 * c12 + 3);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 15 * c12 + 3);
                    }
                  }
                }
                if (c5 == 0) {
                  fprintf(f, "x q[%u];\n", 2);
                }
              } else if (c5 <= 1) {
                for (int c6 = 0; c6 <= c5; c6 += 1) {
                  if (c5 == 0 && c6 == 0) {
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 13);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "x q[%u];\n", 8);
                    fprintf(f, "cx q[%u], q[%u];\n", 13, 8);
                    fprintf(f, "x q[%u];\n", 8);
                    for (int c10 = 17; c10 <= 18; c10 += 1) {
                      fprintf(f, "x q[%u];\n", -5 * c10 + 98);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 13, 17);
                    fprintf(f, "x q[%u];\n", 17);
                  }
                  for (int c8 = 0; c8 <= c5; c8 += 1) {
                    if (c5 == 0 && c6 == 0 && c8 == 0) {
                      fprintf(f, "x q[%u];\n", 13);
                      for (int c10 = 21; c10 <= 24; c10 += 1) {
                        if (c10 == 24) {
                          fprintf(f, "cx q[%u], q[%u];\n", 17, 15);
                        } else if (c10 == 23) {
                          fprintf(f, "cx q[%u], q[%u];\n", 13, 17);
                        } else if (c10 == 22) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c12 + 13);
                          }
                        } else {
                          fprintf(f, "x q[%u];\n", 13);
                        }
                      }
                    }
                    if (c6 == 0 && c8 == 0) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -11 * c12 + 14, 6 * c12 + 9);
                      }
                      if (c5 == 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 1);
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 12 * c12 + 3);
                        }
                      }
                      if (c5 == 1) {
                        fprintf(f, "x q[%u];\n", 3);
                        fprintf(f, "x q[%u];\n", 18);
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 11 * c12 + 3);
                        }
                        fprintf(f, "x q[%u];\n", 18);
                        fprintf(f, "x q[%u];\n", 17);
                        fprintf(f, "cx q[%u], q[%u];\n", 16, 6);
                        fprintf(f, "x q[%u];\n", 16);
                        fprintf(f, "x q[%u];\n", 17);
                        fprintf(f, "x q[%u];\n", 14);
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -9 * c12 + 12, 12 * c12 + 6);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 8, 10);
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -6 * c12 + 16, 6 * c12 + 6);
                        }
                      }
                    }
                    if (c5 == 1 && c8 == 0) {
                      fprintf(f, "x q[%u];\n", -4 * c6 + 10);
                      if (c6 == 0) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 8 * c12);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 16, 12);
                        fprintf(f, "x q[%u];\n", 10);
                        fprintf(f, "x q[%u];\n", 16);
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 8 * c12);
                        }
                      }
                      if (c6 == 0) {
                        fprintf(f, "cx q[%u], q[%u];\n", 13, 10);
                        fprintf(f, "cx q[%u], q[%u];\n", 0, 16);
                        fprintf(f, "cx q[%u], q[%u];\n", 8, 17);
                        fprintf(f, "cx q[%u], q[%u];\n", 8, 17);
                        fprintf(f, "x q[%u];\n", 0);
                        fprintf(f, "x q[%u];\n", 0);
                        fprintf(f, "cx q[%u], q[%u];\n", 5, 0);
                        fprintf(f, "x q[%u];\n", 8);
                        fprintf(f, "x q[%u];\n", 0);
                      }
                    }
                    if (c5 == 1) {
                      fprintf(f, "x q[%u];\n", -3 * c6 + 13);
                      if (c6 == 0 && c8 == 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 13, 17);
                      }
                      if (c6 == 0 && c8 == 1) {
                        fprintf(f, "x q[%u];\n", 13);
                        fprintf(f, "cx q[%u], q[%u];\n", 17, 15);
                      }
                    }
                  }
                }
              } else {
                fprintf(f, "x q[%u];\n", 16);
                fprintf(f, "x q[%u];\n", 17);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c12);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c12);
                }
              }
            }
          } else if (c2 >= 0 && c2 <= 7 && c2 % 7 == 0) {
            if (c2 == 7) {
              for (int c10 = 17; c10 <= 18; c10 += 1) {
                fprintf(f, "x q[%u];\n", -5 * c10 + 92);
              }
              for (int c8 = 0; c8 <= 1; c8 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c8 + 3);
              }
              fprintf(f, "x q[%u];\n", 12);
            } else {
              for (int c12 = 0; c12 <= 2; c12 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c12);
              }
            }
            if (c2 == 7) {
              for (int c10 = 7; c10 <= 15; c10 += 8) {
                if (c10 == 15) {
                  fprintf(f, "x q[%u];\n", 2);
                  fprintf(f, "cx q[%u], q[%u];\n", 2, 12);
                }
                fprintf(f, "x q[%u];\n", (-c10 + 111) / 8);
              }
              fprintf(f, "x q[%u];\n", 12);
              fprintf(f, "x q[%u];\n", 12);
            } else {
              fprintf(f, "x q[%u];\n", 0);
            }
            if (c2 == 7) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c12 + 3);
              }
            } else {
              for (int c12 = 0; c12 <= 2; c12 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c12 + 4);
              }
            }
            if (c2 == 7) {
              for (int c10 = 7; c10 <= 15; c10 += 8) {
                fprintf(f, "x q[%u];\n", (-c10 + 31) / 8);
                if (c10 == 7) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c12 + 10);
                  }
                }
              }
            } else {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c12 + 1);
              }
            }
            fprintf(f, "x q[%u];\n", (-2 * c2 / 7) + 4);
            if (c2 == 0) {
              fprintf(f, "x q[%u];\n", 4);
              fprintf(f, "x q[%u];\n", 7);
              fprintf(f, "cx q[%u], q[%u];\n", 7, 2);
            }
            if (c2 == 0) {
              fprintf(f, "x q[%u];\n", 14);
            }
            if (c2 == 0) {
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c5 + 11, 10 * c5 + 6);
              }
              for (int c5 = 0; c5 <= 1; c5 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 6 * c5 + 11, 9 * c5 + 6);
              }
            }
          }
        }
        if (c2 >= 53 && c2 <= 83 && (19 * c2 - 1) % 40 >= 2 && (c2 + 1) % 6 == 0) {
          if (c2 == 83) {
            fprintf(f, "cx q[%u], q[%u];\n", 2, 10);
          } else {
            if (c2 == 77) {
              fprintf(f, "x q[%u];\n", 0);
            } else {
              if (c2 == 65) {
                fprintf(f, "cx q[%u], q[%u];\n", 3, 1);
              }
              if ((c2 - 1) % 4 == 0) {
                for (int c12 = 0; c12 < (c2 - 41) / 12; c12 += 1) {
                  fprintf(f, "x q[%u];\n", ((-3 * c2 + 197) / 2) + 2 * c12);
                }
                if (c2 == 65) {
                  fprintf(f, "cx q[%u], q[%u];\n", 3, 18);
                  fprintf(f, "cx q[%u], q[%u];\n", 3, 15);
                }
              }
              if (c2 >= 65) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c12 + 3);
                }
                if (c2 == 71) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 12 * c12 + 3);
                  }
                }
              }
            }
            if (c2 >= 71) {
              fprintf(f, "x q[%u];\n", 3);
              if (c2 == 77) {
                fprintf(f, "x q[%u];\n", 1);
                fprintf(f, "x q[%u];\n", 1);
              } else if (c2 == 71) {
                fprintf(f, "cx q[%u], q[%u];\n", 0, 11);
                fprintf(f, "cx q[%u], q[%u];\n", 11, 6);
              }
            }
          }
          if (c2 >= 65) {
            for (int c5 = max(1, (-c2 + 80) / 3); c5 <= min(3, (-c2 + 86) / 3); c5 += 2) {
              if (c2 == 77 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 1);
              }
              fprintf(f, "x q[%u];\n", (-5 * c2 - 15 * c5 + 466) / 6);
              if (c2 == 77 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 1);
              }
              if (c2 == 77 && c5 == 1) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c12 + 1);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 9 * c12 + 3, 5 * c12 + 1);
                }
                fprintf(f, "x q[%u];\n", 6);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 3 * c12, 4 * c12 + 11);
                }
                for (int c6 = 0; c6 <= 1; c6 += 1) {
                  fprintf(f, "x q[%u];\n", -4 * c6 + 15);
                }
              }
            }
            if (c2 == 83) {
              for (int c8 = 0; c8 <= 1; c8 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c8 + 10, 7 * c8 + 12);
              }
              for (int c10 = 1; c10 <= 3; c10 += 1) {
                if (c10 >= 2) {
                  fprintf(f, "x q[%u];\n", -2 * c10 + 16);
                }
                if (c10 <= 2) {
                  fprintf(f, "x q[%u];\n", -2 * c10 + 14);
                }
              }
            }
          }
        }
        if (c2 >= 77 && c2 <= 95 && (c2 + 1) % 6 == 0 && c2 % 12 >= 5 && 6 * (c2 / 12) + 6 * ((c2 + 6) / 12) + 5 == c2) {
          fprintf(f, "x q[%u];\n", 18);
        } else if (c2 + 2 >= 14 * floord(c2 - 3, 12) && 40 * floord(c2 - 3, 12) >= c2 + 121 && c2 + 160 >= 40 * ((c2 - 3) / 12) && 2 * ((c2 - 3) / 12) + 2 * ((19 * c2 - 1) / 40) == c2 + 6 && (c2 - 5) % 6 == 3 && 6 * ((c2 - 3) / 12) + 6 * ((2 * c2 + 6) / 21) + 2 == c2 && (c2 - 2) % 6 == 0) {
          if (c2 <= 74) {
            if ((c2 - 2) % 6 == 0) {
              if (c2 == 74) {
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  fprintf(f, "x q[%u];\n", c8 + 4);
                }
              }
              for (int c8 = 0; c8 <= 1; c8 += 1) {
                fprintf(f, "x q[%u];\n", c8 + 4);
              }
              if (c2 == 68) {
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  fprintf(f, "x q[%u];\n", c8 + 4);
                }
              }
            }
          } else {
            fprintf(f, "x q[%u];\n", 5);
          }
        }
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c1 + 8, 6 * c1 + 10);
  }
  fprintf(f, "x q[%u];\n", 9);
}
fclose(f);
return 0;
}