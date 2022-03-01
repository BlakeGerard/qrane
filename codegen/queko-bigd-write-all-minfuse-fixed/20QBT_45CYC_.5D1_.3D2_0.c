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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.5D1_.3D2_0.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 4; c1 += 1) {
    if (c1 == 1) {
      for (int c13 = 0; c13 <= 2; c13 += 1) {
        fprintf(f, "x q[%u];\n", 7 * c13 + 2);
      }
      for (int c13 = 0; c13 <= 2; c13 += 1) {
        fprintf(f, "x q[%u];\n", 7 * c13 + 2);
      }
    }
    if (c1 <= 1) {
      if (c1 == 1) {
        fprintf(f, "x q[%u];\n", 6);
        fprintf(f, "cx q[%u], q[%u];\n", 17, 6);
      } else {
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          if (c4 == 1) {
            fprintf(f, "x q[%u];\n", 5);
          }
          if (c4 == 0) {
            for (int c13 = 0; c13 <= 3; c13 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c13 + 2);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 6, 8);
          }
          for (int c11 = c4 + 14; c11 <= -c4 + 16; c11 += 1) {
            if (c4 == 0 && c11 == 15) {
              for (int c13 = 0; c13 <= 2; c13 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c13 + 3);
              }
            }
            if (c11 == 15) {
              if (c4 == 1) {
                fprintf(f, "x q[%u];\n", 5);
              } else {
                for (int c13 = 0; c13 <= 2; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c13);
                }
              }
              if (c4 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", 7, 5);
              }
            } else {
              if (c11 == 16) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  for (int c14 = 0; c14 <= -c13 + 2; c14 += 1) {
                    fprintf(f, "x q[%u];\n", -5 * c13 + 2 * c14 + 10);
                  }
                }
                fprintf(f, "cx q[%u], q[%u];\n", 3, 13);
              }
              for (int c13 = 0; c13 <= (-c11 / 2) + 10; c13 += 1) {
                fprintf(f, "x q[%u];\n", (-11 * c11 / 2) + 2 * c13 + 88);
              }
              if (c11 == 14) {
                fprintf(f, "cx q[%u], q[%u];\n", 6, 7);
                for (int c13 = 0; c13 <= 2; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c13);
                }
              }
            }
          }
          if (c4 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", 12, 3);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c13 + 8);
            }
          }
          if (c4 == 0) {
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 2 * c13 + 5);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 3, 13);
          }
        }
      }
      if (c1 == 0) {
        for (int c2 = 2; c2 <= 3; c2 += 1) {
          for (int c4 = 0; c4 <= -c2 + 3; c4 += 1) {
            if (c2 == 2) {
              if (c4 == 1) {
                fprintf(f, "x q[%u];\n", 5);
              } else {
                for (int c13 = 0; c13 <= 2; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c13);
                }
              }
            }
            if (c4 == 0) {
              if (c2 == 3) {
                fprintf(f, "x q[%u];\n", 0);
              } else {
                for (int c8 = 0; c8 <= 3; c8 += 1) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 10 * c14 + 3);
                  }
                  if (c8 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 0);
                    for (int c11 = 14; c11 <= 15; c11 += 1) {
                      fprintf(f, "x q[%u];\n", -13 * c11 + 195);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 13);
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 13);
                    fprintf(f, "x q[%u];\n", 0);
                  }
                }
              }
            }
          }
          if (c2 == 3) {
            fprintf(f, "x q[%u];\n", 0);
          }
        }
      }
    } else if (c1 <= 3) {
      if (c1 == 3) {
        fprintf(f, "x q[%u];\n", 10);
      } else {
        for (int c13 = 0; c13 <= 2; c13 += 1) {
          fprintf(f, "x q[%u];\n", 5 * c13 + 9);
        }
        for (int c13 = 0; c13 <= 1; c13 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c13 + 2);
        }
        for (int c13 = 0; c13 <= 1; c13 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c13 + 2);
        }
        for (int c13 = 0; c13 <= 1; c13 += 1) {
          for (int c14 = 0; c14 <= -c13 + 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", -2 * c13 + 7 * c14 + 2);
          }
        }
        for (int c13 = 0; c13 <= 1; c13 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c13 + 2);
        }
        for (int c13 = 0; c13 <= 1; c13 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c13 + 2);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 12, 14);
        fprintf(f, "cx q[%u], q[%u];\n", 4, 12);
        fprintf(f, "x q[%u];\n", 12);
      }
    }
    for (int c2 = 1; c2 < 2 * c1 - 3; c2 += 1) {
      if (c1 == 4 && c2 == 3) {
        for (int c4 = -1; c4 <= 0; c4 += 1) {
          fprintf(f, "x q[%u];\n", 16);
        }
      }
      if (c1 == 4 && c2 >= 3) {
        fprintf(f, "x q[%u];\n", 16);
        if (c2 == 4) {
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", c13 + 16);
          }
        }
      } else if (c1 == 4 && c2 == 1) {
        for (int c11 = 0; c11 <= 1; c11 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 9 * c11 + 8, 4 * c11 + 2);
        }
      }
      if (2 * ((c2 - 1) / 3) + 2 >= c2) {
        if (c1 == 3 && c2 == 1) {
          for (int c4 = -2; c4 < 0; c4 += 1) {
            for (int c13 = 0; c13 <= c4 + 2; c13 += 1) {
              fprintf(f, "x q[%u];\n", -4 * c4 + 4 * c13 + 11);
            }
          }
        }
        if (c1 == 3 && c2 == 2) {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            if (c9 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", 17, 6);
              fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
            }
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 13 * c13 + 6);
            }
          }
        }
        for (int c9 = max(c1 - 1, -c2 + 4); c9 <= 3; c9 += 1) {
          if (c9 == 3) {
            if (c1 == 3 && c2 == 1) {
              fprintf(f, "x q[%u];\n", 1);
            }
            if ((c2 - 1) % 3 == 0) {
              for (int c13 = 0; c13 <= min(c1 - 3, (-c2 + 4) / 3); c13 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c2 + 17 * c13 - 2);
              }
            } else if (c1 == 3 && c2 == 2) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", c13 + 15);
              }
            }
            if (c1 + c2 == 5) {
              if (c1 == 3) {
                fprintf(f, "x q[%u];\n", 15);
              } else {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c13 + 7, 5 * c13 + 14);
                }
              }
              if (c1 == 4) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c13 + 14);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c13 + 2);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 15 * c13 + 2);
                }
              }
            } else if (c1 == 3 && c2 == 1) {
              for (int c11 = 2; c11 <= 3; c11 += 1) {
                if (c11 == 3) {
                  fprintf(f, "x q[%u];\n", 1);
                } else {
                  fprintf(f, "x q[%u];\n", 1);
                }
              }
              for (int c11 = 4; c11 <= 5; c11 += 1) {
                if (c11 == 5) {
                  fprintf(f, "x q[%u];\n", 1);
                } else {
                  fprintf(f, "x q[%u];\n", 1);
                }
              }
              fprintf(f, "x q[%u];\n", 1);
              fprintf(f, "x q[%u];\n", 1);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c13 + 11);
              }
              fprintf(f, "x q[%u];\n", 1);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c13 + 8, 8 * c13 + 7);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c13 + 4 * c14 + 7);
                }
              }
              fprintf(f, "x q[%u];\n", 1);
            }
            if (c2 == 1) {
              if (c1 == 4) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c13 + 12);
                }
              }
              for (int c13 = 0; c13 < c1 - 2; c13 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c1 + 3 * c13 - 5);
              }
              if (c1 == 4) {
                fprintf(f, "x q[%u];\n", 17);
              } else {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c13 + 8);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 6 * c13 + 13, c13);
                }
              }
              for (int c11 = 11; c11 <= -c1 + 15; c11 += 1) {
                if (c11 == 11) {
                  for (int c13 = 0; c13 < c1 - 2; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c1 + 3 * c13 - 5);
                  }
                  if (c1 == 3) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 19);
                    fprintf(f, "x q[%u];\n", 17);
                  }
                  for (int c13 = 0; c13 <= -c1 + 4; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c1 + 4 * c13 - 7);
                  }
                  if (c1 == 4) {
                    fprintf(f, "cx q[%u], q[%u];\n", 12, 5);
                    fprintf(f, "cx q[%u], q[%u];\n", 19, 8);
                  } else if (c1 == 3) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", c13);
                    }
                  }
                } else {
                  fprintf(f, "x q[%u];\n", 11);
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", c13);
                  }
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9 * c13 + 8, 2 * c13 + 7);
                  }
                  fprintf(f, "x q[%u];\n", 19);
                }
              }
              if (c1 == 3) {
                for (int c11 = 13; c11 <= 15; c11 += 1) {
                  if (c11 == 15) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 10 * c13 + 4);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c13 + 9);
                    }
                    fprintf(f, "x q[%u];\n", 13);
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -6 * c13 + 12, 3 * c13 + 5);
                    }
                  } else if (c11 == 14) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c13 + 4);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", c13);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 7 * c13 + 9);
                    }
                    fprintf(f, "x q[%u];\n", 7);
                    fprintf(f, "x q[%u];\n", 13);
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 12 * c13 + 5);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", -10 * c13 + 18);
                    }
                  } else {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", c13);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -6 * c13 + 18, 10 * c13 + 4);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -6 * c13 + 15, 3 * c13 + 16);
                    }
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c13 + 7, c13 + 5);
                    }
                  }
                }
              } else if (c1 == 4) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 9 * c13 + 8, 7 * c13 + 2);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", c13 + 6);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c13 + 4);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", c13 + 6);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c13 + 4);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 15 * c13 + 2);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 11, 19);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", c13 + 4);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c13 + 7, 7 * c13 + 12);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c13 + 8);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c13 + 6);
                }
                fprintf(f, "x q[%u];\n", 19);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 12 * c13 + 3, 4 * c13);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c13 + 9);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 8, 2);
              }
            }
            if (c2 <= 2) {
              if (c1 == 3 && c2 == 2) {
                fprintf(f, "cx q[%u], q[%u];\n", 18, 16);
              } else if (c1 == 4 && c2 == 1) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c13 + 6 * c14 + 2);
                  }
                }
                fprintf(f, "x q[%u];\n", 19);
                fprintf(f, "x q[%u];\n", 3);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c13 + 9);
                }
              } else if (c1 == 3 && c2 == 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 12, 14);
                fprintf(f, "x q[%u];\n", 16);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c13 + 5);
                }
              }
              for (int c13 = 0; c13 < c1 - 2; c13 += 1) {
                fprintf(f, "x q[%u];\n", -13 * c1 + 15 * c13 + 52);
              }
              if (c1 == 3 && c2 == 1) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 10 * c13 + 9);
                }
              }
              if (c1 == 3 && c2 == 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 8, 2);
                fprintf(f, "cx q[%u], q[%u];\n", 14, 5);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", c13 + 15);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 10 * c13 + 2);
                }
              } else {
                if (c1 == 4 && c2 == 2) {
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c13);
                  }
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 14 * c13 + 1, 14 * c13 + 4);
                  }
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c13 + 15);
                  }
                } else if (c1 == 3 && c2 == 2) {
                  for (int c11 = 8; c11 <= 10; c11 += 1) {
                    if (c11 == 10) {
                      fprintf(f, "cx q[%u], q[%u];\n", 4, 16);
                      fprintf(f, "cx q[%u], q[%u];\n", 11, 1);
                      for (int c13 = 0; c13 <= 1; c13 += 1) {
                        fprintf(f, "x q[%u];\n", 9 * c13 + 5);
                      }
                    } else if (c11 == 9) {
                      fprintf(f, "cx q[%u], q[%u];\n", 4, 16);
                      fprintf(f, "x q[%u];\n", 11);
                    } else {
                      fprintf(f, "cx q[%u], q[%u];\n", 4, 16);
                    }
                  }
                }
                if (c2 == 2) {
                  if (c1 == 3) {
                    fprintf(f, "x q[%u];\n", 13);
                  }
                  for (int c13 = 0; c13 < c1 - 2; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c1 + 3 * c13 - 5);
                  }
                  if (c1 == 3) {
                    fprintf(f, "cx q[%u], q[%u];\n", 1, 3);
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 10 * c13 + 6);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 7, 5);
                    fprintf(f, "cx q[%u], q[%u];\n", 8, 2);
                  }
                  if (c1 == 4) {
                    for (int c11 = 13; c11 <= 14; c11 += 1) {
                      if (c11 == 14) {
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 9 * c13 + 8, 2 * c13 + 7);
                        }
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", -c13 + 14);
                        }
                      } else {
                        fprintf(f, "x q[%u];\n", 14);
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 4 * c13 + 8);
                        }
                      }
                    }
                    for (int c11 = 15; c11 <= 16; c11 += 1) {
                      if (c11 == 16) {
                        fprintf(f, "x q[%u];\n", 13);
                      } else {
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", c13 + 4, 10 * c13 + 3);
                        }
                      }
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 14, 5);
                  } else if (c1 == 3) {
                    for (int c11 = 12; c11 <= 15; c11 += 1) {
                      if (c11 == 15) {
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 8 * c13 + 5);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 11, 1);
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 6 * c13 + 2);
                        }
                        fprintf(f, "x q[%u];\n", 10);
                        fprintf(f, "x q[%u];\n", 17);
                      } else if (c11 == 14) {
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 8 * c13 + 5);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 9, 11);
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 10 * c13 + 7);
                        }
                        fprintf(f, "x q[%u];\n", 15);
                        fprintf(f, "cx q[%u], q[%u];\n", 8, 2);
                      } else if (c11 == 13) {
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 17 * c13 + 1);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 8, 7);
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c13 + 3 * c14 + 2);
                          }
                        }
                        fprintf(f, "x q[%u];\n", 11);
                      } else {
                        fprintf(f, "cx q[%u], q[%u];\n", 9, 1);
                        fprintf(f, "x q[%u];\n", 11);
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 13 * c13 + 6);
                        }
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 6 * c13 + 2);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 5, 13);
                      }
                    }
                  }
                  if (c1 == 4) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c13 + 5);
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 5);
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 10 * c13 + 1);
                    }
                  }
                }
              }
              if (c1 == 3) {
                for (int c11 = -2 * c2 + 21; c11 <= 19; c11 += 1) {
                  if (c2 == 2 && c11 == 19) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", c13 + 11);
                    }
                  } else if (c2 == 1 && c11 == 19) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c13 + 8);
                    }
                  } else if (c11 == 18) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 7 * c13 + 4, 7 * c13 + 12);
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 11);
                  }
                }
                if (c2 == 2) {
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c13 + 11);
                  }
                  fprintf(f, "x q[%u];\n", 3);
                } else if (c2 == 1) {
                  fprintf(f, "x q[%u];\n", 9);
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c13 + 8);
                  }
                }
                fprintf(f, "x q[%u];\n", -8 * c2 + 19);
              } else if (c1 == 4 && c2 == 1) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 15 * c13);
                }
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c13 + 2);
                }
                for (int c11 = 18; c11 <= 19; c11 += 1) {
                  if (c11 == 19) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c13 + 2);
                    }
                  } else {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c13 + 2);
                    }
                  }
                }
                fprintf(f, "x q[%u];\n", 14);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c13 + 2);
                }
                fprintf(f, "x q[%u];\n", 14);
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c13 + 2);
                }
              }
            }
          } else {
            fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 13 * c13 + 6);
            }
          }
        }
        if (c1 == 3 && c2 == 2) {
          for (int c8 = 1; c8 <= 3; c8 += 1) {
            fprintf(f, "x q[%u];\n", 5);
          }
        }
        if (c1 == 4 && c2 == 1) {
          for (int c5 = 1; c5 <= 3; c5 += 1) {
            fprintf(f, "x q[%u];\n", 14);
            if (c5 == 3) {
              fprintf(f, "x q[%u];\n", 14);
            }
          }
        }
        if (c2 <= 2) {
          if (c1 == 3) {
            fprintf(f, "x q[%u];\n", 8 * c2 - 1);
            if (c2 == 1) {
              fprintf(f, "x q[%u];\n", 7);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c13 + 7, 5 * c13 + 14);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 2, 14);
              fprintf(f, "x q[%u];\n", 14);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c13 + 5);
              }
            }
          } else {
            fprintf(f, "x q[%u];\n", 10 * c2 - 7);
            if (c2 == 1) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 15 * c13 + 4, 5 * c13 + 3);
              }
              fprintf(f, "x q[%u];\n", 19);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", -3 * c13 + c14 + 6);
                }
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 3 * c13 + 8, 12 * c13 + 7);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -7 * c13 + 8, 5 * c13 + 7);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c13 + 1);
              }
            }
          }
          if (c2 == 1) {
            fprintf(f, "x q[%u];\n", 6 * c1 - 18);
          }
          if (c1 == 4) {
            fprintf(f, "x q[%u];\n", 19);
          }
        }
        if (c1 == 4 && c2 == 2) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -13 * c4 + 19, c4 + 7);
          }
        } else if (c1 == 3 && c2 == 2) {
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", -c13 + 15);
          }
        } else if (c1 == 4 && c2 == 1) {
          for (int c4 = 0; c4 <= 3; c4 += 1) {
            fprintf(f, "x q[%u];\n", 5);
          }
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c4 + 5);
          }
        } else if (c1 == 3 && c2 == 1) {
          for (int c11 = 21; c11 <= 22; c11 += 1) {
            fprintf(f, "x q[%u];\n", 12 * c11 - 245);
          }
        }
      } else {
        fprintf(f, "cx q[%u], q[%u];\n", 9, 11);
        for (int c4 = 0; c4 <= 1; c4 += 1) {
          if (c4 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", 11, 1);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c13 + 7);
            }
          }
          fprintf(f, "x q[%u];\n", 9);
          if (c4 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", 19, 8);
          }
        }
        fprintf(f, "cx q[%u], q[%u];\n", 9, 1);
      }
    }
    if (c1 <= 3) {
      for (int c2 = 2 * c1 - 3; c2 < 3 * c1 - 4; c2 += 1) {
        if (c1 == 3 && c2 == 3) {
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", -c13 + 15);
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c13 + 15);
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -17 * c13 + 18, 8 * c13 + 4);
          }
        }
        if (c1 == 2 && c2 == 1) {
          fprintf(f, "x q[%u];\n", 14);
        }
        if (c1 == 2 && c2 == 1) {
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", 8 * c13 + 2);
          }
        }
        if (c1 == 3 && c2 == 4) {
          for (int c9 = 0; c9 <= 2; c9 += 1) {
            if (c9 == 0) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c13 + 9);
              }
            }
            fprintf(f, "x q[%u];\n", 9);
            if (c9 == 0) {
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c11 + 8, 4 * c11 + 2);
              }
            }
          }
        }
        if (c1 == 3 && c2 == 4) {
          for (int c11 = 9; c11 <= 10; c11 += 1) {
            if (c11 == 10) {
              fprintf(f, "x q[%u];\n", 13);
            } else {
              fprintf(f, "x q[%u];\n", 13);
            }
          }
          fprintf(f, "cx q[%u], q[%u];\n", 3, 13);
        } else if (c1 == 3) {
          for (int c11 = 6; c11 <= 10; c11 += 1) {
            if (c11 == 9) {
              fprintf(f, "x q[%u];\n", 3);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 14 * c13 + 3 * c14 + 1);
                }
              }
              fprintf(f, "x q[%u];\n", 17);
            } else {
              if ((c11 + 2) % 4 == 0) {
                fprintf(f, "x q[%u];\n", (-17 * c11 + 174) / 4);
              }
              if (c11 >= 8 && c11 % 2 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", (-11 * c11 / 2) + 59, -c11 + 26);
                if (c11 == 10) {
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c13 + 2);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 3, 13);
                }
              }
              if (c11 == 7) {
                for (int c13 = 0; c13 <= 1; c13 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c13 + 12);
                }
              }
            }
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c13 + 13, 9 * c13);
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -2 * c13 + 6, 9 * c13 + 7);
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", c13 + 2);
          }
        }
        if (c1 == 3) {
          if (c2 == 4) {
            fprintf(f, "x q[%u];\n", 16);
            fprintf(f, "x q[%u];\n", 9);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 10 * c13 + 3);
            }
          } else {
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", c13 + 15);
            }
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 9 * c13);
            }
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 2 * c13 + 4, 4 * c13 + 3);
            }
          }
          if (c2 == 3) {
            fprintf(f, "cx q[%u], q[%u];\n", 10, 0);
            fprintf(f, "x q[%u];\n", 16);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c13 + 9);
            }
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c13 + 3);
            }
            fprintf(f, "x q[%u];\n", 4);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 5 * c13 + 1, 5 * c13 + 3);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 17, 9);
          } else if (c2 == 4) {
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 3 * c13 + 9);
            }
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 10 * c13 + 3);
            }
          }
        } else {
          fprintf(f, "cx q[%u], q[%u];\n", 11, 1);
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", 17 * c13 + 2);
          }
          fprintf(f, "x q[%u];\n", 8);
        }
        if (c2 + 5 == 3 * c1) {
          if (c1 == 3) {
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c13 + 12);
            }
          }
          for (int c13 = 0; c13 < c1 - 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", -5 * c1 + 10 * c13 + 18);
          }
          if (c1 == 2) {
            fprintf(f, "cx q[%u], q[%u];\n", 11, 15);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 9 * c13 + 10);
            }
          }
        }
        if (c1 == 3) {
          if (c2 == 4) {
            fprintf(f, "x q[%u];\n", 10);
          } else {
            fprintf(f, "x q[%u];\n", 3);
            fprintf(f, "cx q[%u], q[%u];\n", 1, 4);
            fprintf(f, "x q[%u];\n", 13);
          }
        } else {
          for (int c11 = 15; c11 <= 17; c11 += 1) {
            if (c11 == 17) {
              fprintf(f, "cx q[%u], q[%u];\n", 8, 7);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", -5 * c13 + 19);
              }
              fprintf(f, "x q[%u];\n", 10);
              fprintf(f, "cx q[%u], q[%u];\n", 11, 15);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 15 * c13 + 3);
              }
            } else if (c11 == 16) {
              fprintf(f, "cx q[%u], q[%u];\n", 19, 7);
              fprintf(f, "x q[%u];\n", 14);
              fprintf(f, "cx q[%u], q[%u];\n", 11, 15);
              fprintf(f, "cx q[%u], q[%u];\n", 18, 4);
              fprintf(f, "x q[%u];\n", 10);
            } else {
              fprintf(f, "cx q[%u], q[%u];\n", 19, 8);
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 10 * c13 + 3);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", c13 + 10);
              }
              fprintf(f, "x q[%u];\n", 4);
              fprintf(f, "cx q[%u], q[%u];\n", 15, 18);
            }
          }
          fprintf(f, "cx q[%u], q[%u];\n", 11, 15);
          fprintf(f, "x q[%u];\n", 10);
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 6 * c13 + 6, 6 * c13 + 8);
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", 15 * c13 + 3);
          }
          for (int c11 = 19; c11 <= 25; c11 += 1) {
            if (c11 >= 21 && c11 <= 22) {
              fprintf(f, "x q[%u];\n", 12 * c11 - 248);
            } else if (c11 == 20) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c13 + 6);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -9 * c13 + 13, 16 * c13);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c13 + 8);
              }
            } else if (c11 == 19) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -5 * c13 + 17, 8 * c13 + 6);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -4 * c13 + 15, 3 * c13 + 16);
              }
            }
            if (c11 % 3 == 0) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", (-2 * c11 / 3) + 6 * c13 + 20);
              }
            }
            for (int c13 = 0; c13 <= min(c11 - 19, -c11 + 21); c13 += 1) {
              if (c11 == 20) {
                fprintf(f, "x q[%u];\n", 7 * c13 + 7);
                if (c13 == 0) {
                  fprintf(f, "x q[%u];\n", 7);
                }
              }
              if (c11 >= 20 && c13 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c11 + 179, 8 * c11 - 153);
              }
              if (c11 <= 20 && c13 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", -3 * c11 + 67, c11 - 6);
              }
            }
            if (c11 == 25) {
              fprintf(f, "x q[%u];\n", 10);
            } else if (c11 == 23) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 14 * c13 + 4);
              }
            } else if (c11 == 22) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c13 + 18, 9 * c13 + 4);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c13 + 6);
              }
            } else if (c11 == 21) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c13 + 10);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 16 * c13);
              }
            } else if (c11 == 19) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c13);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", c13 + 3);
              }
            }
          }
        }
        if (c1 == 3 && c2 == 3) {
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", 10 * c13);
          }
          for (int c13 = 0; c13 <= 1; c13 += 1) {
            fprintf(f, "x q[%u];\n", 10 * c13);
          }
          for (int c8 = 0; c8 <= 1; c8 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 4 * c8 + 11, 17 * c8 + 1);
          }
        }
        if (c1 == 3 && c2 == 3) {
          for (int c6 = 1; c6 <= 3; c6 += 1) {
            for (int c11 = 3; c11 <= 5; c11 += 2) {
              fprintf(f, "x q[%u];\n", (-17 * c11 + 87) / 2);
            }
          }
        }
        if (c1 == 2 && c2 == 1) {
          for (int c11 = 4; c11 <= 5; c11 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c11 - 5);
          }
        }
        if (c1 == 3 && c2 == 4) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "x q[%u];\n", 10);
          }
          fprintf(f, "x q[%u];\n", 10);
        }
      }
      if (c1 >= 1 && c1 <= 2) {
        for (int c2 = 2; c2 <= 3; c2 += 1) {
          if (c1 == 2) {
            fprintf(f, "x q[%u];\n", 16);
          } else {
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              for (int c14 = 0; c14 <= -c13 + 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", -c13 + 11 * c14 + 6);
              }
            }
          }
          if (c2 == 3) {
            fprintf(f, "x q[%u];\n", 5);
          }
          if (c1 == 2) {
            fprintf(f, "x q[%u];\n", 17);
            if (c2 == 3) {
              fprintf(f, "cx q[%u], q[%u];\n", 18, 16);
            }
          } else if (c2 == 3) {
            fprintf(f, "x q[%u];\n", 0);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              if (c13 == 1) {
                fprintf(f, "x q[%u];\n", 0);
              } else {
                for (int c14 = 0; c14 <= 2; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c14 + 2);
                }
              }
            }
          }
          if (c2 == 3) {
            for (int c13 = 0; c13 <= -c1 + 2; c13 += 1) {
              fprintf(f, "x q[%u];\n", 11 * c1 + 11 * c13 - 5);
            }
            if (c1 == 2) {
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c13 + 4);
              }
              for (int c13 = 0; c13 <= 1; c13 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -6 * c13 + 18, 10 * c13 + 4);
              }
            }
          }
        }
      }
    } else {
      for (int c13 = 0; c13 <= 1; c13 += 1) {
        fprintf(f, "x q[%u];\n", c13 + 16);
      }
      fprintf(f, "x q[%u];\n", 16);
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", c1 + 3, 6 * c1 + 10);
  }
}
fclose(f);
return 0;
}