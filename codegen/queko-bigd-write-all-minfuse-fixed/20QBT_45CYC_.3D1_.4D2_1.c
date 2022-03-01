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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.3D1_.4D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 2; c1 += 1) {
    for (int c2 = max(c1 - 2, -c1); c2 <= -c1 + 2; c2 += 1) {
      if (c1 == 0 && c2 == 0) {
        fprintf(f, "x q[%u];\n", 10);
      }
      if (c1 + c2 == 0) {
        if (c1 == 0) {
          fprintf(f, "x q[%u];\n", 5);
        } else {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", -8 * c9 + 17);
          }
          fprintf(f, "x q[%u];\n", 9);
        }
      } else {
        if (c1 == 2 && c2 == 0) {
          fprintf(f, "x q[%u];\n", 5);
        }
        if (c2 == 0) {
          if (c1 == 2) {
            fprintf(f, "x q[%u];\n", 3);
          } else {
            fprintf(f, "cx q[%u], q[%u];\n", 14, 13);
            fprintf(f, "cx q[%u], q[%u];\n", 7, 14);
            fprintf(f, "cx q[%u], q[%u];\n", 0, 7);
            fprintf(f, "cx q[%u], q[%u];\n", 13, 19);
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 14 * c9, 6 * c9 + 7);
            }
            fprintf(f, "x q[%u];\n", 19);
            for (int c7 = 18; c7 <= 26; c7 += 1) {
              if (c7 == 26) {
                fprintf(f, "x q[%u];\n", 3);
              } else if (c7 == 25) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c9 + 3);
                }
              } else if (c7 == 24) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", c9 + 6, 3 * c9);
                }
              } else if (c7 == 23) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c9 + 2 * c10 + 4);
                  }
                }
              } else if (c7 == 22) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c9 + 17);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 9, 18);
              } else if (c7 == 21) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c9 + 19, c9 + 17);
                }
              } else if (c7 == 20) {
                fprintf(f, "x q[%u];\n", 18);
              } else if (c7 == 19) {
                fprintf(f, "cx q[%u], q[%u];\n", 18, 14);
              }
              if ((c7 - 2) % 8 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", -c7 + 32, (-5 * c7 + 194) / 8);
              }
            }
            for (int c7 = 32; c7 <= 33; c7 += 1) {
              fprintf(f, "x q[%u];\n", 7 * c7 - 218);
            }
            fprintf(f, "x q[%u];\n", 13);
          }
        }
      }
      if (c1 <= 1) {
        for (int c4 = max(c1, -c2 + 1); c4 <= min(min(-c1 + 2, c2 + 1), -c2 + 3); c4 += 1) {
          if (c1 == 1 && c2 == 1 && c4 == 1) {
            fprintf(f, "x q[%u];\n", 10);
          } else if (c1 == 1 && c2 == 0 && c4 == 1) {
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", 9 * c9 + 1);
            }
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c9 + 1, 3 * c9 + 12);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 16, 2);
            for (int c7 = 11; c7 <= 15; c7 += 1) {
              if (c7 >= 12 && c7 <= 13) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 - 47, 3 * c7 - 24);
              }
              if (c7 <= 12) {
                fprintf(f, "cx q[%u], q[%u];\n", 4 * c7 - 32, -2 * c7 + 26);
              } else if (c7 == 15) {
                fprintf(f, "x q[%u];\n", 11);
              }
              if ((c7 + 1) % 4 == 0) {
                fprintf(f, "x q[%u];\n", (-5 * c7 + 119) / 4);
                if (c7 == 11) {
                  fprintf(f, "x q[%u];\n", 4);
                }
              }
            }
            fprintf(f, "cx q[%u], q[%u];\n", 16, 2);
          } else if (c2 == 2 && c4 == 1) {
            fprintf(f, "x q[%u];\n", 4);
            fprintf(f, "cx q[%u], q[%u];\n", 4, 9);
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", -8 * c9 + 17);
            }
          }
          for (int c5 = max(max(c1, c2 - 1), c4 - 1); c5 <= 1; c5 += 1) {
            if (c1 == 0 && c2 == 0 && c4 == 1 && c5 == 1) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c9 + 2);
              }
            }
            if (c1 == 0 && c2 == 0 && c4 == 1) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", -2 * c5 + 14 * c9 + 4);
              }
              if (c5 == 0) {
                fprintf(f, "x q[%u];\n", 18);
                for (int c7 = 20; c7 <= 22; c7 += 1) {
                  if (c7 == 22) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", c9 + 6, 3 * c9);
                    }
                  } else if (c7 == 21) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c9 + 11, 7 * c9 + 6);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 5 * c9);
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 12);
                    fprintf(f, "x q[%u];\n", 0);
                    fprintf(f, "cx q[%u], q[%u];\n", 6, 8);
                  }
                }
              } else if (c5 == 1) {
                fprintf(f, "x q[%u];\n", 16);
                fprintf(f, "x q[%u];\n", 4);
                fprintf(f, "x q[%u];\n", 1);
                fprintf(f, "cx q[%u], q[%u];\n", 19, 17);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 18 * c9);
                }
              }
              if (c5 == 0) {
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 10);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c9 + 12);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 4, 9);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c9 + 1);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 19, 17);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c9);
                }
              }
              if (c5 == 1) {
                for (int c7 = 19; c7 <= 21; c7 += 1) {
                  if (c7 == 21) {
                    fprintf(f, "x q[%u];\n", 1);
                  } else if (c7 == 20) {
                    fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
                    fprintf(f, "cx q[%u], q[%u];\n", 4, 11);
                    fprintf(f, "x q[%u];\n", 4);
                  }
                  if (c7 >= 20) {
                    fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 - 93, 3 * c7 - 45);
                  } else {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -7 * c9 + 18, 8 * c9);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 6 * c9 + 7, 16 * c9 + 3);
                    }
                  }
                  if (c7 <= 20) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -2 * c7 + 10 * c9 + 43);
                    }
                    if (c7 == 20) {
                      fprintf(f, "x q[%u];\n", 1);
                    } else if (c7 == 19) {
                      fprintf(f, "x q[%u];\n", 4);
                      fprintf(f, "x q[%u];\n", 1);
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 15);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 15 * c9 + 4, 8 * c9 + 9);
                    }
                  }
                }
                fprintf(f, "x q[%u];\n", 17);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c9 + 15, 6 * c9 + 3);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 14, 19);
                fprintf(f, "x q[%u];\n", 10);
                for (int c7 = 23; c7 <= 24; c7 += 1) {
                  if (c7 == 24) {
                    fprintf(f, "cx q[%u], q[%u];\n", 6, 8);
                  } else {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -9 * c9 + 13, c9 + 17);
                    }
                    fprintf(f, "x q[%u];\n", 19);
                    for (int c9 = 0; c9 <= 2; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 3 * c9 + 9);
                    }
                  }
                  fprintf(f, "x q[%u];\n", 8 * c7 - 176);
                  if (c7 == 24) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", c9 + 17);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 5 * c9 + 14);
                    }
                  } else {
                    fprintf(f, "cx q[%u], q[%u];\n", 10, 16);
                  }
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -6 * c9 + 9);
                  if (c9 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 16);
                    fprintf(f, "x q[%u];\n", 9);
                    fprintf(f, "x q[%u];\n", 2);
                    fprintf(f, "cx q[%u], q[%u];\n", 10, 2);
                    fprintf(f, "x q[%u];\n", 10);
                  }
                  fprintf(f, "x q[%u];\n", c9 + 10);
                  if (c9 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", 10, 9);
                    fprintf(f, "cx q[%u], q[%u];\n", 10, 9);
                    fprintf(f, "x q[%u];\n", 9);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c9 + 2, 11 * c9 + 3);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -2 * c9 + 19);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c9 + 6);
                }
              }
              if (c5 == 0) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c9 + 11, 9 * c9);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c9 + 3);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 17 * c9 + 2, 10 * c9 + 7);
                }
                fprintf(f, "x q[%u];\n", 14);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", c9 + 15);
                }
                for (int c7 = 25; c7 <= 26; c7 += 1) {
                  if (c7 == 26) {
                    fprintf(f, "cx q[%u], q[%u];\n", 5, 15);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c9 + 8, c9 + 13);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 2, 7);
                    fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
                  } else {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -12 * c9 + 14);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -6 * c9 + 15);
                      if (c9 == 0) {
                        fprintf(f, "x q[%u];\n", 18);
                      }
                    }
                    fprintf(f, "x q[%u];\n", 1);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 12 * c9 + 7, 14 * c9 + 3);
                    }
                  }
                }
                fprintf(f, "cx q[%u], q[%u];\n", 5, 15);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -10 * c9 + 17);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c9 + 8);
                }
              }
            } else {
              if (c1 == 0 && c2 == 1 && c4 == 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 7);
                fprintf(f, "x q[%u];\n", 9);
                fprintf(f, "cx q[%u], q[%u];\n", 0, 7);
                for (int c7 = 2; c7 <= 11; c7 += 1) {
                  if (c7 == 11) {
                    fprintf(f, "cx q[%u], q[%u];\n", 1, 10);
                  }
                  if (c7 >= 10) {
                    fprintf(f, "cx q[%u], q[%u];\n", -5 * c7 + 60, 13 * c7 - 128);
                    if (c7 == 11) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c9);
                      }
                    } else if (c7 == 10) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c9 + 3);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -11 * c9 + 18, c9 + 14);
                      }
                    }
                  } else if (c7 == 9) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c9 + 2, 12 * c9 + 3);
                    }
                  } else if (c7 == 8) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -9 * c9 + 11);
                    }
                  } else if (c7 == 7) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 16 * c9 + 2, 11 * c9 + 3);
                    }
                  } else if (c7 == 6) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 12 * c9 + 3);
                    }
                  } else if (c7 == 5) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 15, 3 * c9 + 3);
                    }
                  } else if (c7 == 4) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c9 + 6, 18 * c9);
                    }
                    fprintf(f, "x q[%u];\n", 11);
                  } else if (c7 == 3) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", c9 + 10);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c9);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 6, 8);
                  } else {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -c9 + 11, 9 * c9);
                    }
                  }
                }
              }
              if (c1 + c2 == 1 && c4 == 1 && c5 == 1) {
                for (int c7 = 12; c7 <= 17; c7 += 1) {
                  if (c7 == 16) {
                    fprintf(f, "x q[%u];\n", 6 * c1 + 4);
                    if (c1 == 0) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c9 + 9, c9 + 18);
                      }
                    } else if (c1 == 1) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c9 + 1);
                      }
                    }
                  } else {
                    if (c1 == 0 && c7 == 17) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 10 * c9 + 4, c9 + 18);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c9 + 9, 15 * c9 + 2);
                      }
                    } else if (c1 == 1 && c7 == 17) {
                      fprintf(f, "cx q[%u], q[%u];\n", 2, 15);
                    }
                    if (c1 == 0 && c7 == 15) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", -c9 + 5);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 18, 12 * c9 + 7);
                      }
                    } else if (c1 == 1 && c7 == 15) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c9 + 1);
                      }
                    } else if (c1 == 0 && c7 == 14) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -9 * c9 + 13, c9 + 17);
                      }
                      fprintf(f, "x q[%u];\n", 1);
                    } else if (c1 == 0 && c7 == 13) {
                      fprintf(f, "x q[%u];\n", 1);
                      fprintf(f, "x q[%u];\n", 4);
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -2 * c9 + 16, 12 * c9 + 5);
                      }
                    } else if (c1 == 1 && c7 == 13) {
                      fprintf(f, "cx q[%u], q[%u];\n", 16, 5);
                    } else {
                      if (c1 == 0 && c7 == 12) {
                        fprintf(f, "cx q[%u], q[%u];\n", 5, 15);
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", 9 * c9 + 1);
                        }
                      }
                      if ((c7 - 2) % 5 == 0) {
                        fprintf(f, "x q[%u];\n", ((-4 * c7 + 68) / 5) + c1);
                      }
                    }
                  }
                }
                if (c1 == 0) {
                  for (int c7 = 18; c7 <= 21; c7 += 1) {
                    if (c7 == 21) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c9 + 8);
                      }
                    } else if (c7 == 20) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c9 + 8, 5 * c9 + 13);
                      }
                    } else if (c7 == 19) {
                      fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
                    } else {
                      fprintf(f, "x q[%u];\n", 18);
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -5 * c9 + 12, 5 * c9 + 9);
                      }
                    }
                  }
                }
              }
              if (c1 == 0 && c2 == 1 && c4 == 2 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 1);
              } else if (c1 == 1 && c2 == 0 && c4 == 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 2);
                fprintf(f, "x q[%u];\n", 13);
                fprintf(f, "x q[%u];\n", 3);
                fprintf(f, "x q[%u];\n", 3);
                fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
                for (int c7 = 20; c7 <= 22; c7 += 1) {
                  if (c7 == 22) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", c9 + 13);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 0, 7);
                  } else if (c7 == 21) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c9 + 5);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", c9 + 13);
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 13);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c9 + 5);
                    }
                  }
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c9 + 13);
                }
              }
              if (c1 == 0 && c4 == 0 && c5 == 1) {
                for (int c9 = 0; c9 < c2; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -5 * c2 + 15 * c9 + 14);
                }
              } else if (c1 == 0 && c2 == 1 && c4 == 1 && c5 == 1) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 10 * c9 + 8);
                }
                for (int c7 = 23; c7 <= 24; c7 += 1) {
                  if (c7 == 24) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c9 + 11, 5 * c9 + 8);
                    }
                  } else {
                    fprintf(f, "cx q[%u], q[%u];\n", 6, 8);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c9 + 12);
                    }
                  }
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 15 * c9 + 4);
                  if (c9 == 0) {
                    fprintf(f, "x q[%u];\n", 4);
                    fprintf(f, "x q[%u];\n", 3);
                  }
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c9 + 8);
                }
              }
            }
            if (c1 == 0 && c4 == 1 && c5 == 0) {
              if (c2 == 0) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 10 * c9);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
              }
              for (int c9 = 0; c9 <= c2; c9 += 1) {
                fprintf(f, "x q[%u];\n", -2 * c2 + 10 * c9 + 7);
              }
              if (c2 == 0) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", c9 + 4);
                }
              }
              if (c2 == 0) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -7 * c9 + 18, 8 * c9);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -6 * c9 + 16);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 5, 15);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 11 * c9 + 2);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 18 * c9);
                }
              }
            } else {
              if (c1 == 0 && c2 == 1 && c4 >= 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 9);
              } else if (c1 == 1 && c2 == 0 && c4 == 1 && c5 == 1) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 15 * c9 + 4, 8 * c9 + 9);
                }
                fprintf(f, "x q[%u];\n", 5);
              }
              if (c1 == 1 && c2 == 1 && c4 == 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", 2);
                fprintf(f, "cx q[%u], q[%u];\n", 2, 15);
                fprintf(f, "cx q[%u], q[%u];\n", 10, 2);
                fprintf(f, "x q[%u];\n", 12);
              }
              if (c2 == c1 && c4 == 1 && c5 == 1) {
                for (int c7 = 26; c7 <= min(32, 8 * c1 + 31); c7 += 1) {
                  if (c1 == 0 && c7 == 30) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 6 * c9 + 6, 18 * c9);
                    }
                  } else {
                    if (c1 == 0 && c7 == 29) {
                      fprintf(f, "cx q[%u], q[%u];\n", 18, 0);
                    } else if (c1 == 0 && c7 == 28) {
                      fprintf(f, "x q[%u];\n", 11);
                    }
                    if (c1 == 0 && c7 >= 28 && c7 <= 29) {
                      fprintf(f, "cx q[%u], q[%u];\n", 5 * c7 - 134, 8 * c7 - 224);
                      if (c7 == 28) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -2 * c9 + 7, 12 * c9 + 3);
                        }
                      }
                    } else {
                      if (c1 == 0 && c7 == 31) {
                        fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
                      }
                      if (c7 == 31) {
                        fprintf(f, "cx q[%u], q[%u];\n", 0, -7 * c1 + 14);
                        if (c1 == 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 12, 4);
                        } else if (c1 == 0) {
                          fprintf(f, "x q[%u];\n", 13);
                          fprintf(f, "x q[%u];\n", 4);
                        }
                      } else {
                        if (c1 == 1 && c7 == 32) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", -8 * c9 + 15);
                          }
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c9);
                          }
                        }
                        if (c1 == 1 && c7 == 30) {
                          fprintf(f, "cx q[%u], q[%u];\n", 12, 9);
                        }
                      }
                      if (c1 == 1 && c7 == 27) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", 14 * c9 + 2);
                        }
                      } else if (c1 == 1 && c7 == 26) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 16, 16 * c9 + 2);
                        }
                      } else if (c1 == 0 && c7 == 26) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", -5 * c9 + 11);
                        }
                      }
                    }
                  }
                  if (c1 == 0 && (c7 + 2) % 4 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", (-3 * c7 + 106) / 4, (-3 * c7 + 134) / 4);
                    if (c7 == 30) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -8 * c9 + 16, 11 * c9 + 2);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c9 + 5);
                      }
                    }
                    if (c7 == 26) {
                      fprintf(f, "x q[%u];\n", 5);
                    }
                  } else if (c1 == 0 && c7 == 29) {
                    fprintf(f, "x q[%u];\n", 17);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c9 + 5);
                    }
                  } else if (c1 == 0 && c7 == 27) {
                    fprintf(f, "cx q[%u], q[%u];\n", 7, 14);
                    fprintf(f, "cx q[%u], q[%u];\n", 11, 0);
                  }
                }
              }
            }
            if (c1 == 0 && c2 + c5 == 1) {
              for (int c7 = max(29, -7 * c2 + 32); c7 <= -8 * c2 + 37; c7 += 1) {
                if (c2 == 1 && c7 == 29) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 18, -4 * c4 + 7);
                } else if (c7 == 36) {
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c9 + 16, 11 * c9 + 2);
                  }
                } else {
                  if (c7 == 35) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -15 * c9 + 16);
                    }
                  } else if (c7 == 34) {
                    fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 13 * c9 + 3);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 4 * c9 + 10, 11 * c9 + 2);
                    }
                  } else if (c7 == 33) {
                    fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
                    fprintf(f, "cx q[%u], q[%u];\n", 11, 8);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c9);
                    }
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 14, 3 * c9 + 13);
                    }
                  } else if (c7 == 32) {
                    fprintf(f, "cx q[%u], q[%u];\n", 14, 19);
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c9 + 2, 4 * c9 + 3);
                    }
                    fprintf(f, "x q[%u];\n", 13);
                  }
                  if ((c7 + 1) % 3 == 0) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", -2 * c7 + 8 * c9 + 72);
                    }
                  }
                  if (c7 <= 33) {
                    fprintf(f, "x q[%u];\n", 7 * c7 - 212);
                  } else if (c7 == 37) {
                    for (int c9 = 0; c9 <= 1; c9 += 1) {
                      fprintf(f, "x q[%u];\n", 5 * c9 + 8);
                    }
                  }
                }
              }
              if (c2 == 1 && c4 == 1) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c9 + 3);
                }
              }
            } else if (c1 == 1 && c2 == 0 && c4 == 1 && c5 == 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4, 11);
              fprintf(f, "x q[%u];\n", 0);
              fprintf(f, "cx q[%u], q[%u];\n", 0, 14);
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c9 + 4);
              }
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c9 + 11);
              }
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 12 * c9 + 2, 10 * c9 + 7);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 14, 17);
              for (int c7 = 30; c7 <= 31; c7 += 1) {
                if (c7 == 31) {
                  fprintf(f, "cx q[%u], q[%u];\n", 19, 17);
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", 19, 17);
                }
              }
            } else if (c1 == 0 && c2 == 1 && c4 == 0 && c5 == 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 9, 18);
              fprintf(f, "x q[%u];\n", 9);
              fprintf(f, "x q[%u];\n", 9);
            } else if (c1 == 1 && c2 == 1 && c4 == 1 && c5 == 1) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -11 * c9 + 18, c9 + 14);
              }
            }
            if (c1 == 0 && c2 == 2 && c4 == 1 && c5 == 1) {
              fprintf(f, "x q[%u];\n", 3);
              fprintf(f, "x q[%u];\n", 3);
              fprintf(f, "cx q[%u], q[%u];\n", 12, 4);
            }
            if (c1 == 0 && c4 == 1 && c5 == 0) {
              for (int c7 = 0; c7 <= c2; c7 += 1) {
                fprintf(f, "x q[%u];\n", -9 * c2 + 8 * c7 + 16);
              }
              if (c2 == 1) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "x q[%u];\n", -5 * c7 + 12);
                }
              } else if (c2 == 0) {
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c7 + 16, 15 * c7 + 2);
                }
                for (int c7 = 0; c7 <= 1; c7 += 1) {
                  for (int c8 = 0; c8 <= c7; c8 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c7 + 16 * c8 + 1);
                  }
                }
              }
            } else if (c1 == 0 && c2 == 1 && c4 == 2 && c5 == 1) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c9 + 10, 6 * c9 + 9);
              }
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c9 + 1);
              }
            } else if (c1 == 1 && c2 == 0 && c4 == 1 && c5 == 1) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c9 + 17);
              }
            }
          }
          if (c1 == 1 && c2 == 1 && c4 == 1) {
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c9 + 7);
            }
          } else if (c1 == 0 && c2 == 0 && c4 == 1) {
            fprintf(f, "x q[%u];\n", 17);
            fprintf(f, "cx q[%u], q[%u];\n", 14, 17);
            fprintf(f, "x q[%u];\n", 4);
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 2 * c9 + 12, 13 * c9 + 4);
            }
            fprintf(f, "x q[%u];\n", 12);
            fprintf(f, "x q[%u];\n", 12);
            for (int c7 = 22; c7 <= 37; c7 += 15) {
              fprintf(f, "x q[%u];\n", (7 * c7 - 139) / 15);
              if (c7 == 22) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 12 * c9 + 1, 5 * c9 + 12);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "x q[%u];\n", -5 * c9 + 12 * c10 + 6);
                  }
                }
                fprintf(f, "x q[%u];\n", 6);
                fprintf(f, "x q[%u];\n", 6);
                fprintf(f, "x q[%u];\n", 11);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c9 + 11);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 11, 0);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c9 + 11, 8 * c9 + 8);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c9 + 8);
                }
              }
            }
            fprintf(f, "x q[%u];\n", 6);
            fprintf(f, "x q[%u];\n", 6);
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c9 + 11, 8 * c9);
            }
            fprintf(f, "x q[%u];\n", 11);
          }
        }
        if (c1 == 0 && c2 == 0) {
          fprintf(f, "x q[%u];\n", 12);
        } else if (c1 == 1 && c2 == 0) {
          fprintf(f, "x q[%u];\n", 8);
        }
      }
      if (c1 >= 1 && c2 == 0) {
        fprintf(f, "x q[%u];\n", -10 * c1 + 25);
      }
    }
  }
  fprintf(f, "x q[%u];\n", 14);
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 7 * c1 + 11, c1 + 6);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 7 * c1 + 2);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c1, 4 * c1 + 8);
  }
}
fclose(f);
return 0;
}