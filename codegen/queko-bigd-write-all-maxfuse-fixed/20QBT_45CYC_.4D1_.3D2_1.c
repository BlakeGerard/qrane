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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.4D1_.3D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 8 * c1 + 8, 2 * c1 + 13);
  }
  for (int c1 = 0; c1 <= 3; c1 += 1) {
    if (c1 == 3) {
      fprintf(f, "x q[%u];\n", 9);
    }
    if (c1 >= 2) {
      if (c1 == 2) {
        for (int c16 = 0; c16 <= 1; c16 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c16 + 7);
        }
        fprintf(f, "x q[%u];\n", 17);
      }
      if (c1 == 3) {
        fprintf(f, "x q[%u];\n", 7);
      } else {
        for (int c8 = 2; c8 <= 4; c8 += 1) {
          for (int c9 = max(0, -2 * c8 + 6); c9 <= min(2, -2 * c8 + 8); c9 += 1) {
            if (c9 % 2 == 0) {
              fprintf(f, "x q[%u];\n", -12 * c8 - 6 * c9 + 53);
            } else {
              fprintf(f, "cx q[%u], q[%u];\n", 17, 9);
              fprintf(f, "x q[%u];\n", 9);
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c16 + 7);
              }
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c16 + 7);
              }
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 9 * c16 + 7);
              }
              fprintf(f, "x q[%u];\n", 7);
              fprintf(f, "x q[%u];\n", 5);
            }
          }
        }
      }
    }
    if (c1 <= 2) {
      for (int c4 = max(6 * c1 - 8, -c1); c4 <= (c1 % 2) + 2 * c1 + 3; c4 += 1) {
        if (c1 >= c4) {
          for (int c6 = 0; c6 <= min(c1, c4 + 1); c6 += 1) {
            if (c1 == 1 && c4 + c6 <= 1) {
              for (int c8 = 0; c8 <= min(2, 2 * c4 + 2); c8 += 2) {
                if (c4 == 1 && c6 == 0 && c8 == 2) {
                  for (int c14 = 17; c14 <= 18; c14 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 13 * c14 - 219, 3 * c14 - 41);
                  }
                }
                if (c4 == 0 && c8 == 2) {
                  if (c6 == 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 19);
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c16 + 1);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 19, 6);
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 2);
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 19);
                    fprintf(f, "x q[%u];\n", 2);
                  } else {
                    fprintf(f, "x q[%u];\n", 3);
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 7);
                    fprintf(f, "x q[%u];\n", 3);
                  }
                } else if (c4 == 0 && c6 == 0 && c8 == 0) {
                  fprintf(f, "x q[%u];\n", 11);
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    for (int c16 = 0; c16 <= -c12 + 2; c16 += 1) {
                      fprintf(f, "x q[%u];\n", -2 * c12 + 3 * c16 + 6);
                    }
                    if (c12 == 0) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 14 * c16, 7 * c16 + 5);
                      }
                      for (int c14 = 12; c14 <= 17; c14 += 1) {
                        if (c14 == 16) {
                          for (int c16 = 0; c16 <= 1; c16 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c16 + 3);
                          }
                        } else {
                          if (c14 == 15) {
                            fprintf(f, "cx q[%u], q[%u];\n", 17, 5);
                          }
                          if (c14 <= 15 && (c14 + 1) % 2 == 0) {
                            fprintf(f, "x q[%u];\n", -c14 + 27);
                            if (c14 == 15) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", 15 * c16 + 3);
                              }
                            }
                            if (c14 == 13) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", 5 * c16);
                              }
                              fprintf(f, "cx q[%u], q[%u];\n", 17, 11);
                              fprintf(f, "x q[%u];\n", 9);
                            }
                          } else {
                            if (c14 == 14) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", 7 * c16 + 5);
                              }
                              fprintf(f, "cx q[%u], q[%u];\n", 17, 9);
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", 15 * c16 + 3);
                              }
                            }
                            if ((c14 - 2) % 5 == 0) {
                              fprintf(f, "cx q[%u], q[%u];\n", -c14 + 29, (-6 * c14 + 117) / 5);
                            }
                          }
                        }
                      }
                      fprintf(f, "x q[%u];\n", 12);
                    }
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c11 + 4);
                  }
                }
                if (c6 == 0) {
                  if (c4 == 0 && c8 == 0) {
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 5 * c16 + 8);
                    }
                  }
                  if (c4 >= 0 && c8 == 0) {
                    fprintf(f, "x q[%u];\n", 13);
                  }
                  if (c4 <= 0 && c8 == 0) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c4 + 8, -9 * c4 + 6);
                    if (c4 == 0) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 5 * c16 + 13, 9 * c16 + 6);
                      }
                    }
                  }
                  if (c4 == 0) {
                    fprintf(f, "x q[%u];\n", c8 + 13);
                    if (c8 == 2) {
                      fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                      fprintf(f, "x q[%u];\n", 15);
                    }
                  } else if (c4 == 1 && c8 == 0) {
                    fprintf(f, "x q[%u];\n", 19);
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 14 * c14 + 5);
                    }
                  }
                  if (c8 == 2) {
                    for (int c14 = c4 + 8; c14 <= 9; c14 += 1) {
                      if (c4 == 0 && c14 == 9) {
                        for (int c16 = 0; c16 <= 1; c16 += 1) {
                          fprintf(f, "x q[%u];\n", c16 + 15);
                        }
                      }
                      if (c14 == 9) {
                        fprintf(f, "x q[%u];\n", 10);
                      } else {
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 10);
                      }
                    }
                  }
                  for (int c16 = max(0, c4); c16 <= min(1, (-c8 / 2) + c4 + 1); c16 += 1) {
                    fprintf(f, "x q[%u];\n", -8 * c4 + 4 * c8 + 8 * c16 + 8);
                  }
                  if (c4 == 0 && c8 == 2) {
                    fprintf(f, "x q[%u];\n", 10);
                    fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                  }
                  if (c4 == 0 && c8 == 2) {
                    for (int c14 = 11; c14 <= 14; c14 += 1) {
                      if (c14 == 14) {
                        fprintf(f, "x q[%u];\n", 17);
                      } else if (c14 == 13) {
                        fprintf(f, "cx q[%u], q[%u];\n", 17, 11);
                      } else if (c14 == 12) {
                        for (int c16 = 0; c16 <= 1; c16 += 1) {
                          fprintf(f, "x q[%u];\n", 7 * c16 + 11);
                        }
                      } else {
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                      }
                    }
                  } else if (c4 == 0 && c8 == 0) {
                    for (int c14 = 8; c14 <= 9; c14 += 1) {
                      if (c14 == 9) {
                        fprintf(f, "x q[%u];\n", 16);
                      } else {
                        fprintf(f, "cx q[%u], q[%u];\n", 7, 16);
                      }
                    }
                    fprintf(f, "x q[%u];\n", 16);
                  }
                  if (c4 == 0 && c8 == 2) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3, 18);
                  }
                }
                if (c4 == 0 && c6 == 1 && c8 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 5);
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c16 + 11);
                  }
                  fprintf(f, "x q[%u];\n", 0);
                }
                if (c4 == 0 && c6 == 1 && c8 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 17);
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 17 * c16);
                  }
                }
              }
              if (c4 >= 0 && c6 == 0) {
                for (int c12 = -c4; c12 <= 0; c12 += 1) {
                  if (c12 == 0) {
                    fprintf(f, "x q[%u];\n", 11);
                    if (c4 == 0) {
                      fprintf(f, "x q[%u];\n", 7);
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 12 * c16 + 7);
                      }
                      fprintf(f, "x q[%u];\n", 7);
                    }
                  }
                  if (c4 + c12 == 0) {
                    fprintf(f, "x q[%u];\n", 7);
                  }
                }
              }
            } else if (c1 == 1 && c4 == 1 && c6 == 1) {
              fprintf(f, "cx q[%u], q[%u];\n", 8, 6);
            } else {
              for (int c11 = 0; c11 <= 2; c11 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c11 + 4);
              }
              for (int c11 = 0; c11 <= 3; c11 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c11 + 1);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 11, 2);
              fprintf(f, "cx q[%u], q[%u];\n", 2, 19);
              for (int c14 = 19; c14 <= 23; c14 += 4) {
                fprintf(f, "x q[%u];\n", (-9 * c14 + 211) / 4);
              }
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c11 + 1);
              }
              fprintf(f, "cx q[%u], q[%u];\n", 2, 1);
            }
          }
          if (c1 == 1 && c4 == 0) {
            fprintf(f, "x q[%u];\n", 19);
          }
        } else {
          if (c1 + c4 >= 3 && c1 + c4 <= 8 && (c1 + c4) % 3 <= 1) {
            if (c1 == 1 && c4 == 2) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 14 * c14 + 5);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10 * c14 + 5, 10 * c14 + 3);
              }
            }
            if (2 * c1 + 1 >= c4) {
              if (c1 == 1 && c4 == 2) {
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  if (c8 == 1) {
                    fprintf(f, "x q[%u];\n", 16);
                  }
                  for (int c16 = 0; c16 <= -c8 + 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", -6 * c8 + 2 * c16 + 13);
                  }
                }
              } else if (c1 == 1 && c4 == 3) {
                for (int c8 = 0; c8 <= 4; c8 += 1) {
                  if (c8 == 3) {
                    fprintf(f, "x q[%u];\n", 12);
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c16 + 9, 16 * c16 + 2);
                    }
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 3 * c16 + 9);
                    }
                    for (int c14 = 10; c14 <= 11; c14 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c14 - 98, -7 * c14 + 80);
                    }
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c16 + 3);
                    }
                    fprintf(f, "x q[%u];\n", 12);
                  }
                  if (c8 >= 3) {
                    fprintf(f, "x q[%u];\n", 12);
                    if (c8 == 4) {
                      fprintf(f, "x q[%u];\n", 12);
                    }
                  } else if (c8 == 2) {
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c16 + 3);
                    }
                  }
                  if (c8 % 4 == 0) {
                    for (int c16 = 0; c16 <= (-c8 / 4) + 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", (-3 * c8 / 2) + 2 * c16 + 13);
                    }
                    if (c8 == 0) {
                      fprintf(f, "x q[%u];\n", 15);
                    }
                  }
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c14 + 7);
                }
                fprintf(f, "x q[%u];\n", 16);
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  for (int c9 = 0; c9 <= c8; c9 += 1) {
                    fprintf(f, "x q[%u];\n", -2 * c8 + 8 * c9 + 4);
                  }
                }
              }
              if (c1 == 2 && c4 == 4) {
                fprintf(f, "cx q[%u], q[%u];\n", 16, 15);
              }
              if (c1 == 2 && c4 == 5) {
                fprintf(f, "x q[%u];\n", 16);
              } else if (c1 == 1 && c4 == 2) {
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
                fprintf(f, "x q[%u];\n", 14);
              } else if (c1 == 1) {
                for (int c8 = 0; c8 <= 2; c8 += 1) {
                  if (c8 == 2) {
                    fprintf(f, "x q[%u];\n", 4);
                    fprintf(f, "x q[%u];\n", 4);
                    fprintf(f, "x q[%u];\n", 4);
                  }
                  if (c8 >= 1) {
                    for (int c9 = 0; c9 <= 2; c9 += 1) {
                      if (2 * c8 + c9 >= 4) {
                        for (int c12 = max(-c8 + 1, -c9 + (c9 + 1) / 2); c12 <= min(c9, -c9 + 2); c12 += 1) {
                          if (c12 >= 0) {
                            if (c8 == 2 && c9 == 1 && c12 == 0) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", -4 * c16 + 8);
                              }
                            } else if (c8 == 2 && c9 == 2 && c12 == 0) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", 3 * c16 + 5, 3 * c16 + 3);
                              }
                            }
                            if (c8 == 2 && c12 == 0) {
                              if (c9 == 2) {
                                fprintf(f, "cx q[%u], q[%u];\n", 19, 8);
                              } else if (c9 == 1) {
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 9 * c16 + 1, 7 * c16 + 8);
                                }
                              } else {
                                fprintf(f, "x q[%u];\n", 4);
                              }
                              if (c9 == 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", 11, 1);
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "x q[%u];\n", 2 * c16 + 8);
                                }
                              }
                            }
                            if (c12 == 0 && c9 % 2 == 0) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", -12 * c8 - 6 * c9 + 3 * c16 + 39);
                              }
                              if (c8 == 2 && c9 == 2) {
                                fprintf(f, "x q[%u];\n", 19);
                                fprintf(f, "x q[%u];\n", 15);
                              }
                              if (c8 == 2 && c9 == 2) {
                                fprintf(f, "x q[%u];\n", 3);
                                fprintf(f, "x q[%u];\n", 15);
                              }
                            }
                            if (c8 == 2 && c9 >= 1 && c12 == 0) {
                              for (int c14 = 12; c14 <= 13; c14 += 1) {
                                if (c9 == 2 && c14 == 13) {
                                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c16 + 12, 7 * c16 + 3);
                                  }
                                  fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
                                } else {
                                  if (c9 == 1 && c14 == 13) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 16, 15);
                                  } else if (c9 == 2) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 8, 6);
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c16 + 12, 10 * c16 + 3);
                                    }
                                  } else {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "x q[%u];\n", 7 * c16 + 8);
                                    }
                                  }
                                  if (c9 == 1) {
                                    fprintf(f, "x q[%u];\n", -10 * c14 + 131);
                                  }
                                  if (c9 == 1 && c14 == 13) {
                                    fprintf(f, "x q[%u];\n", 8);
                                  }
                                }
                              }
                            }
                            if (c8 == 2 && c12 == 0) {
                              if (c9 == 2) {
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "x q[%u];\n", 5 * c16 + 8);
                                }
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "x q[%u];\n", 9 * c16 + 10);
                                }
                              } else if (c9 == 1) {
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "x q[%u];\n", 14 * c16 + 1);
                                }
                              } else {
                                fprintf(f, "x q[%u];\n", 4);
                              }
                              if (c9 == 1) {
                                for (int c14 = 15; c14 <= 16; c14 += 1) {
                                  if (c14 == 16) {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "cx q[%u], q[%u];\n", 11 * c16 + 2, 5 * c16 + 1);
                                    }
                                  } else {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "x q[%u];\n", 15 * c16 + 1);
                                    }
                                  }
                                }
                              }
                              if (c9 <= 1) {
                                for (int c14 = -c9 + 18; c14 <= -c9 + 20; c14 += 1) {
                                  if (c9 == 0 && c14 == 20) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 3, 18);
                                  } else if (c9 == 1 && c14 == 17) {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "x q[%u];\n", 7 * c16 + 6);
                                    }
                                  }
                                  if (3 * c9 + c14 == 20) {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "x q[%u];\n", -2 * c9 + 17 * c16 + 2);
                                    }
                                    if (c9 == 0) {
                                      fprintf(f, "cx q[%u], q[%u];\n", 1, 8);
                                    }
                                  } else {
                                    if (c9 == 0) {
                                      fprintf(f, "cx q[%u], q[%u];\n", 8 * c14 - 133, 4 * c14 - 70);
                                    } else if (c14 == 19) {
                                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                                        fprintf(f, "x q[%u];\n", 3 * c16 + 2);
                                      }
                                    }
                                    if (c14 == 19) {
                                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                                        fprintf(f, "x q[%u];\n", -2 * c9 + 9 * c16 + 2);
                                      }
                                    }
                                    if (c9 == 1 && c14 == 19) {
                                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                                        fprintf(f, "x q[%u];\n", 12 * c16 + 1);
                                      }
                                    } else if (c9 == 0 && c14 == 19) {
                                      fprintf(f, "x q[%u];\n", 8);
                                      fprintf(f, "x q[%u];\n", 10);
                                    } else if (c9 == 1) {
                                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                                        fprintf(f, "cx q[%u], q[%u];\n", 9 * c16 + 4, 5 * c16 + 1);
                                      }
                                    }
                                  }
                                  if (c9 == 1 && c14 <= 18) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 13 * c14 - 217, 3 * c14 - 49);
                                  }
                                  if (c14 == 18) {
                                    fprintf(f, "cx q[%u], q[%u];\n", -13 * c9 + 13, 3 * c9 + 6);
                                  }
                                }
                                if (c9 == 1) {
                                  fprintf(f, "x q[%u];\n", 5);
                                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                                    fprintf(f, "cx q[%u], q[%u];\n", -2 * c16 + 19, 3 * c16 + 6);
                                  }
                                }
                              }
                            } else if (c8 == 2 && c9 == 1 && c12 == 1) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", 3 * c16 + 1);
                              }
                            }
                            if (c8 == 2 && c9 == 1) {
                              if (c12 == 0) {
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 4 * c16 + 13, 3 * c16 + 6);
                                }
                              }
                              fprintf(f, "x q[%u];\n", -c12 + 5);
                            } else if (c8 == 2 && c9 == 0) {
                              for (int c16 = 0; c16 <= 1; c16 += 1) {
                                fprintf(f, "x q[%u];\n", 7 * c16 + 1);
                              }
                              fprintf(f, "x q[%u];\n", 19);
                              fprintf(f, "cx q[%u], q[%u];\n", 11, 1);
                              fprintf(f, "x q[%u];\n", 19);
                            }
                            if (c8 == 2 && c9 <= 1 && c12 == 0) {
                              if (c9 == 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", 19, 13);
                                fprintf(f, "cx q[%u], q[%u];\n", 5, 18);
                              } else {
                                fprintf(f, "x q[%u];\n", 4);
                                fprintf(f, "cx q[%u], q[%u];\n", 2, 19);
                              }
                              if (c9 == 0) {
                                for (int c14 = 24; c14 <= 26; c14 += 1) {
                                  if (c14 == 26) {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "x q[%u];\n", c16 + 3);
                                    }
                                  } else if (c14 == 25) {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "cx q[%u], q[%u];\n", -c16 + 4, 16 * c16 + 2);
                                    }
                                  } else {
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "x q[%u];\n", 4 * c16 + 15);
                                    }
                                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                                      fprintf(f, "cx q[%u], q[%u];\n", 4 * c16 + 4, 11 * c16 + 2);
                                    }
                                  }
                                }
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "x q[%u];\n", -4 * c16 + 8);
                                }
                              } else if (c9 == 1) {
                                for (int c16 = 0; c16 <= 1; c16 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 3 * c16 + 5, 3 * c16 + 3);
                                }
                              }
                            } else if (c8 == 2 && c9 == 2 && c12 == 0) {
                              for (int c14 = 15; c14 <= 16; c14 += 1) {
                                if (c14 == 16) {
                                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                                    fprintf(f, "x q[%u];\n", 7 * c16 + 1);
                                  }
                                } else {
                                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 18 * c16 + 1, 5 * c16 + 8);
                                  }
                                }
                              }
                            }
                          } else {
                            fprintf(f, "x q[%u];\n", 5);
                          }
                          if (c8 == 2 && c9 == 1 && c12 == 0) {
                            fprintf(f, "x q[%u];\n", 0);
                          }
                        }
                        if (c8 == 2 && c9 == 0) {
                          for (int c11 = 1; c11 <= 3; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 10);
                            if (c11 == 3) {
                              fprintf(f, "cx q[%u], q[%u];\n", 10, 15);
                            }
                          }
                        }
                        if (c8 == 2 && c9 == 1) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c11 + 3);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c11 + 4);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c11 + 9);
                          }
                        }
                        if (c8 == 2 && c9 == 0) {
                          fprintf(f, "x q[%u];\n", 12);
                        }
                      } else {
                        if (c9 == 1) {
                          for (int c16 = 0; c16 <= 1; c16 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c16 + 15);
                          }
                        }
                        if (c9 == 0) {
                          fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                        }
                      }
                    }
                    if (c8 == 2) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c16 + 8);
                      }
                    }
                  } else {
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c16 + 6);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 19, 6);
                  }
                }
              }
              if (c1 == 2) {
                if (c4 == 5) {
                  fprintf(f, "x q[%u];\n", 15);
                  fprintf(f, "x q[%u];\n", 15);
                  fprintf(f, "x q[%u];\n", 15);
                }
                fprintf(f, "x q[%u];\n", -c4 + 20);
              }
              if (c4 == c1 + 2) {
                if (c1 == 2) {
                  fprintf(f, "x q[%u];\n", 16);
                  fprintf(f, "x q[%u];\n", 16);
                } else {
                  fprintf(f, "x q[%u];\n", 14);
                  fprintf(f, "x q[%u];\n", 0);
                  fprintf(f, "x q[%u];\n", 0);
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 17);
                  for (int c14 = 5; c14 <= 7; c14 += 2) {
                    if (c14 == 7) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c16 + 14);
                      }
                    }
                    fprintf(f, "x q[%u];\n", -9 * c14 + 63);
                    if (c14 == 5) {
                      fprintf(f, "cx q[%u], q[%u];\n", 14, 0);
                    }
                    fprintf(f, "x q[%u];\n", -9 * c14 + 63);
                  }
                  for (int c14 = 8; c14 <= 9; c14 += 1) {
                    fprintf(f, "x q[%u];\n", -4 * c14 + 50);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 9 * c16 + 9);
                  }
                  fprintf(f, "x q[%u];\n", 15);
                  for (int c14 = 11; c14 <= 15; c14 += 1) {
                    if (c14 == 14) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10, 16);
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c16 + 3);
                      }
                    } else if (c14 == 13) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c16 + 3);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 10, 16);
                    } else if (c14 == 12) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3, 18);
                    } else {
                      fprintf(f, "x q[%u];\n", -3 * c14 + 51);
                      if (c14 == 11) {
                        for (int c16 = 0; c16 <= 1; c16 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 8 * c16 + 9, c16 + 10);
                        }
                      }
                    }
                  }
                  fprintf(f, "x q[%u];\n", 16);
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    if (c9 == 1) {
                      fprintf(f, "x q[%u];\n", 15);
                      fprintf(f, "x q[%u];\n", 15);
                      fprintf(f, "cx q[%u], q[%u];\n", 18, 15);
                      fprintf(f, "x q[%u];\n", 18);
                      fprintf(f, "x q[%u];\n", 18);
                      fprintf(f, "cx q[%u], q[%u];\n", 3, 18);
                    }
                    for (int c16 = 0; c16 <= 1; c16 += 1) {
                      fprintf(f, "x q[%u];\n", 15 * c16 + 3);
                    }
                    if (c9 == 0) {
                      fprintf(f, "x q[%u];\n", 16);
                      fprintf(f, "cx q[%u], q[%u];\n", 16, 15);
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 6 * c16 + 11);
                      }
                      fprintf(f, "x q[%u];\n", 15);
                    }
                    if (c9 == 0) {
                      for (int c11 = 0; c11 <= 3; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 11);
                      }
                    }
                  }
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c16 + 3);
                  }
                }
              }
              if (c1 == 1) {
                if (c4 == 3) {
                  fprintf(f, "x q[%u];\n", 14);
                } else {
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c16 + 6);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                  fprintf(f, "x q[%u];\n", 14);
                  fprintf(f, "x q[%u];\n", 14);
                  for (int c9 = 1; c9 <= 2; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 14);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                }
              }
              if (c1 == 2 && c4 == 5) {
                fprintf(f, "cx q[%u], q[%u];\n", 16, 15);
                fprintf(f, "x q[%u];\n", 16);
              }
              if (c1 == 1 && c4 == 3) {
                fprintf(f, "x q[%u];\n", 14);
              }
            } else if (c1 == 1 && c4 == 6) {
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c16 + 8);
              }
              for (int c6 = 1; c6 <= 2; c6 += 1) {
                if (c6 == 2) {
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 15 * c16 + 3);
                  }
                  fprintf(f, "x q[%u];\n", 3);
                } else {
                  fprintf(f, "x q[%u];\n", 11);
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 17);
                  fprintf(f, "x q[%u];\n", 17);
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 5);
                  fprintf(f, "cx q[%u], q[%u];\n", 0, 17);
                  fprintf(f, "x q[%u];\n", 0);
                  fprintf(f, "cx q[%u], q[%u];\n", 14, 0);
                  fprintf(f, "x q[%u];\n", 0);
                  fprintf(f, "cx q[%u], q[%u];\n", 14, 12);
                  for (int c14 = 11; c14 <= 15; c14 += 1) {
                    if (c14 == 14) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c16);
                      }
                    } else if (c14 == 12) {
                      fprintf(f, "cx q[%u], q[%u];\n", 14, 0);
                    } else {
                      fprintf(f, "x q[%u];\n", -c14 + 25);
                    }
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c11 + 10);
                  }
                  fprintf(f, "x q[%u];\n", 12);
                  fprintf(f, "x q[%u];\n", 12);
                  fprintf(f, "cx q[%u], q[%u];\n", 9, 10);
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 10);
                  }
                  fprintf(f, "x q[%u];\n", 10);
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 14 * c16);
                  }
                  fprintf(f, "x q[%u];\n", 12);
                  fprintf(f, "cx q[%u], q[%u];\n", 9, 2);
                  fprintf(f, "cx q[%u], q[%u];\n", 11, 2);
                  fprintf(f, "x q[%u];\n", 2);
                  fprintf(f, "x q[%u];\n", 2);
                  fprintf(f, "x q[%u];\n", 2);
                  fprintf(f, "cx q[%u], q[%u];\n", 17, 11);
                }
                fprintf(f, "cx q[%u], q[%u];\n", -8 * c6 + 19, 14 * c6 - 10);
                if (c6 == 1) {
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -6 * c16 + 11, 5 * c16 + 4);
                  }
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c16 + 4, 8 * c16 + 1);
                  }
                  for (int c16 = 0; c16 <= 2; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c16 + 1);
                  }
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -2 * c16 + 11, 17 * c16 + 2);
                  }
                  for (int c14 = 12; c14 <= 13; c14 += 1) {
                    if (c14 == 13) {
                      fprintf(f, "x q[%u];\n", 19);
                    }
                    fprintf(f, "x q[%u];\n", -10 * c14 + 139);
                    if (c14 == 12) {
                      fprintf(f, "cx q[%u], q[%u];\n", 4, 2);
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c16 + 9);
                      }
                    }
                  }
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 8 * c16 + 2, 18 * c16 + 1);
                  }
                  for (int c14 = 15; c14 <= 23; c14 += 1) {
                    if (c14 == 17) {
                      for (int c16 = 0; c16 <= 1; c16 += 1) {
                        fprintf(f, "x q[%u];\n", 17 * c16 + 2);
                      }
                    } else if (c14 == 16) {
                      fprintf(f, "cx q[%u], q[%u];\n", 2, 19);
                    } else if ((c14 + 1) % 4 == 0) {
                      fprintf(f, "x q[%u];\n", (-9 * c14 + 211) / 4);
                      if (c14 == 15) {
                        fprintf(f, "cx q[%u], q[%u];\n", 11, 2);
                        for (int c16 = 0; c16 <= 1; c16 += 1) {
                          fprintf(f, "x q[%u];\n", 9 * c16 + 1);
                        }
                      }
                    }
                  }
                  fprintf(f, "x q[%u];\n", 5);
                }
              }
            } else if (c1 == 1) {
              fprintf(f, "x q[%u];\n", 7);
              fprintf(f, "x q[%u];\n", 7);
              fprintf(f, "x q[%u];\n", 11);
            } else {
              fprintf(f, "x q[%u];\n", 1);
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", c16 + 1);
              }
              fprintf(f, "x q[%u];\n", 1);
            }
          } else if (c1 >= 1 && c4 == 2 * c1 + 2) {
            if (c1 == 2) {
              fprintf(f, "x q[%u];\n", 4);
              fprintf(f, "cx q[%u], q[%u];\n", 17, 11);
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -2 * c16 + 11, 15 * c16 + 4);
              }
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c16 + 4);
              }
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c16 + 4);
              }
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c16 + 4);
              }
              fprintf(f, "x q[%u];\n", 5);
              for (int c16 = 0; c16 <= 1; c16 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -15 * c16 + 17, 5 * c16 + 5);
              }
              for (int c14 = 15; c14 <= 17; c14 += 1) {
                if (c14 == 16) {
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 8 * c16 + 2, 18 * c16 + 1);
                  }
                  for (int c16 = 0; c16 <= 1; c16 += 1) {
                    fprintf(f, "x q[%u];\n", 12 * c16 + 5);
                  }
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", -5 * c14 + 85, -c14 + 34);
                }
              }
              fprintf(f, "x q[%u];\n", 9);
            } else {
              fprintf(f, "x q[%u];\n", 7);
              fprintf(f, "x q[%u];\n", 7);
            }
          }
          if (c1 == 1 && c4 >= 3 && c4 <= 4) {
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              fprintf(f, "x q[%u];\n", -6 * c6 + 12);
            }
          } else if (c1 == 2 && c4 == 7) {
            fprintf(f, "x q[%u];\n", 15);
          } else if (c1 == 0 && c4 == 1) {
            fprintf(f, "x q[%u];\n", 2);
          }
        }
      }
      if (c1 == 0) {
        fprintf(f, "x q[%u];\n", 1);
      } else if (c1 == 1) {
        for (int c16 = 0; c16 <= 1; c16 += 1) {
          fprintf(f, "x q[%u];\n", 5 * c16 + 8);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 13, 6);
        for (int c16 = 0; c16 <= 1; c16 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c16 + 6);
        }
        fprintf(f, "x q[%u];\n", 6);
        fprintf(f, "cx q[%u], q[%u];\n", 13, 6);
        fprintf(f, "cx q[%u], q[%u];\n", 13, 6);
        fprintf(f, "x q[%u];\n", 8);
        fprintf(f, "x q[%u];\n", 6);
        fprintf(f, "cx q[%u], q[%u];\n", 8, 13);
      }
    }
    if (c1 == 1) {
      for (int c3 = 1; c3 <= 3; c3 += 1) {
        fprintf(f, "x q[%u];\n", 7);
        if (c3 == 3) {
          fprintf(f, "cx q[%u], q[%u];\n", 7, 16);
          fprintf(f, "x q[%u];\n", 7);
          fprintf(f, "cx q[%u], q[%u];\n", 7, 16);
        }
      }
    }
    if (c1 == 1) {
      for (int c3 = 0; c3 <= 1; c3 += 1) {
        fprintf(f, "x q[%u];\n", -8 * c3 + 10);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 5);
  }
}
fclose(f);
return 0;
}