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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.4D1_.2D2_3.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 4; c0 += 1) {
  if (c0 <= 2) {
    if (c0 == 2) {
      fprintf(f, "x q[%u];\n", 13);
      for (int c9 = 0; c9 <= 1; c9 += 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 11 * c9 + 2, 10 * c9 + 9);
      }
      fprintf(f, "x q[%u];\n", 19);
    }
    for (int c2 = (c0 + 1) / 2; c2 <= min(3, -2 * c0 + 5); c2 += 1) {
      if (c0 >= c2) {
        if (c2 == 1) {
          if (c0 == 1) {
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c9 + 1);
            }
          }
          for (int c7 = 5; c7 <= c0 + 4; c7 += 1) {
            if (c7 == 5) {
              for (int c9 = 0; c9 <= -c0 + 2; c9 += 1) {
                fprintf(f, "x q[%u];\n", c0 + c9 + 8);
              }
            } else {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c9 + 8);
              }
            }
          }
          if (c0 == 1) {
            for (int c7 = 6; c7 <= 32; c7 += 1) {
              if (c7 == 32) {
                fprintf(f, "x q[%u];\n", 1);
              } else if (c7 == 31) {
                fprintf(f, "x q[%u];\n", 10);
              } else if (c7 == 6) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c9 + 2, 4 * c9 + 9);
                }
              }
            }
          }
          for (int c7 = -3 * c0 + 40; c7 <= 37; c7 += 1) {
            if (c0 == 2 && c7 == 37) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", c9 + 12);
              }
            }
            if ((c7 - 1) % 3 == 0) {
              for (int c9 = 0; c9 < ((c7 - 37) / 3) + c0; c9 += 1) {
                fprintf(f, "x q[%u];\n", 18 * c9 + 1);
              }
              if (c0 == 2 && c7 == 34) {
                fprintf(f, "x q[%u];\n", 19);
              }
            } else if (c7 == 36) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 7 * c9 + 4, 18 * c9 + 1);
              }
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", c9 + 12);
              }
            } else {
              fprintf(f, "x q[%u];\n", 19);
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c9 + 2, c9 + 12);
              }
            }
          }
          if (c0 == 1) {
            for (int c7 = 39; c7 <= 50; c7 += 1) {
              if (c7 == 50) {
                fprintf(f, "x q[%u];\n", 6);
              } else if (c7 == 42) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c9 + 9);
                }
              } else if (c7 == 41) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", c9 + 12, 9 * c9 + 9);
                }
              } else if (c7 == 40) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c9 + 10);
                }
              } else if (c7 == 39) {
                fprintf(f, "x q[%u];\n", 12);
              }
            }
          } else {
            for (int c7 = 39; c7 <= 42; c7 += 1) {
              if (c7 == 42) {
                fprintf(f, "x q[%u];\n", 13);
              } else if (c7 == 40) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 7 * c9 + 4);
                }
              } else if (c7 == 39) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 10 * c9 + 1);
                }
              }
            }
          }
        } else {
          fprintf(f, "x q[%u];\n", 18);
        }
        if (c0 == 2 && c2 == 1) {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", -9 * c9 + 13);
          }
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", -14 * c9 + 18);
          }
        }
      } else if (c0 + 2 >= c2) {
        if (c0 == 1 && c2 == 3) {
          fprintf(f, "x q[%u];\n", 10);
        }
        for (int c4 = max(c0 - 1, -c2 + 1); c4 <= 0; c4 += 1) {
          if (c2 <= 2) {
            for (int c5 = c2 - 1; c5 <= min(min(-c0 + 2, c2), c4 + 2); c5 += 1) {
              if (c0 == 0 && c2 == 2 && c5 == 1) {
                for (int c6 = 0; c6 <= 3 * c4 + 6; c6 += 1) {
                  if (c6 <= 2) {
                    for (int c7 = max(-1, -43 * c6 + 42); c7 <= 42; c7 += 1) {
                      if ((43 * c6 + c7 - 42) % 86 == 0) {
                        fprintf(f, "x q[%u];\n", -3 * c4 + 1);
                      } else if (c6 == 2 && c7 == 38) {
                        fprintf(f, "cx q[%u], q[%u];\n", -3 * c4 + 1, -3 * c4 + 13);
                      } else if (c4 == 0 && c6 == 2 && c7 == 37) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", 10 * c9 + 1);
                        }
                      } else if (c4 == 0 && c6 == 2 && c7 == 31) {
                        fprintf(f, "x q[%u];\n", 13);
                      } else if (c4 == -1 && c6 == 2 && c7 == 30) {
                        fprintf(f, "x q[%u];\n", 16);
                      } else if (c4 == 0 && c6 == 2 && c7 == 23) {
                        fprintf(f, "x q[%u];\n", 13);
                      }
                    }
                  } else if (c6 == 3) {
                    fprintf(f, "x q[%u];\n", -3 * c4 + 1);
                    if (c4 == 0) {
                      for (int c7 = 0; c7 <= 53; c7 += 1) {
                        if (c7 == 52) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", c9 + 14, 10 * c9 + 7);
                          }
                        } else if (c7 == 51) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", 3 * c9 + 14, c9 + 7);
                          }
                        } else {
                          if (c7 == 50) {
                            fprintf(f, "cx q[%u], q[%u];\n", 5, 15);
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -8 * c9 + 9, 5 * c9 + 8);
                            }
                          } else if (c7 == 49) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 6 * c9, 4 * c9 + 5);
                            }
                          } else if (c7 == 47) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c9 + 2);
                            }
                          } else if (c7 == 45) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 3 * c9 + 2, 7 * c9 + 10);
                            }
                          } else if (c7 == 43) {
                            fprintf(f, "x q[%u];\n", 19);
                          } else if (c7 == 41) {
                            fprintf(f, "x q[%u];\n", 8);
                          } else if (c7 == 40) {
                            fprintf(f, "x q[%u];\n", 19);
                          } else {
                            if (c7 == 36) {
                              fprintf(f, "x q[%u];\n", 12);
                            } else if ((c7 - 3) % 36 == 0) {
                              for (int c9 = 0; c9 <= (-c7 + 39) / 36; c9 += 1) {
                                fprintf(f, "x q[%u];\n", (c7 / 3) + 10 * c9 - 1);
                              }
                            }
                            if (c7 <= 39 && c7 % 3 == 0) {
                              for (int c9 = 0; c9 < (c7 / 3) - 11; c9 += 1) {
                                fprintf(f, "x q[%u];\n", -2 * c7 + 15 * c9 + 80);
                              }
                              if (c7 == 39) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", c9 + 7);
                                }
                              }
                              if (c7 <= 24) {
                                for (int c9 = 0; c9 < (c7 / 3) - 6; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", -5 * c7 + 13 * c9 + 123);
                                }
                                if (c7 == 21) {
                                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                                    fprintf(f, "x q[%u];\n", 5 * c9 + 11);
                                  }
                                }
                              }
                              if (c7 == 21) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 6 * c9 + 9);
                                }
                              } else if (c7 == 18) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 8 * c9 + 11);
                                }
                              }
                            } else {
                              if (c7 == 37) {
                                fprintf(f, "x q[%u];\n", 14);
                              } else if (c7 == 31) {
                                fprintf(f, "x q[%u];\n", 3);
                              } else if (c7 == 26) {
                                fprintf(f, "x q[%u];\n", 13);
                              } else if (c7 == 25) {
                                fprintf(f, "cx q[%u], q[%u];\n", 13, 19);
                              } else if (c7 == 23) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", c9 + 14);
                                }
                              } else if (c7 == 22) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 6 * c9 + 10);
                                }
                              }
                              if (c7 == 10) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 3 * c9);
                                }
                              }
                              if (c7 <= 25 && (c7 - 1) % 3 == 0) {
                                for (int c9 = 0; c9 < (c7 - 19) / 3; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", -5 * c7 + 13 * c9 + 128);
                                }
                                if (c7 == 22) {
                                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                                    fprintf(f, "x q[%u];\n", c9 + 14);
                                  }
                                }
                              }
                              if (c7 == 8) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 16 * c9);
                                }
                              } else if (c7 == 4) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 10 * c9);
                                }
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 12 * c9 + 4);
                                }
                              } else if (c7 >= 37 && (c7 - 4) % 11 == 0) {
                                fprintf(f, "cx q[%u], q[%u];\n", (-12 * c7 + 576) / 11, (-4 * c7 + 247) / 11);
                                if (c7 == 48) {
                                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                                    fprintf(f, "x q[%u];\n", 13 * c9 + 2);
                                  }
                                }
                              } else if (c7 == 44) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", c9 + 5);
                                }
                              } else if (c7 == 42) {
                                fprintf(f, "x q[%u];\n", 8);
                              }
                            }
                          }
                          if ((c7 - 2) % 48 == 0) {
                            for (int c9 = 0; c9 <= (-c7 + 50) / 48; c9 += 1) {
                              fprintf(f, "x q[%u];\n", ((5 * c7 + 38) / 48) + 12 * c9);
                            }
                          }
                          if (c7 <= 26 && (c7 + 1) % 3 == 0) {
                            for (int c9 = 0; c9 < (c7 - 20) / 3; c9 += 1) {
                              fprintf(f, "x q[%u];\n", -5 * c7 + 13 * c9 + 133);
                            }
                          }
                          if (c7 <= 29 && (c7 + 1) % 3 == 0) {
                            for (int c9 = 0; c9 < (c7 - 23) / 3; c9 += 1) {
                              fprintf(f, "x q[%u];\n", -5 * c7 + 16 * c9 + 148);
                            }
                            if (c7 == 23) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 13 * c9 + 3);
                              }
                            } else if (c7 == 20) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 6 * c9 + 9);
                              }
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 5 * c9 + 11);
                              }
                            }
                            if (c7 == 14) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 16 * c9 + 3);
                              }
                            }
                            if (c7 == 5) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 12 * c9 + 4);
                              }
                            }
                          } else {
                            if (c7 % 38 == 0) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", (4 * c7 / 19) + 3 * c9 + 1);
                              }
                            } else if ((c7 - 1) % 39 == 0) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", ((7 * c7 + 32) / 39) + 3 * c9);
                              }
                            } else {
                              if (c7 >= 28 && c7 <= 30 && c7 % 2 == 0) {
                                fprintf(f, "x q[%u];\n", 19);
                              }
                              if (c7 >= 28 && (c7 - 2) % 13 == 0) {
                                fprintf(f, "x q[%u];\n", (c7 + 206) / 13);
                              }
                            }
                            if ((c7 - 3) % 35 == 0) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", ((c7 + 32) / 35) + 15 * c9);
                              }
                              if (c7 == 38) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", -c9 + 8, 10 * c9 + 1);
                                }
                              }
                            } else if (c7 == 35) {
                              fprintf(f, "cx q[%u], q[%u];\n", 2, 12);
                            } else if (c7 == 30) {
                              fprintf(f, "x q[%u];\n", 3);
                            } else if (c7 == 27) {
                              fprintf(f, "cx q[%u], q[%u];\n", 13, 18);
                            }
                            if (c7 == 19) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 5 * c9 + 11);
                              }
                            } else if (c7 == 16) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", 7 * c9 + 4, 3 * c9 + 16);
                              }
                            }
                            if (c7 == 13) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 13 * c9 + 3);
                              }
                            } else if (c7 <= 12 && c7 % 6 == 0) {
                              for (int c9 = 0; c9 < c7 / 6; c9 += 1) {
                                fprintf(f, "x q[%u];\n", (-8 * c7 / 3) + 3 * c9 + 32);
                              }
                              if (c7 == 12) {
                                fprintf(f, "x q[%u];\n", 16);
                              }
                            } else if (c7 == 7) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 16 * c9);
                              }
                            }
                            if (c7 >= 37 && (c7 + 3) % 10 == 0) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                if (10 * c9 + 37 >= c7) {
                                  fprintf(f, "x q[%u];\n", ((2 * c7 - 34) / 5) + 3 * c9);
                                  if (c7 == 37 && c9 == 0) {
                                    fprintf(f, "x q[%u];\n", 8);
                                    fprintf(f, "cx q[%u], q[%u];\n", 17, 8);
                                  }
                                }
                                if (c9 == 0) {
                                  fprintf(f, "cx q[%u], q[%u];\n", (-3 * c7 + 191) / 10, (2 * c7 - 19) / 5);
                                }
                              }
                            }
                          }
                          if ((c7 - 17) % 36 == 0) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              fprintf(f, "x q[%u];\n", ((c7 + 31) / 12) + 7 * c9);
                            }
                          } else {
                            if (c7 <= 27 && c7 % 3 == 0) {
                              for (int c9 = 0; c9 < (c7 / 3) - 7; c9 += 1) {
                                fprintf(f, "x q[%u];\n", -5 * c7 + 13 * c9 + 138);
                              }
                              if (c7 == 9) {
                                for (int c9 = 0; c9 <= 1; c9 += 1) {
                                  fprintf(f, "x q[%u];\n", 3 * c9);
                                }
                              }
                            } else if ((c7 - 11) % 35 == 0) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", ((2 * c7 - 22) / 35) + 3 * c9);
                              }
                            }
                            if (c7 <= 32 && (c7 + 2) % 17 == 0) {
                              fprintf(f, "x q[%u];\n", (-16 * c7 + 563) / 17);
                            } else if (c7 >= 25 && c7 <= 28 && (c7 - 1) % 3 == 0) {
                              fprintf(f, "x q[%u];\n", -5 * c7 + 143);
                            }
                          }
                        }
                      }
                    }
                    if (c4 == 0) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c9 + 7);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c9 + 7);
                      }
                    }
                  } else {
                    fprintf(f, "x q[%u];\n", 8);
                  }
                }
              } else if (c0 == 0 && c2 == 1) {
                if (c5 == 1) {
                  for (int c9 = 0; c9 <= 3; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c9 + 7);
                  }
                  for (int c7 = 15; c7 <= 44; c7 += 1) {
                    if (c7 == 43) {
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c9 + 9);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c9 + 5);
                      }
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        for (int c10 = 0; c10 <= c9; c10 += 1) {
                          fprintf(f, "x q[%u];\n", -6 * c9 + 4 * c10 + 8);
                        }
                      }
                    } else {
                      if (c7 == 42) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", 7 * c9 + 5);
                        }
                      } else {
                        if (c7 == 39) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c9 + 5);
                          }
                          fprintf(f, "x q[%u];\n", 12);
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c9);
                          }
                        } else if (c7 == 31) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", c9 + 8);
                          }
                        } else if (c7 == 29) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 9, 4 * c9 + 8);
                          }
                        } else if ((c7 + 4) % 8 == 0) {
                          for (int c9 = 0; c9 < (c7 - 28) / 8; c9 += 1) {
                            fprintf(f, "x q[%u];\n", ((-3 * c7 + 204) / 8) + 5 * c9);
                          }
                          if (c7 == 36) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              for (int c10 = 0; c10 <= -c9 + 1; c10 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", 2 * c9 + 3 * c10 + 4, c9 + 10 * c10 + 1);
                              }
                            }
                            fprintf(f, "x q[%u];\n", 17);
                          }
                        } else {
                          if (c7 == 32) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              for (int c10 = 0; c10 <= -c9 + 2; c10 += 1) {
                                fprintf(f, "x q[%u];\n", c9 + 4 * c10 + 7);
                              }
                            }
                          } else if (c7 == 22) {
                            fprintf(f, "x q[%u];\n", 14);
                            for (int c9 = 0; c9 <= 3; c9 += 1) {
                              fprintf(f, "x q[%u];\n", 3 * c9 + 10);
                            }
                          } else if (c7 >= 30 && (c7 + 2) % 8 == 0) {
                            fprintf(f, "cx q[%u], q[%u];\n", (3 * c7 - 50) / 8, (-5 * c7 + 218) / 4);
                          }
                          if ((c7 + 2) % 17 == 0) {
                            fprintf(f, "x q[%u];\n", (-16 * c7 + 546) / 17);
                            if (c7 == 32) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", -c9 + 6, 8 * c9 + 9);
                              }
                            }
                          } else if (c7 == 24) {
                            fprintf(f, "x q[%u];\n", 14);
                          } else if (c7 == 19) {
                            for (int c9 = 0; c9 <= 3; c9 += 1) {
                              fprintf(f, "x q[%u];\n", c9);
                            }
                          } else if ((c7 + 3) % 12 == 0) {
                            for (int c9 = 0; c9 <= (-c7 + 45) / 12; c9 += 1) {
                              fprintf(f, "x q[%u];\n", ((c7 - 17) / 2) + 4 * c9);
                            }
                            if (c7 == 21) {
                              for (int c9 = 0; c9 <= 2; c9 += 1) {
                                fprintf(f, "x q[%u];\n", c9 + 13);
                              }
                              for (int c9 = 0; c9 <= 2; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 8 * c9 + 3);
                              }
                            }
                          } else if (c7 >= 35 && (c7 + 1) % 6 == 0) {
                            fprintf(f, "cx q[%u], q[%u];\n", (3 * c7 - 93) / 2, (5 * c7 - 121) / 6);
                            if (c7 == 41) {
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "x q[%u];\n", 10 * c9);
                              }
                              for (int c9 = 0; c9 <= 1; c9 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", -c9 + 6, 10 * c9 + 2);
                              }
                            }
                          } else {
                            if (c7 == 38) {
                              fprintf(f, "cx q[%u], q[%u];\n", 6, 12);
                            }
                            if (c7 >= 37 && c7 <= 38) {
                              fprintf(f, "x q[%u];\n", 12 * c7 - 439);
                            }
                          }
                        }
                        if (c7 >= 38 && c7 <= 39) {
                          fprintf(f, "x q[%u];\n", 12 * c7 - 451);
                        } else {
                          if (c7 == 37) {
                            for (int c9 = 0; c9 <= 2; c9 += 1) {
                              fprintf(f, "x q[%u];\n", 3 * c9 + 1);
                            }
                          }
                          if (c7 >= 36 && c7 <= 37) {
                            fprintf(f, "cx q[%u], q[%u];\n", 7 * c7 - 247, 2 * c7 - 57);
                          }
                        }
                      }
                      if (c7 == 42) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c9 + 9);
                        }
                      } else {
                        if (c7 == 40) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c9 + 10 * c10);
                            }
                          }
                        } else if (c7 == 38) {
                          fprintf(f, "x q[%u];\n", 2);
                        } else if (c7 == 35) {
                          fprintf(f, "x q[%u];\n", 17);
                        } else if (c7 == 34) {
                          fprintf(f, "x q[%u];\n", 17);
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c9 + 2);
                          }
                        } else if (c7 == 33) {
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c9 + 2);
                          }
                          fprintf(f, "x q[%u];\n", 17);
                        } else if (c7 == 28) {
                          fprintf(f, "x q[%u];\n", 8);
                          fprintf(f, "x q[%u];\n", 5);
                          fprintf(f, "x q[%u];\n", 17);
                        } else if (c7 == 25) {
                          fprintf(f, "cx q[%u], q[%u];\n", 17, 8);
                        } else if (c7 == 23) {
                          fprintf(f, "x q[%u];\n", 14);
                          for (int c9 = 0; c9 <= 1; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 17 * c9 + 2);
                          }
                        } else if (c7 == 20) {
                          for (int c9 = 0; c9 <= 4; c9 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c9 + 3);
                          }
                        }
                        if (c7 >= 31 && (c7 - 4) % 9 == 0) {
                          fprintf(f, "x q[%u];\n", (-10 * c7 + 463) / 9);
                          if (c7 == 40) {
                            for (int c9 = 0; c9 <= 1; c9 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 6 * c9 + 6, 15 * c9 + 2);
                            }
                          }
                        }
                      }
                      if (c7 >= 35 && c7 % 7 == 0) {
                        for (int c9 = 0; c9 <= 1; c9 += 1) {
                          fprintf(f, "x q[%u];\n", (-6 * c7 / 7) + 4 * c9 + 38);
                        }
                        if (c7 == 35) {
                          fprintf(f, "x q[%u];\n", 7);
                        }
                      } else if (c7 == 27) {
                        fprintf(f, "cx q[%u], q[%u];\n", 5, 17);
                      } else if (c7 == 26) {
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c7 >= 31 && (c7 + 1) % 8 == 0) {
                        fprintf(f, "x q[%u];\n", (c7 - 11) / 4);
                      }
                    }
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", c9 + 5);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c9 + 9);
                  }
                } else {
                  for (int c9 = 0; c9 <= 3; c9 += 1) {
                    fprintf(f, "x q[%u];\n", c9 + 1);
                  }
                }
              } else if (c0 == 0 && c5 == 2) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", c9 + 14, 10 * c9 + 7);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c9 + 7);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", c9 + 14);
                }
              } else {
                fprintf(f, "x q[%u];\n", 6);
                fprintf(f, "cx q[%u], q[%u];\n", 0, 6);
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c9);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c9);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c9);
                }
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c9);
                }
              }
            }
          } else {
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", 6 * c9);
            }
          }
        }
        if (c0 == 0 && c2 == 2) {
          fprintf(f, "cx q[%u], q[%u];\n", 9, 4);
          fprintf(f, "x q[%u];\n", 9);
        }
      } else {
        fprintf(f, "x q[%u];\n", 12);
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2 * c9 + 10, 5 * c9 + 4);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", c9 + 9);
        }
      }
    }
  } else if (c0 == 4) {
    for (int c9 = 0; c9 <= 1; c9 += 1) {
      fprintf(f, "x q[%u];\n", -13 * c9 + 19);
    }
    for (int c7 = 20; c7 <= 37; c7 += 17) {
      fprintf(f, "x q[%u];\n", (-2 * c7 + 363) / 17);
    }
  } else {
    for (int c2 = 0; c2 <= 2; c2 += 1) {
      if (c2 == 2) {
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 10 * c9 + 1);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c9 + 1);
        }
        fprintf(f, "x q[%u];\n", 10);
        fprintf(f, "x q[%u];\n", 10);
      } else if (c2 == 1) {
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 2 * c9 + 8);
        }
      } else {
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", -14 * c9 + 18);
        }
        fprintf(f, "x q[%u];\n", 18);
      }
      if (c2 == 1) {
        fprintf(f, "cx q[%u], q[%u];\n", 5, 17);
      }
      if (c2 <= 1) {
        if (c2 == 1) {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", 18 * c9 + 1);
          }
        }
        fprintf(f, "x q[%u];\n", 4);
        if (c2 == 1) {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 17, 8 * c9 + 11);
          }
        }
      }
      if (c2 >= 1) {
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", c9 + 14);
        }
        if (c2 == 1) {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c9 + 11);
          }
        }
        if (c2 == 1) {
          for (int c7 = 37; c7 <= 38; c7 += 1) {
            if (c7 == 38) {
              fprintf(f, "cx q[%u], q[%u];\n", 8, 7);
            } else {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c9 + 11);
              }
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c9 + 8);
              }
            }
          }
        }
      }
      if (c2 == 2) {
        for (int c7 = 37; c7 <= 38; c7 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c7 - 443);
          if (c7 == 37) {
            for (int c9 = 0; c9 <= 1; c9 += 1) {
              fprintf(f, "x q[%u];\n", c9 + 14);
            }
          }
        }
        for (int c7 = 38; c7 <= 39; c7 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c7 - 455);
        }
      } else if (c2 == 1) {
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 8 * c9 + 11);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", -9 * c9 + 14);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -7 * c9 + 8, 2 * c9 + 11);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 15 * c9 + 4);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -9 * c9 + 14, 8 * c9 + 7);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c9 + 1);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c9 + 1);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -4 * c9 + 9, 16 * c9 + 1);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 16 * c9 + 1);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c9 + 5);
        }
        for (int c9 = 0; c9 <= 1; c9 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 6 * c9, 4 * c9 + 5);
        }
      }
      if (c2 >= 1) {
        fprintf(f, "x q[%u];\n", 5 * c2 - 5);
        if (c2 == 2) {
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", c9 + 5);
          }
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", -13 * c9 + 19);
          }
        } else if (c2 == 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2, 9);
        }
        fprintf(f, "cx q[%u], q[%u];\n", -13 * c2 + 26, -13 * c2 + 31);
        if (c2 == 2) {
          fprintf(f, "x q[%u];\n", 15);
          fprintf(f, "cx q[%u], q[%u];\n", 15, 14);
        } else if (c2 == 1) {
          fprintf(f, "cx q[%u], q[%u];\n", 2, 9);
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 6 * c9 + 7, 7 * c9 + 11);
          }
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", 7 * c9 + 2);
          }
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", 5 * c9 + 13);
          }
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", -16 * c9 + 18);
          }
          for (int c7 = 49; c7 <= 50; c7 += 1) {
            if (c7 == 50) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 6 * c9 + 3, 4 * c9 + 4);
              }
            }
            fprintf(f, "cx q[%u], q[%u];\n", -7 * c7 + 352, 8 * c7 - 388);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 2, 9);
          for (int c9 = 0; c9 <= 1; c9 += 1) {
            fprintf(f, "x q[%u];\n", -6 * c9 + 8);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 9, 8);
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -6 * c4 + 7, 2 * c4 + 11);
          }
        }
      }
    }
  }
  if (c0 == 1) {
    for (int c2 = 0; c2 <= 1; c2 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 11 * c2 + 2, 7 * c2 + 12);
    }
  }
}
fclose(f);
return 0;
}