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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.4D1_.1D2_0.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 4; c0 += 1) {
  if (c0 >= 2) {
    if (c0 == 2) {
      for (int c3 = 0; c3 <= 2; c3 += 1) {
        fprintf(f, "x q[%u];\n", 5 * c3 + 1);
      }
      for (int c3 = 0; c3 <= 2; c3 += 1) {
        fprintf(f, "x q[%u];\n", 5 * c3 + 1);
      }
      for (int c1 = 2; c1 <= 27; c1 += 1) {
        if (c1 == 27) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "x q[%u];\n", 13);
            if (c4 == 0) {
              fprintf(f, "x q[%u];\n", 13);
            }
          }
        } else if (c1 == 26) {
          fprintf(f, "cx q[%u], q[%u];\n", 5, 12);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c3 + 17, 3 * c3 + 13);
          }
        } else if (c1 == 2) {
          fprintf(f, "x q[%u];\n", 1);
        } else if ((c1 - 7) % 18 == 0) {
          for (int c3 = 0; c3 <= (-c1 + 25) / 18; c3 += 1) {
            fprintf(f, "x q[%u];\n", ((8 * c1 - 47) / 9) + 13 * c3);
          }
          if (c1 == 25) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 3 * c3 + 12);
            }
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", c3 + 2);
            }
          }
        } else if (c1 == 24) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 10 * c3 + 5);
          }
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", 13 * c3 + 3 * c4 + 4);
            }
          }
        } else {
          if (c1 == 23) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
                fprintf(f, "x q[%u];\n", 13 * c3 + 3 * c4 + 4);
              }
            }
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 10 * c3 + 5);
            }
          } else {
            if (c1 == 22) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 13 * c3 + 2);
              }
            } else if (c1 == 20) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 12 * c3 + 5, 3 * c3 + 12);
              }
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c3 + 13);
              }
            } else if (c1 == 15) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c3 + 13);
              }
            }
            if (c1 >= 18 && c1 % 2 == 0) {
              fprintf(f, "x q[%u];\n", (-3 * c1 / 2) + 34);
              if (c1 == 22) {
                fprintf(f, "x q[%u];\n", 17);
              }
              if (c1 == 22) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
                    fprintf(f, "x q[%u];\n", 9 * c3 + 3 * c4 + 4);
                  }
                }
              }
              if (c1 == 18) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c3 + 13);
                }
              }
            } else {
              if (c1 == 21) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c3 + 13);
                }
                fprintf(f, "x q[%u];\n", 17);
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c3 + 15, 10 * c3 + 2);
                }
              } else if (c1 == 19) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c3 + 13);
                }
                for (int c3 = 0; c3 <= 2; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c3 + 7);
                }
              }
              if (c1 == 17) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c3 + 13);
                }
                for (int c3 = 0; c3 <= 2; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c3 + 1);
                }
              } else if (c1 == 16) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c3 + 13);
                }
                for (int c3 = 0; c3 <= 2; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c3 + 1);
                }
              } else if (c1 == 15) {
                for (int c3 = 0; c3 <= 2; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c3 + 1);
                }
              } else if (c1 == 10) {
                for (int c3 = 0; c3 <= 1; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 14 * c3 + 1);
                }
              } else if (c1 == 8) {
                for (int c3 = 0; c3 <= 2; c3 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c3 + 1);
                }
              } else {
                if (c1 == 5) {
                  for (int c3 = 0; c3 <= 1; c3 += 1) {
                    fprintf(f, "x q[%u];\n", 14 * c3);
                  }
                } else if (c1 == 4) {
                  fprintf(f, "x q[%u];\n", 1);
                } else if (c1 == 3) {
                  fprintf(f, "x q[%u];\n", 1);
                }
                if (c1 <= 12 && (c1 + 2) % 7 == 0) {
                  for (int c3 = 0; c3 <= (-c1 + 19) / 7; c3 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c3 + 1);
                  }
                }
              }
            }
          }
          if ((c1 - 6) % 17 == 0) {
            for (int c3 = 0; c3 <= (-c1 + 23) / 17; c3 += 1) {
              fprintf(f, "x q[%u];\n", ((12 * c1 - 55) / 17) + 13 * c3);
            }
          } else if (c1 >= 11 && c1 <= 14 && (c1 + 1) % 3 == 0) {
            for (int c3 = 0; c3 <= (-c1 + 17) / 3; c3 += 1) {
              fprintf(f, "x q[%u];\n", 3 * c3 + 1);
            }
            if (c1 == 14) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c3 + 13);
              }
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 15 * c3 + 3);
              }
            }
          } else if (c1 == 4) {
            for (int c3 = 0; c3 <= 2; c3 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c3 + 6);
            }
          }
        }
        if (c1 >= 24 && c1 % 3 == 0) {
          fprintf(f, "cx q[%u], q[%u];\n", (2 * c1 / 3) - 13, (10 * c1 / 3) - 78);
        } else if (c1 >= 9 && c1 <= 13 && (c1 - 1) % 4 == 0) {
          for (int c3 = 0; c3 <= (-c1 + 17) / 4; c3 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c3 + 1);
          }
        }
      }
    } else if (c0 == 3) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 18 * c3);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 8 * c3);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 4 * c3 + 2);
      }
      for (int c4 = 0; c4 <= 1; c4 += 1) {
        fprintf(f, "x q[%u];\n", 6 * c4 + 10);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 3 * c3 + 11);
      }
      fprintf(f, "x q[%u];\n", 6);
      fprintf(f, "cx q[%u], q[%u];\n", 9, 8);
    }
    for (int c1 = max(3, -25 * c0 + 78); c1 <= min(28, -25 * c0 + 103); c1 += 1) {
      if (c0 == 2 && c1 == 28) {
        for (int c3 = 0; c3 <= 1; c3 += 1) {
          fprintf(f, "x q[%u];\n", 4 * c3 + 13);
        }
      } else if (c0 == 3 && c1 == 23) {
        for (int c3 = 0; c3 <= 1; c3 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c3 + 3);
        }
      } else if (c0 == 3 && c1 == 13) {
        fprintf(f, "cx q[%u], q[%u];\n", 8, 17);
        for (int c3 = 0; c3 <= 1; c3 += 1) {
          fprintf(f, "x q[%u];\n", 4 * c3 + 12);
        }
      } else {
        if (c0 == 3 && c1 >= 16 && c1 <= 20 && c1 % 4 == 0) {
          fprintf(f, "x q[%u];\n", (9 * c1 / 4) - 28);
          if (c1 == 20) {
            fprintf(f, "x q[%u];\n", 14);
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 4 * c3 + 8, 12 * c3 + 3);
            }
          }
        } else {
          if (c0 == 3 && c1 == 18) {
            fprintf(f, "x q[%u];\n", 12);
          } else if (c0 == 3 && c1 == 11) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c3 + 3);
            }
          } else {
            if (c0 == 3 && c1 == 6) {
              fprintf(f, "x q[%u];\n", 11);
            }
            if (c0 == 3 && (c1 - 6) % 19 == 0) {
              fprintf(f, "cx q[%u], q[%u];\n", (-8 * c1 + 219) / 19, (11 * c1 - 9) / 19);
            }
          }
          if (c0 == 3 && c1 >= 18 && (c1 + 3) % 7 == 0) {
            for (int c3 = 0; c3 <= (-c1 + 25) / 7; c3 += 1) {
              fprintf(f, "x q[%u];\n", c1 + c3 - 10);
            }
          }
        }
        if (c0 == 3 && c1 >= 12 && c1 % 4 == 0) {
          for (int c3 = 0; c3 <= (-c1 / 4) + 4; c3 += 1) {
            fprintf(f, "x q[%u];\n", (-c1 / 2) + 4 * c3 + 18);
          }
        }
      }
      if ((c1 - 3) % 25 == 0) {
        for (int c3 = 0; c3 <= ((-c1 + 103) / 25) - c0; c3 += 1) {
          for (int c4 = c3; c4 <= c3 + 1; c4 += 1) {
            if (c3 == 0 && (c1 - 3) % 25 == 0) {
              if (c0 == 2 && c1 == 28) {
                fprintf(f, "x q[%u];\n", 6 * c4 + 10);
              }
              fprintf(f, "x q[%u];\n", ((-c1 + 328) / 25) - c0 + 6 * c4);
            }
            if (c0 == 3 && c1 == 3) {
              fprintf(f, "x q[%u];\n", -6 * c3 + 6 * c4 + 10);
            }
            if (c0 == 2 && c1 == 28 && c3 == 1) {
              fprintf(f, "x q[%u];\n", 6 * c4 + 4);
            } else if (c0 == 3 && c1 == 3 && c3 == 0) {
              fprintf(f, "x q[%u];\n", 6 * c4 + 10);
              fprintf(f, "x q[%u];\n", 10);
              fprintf(f, "x q[%u];\n", -c4 + 10);
            }
          }
          if (c0 == 3 && c1 == 3 && c3 == 0) {
            fprintf(f, "cx q[%u], q[%u];\n", 10, 16);
          }
        }
        if (c0 == 2 && c1 == 28) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c3 + 2);
          }
        }
        if (c0 == 3 && c1 == 3) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c3 + 11);
          }
          fprintf(f, "x q[%u];\n", 6);
        }
        if (c0 == 3 && c1 == 28) {
          fprintf(f, "cx q[%u], q[%u];\n", 12, 8);
        }
      } else {
        if (c1 == 22) {
          fprintf(f, "x q[%u];\n", 14);
        } else {
          if (c1 == 21) {
            fprintf(f, "x q[%u];\n", 14);
          } else if (c1 == 12) {
            fprintf(f, "x q[%u];\n", 3);
          } else if (c1 == 4) {
            fprintf(f, "x q[%u];\n", 9);
          }
          if (c1 >= 17 && c1 <= 21 && (c1 - 1) % 4 == 0) {
            fprintf(f, "x q[%u];\n", (9 * c1 - 121) / 4);
            if (c1 == 21) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c3 + 3);
              }
            }
          } else if (c1 == 18) {
            fprintf(f, "x q[%u];\n", 14);
          } else if (c1 == 14) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", c3 + 9);
            }
          } else if (c1 == 8) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -10 * c3 + 18, c3 + 2);
            }
            fprintf(f, "x q[%u];\n", 11);
          }
        }
        if (c1 >= 19 && (c1 + 2) % 7 == 0) {
          for (int c3 = 0; c3 <= (-c1 + 26) / 7; c3 += 1) {
            fprintf(f, "x q[%u];\n", c1 + c3 - 11);
          }
        }
        if (c1 >= 15 && c1 <= 19 && (c1 + 1) % 4 == 0) {
          fprintf(f, "cx q[%u], q[%u];\n", (3 * c1 - 9) / 4, (9 * c1 - 103) / 4);
          if (c1 == 15) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c3 + 12);
            }
          }
        } else {
          if (c1 == 6) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 5 * c3 + 1);
            }
          } else if ((c1 - 5) % 12 == 0) {
            for (int c3 = 0; c3 <= (-c1 + 17) / 12; c3 += 1) {
              fprintf(f, "x q[%u];\n", ((c1 + 127) / 12) + 3 * c3);
            }
          }
          if (c1 >= 5 && c1 <= 6) {
            fprintf(f, "cx q[%u], q[%u];\n", c1 + 4, 11 * c1 - 52);
          }
        }
        if (c1 == 5) {
          fprintf(f, "cx q[%u], q[%u];\n", 6, 1);
        } else if (c1 >= 11 && (c1 + 1) % 4 == 0) {
          for (int c3 = 0; c3 <= (-c1 + 15) / 4; c3 += 1) {
            fprintf(f, "x q[%u];\n", ((-c1 + 35) / 2) + 4 * c3);
          }
          if (c1 == 27) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", c3 + 11, 6 * c3 + 9);
            }
          } else if (c1 == 23) {
            fprintf(f, "x q[%u];\n", 14);
          }
          if (c1 == 19) {
            fprintf(f, "x q[%u];\n", 14);
          }
        } else {
          if (c1 == 22) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c3 + 3);
            }
          }
          if (c1 == 16) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c3 + 12);
            }
          } else if (c1 == 14) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c3 + 12);
            }
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", 9 * c3 + 8);
            }
          } else if (c1 == 13) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", c3 + 9);
            }
          } else if (c1 == 12) {
            for (int c3 = 0; c3 <= 1; c3 += 1) {
              fprintf(f, "x q[%u];\n", c3 + 9);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 8, 17);
          } else {
            if (c1 == 10) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c3 + 3);
              }
            } else if (c1 == 9) {
              fprintf(f, "x q[%u];\n", 3);
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 16 * c3 + 2);
              }
              fprintf(f, "x q[%u];\n", 16);
            } else if (c1 == 7) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 9 * c3 + 9, 7 * c3 + 3);
              }
              fprintf(f, "x q[%u];\n", 11);
            } else if (c0 == 3 && c1 == 4) {
              fprintf(f, "x q[%u];\n", 6);
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c3 + 11);
              }
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c3);
              }
            } else if (c0 == 3 && c1 >= 24 && c1 <= 26 && c1 % 2 == 0) {
              fprintf(f, "x q[%u];\n", -6 * c1 + 159);
            }
            if ((c1 + 4) % 14 == 0) {
              for (int c3 = 0; c3 <= (-c1 + 24) / 14; c3 += 1) {
                fprintf(f, "x q[%u];\n", ((c1 + 74) / 7) + 4 * c3);
              }
            }
          }
        }
      }
    }
    if (c0 == 2) {
      for (int c1 = 29; c1 <= 36; c1 += 1) {
        if (c1 == 36) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 18 * c3);
          }
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c3 + 2);
          }
          fprintf(f, "x q[%u];\n", 5);
        } else if (c1 == 35) {
          fprintf(f, "x q[%u];\n", 12);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c3 + 2);
          }
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -8 * c3 + 8, 15 * c3 + 3);
          }
        } else if (c1 == 34) {
          fprintf(f, "cx q[%u], q[%u];\n", 12, 8);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c3 + 2);
          }
        } else if (c1 == 33) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 10 * c3 + 2);
          }
        } else if (c1 == 32) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 3 * c3 + 2, 6 * c3 + 6);
          }
        } else if (c1 == 31) {
          fprintf(f, "x q[%u];\n", 13);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 9 * c3 + 3);
          }
        } else if (c1 == 30) {
          fprintf(f, "x q[%u];\n", 13);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 10 * c3 + 2);
          }
        } else {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c3 + 13);
          }
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c3 + 2);
          }
        }
      }
      for (int c1 = 37; c1 <= 48; c1 += 1) {
        if (c1 == 48) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c3 + 12 * c4 + 7);
            }
          }
        } else if (c1 == 47) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c3 + 12 * c4 + 7);
            }
          }
        } else if (c1 == 46) {
          fprintf(f, "x q[%u];\n", 15);
        }
        if (c1 >= 43) {
          for (int c3 = 0; c3 <= -c1 + 44; c3 += 1) {
            fprintf(f, "x q[%u];\n", -2 * c1 + 12 * c3 + 93);
          }
          if (c1 >= 44) {
            for (int c3 = 0; c3 <= -c1 + 45; c3 += 1) {
              fprintf(f, "x q[%u];\n", -2 * c1 + 7 * c3 + 95);
            }
            if (c1 == 45) {
              for (int c3 = 0; c3 <= 1; c3 += 1) {
                fprintf(f, "x q[%u];\n", 12 * c3 + 7);
              }
            }
          }
        } else if (c1 == 42) {
          fprintf(f, "x q[%u];\n", 5);
        }
        if (c1 >= 42) {
          for (int c3 = 0; c3 <= -c1 + 43; c3 += 1) {
            fprintf(f, "x q[%u];\n", -2 * c1 + 7 * c3 + 91);
          }
        } else if (c1 == 41) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", -2 * c3 + 7 * c4 + 7);
            }
          }
        } else if (c1 == 40) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", -2 * c3 + 7 * c4 + 7);
            }
          }
        } else if (c1 == 39) {
          fprintf(f, "x q[%u];\n", 5);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c3 + 2);
          }
        } else if (c1 == 38) {
          fprintf(f, "x q[%u];\n", 5);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c3 + 2);
          }
        } else {
          fprintf(f, "x q[%u];\n", 5);
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c3 + 2);
          }
        }
        if (c1 <= 46) {
          for (int c3 = 0; c3 < c1 - 44; c3 += 1) {
            fprintf(f, "x q[%u];\n", -8 * c1 + 12 * c3 + 375);
          }
        }
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
          fprintf(f, "x q[%u];\n", 8 * c3 + 12 * c4 + 7);
        }
      }
      for (int c1 = 50; c1 <= 51; c1 += 1) {
        if (c1 == 51) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 8 * c3 + 11);
          }
        } else {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", 8 * c3 + 12 * c4 + 7);
            }
          }
        }
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 3 * c3 + 11);
      }
      fprintf(f, "cx q[%u], q[%u];\n", 4, 19);
      fprintf(f, "x q[%u];\n", 4);
    } else if (c0 == 4) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 6 * c3 + 9);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 16 * c3 + 2);
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        for (int c4 = 0; c4 <= -c3 + 1; c4 += 1) {
          fprintf(f, "x q[%u];\n", -c3 + 6 * c4 + 9);
        }
      }
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", 16 * c3 + 2);
      }
      for (int c1 = 9; c1 <= 13; c1 += 1) {
        if (c1 == 13) {
          fprintf(f, "x q[%u];\n", 2);
        } else if (c1 == 12) {
          fprintf(f, "cx q[%u], q[%u];\n", 2, 1);
        } else if (c1 == 9) {
          fprintf(f, "x q[%u];\n", 2);
          fprintf(f, "x q[%u];\n", 15);
        }
      }
    }
    for (int c1 = -9 * c0 + 56; c1 <= 29; c1 += 1) {
      if (c0 == 3 && c1 == 29) {
        fprintf(f, "cx q[%u], q[%u];\n", 8, 17);
      }
      if ((c1 - 2) % 9 == 0) {
        fprintf(f, "x q[%u];\n", ((-2 * c1 + 328) / 9) - 6 * c0);
      } else if (c1 == 28) {
        fprintf(f, "cx q[%u], q[%u];\n", 15, 6);
      } else if (c1 == 26) {
        fprintf(f, "cx q[%u], q[%u];\n", 8, 3);
        fprintf(f, "x q[%u];\n", 12);
      } else if (c1 == 25) {
        fprintf(f, "cx q[%u], q[%u];\n", 9, 8);
        fprintf(f, "x q[%u];\n", 12);
      } else if (c1 == 24) {
        fprintf(f, "cx q[%u], q[%u];\n", 12, 8);
      } else if (c1 == 23) {
        fprintf(f, "x q[%u];\n", 8);
      } else if (c1 == 21) {
        fprintf(f, "x q[%u];\n", 8);
      }
    }
    if (c0 == 3) {
      for (int c1 = 30; c1 <= 38; c1 += 1) {
        if (c1 == 38) {
          fprintf(f, "x q[%u];\n", 11);
        } else if (c1 == 37) {
          fprintf(f, "x q[%u];\n", 11);
        } else if (c1 == 36) {
          fprintf(f, "x q[%u];\n", 11);
        } else if (c1 == 35) {
          fprintf(f, "x q[%u];\n", 17);
          fprintf(f, "x q[%u];\n", 11);
        } else if (c1 == 34) {
          fprintf(f, "cx q[%u], q[%u];\n", 12, 17);
          fprintf(f, "x q[%u];\n", 13);
        } else if (c1 == 33) {
          fprintf(f, "cx q[%u], q[%u];\n", 17, 13);
        } else if (c1 == 32) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 9 * c3 + 8);
          }
        } else if (c1 == 31) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            fprintf(f, "x q[%u];\n", 9 * c3 + 8);
          }
        } else {
          fprintf(f, "x q[%u];\n", 12);
        }
      }
      for (int c1 = 39; c1 <= 40; c1 += 1) {
        if (c1 == 40) {
          fprintf(f, "x q[%u];\n", 11);
        } else {
          fprintf(f, "x q[%u];\n", 11);
        }
      }
      fprintf(f, "x q[%u];\n", 0);
    } else if (c0 == 4) {
      fprintf(f, "x q[%u];\n", 9);
    }
  } else if (c0 == 1) {
    for (int c1 = 6; c1 <= 8; c1 += 1) {
      if (c1 == 8) {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 2 * c3);
        }
      } else if (c1 == 7) {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 2 * c3);
        }
      } else {
        for (int c3 = 0; c3 <= 3; c3 += 1) {
          fprintf(f, "x q[%u];\n", 2 * c3 + 5);
        }
      }
    }
    for (int c1 = 11; c1 <= 12; c1 += 1) {
      if (c1 == 12) {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 4 * c3);
        }
      } else {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 4 * c3);
        }
      }
    }
    for (int c3 = 0; c3 <= 3; c3 += 1) {
      fprintf(f, "x q[%u];\n", 5 * c3 + 4);
    }
    for (int c1 = 14; c1 <= 15; c1 += 1) {
      if (c1 == 15) {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 8 * c3);
        }
      } else {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 9 * c3);
        }
      }
    }
    for (int c1 = 16; c1 <= 25; c1 += 1) {
      if (c1 == 17) {
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          fprintf(f, "x q[%u];\n", 5 * c3 + 1);
        }
      } else if (c1 % 4 == 0) {
        fprintf(f, "x q[%u];\n", (9 * c1 / 4) - 36);
      }
      if ((c1 - 1) % 4 == 0) {
        fprintf(f, "x q[%u];\n", (9 * c1 - 153) / 4);
        if (c1 == 25) {
          for (int c3 = 0; c3 <= 2; c3 += 1) {
            fprintf(f, "x q[%u];\n", 8 * c3 + 3);
          }
        }
      }
    }
    for (int c3 = 0; c3 <= 1; c3 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", -14 * c3 + 17, 5 * c3 + 13);
    }
    for (int c3 = 0; c3 <= 1; c3 += 1) {
      fprintf(f, "x q[%u];\n", 15 * c3 + 3);
    }
    fprintf(f, "x q[%u];\n", 0);
    for (int c1 = 37; c1 <= 38; c1 += 1) {
      if (c1 == 38) {
        fprintf(f, "x q[%u];\n", 0);
      } else {
        fprintf(f, "x q[%u];\n", 0);
      }
    }
  } else {
    for (int c3 = 0; c3 <= 2; c3 += 1) {
      fprintf(f, "x q[%u];\n", 8 * c3);
    }
  }
}
fclose(f);
return 0;
}