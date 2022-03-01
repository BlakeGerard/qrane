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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.6D1_.2D2_4.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 2; c1 += 1) {
    for (int c3 = max(0, c1 - 1); c3 <= -c1 + c1 / 2 + 3; c3 += 1) {
      if (c1 >= 1 && c3 + 2 >= 2 * c1) {
        if (c1 == 1 && c3 == 1) {
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", -7 * c14 + 18);
          }
          fprintf(f, "x q[%u];\n", 18);
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", -2 * c14 + 19, 6 * c14 + 12);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 5 * c14 + 12);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 12, 13);
          for (int c14 = -2; c14 <= 0; c14 += 1) {
            fprintf(f, "x q[%u];\n", -c14 + 17);
          }
          fprintf(f, "x q[%u];\n", 13);
        }
        if (c1 == 1) {
          for (int c6 = max(0, (c3 % 2) - 3 * c3 + 2); c6 <= 2; c6 += 1) {
            if (c6 >= 1) {
              if (c3 <= 1) {
                if (c3 == 1 && c6 == 2) {
                  fprintf(f, "x q[%u];\n", 9);
                } else if (c3 == 0 && c6 == 2) {
                  fprintf(f, "x q[%u];\n", 12);
                } else {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "x q[%u];\n", 9);
                  }
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", c14 + 9);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 9, 7);
                }
              } else {
                if (c6 == 1) {
                  fprintf(f, "x q[%u];\n", 5);
                }
                for (int c8 = -c6 + 1; c8 <= -c6 + 2; c8 += 1) {
                  if (c6 == 2 && c8 == 0) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 3 * c11 + 5, 9 * c11 + 10);
                    }
                  }
                  if (c8 == 0) {
                    for (int c10 = -c6 + 2; c10 <= 1; c10 += 1) {
                      if (c6 == 2 && c10 == 1) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 5);
                        }
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 5);
                        }
                      }
                      if (c6 == 2) {
                        if (c10 == 0) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c14 + 10);
                          }
                        }
                        for (int c12 = -2 * c10 + 12; c12 <= -3 * c10 + 13; c12 += 1) {
                          if (3 * c10 + c12 == 13) {
                            fprintf(f, "x q[%u];\n", 10);
                            if (c10 == 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 5, 16);
                            }
                          } else {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 9 * c14 + 10);
                            }
                          }
                        }
                        if (c10 == 1) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c14 + 5);
                          }
                        }
                      } else {
                        fprintf(f, "cx q[%u], q[%u];\n", 4, 14);
                      }
                    }
                    if (c6 == 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 4, 12);
                      fprintf(f, "x q[%u];\n", 4);
                    }
                  }
                  if (c6 + c8 == 1) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      for (int c15 = 0; c15 <= c14; c15 += 1) {
                        fprintf(f, "x q[%u];\n", -c14 + 8 * c15 + 5);
                      }
                    }
                  } else if (c6 == 2) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c14 + 14);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -8 * c14 + 16, 17 * c14 + 2);
                    }
                    fprintf(f, "cx q[%u], q[%u];\n", 2, 1);
                  }
                  if (c6 == 2) {
                    fprintf(f, "cx q[%u], q[%u];\n", -7 * c8 + 5, -3 * c8 + 10);
                  }
                  if (c6 + c8 == 2) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", c14 + 1);
                    }
                    if (c6 == 2) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 5);
                      }
                    }
                  }
                  if (c6 == 2) {
                    fprintf(f, "x q[%u];\n", -7 * c8 + 5);
                  } else if (c8 == 0) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                    }
                    fprintf(f, "x q[%u];\n", 18);
                  }
                }
                if (c6 == 2) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", c14 + 1);
                  }
                } else {
                  fprintf(f, "x q[%u];\n", 1);
                }
              }
            } else {
              if (c3 == 2) {
                fprintf(f, "x q[%u];\n", 5);
                fprintf(f, "x q[%u];\n", 5);
                fprintf(f, "x q[%u];\n", 5);
                fprintf(f, "x q[%u];\n", 5);
                fprintf(f, "x q[%u];\n", 5);
                fprintf(f, "x q[%u];\n", 5);
                fprintf(f, "x q[%u];\n", 5);
                for (int c10 = 1; c10 <= 2; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 5);
                }
              }
              for (int c10 = 2; c10 <= c3 + 1; c10 += 1) {
                if (c3 == 2) {
                  fprintf(f, "x q[%u];\n", 5);
                }
                if (c10 == 2) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", c14 + 12);
                  }
                }
              }
              if (c3 == 2) {
                for (int c10 = 3; c10 <= 4; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 5);
                }
                fprintf(f, "x q[%u];\n", 5);
              }
              fprintf(f, "x q[%u];\n", 4 * c3 + 5);
            }
          }
          if (c3 == 2) {
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -5 * c12 + 15, 4 * c12 + 5);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 11 * c14 + 8);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 11 * c14 + 8);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 10 * c14 + 5);
            }
          } else if (c3 == 1) {
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", c14 + 17);
            }
          }
        } else {
          fprintf(f, "cx q[%u], q[%u];\n", 9, 7);
          for (int c12 = 0; c12 <= 1; c12 += 1) {
            fprintf(f, "cx q[%u], q[%u];\n", 9 * c12 + 7, 9 * c12 + 1);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 6 * c14 + 10);
          }
        }
      }
      if (c1 >= 1 && c3 == 1) {
        fprintf(f, "x q[%u];\n", 7);
        if (c1 == 2) {
          for (int c6 = 0; c6 <= 1; c6 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c6 + 7);
          }
        }
      } else {
        if (c1 == 0 && c3 <= 2) {
          for (int c4 = -c3 + 1; c4 <= 0; c4 += 1) {
            if (c4 == 0) {
              for (int c6 = 0; c6 <= -c3 + 2; c6 += 1) {
                if (c3 == 1 && c6 == 1) {
                  fprintf(f, "x q[%u];\n", 9);
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3 * c10 + 10, 2 * c10 + 9);
                  }
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c14 + 6);
                  }
                } else if (c3 == 2) {
                  fprintf(f, "x q[%u];\n", 12);
                  fprintf(f, "x q[%u];\n", 8);
                } else {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c14 + 2);
                  }
                }
                for (int c10 = 2; c10 <= -c3 - c6 + 4; c10 += 1) {
                  if (c3 == 1 && c6 == 0 && c10 == 2) {
                    fprintf(f, "cx q[%u], q[%u];\n", 17, 18);
                    for (int c12 = 23; c12 <= 24; c12 += 1) {
                      if (c12 == 24) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 6);
                        }
                      } else {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -4 * c14 + 10, 8 * c14 + 9);
                        }
                      }
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c14 + 6);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14 + 9);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14 + 9);
                    }
                    for (int c12 = 28; c12 <= 29; c12 += 1) {
                      if (c12 == 29) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -3 * c14 + 16, c14 + 10);
                        }
                      } else {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", c14 + 9);
                        }
                      }
                    }
                  } else {
                    if (c3 == 2 && c6 == 0 && c10 == 2) {
                      fprintf(f, "x q[%u];\n", 4);
                    }
                    for (int c12 = -12 * c6 + 23; c12 <= 23; c12 += 1) {
                      if (12 * c6 + c12 == 23) {
                        for (int c14 = 0; c14 <= -c3 + 2; c14 += 1) {
                          fprintf(f, "x q[%u];\n", -2 * c3 + 13 * c14 + 8);
                        }
                      } else {
                        if (c12 == 22) {
                          fprintf(f, "x q[%u];\n", 7);
                        } else if (c12 == 18) {
                          for (int c14 = -1; c14 <= 0; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c14 + 12);
                          }
                        } else if (c12 == 15) {
                          fprintf(f, "x q[%u];\n", 8);
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -12 * c14 + 13, 8 * c14 + 3);
                          }
                        } else if (c12 == 13) {
                          for (int c14 = 0; c14 <= 2; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c14 + 9);
                          }
                        }
                        if ((c12 - 4) % 9 == 0) {
                          for (int c14 = 0; c14 < (c12 - 4) / 9; c14 += 1) {
                            fprintf(f, "x q[%u];\n", ((-5 * c12 + 119) / 9) + 10 * c14);
                          }
                        } else if ((c12 + 2) % 5 == 0) {
                          fprintf(f, "x q[%u];\n", (-8 * c12 + 204) / 5);
                          if (c12 == 23) {
                            fprintf(f, "x q[%u];\n", 7);
                          }
                          if (c12 == 18) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 10 * c14 + 1);
                            }
                          }
                        } else {
                          if (c12 == 21) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 4 * c14 + 7, 2 * c14 + 1);
                            }
                          } else if (c12 == 20) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 10 * c14 + 3);
                            }
                          } else if (c12 == 19) {
                            fprintf(f, "x q[%u];\n", 1);
                            fprintf(f, "cx q[%u], q[%u];\n", 13, 3);
                          }
                          if (c12 == 17) {
                            fprintf(f, "x q[%u];\n", 7);
                            fprintf(f, "cx q[%u], q[%u];\n", 4, 12);
                          } else if (c12 == 15) {
                            fprintf(f, "x q[%u];\n", 4);
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", -7 * c14 + 16);
                            }
                          } else if (c12 <= 16 && c12 % 4 == 0) {
                            fprintf(f, "x q[%u];\n", (3 * c12 / 4) - 3);
                            if (c12 == 16) {
                              fprintf(f, "x q[%u];\n", 4);
                            }
                          } else if (c12 == 14) {
                            fprintf(f, "x q[%u];\n", 4);
                            for (int c14 = 0; c14 <= 2; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c14 + 9);
                            }
                          }
                        }
                      }
                    }
                  }
                  if (c6 == 0 && c10 == 2) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", -9 * c3 + 6 * c14 + 19);
                    }
                    if (c3 == 1) {
                      for (int c12 = 31; c12 <= 33; c12 += 1) {
                        if (c12 <= 32) {
                          for (int c14 = 0; c14 < c12 - 30; c14 += 1) {
                            fprintf(f, "x q[%u];\n", -9 * c12 + 6 * c14 + 298);
                          }
                          if (c12 == 32) {
                            fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
                          } else if (c12 == 31) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              for (int c15 = 0; c15 <= c14; c15 += 1) {
                                fprintf(f, "x q[%u];\n", 2 * c14 + 6 * c15 + 8);
                              }
                            }
                          }
                        } else {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 13 * c14 + 6);
                          }
                        }
                      }
                    }
                  }
                  if (c10 == 2) {
                    for (int c12 = max(24, -21 * c6 + 36); c12 <= 36; c12 += 1) {
                      if (c12 == 36) {
                        for (int c14 = 0; c14 <= c6; c14 += 1) {
                          fprintf(f, "x q[%u];\n", -4 * c6 + 13 * c14 + 8);
                        }
                      } else {
                        if (c12 == 29) {
                          fprintf(f, "cx q[%u], q[%u];\n", 0, 1);
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c14 + 8);
                          }
                        }
                        if (c12 <= 31) {
                          for (int c14 = 0; c14 < c12 - 29; c14 += 1) {
                            fprintf(f, "x q[%u];\n", -13 * c12 + 16 * c14 + 405);
                          }
                          if (c12 == 31) {
                            fprintf(f, "x q[%u];\n", 15);
                          } else if (c12 == 30) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              for (int c15 = 0; c15 <= c14; c15 += 1) {
                                fprintf(f, "x q[%u];\n", -12 * c14 + 16 * c15 + 14);
                              }
                            }
                          } else if (c12 == 29) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              for (int c15 = 0; c15 <= c14; c15 += 1) {
                                fprintf(f, "x q[%u];\n", -13 * c14 + 16 * c15 + 15);
                              }
                            }
                          } else if (c12 == 28) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 16 * c14 + 2);
                            }
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -2 * c14 + 19, 4 * c14);
                            }
                          } else if (c12 == 27) {
                            fprintf(f, "cx q[%u], q[%u];\n", 2, 0);
                          } else if (c12 == 26) {
                            fprintf(f, "cx q[%u], q[%u];\n", 0, 12);
                          } else if (c12 == 25) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                            }
                          } else if (c12 == 24) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                            }
                          }
                        } else if (c12 == 32) {
                          fprintf(f, "cx q[%u], q[%u];\n", 10, 2);
                        }
                      }
                    }
                  }
                }
                if (c3 == 1 && c6 == 1) {
                  fprintf(f, "x q[%u];\n", 18);
                } else if (c3 == 2) {
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    for (int c10 = 0; c10 <= 1; c10 += 1) {
                      fprintf(f, "x q[%u];\n", 13);
                    }
                  }
                }
              }
            }
            if (c4 == 0) {
              for (int c8 = -c3 + 1; c8 <= -c3 + 2; c8 += 1) {
                if (c3 == 2 && c8 == 0) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    for (int c13 = 0; c13 <= 1; c13 += 1) {
                      fprintf(f, "x q[%u];\n", 18);
                    }
                  }
                  fprintf(f, "x q[%u];\n", 18);
                }
                for (int c10 = 0; c10 <= min(2, c8 + 2); c10 += 1) {
                  if (c3 == 2 && c8 == 0 && c10 == 1) {
                    fprintf(f, "x q[%u];\n", 4);
                    for (int c12 = 12; c12 <= 13; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -c12 + 30, -10 * c12 + 134);
                      if (c12 == 12) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 13 * c14 + 4);
                        }
                      }
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14 + 14);
                    }
                  }
                  if (c3 == 2 && c8 == 0 && c10 == 2) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c14 + 6);
                    }
                  } else if (c3 == 1 && c8 == 0 && c10 == 2) {
                    for (int c12 = 0; c12 <= 9; c12 += 1) {
                      if (c12 == 7) {
                        fprintf(f, "x q[%u];\n", 19);
                      }
                      if (c12 >= 7 && c12 <= 8) {
                        fprintf(f, "cx q[%u], q[%u];\n", -2 * c12 + 22, 3 * c12 - 5);
                        if (c12 == 8) {
                          fprintf(f, "cx q[%u], q[%u];\n", 16, 10);
                        }
                      } else {
                        if (c12 == 9) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c14 + 6);
                          }
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c14 + 10);
                          }
                        }
                        if (c12 == 6) {
                          fprintf(f, "cx q[%u], q[%u];\n", 8, 19);
                        } else if (c12 == 5) {
                          fprintf(f, "cx q[%u], q[%u];\n", 15, 8);
                        } else if (c12 == 4) {
                          fprintf(f, "cx q[%u], q[%u];\n", 15, 8);
                        } else if (c12 == 3) {
                          fprintf(f, "x q[%u];\n", 8);
                          fprintf(f, "x q[%u];\n", 15);
                        } else if (c12 == 2) {
                          fprintf(f, "x q[%u];\n", 15);
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c14 + 8);
                          }
                        } else if (c12 == 1) {
                          fprintf(f, "x q[%u];\n", 15);
                          fprintf(f, "x q[%u];\n", 7);
                        } else if (c12 == 0) {
                          fprintf(f, "x q[%u];\n", 15);
                          fprintf(f, "x q[%u];\n", 7);
                        }
                      }
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 3 * c14 + 10);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 13 * c14 + 6);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 3 * c14 + 10);
                    }
                  }
                  if (c8 == 0 && c10 == 2) {
                    for (int c12 = -c3 + 13; c12 <= 12; c12 += 1) {
                      if (c3 == 2 && c12 == 12) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 11 * c14 + 6);
                        }
                      } else if (c3 == 1 && c12 == 12) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 10);
                        }
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 12);
                        }
                      } else {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 11 * c14 + 6);
                        }
                      }
                    }
                  }
                  if (c8 == 0 && c3 + c10 == 3) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c3 + 3 * c14 + 10);
                    }
                    if (c3 == 1) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c14 + 13);
                      }
                    }
                  } else if (c3 == 2 && c8 == 0 && c10 == 2) {
                    for (int c12 = 13; c12 <= 14; c12 += 1) {
                      if (c12 == 14) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -c14 + 7, 16 * c14 + 1);
                        }
                      } else {
                        fprintf(f, "x q[%u];\n", 6);
                      }
                    }
                  }
                  if (c10 <= 1) {
                    for (int c14 = 0; c14 < c3 + c8; c14 += 1) {
                      fprintf(f, "x q[%u];\n", -4 * c3 - 4 * c8 + 3 * c14 + 22);
                    }
                  }
                  if (c8 == 0 && c3 + c10 >= 3) {
                    for (int c12 = c3 - c10 + 15; c12 <= min(21 * c3 - 5, -c3 + 18 * c10 + 2); c12 += 1) {
                      if (c10 == 2 && (c12 + 6) % 21 == 0) {
                        for (int c14 = 0; c14 <= -c3 + 2; c14 += 1) {
                          fprintf(f, "x q[%u];\n", ((-4 * c12 + 60) / 21) + 4 * c3 + 13 * c14);
                        }
                      }
                      if (c3 == 1 && c10 == 2 && c12 <= 15) {
                        fprintf(f, "cx q[%u], q[%u];\n", -6 * c12 + 96, 13 * c12 - 179);
                      } else if (c3 == 1 && c10 == 2 && c12 == 16) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          for (int c15 = 0; c15 <= 1; c15 += 1) {
                            fprintf(f, "x q[%u];\n", -c14 + 13 * c15 + 4);
                          }
                        }
                        fprintf(f, "x q[%u];\n", 11);
                      }
                      if (c3 == 1 && c10 == 2 && c12 >= 15) {
                        for (int c14 = c12 - 15; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c12 - 11 * c14 - 31);
                        }
                      }
                      if (c3 + c10 == 3 && c12 == 3 * c3 + 12) {
                        fprintf(f, "cx q[%u], q[%u];\n", -6 * c3 + 18, 6 * c3 + 5);
                      } else {
                        if (c10 == 2 && (c12 + 4) % 11 == 0) {
                          for (int c14 = 0; c14 < (c12 - 7) / 11; c14 += 1) {
                            fprintf(f, "x q[%u];\n", ((12 * c12 - 216) / 11) + 7 * c14);
                          }
                          if (c3 == 2 && c12 == 18) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              for (int c15 = 0; c15 <= c14; c15 += 1) {
                                fprintf(f, "x q[%u];\n", -4 * c14 + 5 * c15 + 5);
                              }
                            }
                          }
                        } else {
                          if (c3 == 2 && c10 == 2 && c12 == 28) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 9 * c14 + 10);
                            }
                          } else if (c3 == 2 && c10 == 2 && c12 == 27) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 9 * c14 + 10, 3 * c14 + 9);
                            }
                          } else if (c3 == 2 && c10 == 2 && c12 == 26) {
                            for (int c14 = -1; c14 <= 0; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c14 + 12);
                            }
                          } else if (c3 == 2 && c10 == 2 && c12 == 25) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                            }
                          } else if (c3 == 2 && c10 == 2 && c12 == 23) {
                            fprintf(f, "cx q[%u], q[%u];\n", 9, 7);
                          } else if (c3 == 2 && c10 == 2 && c12 == 21) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c14);
                            }
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", -12 * c14 + 13);
                            }
                          } else if (c3 == 2 && c10 == 2 && c12 == 20) {
                            for (int c14 = 0; c14 <= 2; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c14);
                            }
                            fprintf(f, "x q[%u];\n", 5);
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c14 + 1);
                            }
                          } else if (c3 == 2 && c10 == 2 && c12 == 19) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              for (int c15 = 0; c15 <= c14; c15 += 1) {
                                fprintf(f, "x q[%u];\n", -4 * c14 + 5 * c15 + 5);
                              }
                            }
                            fprintf(f, "x q[%u];\n", 8);
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 2 * c14 + 2, 12 * c14);
                            }
                            fprintf(f, "x q[%u];\n", 18);
                          }
                          if (c3 == 2 && c10 == 2 && c12 == 17) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c14 + 1);
                            }
                          } else if (c3 == 2 && c10 == 1 && c12 == 16) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 3 * c14 + 14);
                            }
                          }
                        }
                        if (c3 == 2 && c10 == 2 && (c12 - 1) % 17 == 0) {
                          fprintf(f, "x q[%u];\n", (-8 * c12 + 348) / 17);
                          if (c12 == 18) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c14 + 14);
                            }
                          }
                        } else if (c3 == 2 && c10 == 2 && c12 == 17) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c14 + 14);
                          }
                        } else if (c3 == 2 && c10 == 1 && c12 == 17) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 6 * c14);
                          }
                        } else if (c3 == 2 && c10 == 2 && c12 == 16) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c14 + 1);
                          }
                        } else if (c3 == 2 && c10 == 1 && c12 == 16) {
                          fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
                        } else if (c3 == 2 && c12 == 15) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c14 + 1);
                          }
                        } else if (c3 == 1 && c12 == 14) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            for (int c15 = 0; c15 <= c14; c15 += 1) {
                              fprintf(f, "x q[%u];\n", -c14 + 3 * c15 + 14);
                            }
                          }
                        }
                      }
                    }
                    if (c3 == 1 && c10 == 2) {
                      for (int c12 = 17; c12 <= 18; c12 += 1) {
                        if (c12 == 18) {
                          fprintf(f, "x q[%u];\n", 12);
                          fprintf(f, "x q[%u];\n", 14);
                          fprintf(f, "cx q[%u], q[%u];\n", 1, 11);
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c14 + 6);
                          }
                        } else {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            for (int c15 = 0; c15 <= c14; c15 += 1) {
                              fprintf(f, "x q[%u];\n", -11 * c14 + 13 * c15 + 14);
                            }
                          }
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", c14 + 11);
                          }
                        }
                      }
                      for (int c12 = 19; c12 <= 29; c12 += 1) {
                        if (c12 == 29) {
                          fprintf(f, "x q[%u];\n", 4);
                        } else if (c12 == 28) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                          }
                        } else if (c12 == 24) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c14 + 14);
                          }
                        } else {
                          if (c12 == 23) {
                            fprintf(f, "x q[%u];\n", 12);
                          } else if (c12 == 21) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 4 * c14 + 7, 2 * c14 + 1);
                            }
                            fprintf(f, "x q[%u];\n", 15);
                          } else if (c12 == 20) {
                            fprintf(f, "x q[%u];\n", 11);
                            fprintf(f, "cx q[%u], q[%u];\n", 17, 14);
                            fprintf(f, "x q[%u];\n", 15);
                          } else if (c12 == 19) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", -3 * c14 + 14);
                            }
                            fprintf(f, "x q[%u];\n", 16);
                          } else if ((c12 + 2) % 4 == 0) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                            }
                          }
                          if (c12 >= 23 && (c12 + 1) % 4 == 0) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                            }
                          }
                        }
                      }
                    } else if (c3 == 2 && c10 == 1) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c14 + 6);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c14 + 14);
                      }
                    }
                  }
                  if (c3 == 1 && c8 == 1 && c10 == 2) {
                    fprintf(f, "x q[%u];\n", 14);
                  }
                }
              }
            } else {
              for (int c8 = 0; c8 <= 1; c8 += 1) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  for (int c13 = 0; c13 <= 1; c13 += 1) {
                    fprintf(f, "x q[%u];\n", 11 * c8 + 8);
                  }
                }
              }
            }
            if (c4 == 0) {
              for (int c6 = -c3 + 4; c6 <= 3; c6 += 1) {
                if (c3 == 1 && c6 == 3) {
                  fprintf(f, "x q[%u];\n", 12);
                }
                if (c6 == 3) {
                  fprintf(f, "x q[%u];\n", -10 * c3 + 22);
                  if (c3 == 1) {
                    fprintf(f, "x q[%u];\n", 4);
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c14 + 1);
                    }
                  }
                } else {
                  fprintf(f, "x q[%u];\n", 4);
                  fprintf(f, "cx q[%u], q[%u];\n", 2, 0);
                  fprintf(f, "x q[%u];\n", 0);
                  fprintf(f, "x q[%u];\n", 18);
                  fprintf(f, "x q[%u];\n", 0);
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c14);
                  }
                  for (int c10 = 2; c10 <= 3; c10 += 1) {
                    if (c10 == 2) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                      }
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                    }
                    if (c10 == 2) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 3);
                      }
                    }
                  }
                }
              }
            }
          }
        } else if (c1 == 0 && c3 == 3) {
          fprintf(f, "x q[%u];\n", 2);
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 9 * c14 + 2);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 2, 0);
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", -7 * c14 + 18);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 7 * c14);
          }
          fprintf(f, "cx q[%u], q[%u];\n", 9, 7);
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 2 * c14 + 5);
          }
          for (int c6 = 0; c6 <= 2; c6 += 1) {
            if (c6 % 2 == 0) {
              if (c6 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", 10, 9);
              }
              for (int c14 = -1; c14 <= 0; c14 += 1) {
                fprintf(f, "x q[%u];\n", -4 * c6 - c14 + 9);
              }
              if (c6 == 0) {
                fprintf(f, "cx q[%u], q[%u];\n", 2, 7);
              }
              if (c6 == 0) {
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  for (int c10 = -c8 + 2; c10 <= -c8 + 3; c10 += 1) {
                    fprintf(f, "x q[%u];\n", -5 * c8 + 7);
                  }
                }
              }
            }
            if (c6 <= 1) {
              for (int c10 = -c6 + 2; c10 <= 2; c10 += 1) {
                if (c6 == 1 && c10 == 2) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", -12 * c14 + 13);
                  }
                  fprintf(f, "x q[%u];\n", 13);
                }
                if (c10 == 2) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 2);
                  }
                  if (c6 == 1) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      for (int c15 = 0; c15 <= c14; c15 += 1) {
                        fprintf(f, "x q[%u];\n", -3 * c14 + 5 * c15 + 5);
                      }
                    }
                  }
                }
                if (c6 == 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -14 * c10 + 30, -9 * c10 + 19);
                  if (c10 == 1) {
                    fprintf(f, "x q[%u];\n", 16);
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c14 + 10);
                    }
                  }
                }
              }
              if (c6 == 0) {
                for (int c9 = 0; c9 <= 1; c9 += 1) {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "x q[%u];\n", 0);
                  }
                }
              }
            }
          }
        }
        if (c1 == 0 && c3 == 0) {
          for (int c6 = 0; c6 <= 3; c6 += 1) {
            if ((c6 + 1) % 2 == 0) {
              if (c6 == 3) {
                fprintf(f, "cx q[%u], q[%u];\n", 16, 10);
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 13 * c14 + 3);
                }
              } else {
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c10 + 1);
                }
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 4 * c10 + 2, 15 * c10 + 1);
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", c14 + 1);
                }
              }
            } else {
              for (int c8 = (c6 / 2) - 2; c8 <= 0; c8 += 1) {
                if (c6 == 2 && c8 == 0) {
                  fprintf(f, "x q[%u];\n", 15);
                } else if (c6 == 2 && c8 == -1) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", c14 + 1);
                  }
                }
                if (c6 == 2) {
                  for (int c10 = 1; c10 <= -c8 + 2; c10 += 1) {
                    if (c8 == 0 && c10 == 2) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c14 + 11);
                      }
                    }
                    if (c8 + c10 >= 1) {
                      if (c8 == 0 && c10 == 2) {
                        for (int c12 = 15; c12 <= 17; c12 += 1) {
                          if (c12 == 17) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 16 * c14 + 3);
                            }
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 9 * c14 + 4);
                            }
                          } else if (c12 == 16) {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 6 * c14 + 13, c14 + 3);
                            }
                          } else {
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", c14 + 12);
                            }
                          }
                        }
                      }
                      if (c10 == 2) {
                        for (int c12 = 18; c12 <= 3 * c8 + 35; c12 += 1) {
                          if (c12 == 20) {
                            fprintf(f, "x q[%u];\n", -7 * c8);
                          } else {
                            if (c8 == 0 && c12 == 18) {
                              for (int c14 = -1; c14 <= 0; c14 += 1) {
                                fprintf(f, "x q[%u];\n", -c14);
                              }
                              fprintf(f, "cx q[%u], q[%u];\n", 13, 3);
                            }
                            if ((c12 - 1) % 17 == 0) {
                              fprintf(f, "x q[%u];\n", ((-8 * c12 + 314) / 17) - 5 * c8);
                              if (c8 == 0 && c12 == 18) {
                                fprintf(f, "cx q[%u], q[%u];\n", 6, 19);
                              }
                            } else if (c8 == 0 && c12 == 34) {
                              fprintf(f, "x q[%u];\n", 2);
                            } else if (c8 == 0 && c12 == 19) {
                              for (int c14 = 0; c14 <= 1; c14 += 1) {
                                fprintf(f, "x q[%u];\n", 13 * c14 + 6);
                              }
                              for (int c14 = 0; c14 <= 1; c14 += 1) {
                                fprintf(f, "x q[%u];\n", c14);
                              }
                              fprintf(f, "cx q[%u], q[%u];\n", 13, 3);
                            }
                          }
                        }
                      }
                      fprintf(f, "x q[%u];\n", -5 * c8 + 2);
                      if (c8 == -1 && c10 == 2) {
                        for (int c12 = 34; c12 <= 35; c12 += 1) {
                          if (c12 == 35) {
                            fprintf(f, "x q[%u];\n", 7);
                          } else {
                            fprintf(f, "x q[%u];\n", 7);
                          }
                        }
                      }
                    }
                    if (c10 == 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -2 * c8, -6 * c8 + 1);
                    } else if (c8 == 0 && c10 == 2) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 3 * c14 + 2, 15 * c14 + 1);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c14 + 1);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c14 + 5);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 10 * c14 + 6, 2 * c14 + 17);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c14 + 16);
                      }
                    }
                  }
                } else {
                  if (c8 == 0) {
                    for (int c14 = 0; c14 <= 3; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c14);
                    }
                  }
                  if (c8 == 0) {
                    for (int c12 = 1; c12 <= 19; c12 += 1) {
                      if (c12 == 19) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c14 + 9);
                        }
                      } else if (c12 == 17) {
                        for (int c14 = 0; c14 <= 2; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c14 + 9);
                        }
                      } else if (c12 == 16) {
                        for (int c14 = 0; c14 <= 3; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 6);
                        }
                      } else if (c12 == 11) {
                        for (int c14 = 0; c14 <= 3; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 6);
                        }
                      } else if (c12 == 3) {
                        for (int c14 = 0; c14 <= 2; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 8 * c14 + 2);
                        }
                      } else if ((c12 - 2) % 10 == 0) {
                        for (int c14 = 0; c14 <= (c12 - 2) / 10; c14 += 1) {
                          fprintf(f, "x q[%u];\n", ((-9 * c12 + 198) / 10) + 9 * c14);
                        }
                        if (c12 == 2) {
                          for (int c14 = 0; c14 <= 3; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c14);
                          }
                        }
                      } else if (c12 == 1) {
                        for (int c14 = 0; c14 <= 3; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c14);
                        }
                      } else if (c12 >= 13 && (c12 + 2) % 5 == 0) {
                        if (c12 == 18) {
                          fprintf(f, "x q[%u];\n", 9);
                          fprintf(f, "x q[%u];\n", 10);
                        }
                        fprintf(f, "x q[%u];\n", (-8 * c12 + 184) / 5);
                        if (c12 == 18) {
                          fprintf(f, "x q[%u];\n", 8);
                          fprintf(f, "x q[%u];\n", 9);
                        }
                        if (c12 == 18) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            if (c14 == 0) {
                              fprintf(f, "x q[%u];\n", 7);
                            }
                            fprintf(f, "x q[%u];\n", 10 * c14 + 7);
                            fprintf(f, "x q[%u];\n", 10 * c14 + 7);
                            fprintf(f, "x q[%u];\n", 8 * c14 + 9);
                            if (c14 == 0) {
                              fprintf(f, "x q[%u];\n", 8);
                            }
                          }
                        }
                      }
                    }
                  }
                  fprintf(f, "x q[%u];\n", -7 * c8);
                  if (c8 == 0) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 17 * c14 + 1, 3 * c14 + 11);
                    }
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14 + 9);
                    }
                  }
                  if (c8 == 0) {
                    for (int c12 = 21; c12 <= 23; c12 += 1) {
                      if (c12 == 23) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c14 + 10);
                        }
                        fprintf(f, "x q[%u];\n", 0);
                      } else if (c12 == 22) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 9 * c14);
                        }
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c14 + 10);
                        }
                      } else {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", c14 + 9);
                        }
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 3 * c14 + 11);
                        }
                      }
                    }
                  }
                }
              }
            }
            if (c6 == 2) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 3 * c14 + 16);
              }
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 6 * c9 + 2, 6 * c9);
              }
            } else if (c6 == 1) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                for (int c10 = 0; c10 <= -c9 + 2; c10 += 1) {
                  fprintf(f, "x q[%u];\n", -10 * c9 + c10 + 11);
                }
              }
            } else if (c6 == 0) {
              for (int c9 = 0; c9 <= 1; c9 += 1) {
                fprintf(f, "cx q[%u], q[%u];\n", -c9 + 13, 8 * c9 + 3);
              }
            }
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 13 * c14 + 3);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 6 * c14 + 10);
          }
          for (int c12 = 31; c12 <= 32; c12 += 1) {
            for (int c14 = 0; c14 < c12 - 30; c14 += 1) {
              fprintf(f, "x q[%u];\n", -9 * c12 + 6 * c14 + 298);
            }
            if (c12 == 31) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                for (int c15 = 0; c15 <= c14; c15 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c14 + 6 * c15 + 8);
                }
              }
            }
          }
        }
      }
    }
    if (c1 == 0) {
      for (int c2 = 1; c2 <= 8; c2 += 1) {
        for (int c3 = max(0, -c2 + (c2 + 1) / 2 + 1); c3 <= min(1, -c2 + (c2 + 1) / 2 + 3); c3 += 1) {
          if ((c2 + 2 * c3 - 2) % 4 <= 1) {
            fprintf(f, "x q[%u];\n", 15);
          }
        }
        if (c2 == 7) {
          for (int c3 = 0; c3 <= 1; c3 += 1) {
            for (int c10 = 1; c10 <= 2; c10 += 1) {
              fprintf(f, "x q[%u];\n", 15);
            }
          }
          fprintf(f, "x q[%u];\n", 15);
        }
      }
    }
  }
  for (int c1 = 0; c1 <= 3; c1 += 1) {
    fprintf(f, "x q[%u];\n", 0);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 0);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 14);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 8);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 14 * c1 + 2);
  }
}
fclose(f);
return 0;
}