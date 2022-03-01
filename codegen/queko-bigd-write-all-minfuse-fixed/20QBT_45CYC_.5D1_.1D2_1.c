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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.5D1_.1D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 4; c1 += 1) {
    if (c1 == 1) {
      for (int c14 = 0; c14 <= 3; c14 += 1) {
        fprintf(f, "x q[%u];\n", 5 * c14);
      }
    }
    for (int c3 = max(c1 - 3, -c1 + c1 / 2 + 2); c3 <= 2; c3 += 1) {
      if (2 * c1 + c3 <= 5) {
        for (int c5 = 0; c5 <= min(-c1 + 2, -c3 + 2); c5 += 1) {
          for (int c6 = -c1 + 2; c6 <= min(-2 * c1 + 5, c1 + c3 - 1); c6 += 1) {
            if (c1 == 1 && c3 == 1 && c6 == 1) {
              for (int c8 = 0; c8 <= 2; c8 += 1) {
                if (c5 == 0 && c8 == 0) {
                  for (int c14 = 0; c14 <= 4; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14);
                  }
                  for (int c14 = 0; c14 <= 3; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14);
                  }
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 2);
                  }
                  for (int c14 = 0; c14 <= 3; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 12);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 6, 14);
                }
                fprintf(f, "x q[%u];\n", 8 * c5 + 6);
              }
            }
            if (c3 == 1 && c5 == 0 && c6 == 1) {
              if (c1 == 2) {
                fprintf(f, "x q[%u];\n", 4);
              } else {
                for (int c14 = 0; c14 <= 3; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c14);
                }
              }
              if (c1 == 2) {
                fprintf(f, "x q[%u];\n", 4);
              } else {
                for (int c14 = 0; c14 <= 3; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c14);
                }
              }
            }
            if (c1 == 1 && c3 == 1 && c5 == 0 && c6 == 1) {
              for (int c14 = 0; c14 <= 2; c14 += 1) {
                fprintf(f, "x q[%u];\n", c14 + 3);
              }
              for (int c14 = 0; c14 <= 2; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 1);
              }
              for (int c12 = 2; c12 <= 8; c12 += 1) {
                if (c12 == 8) {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c14 + 1);
                  }
                } else if (c12 == 7) {
                  for (int c14 = 0; c14 <= 3; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c14 + 4);
                  }
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 1);
                  }
                } else if (c12 == 6) {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 1);
                  }
                } else if (c12 == 5) {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 1);
                  }
                } else if (c12 == 4) {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 1);
                  }
                } else if (c12 == 3) {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 1);
                  }
                } else {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14 + 1);
                  }
                }
              }
              for (int c14 = 0; c14 <= 2; c14 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c14 + 1);
              }
              fprintf(f, "x q[%u];\n", 7);
            }
            if (c1 == 1 && c5 == 0 && c6 == 1) {
              for (int c12 = 11; c12 <= min(13, -26 * c3 + 63); c12 += 1) {
                if (c12 == 11) {
                  for (int c14 = 0; c14 <= -c3 + 3; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                  }
                } else if (c12 == 13) {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                  }
                } else {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                  }
                  fprintf(f, "x q[%u];\n", 4);
                }
              }
              if (c3 == 1) {
                for (int c12 = 14; c12 <= 18; c12 += 1) {
                  if (c12 == 18) {
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                    }
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c14 + 1);
                    }
                  } else if (c12 == 17) {
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                    }
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c14 + 1);
                    }
                    fprintf(f, "x q[%u];\n", 6);
                  } else if (c12 == 16) {
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                    }
                  } else if (c12 == 15) {
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 1);
                    for (int c14 = 0; c14 <= 2; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                    }
                  }
                }
                for (int c14 = 0; c14 <= 2; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                }
                for (int c14 = 0; c14 <= 2; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c14 + 4);
                }
              }
              if (c3 == 2) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", c14 + 12);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 19, 13);
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                }
                for (int c12 = 14; c12 <= 16; c12 += 1) {
                  if (c12 == 16) {
                    fprintf(f, "x q[%u];\n", 19);
                    fprintf(f, "cx q[%u], q[%u];\n", 15, 0);
                  } else if (c12 == 15) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      for (int c15 = 0; c15 <= c14; c15 += 1) {
                        fprintf(f, "x q[%u];\n", -c14 + 13 * c15 + 1);
                      }
                    }
                    fprintf(f, "x q[%u];\n", 19);
                  } else {
                    fprintf(f, "x q[%u];\n", 19);
                    fprintf(f, "cx q[%u], q[%u];\n", 0, 13);
                  }
                }
                fprintf(f, "x q[%u];\n", 7);
                fprintf(f, "x q[%u];\n", 19);
                fprintf(f, "x q[%u];\n", 15);
              }
            } else if (c1 == 1 && c3 == 1 && c5 == 1 && c6 == 1) {
              fprintf(f, "x q[%u];\n", 14);
            } else if (c1 == 2 && c3 == 1 && c6 == 0) {
              fprintf(f, "x q[%u];\n", 18);
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c14 + 17, 18 * c14);
              }
            }
            if (c1 == 1 && c3 + c5 == 2 && c6 == 1) {
              for (int c12 = 18; c12 <= 19; c12 += 1) {
                if (c3 == 1 && c12 == 19) {
                  fprintf(f, "x q[%u];\n", 14);
                } else if (c3 == 2 && c12 == 19) {
                  fprintf(f, "x q[%u];\n", 15);
                  fprintf(f, "x q[%u];\n", 19);
                } else if (c3 == 1) {
                  fprintf(f, "x q[%u];\n", 14);
                } else {
                  fprintf(f, "x q[%u];\n", 15);
                  fprintf(f, "x q[%u];\n", 19);
                }
              }
            }
            if (c3 == 1 && c1 + c6 == 2) {
              if (c1 == 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 14);
              } else if (c1 == 1) {
                for (int c14 = 0; c14 <= 2; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c14 + 2);
                }
              } else {
                fprintf(f, "cx q[%u], q[%u];\n", 18, 1);
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  for (int c15 = 0; c15 <= c14; c15 += 1) {
                    fprintf(f, "x q[%u];\n", -6 * c14 + 17 * c15 + 6);
                  }
                }
              }
              if (c1 == 1 && c5 == 0) {
                for (int c14 = 0; c14 <= 2; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c14 + 2);
                }
                for (int c12 = 22; c12 <= 23; c12 += 1) {
                  if (c12 == 23) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 16 * c14 + 2);
                    }
                  } else {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c14 + 2);
                    }
                  }
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 16 * c14 + 2);
                }
              } else if (c1 == 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
              }
              if (c1 == 1) {
                if (c5 == 1) {
                  fprintf(f, "x q[%u];\n", 14);
                } else {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 14 * c14 + 2);
                  }
                }
                if (c5 == 1) {
                  fprintf(f, "x q[%u];\n", 14);
                }
                if (c5 == 1) {
                  fprintf(f, "x q[%u];\n", 14);
                } else {
                  for (int c14 = 0; c14 <= 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c14 + 2);
                  }
                }
                if (c5 == 0) {
                  for (int c12 = 27; c12 <= 34; c12 += 1) {
                    if (c12 == 34) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 7 * c14 + 6, 17 * c14 + 1);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        for (int c15 = 0; c15 <= -c14 + 1; c15 += 1) {
                          fprintf(f, "x q[%u];\n", 7 * c14 + 14 * c15 + 2);
                        }
                      }
                    } else if (c12 == 33) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c14 + 2);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 6 * c14 + 9);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 13 * c14 + 6, 5 * c14 + 8);
                      }
                    } else if (c12 == 32) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 6 * c14 + 9);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c14 + 2);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 13 * c14 + 6, 5 * c14 + 8);
                      }
                    } else if (c12 == 31) {
                      for (int c14 = 0; c14 <= 2; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c14 + 2);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -6 * c14 + 15, 7 * c14 + 6);
                      }
                    } else if (c12 == 30) {
                      fprintf(f, "x q[%u];\n", 13);
                      fprintf(f, "x q[%u];\n", 9);
                      for (int c14 = 0; c14 <= 2; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c14 + 2);
                      }
                    } else if (c12 == 29) {
                      for (int c14 = 0; c14 <= 2; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c14 + 2);
                      }
                      fprintf(f, "x q[%u];\n", 13);
                    } else if (c12 == 28) {
                      for (int c14 = 0; c14 <= 2; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c14 + 2);
                      }
                      fprintf(f, "x q[%u];\n", 13);
                    } else {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c14 + 2);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 9, 13);
                    }
                  }
                }
              }
              if (c1 == 2 && c5 == 0) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -14 * c14 + 15, 14 * c14);
                }
              }
            } else if (c1 == 1 && c6 == 1) {
              fprintf(f, "x q[%u];\n", 19);
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c14 + 4, 3 * c14 + 15);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 11, 19);
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c14 + 11);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c14 + 11);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c14 + 11);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c14 + 11);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c14 + 11);
              }
              for (int c12 = 28; c12 <= 29; c12 += 1) {
                if (c12 == 29) {
                  fprintf(f, "x q[%u];\n", 7);
                } else {
                  fprintf(f, "x q[%u];\n", 7);
                }
              }
              for (int c12 = 30; c12 <= 32; c12 += 1) {
                if (c12 == 32) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c14 + 13);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 18);
                } else if (c12 == 31) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 14 * c14 + 4);
                  }
                } else {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 18 * c14);
                  }
                  fprintf(f, "x q[%u];\n", 7);
                }
              }
            }
            if (c1 + c3 == 3 && c5 == 0) {
              if (c1 == 1 && c6 == 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c14 + 13);
                }
              }
              for (int c14 = 0; c14 < c1; c14 += 1) {
                fprintf(f, "x q[%u];\n", -18 * c1 + 15 * c14 + 36);
              }
              if (c1 == 2 && c6 == 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -7 * c14 + 15, 14 * c14);
                }
                for (int c12 = 21; c12 <= 22; c12 += 1) {
                  if (c12 == 22) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", c14 + 14);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 11, 9);
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 7 * c14 + 1);
                    }
                    fprintf(f, "x q[%u];\n", 17);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", -8 * c12 + 176, 12 * c12 - 251);
                  if (c12 == 21) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14 + 9);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 14 * c14);
                    }
                  }
                }
              }
            }
            if (c3 == 1 && c5 == 0 && c6 == 1) {
              if (c1 == 2) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c14 + 9);
                }
              } else {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", c14 + 12, c14 + 17);
                }
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c1 + 5 * c14 - 6);
              }
              if (c1 == 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  for (int c15 = 0; c15 <= -c14 + 1; c15 += 1) {
                    fprintf(f, "x q[%u];\n", 7 * c14 + 14 * c15 + 2);
                  }
                }
              }
              if (c1 == 1) {
                for (int c12 = 36; c12 <= 37; c12 += 1) {
                  if (c12 == 37) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 14 * c14 + 2);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c14 + 12);
                    }
                  } else {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 14 * c14 + 2);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c14 + 12);
                    }
                  }
                }
              } else if (c1 == 2) {
                fprintf(f, "x q[%u];\n", 13);
              }
              if (c1 == 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  for (int c15 = 0; c15 <= -c14 + 1; c15 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c14 + 11 * c15 + 5);
                  }
                }
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c1 + c14 + 10);
              }
              if (c1 == 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 11 * c14 + 5);
                }
                for (int c12 = 40; c12 <= 49; c12 += 1) {
                  if (c12 == 49) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 7);
                  } else if (c12 == 48) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 7);
                  } else {
                    if (c12 == 43) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c14 + 5);
                      }
                    } else if (c12 == 41) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 6 * c14 + 5);
                      }
                    } else if (c12 == 40) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c14 + 5);
                      }
                    }
                    if (c12 <= 46) {
                      for (int c14 = 0; c14 < c12 - 44; c14 += 1) {
                        fprintf(f, "x q[%u];\n", -5 * c12 + 4 * c14 + 235);
                      }
                      if (c12 == 46) {
                        fprintf(f, "x q[%u];\n", 10);
                      } else if (c12 == 45) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          for (int c15 = 0; c15 <= -c14 + 1; c15 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c14 + 11 * c15 + 5);
                          }
                        }
                      } else if (c12 == 44) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          for (int c15 = 0; c15 <= -c14 + 1; c15 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c14 + 5 * c15 + 5);
                          }
                        }
                      } else if (c12 == 42) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c14 + 5);
                        }
                      }
                    } else {
                      fprintf(f, "x q[%u];\n", 9);
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c14 + 5);
                      }
                    }
                  }
                }
                fprintf(f, "x q[%u];\n", 3);
                for (int c12 = 51; c12 <= 52; c12 += 1) {
                  if (c12 == 52) {
                    fprintf(f, "x q[%u];\n", 3);
                  } else {
                    fprintf(f, "x q[%u];\n", 3);
                  }
                }
                fprintf(f, "x q[%u];\n", 3);
              }
            } else if (c1 == 1 && c3 == 2 && c5 == 0 && c6 == 1) {
              for (int c12 = 36; c12 <= 52; c12 += 1) {
                if (c12 == 52) {
                  fprintf(f, "x q[%u];\n", 19);
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -14 * c14 + 17, 6 * c14 + 6);
                  }
                } else if (c12 == 51) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c14 + 13);
                  }
                  fprintf(f, "x q[%u];\n", 12);
                } else if (c12 == 50) {
                  fprintf(f, "x q[%u];\n", 12);
                } else if (c12 == 49) {
                  fprintf(f, "x q[%u];\n", 12);
                } else if (c12 == 48) {
                  fprintf(f, "x q[%u];\n", 12);
                } else if (c12 == 47) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                  }
                } else if (c12 == 46) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                  }
                } else if (c12 == 45) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                  }
                } else if (c12 == 44) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                  }
                } else if (c12 == 43) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                  }
                } else if (c12 == 42) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 12);
                  }
                } else if (c12 == 40) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    for (int c15 = 0; c15 <= c14; c15 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c14 + 5 * c15 + 1);
                    }
                  }
                } else if (c12 == 39) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    for (int c15 = 0; c15 <= c14; c15 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c14 + 5 * c15 + 1);
                    }
                  }
                } else if (c12 == 38) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    for (int c15 = 0; c15 <= c14; c15 += 1) {
                      fprintf(f, "x q[%u];\n", 12 * c14 + 6 * c15 + 1);
                    }
                  }
                } else if (c12 == 37) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c14 + 13);
                  }
                } else if (c12 == 36) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c14 + 13);
                  }
                }
              }
              fprintf(f, "x q[%u];\n", 19);
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c14 + 3);
              }
            }
            if (c1 == 1 && c5 == 0 && c6 == 1) {
              for (int c12 = 54; c12 <= 56; c12 += 1) {
                if (c3 == 2 && c12 == 56) {
                  fprintf(f, "x q[%u];\n", 6);
                }
                if (c12 == 56) {
                  for (int c14 = 0; c14 <= -c3 + 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 11 * c14 + 8);
                  }
                } else if (c12 == 54) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", -2 * c3 + 11 * c14 + 10);
                  }
                } else {
                  if (c3 == 2) {
                    fprintf(f, "x q[%u];\n", 6);
                  }
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", -4 * c3 + 11 * c14 + 12);
                  }
                }
              }
              if (c3 == 2) {
                for (int c12 = 57; c12 <= 61; c12 += 1) {
                  if (c12 == 61) {
                    fprintf(f, "x q[%u];\n", 6);
                  } else if (c12 == 60) {
                    fprintf(f, "x q[%u];\n", 6);
                  } else if (c12 == 59) {
                    fprintf(f, "x q[%u];\n", 6);
                  } else if (c12 == 58) {
                    fprintf(f, "x q[%u];\n", 6);
                  } else {
                    fprintf(f, "x q[%u];\n", 6);
                  }
                }
              }
            } else if (c1 == 1 && c3 == 1 && c5 == 1 && c6 == 1) {
              fprintf(f, "x q[%u];\n", 16);
            } else if (c1 == 1 && c3 == 2 && c6 == 2) {
              fprintf(f, "x q[%u];\n", 18);
            }
            if (c1 == 1 && c3 == 1 && c6 == 1) {
              for (int c10 = 1; c10 <= 3; c10 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c5 + 10);
                if (c10 == 3) {
                  for (int c14 = 0; c14 <= -c5 + 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c5 - 2 * c14 + 10);
                  }
                  for (int c14 = 0; c14 <= -c5 + 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c5 - 2 * c14 + 10);
                  }
                  if (c5 == 0) {
                    fprintf(f, "x q[%u];\n", 10);
                    fprintf(f, "x q[%u];\n", 10);
                  }
                } else if (c10 == 2) {
                  for (int c12 = 0; c12 <= -c5 + 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c5 - 2 * c12 + 10);
                  }
                }
              }
            }
            if (c1 == 2 && c3 == 1 && c5 == 0 && c6 == 1) {
              for (int c9 = 1; c9 <= 3; c9 += 1) {
                fprintf(f, "x q[%u];\n", 13);
              }
              fprintf(f, "x q[%u];\n", 13);
            }
            if (c1 == 2 && c3 == 1 && c5 == 0 && c6 == 1) {
              for (int c8 = 4; c8 <= 6; c8 += 1) {
                fprintf(f, "x q[%u];\n", 17);
              }
            } else if (c1 == 1 && c3 == 2 && c5 == 0 && c6 == 1) {
              fprintf(f, "x q[%u];\n", 4);
              fprintf(f, "x q[%u];\n", 4);
            }
            if (c1 == 2 && c3 == 1 && c5 == 0 && c6 == 0) {
              fprintf(f, "x q[%u];\n", 1);
            }
          }
          if (c1 == 0 && c3 == 2 && c5 == 0) {
            for (int c14 = 0; c14 <= 3; c14 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c14);
            }
          }
        }
      } else if (c1 >= 3 && c3 >= 1) {
        if (c1 == 3 && c3 == 1) {
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", c14 + 14);
          }
        }
        if (c3 == 1) {
          for (int c8 = 0; c8 <= 1; c8 += 1) {
            fprintf(f, "x q[%u];\n", -3 * c8 + 18);
          }
          if (c1 == 3) {
            for (int c14 = 0; c14 <= 2; c14 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c14 + 1);
            }
            for (int c14 = 0; c14 <= 2; c14 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c14 + 1);
            }
            fprintf(f, "x q[%u];\n", 4);
          }
        }
        if (c1 == 3) {
          fprintf(f, "x q[%u];\n", 4);
          if (c3 == 2) {
            fprintf(f, "x q[%u];\n", 4);
          } else if (c3 == 1) {
            fprintf(f, "x q[%u];\n", 13);
          }
          fprintf(f, "x q[%u];\n", 13);
          if (c3 == 2) {
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c14 + 1);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 2 * c14 + 9);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 2 * c14 + 9);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 1, 14);
          }
          if (c3 == 1) {
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c14 + 6);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 8, 1);
            fprintf(f, "cx q[%u], q[%u];\n", 6, 1);
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c14 + 1);
            }
          }
        } else {
          if (c3 == 2) {
            fprintf(f, "cx q[%u], q[%u];\n", 6, 1);
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", -12 * c14 + 18);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 1, 14);
            fprintf(f, "cx q[%u], q[%u];\n", 6, 14);
            fprintf(f, "cx q[%u], q[%u];\n", 17, 6);
          }
          if (c3 == 1) {
            fprintf(f, "x q[%u];\n", 18);
            fprintf(f, "cx q[%u], q[%u];\n", 18, 1);
          }
        }
        if (c1 == 4 && c3 == 1) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c5 + 14);
          }
        } else if (c1 == 3 && c3 == 1) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            for (int c6 = 0; c6 <= c5; c6 += 1) {
              fprintf(f, "x q[%u];\n", -10 * c5 + 2 * c6 + 19);
            }
          }
        }
      } else {
        if (c1 == 2) {
          fprintf(f, "x q[%u];\n", 4);
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c14 + 9);
          }
        }
        if (c1 == 2) {
          for (int c12 = 7; c12 <= 8; c12 += 1) {
            if (c12 == 8) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 11);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c14 + 9, c14);
              }
            } else {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c14 + 9);
              }
            }
          }
        }
        for (int c14 = 0; c14 <= 1; c14 += 1) {
          for (int c15 = 0; c15 <= c14; c15 += 1) {
            fprintf(f, "x q[%u];\n", 7 * c14 + 7 * c15 + 4);
          }
        }
        if (c1 == 2) {
          for (int c12 = 12; c12 <= 20; c12 += 1) {
            if (c12 == 20) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c14);
              }
            } else if (c12 == 19) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c14);
              }
            } else if (c12 == 18) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c14);
              }
            } else if (c12 == 17) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", c14);
              }
            } else if (c12 == 12) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", c14 + 14);
              }
            }
          }
        }
        if (c1 == 2) {
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 9 * c14);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", c14 + 14);
          }
        } else {
          fprintf(f, "x q[%u];\n", 4);
        }
        if (c1 == 3 && c3 == 0) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 5 * c5 + 6, 8 * c5 + 1);
          }
        }
      }
    }
    if (c1 == 3) {
      fprintf(f, "x q[%u];\n", 4);
    }
    if (c1 == 2) {
      for (int c3 = 0; c3 <= 3; c3 += 1) {
        fprintf(f, "x q[%u];\n", 17);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 15);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", -c1 + 9);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 8);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 0);
  }
  fprintf(f, "x q[%u];\n", 1);
}
fclose(f);
return 0;
}