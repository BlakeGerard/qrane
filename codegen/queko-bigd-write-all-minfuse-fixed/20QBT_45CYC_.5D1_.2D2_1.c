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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.5D1_.2D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 3; c1 += 1) {
    if (c1 >= 2) {
      if (c1 == 2) {
        for (int c11 = 0; c11 <= 1; c11 += 1) {
          fprintf(f, "x q[%u];\n", 2 * c11 + 17);
        }
        for (int c4 = -1; c4 <= 0; c4 += 1) {
          fprintf(f, "x q[%u];\n", 19);
        }
      }
      for (int c11 = c1 - 2; c11 <= 1; c11 += 1) {
        fprintf(f, "x q[%u];\n", 8 * c1 - 8 * c11 + 1);
      }
      if (c1 == 3) {
        fprintf(f, "x q[%u];\n", 17);
      } else {
        fprintf(f, "cx q[%u], q[%u];\n", 9, 0);
        for (int c11 = 0; c11 <= 1; c11 += 1) {
          fprintf(f, "cx q[%u], q[%u];\n", -7 * c11 + 12, c11 + 8);
        }
        for (int c4 = 1; c4 <= 2; c4 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c4 - 2);
          fprintf(f, "x q[%u];\n", -c4 + 10);
        }
      }
    } else {
      for (int c3 = -c1; c3 <= -c1 + 1; c3 += 1) {
        if (c1 == 0 && c3 == 1) {
          for (int c5 = 0; c5 <= 1; c5 += 1) {
            fprintf(f, "x q[%u];\n", 9);
          }
        }
        for (int c4 = max(-2 * c1 + 2 * c3, -c1 - 2 * c3); c4 <= min(2, -2 * c1 + c3 + 4); c4 += 1) {
          if (c1 == 1 && c4 >= 0 && c4 <= 1) {
            for (int c5 = 1; c5 <= -c4 + 2; c5 += 1) {
              if (c4 == 1 && c5 == 1) {
                fprintf(f, "x q[%u];\n", -6 * c3 + 9);
                if (c3 == 0) {
                  fprintf(f, "x q[%u];\n", 9);
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 7 * c11 + 7);
                  }
                }
              } else {
                if (c5 == 2) {
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", -9 * c9 + 13);
                  }
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", 4, 14);
                  fprintf(f, "cx q[%u], q[%u];\n", 4, 14);
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c11 + 8, -5 * c11 + 19);
                  }
                }
                for (int c6 = 0; c6 <= -c5 + 2; c6 += 1) {
                  if (c5 == 1) {
                    fprintf(f, "x q[%u];\n", 17 * c6);
                    if (c6 == 0) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c11 + 8);
                      }
                    }
                  }
                  if (c6 == 0) {
                    if (c5 == 2) {
                      for (int c9 = -1; c9 <= 9; c9 += 1) {
                        if (c9 == 9) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 6 * c11 + 5);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c11 + 4);
                          }
                        } else if (c9 == 8) {
                          fprintf(f, "cx q[%u], q[%u];\n", 8, 15);
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c11 + 4);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 6 * c11 + 5);
                          }
                        } else {
                          if (c9 == 7) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c9 == 6) {
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 3 * c11 + 8, 5 * c11);
                            }
                          } else if (c9 == 5) {
                            fprintf(f, "cx q[%u], q[%u];\n", 11, 6);
                          } else if (c9 == 4) {
                            fprintf(f, "x q[%u];\n", 1);
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c11 + 11);
                            }
                          } else if (c9 == 3) {
                            fprintf(f, "x q[%u];\n", 1);
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c11 + 11);
                            }
                          } else if (c9 == 2) {
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                            }
                          } else if (c9 == 1) {
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                            }
                          } else if (c9 == -1) {
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                            }
                          }
                          if (c9 % 7 == 0) {
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", (-c9 / 7) + 5 * c11 + 1);
                            }
                          }
                        }
                      }
                    }
                    for (int c9 = 10; c9 <= c5 + 9; c9 += 1) {
                      if (c5 == 2 && c9 == 11) {
                        for (int c11 = 0; c11 <= 1; c11 += 1) {
                          fprintf(f, "x q[%u];\n", 10 * c11 + 4);
                        }
                        for (int c11 = 0; c11 <= 1; c11 += 1) {
                          fprintf(f, "x q[%u];\n", 11 * c11);
                        }
                      } else {
                        if (c5 == 2) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -11 * c11 + 11, 9 * c11 + 6);
                          }
                        }
                        fprintf(f, "x q[%u];\n", -13 * c5 + 31);
                        if (c5 == 2) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c11 + 4);
                          }
                        } else {
                          fprintf(f, "x q[%u];\n", 19);
                        }
                      }
                    }
                    if (c5 == 2) {
                      for (int c9 = 12; c9 <= 13; c9 += 1) {
                        if (c9 == 13) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c11 + 6);
                          }
                        } else {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", 3 * c11 + 11, c11 + 6);
                          }
                        }
                      }
                    }
                  }
                }
                if (c5 == 2) {
                  fprintf(f, "x q[%u];\n", 13);
                }
              }
            }
            if (c3 == 0 && c4 == 1) {
              fprintf(f, "x q[%u];\n", 13);
              fprintf(f, "x q[%u];\n", 19);
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c11 + 17);
              }
              fprintf(f, "x q[%u];\n", 13);
              fprintf(f, "cx q[%u], q[%u];\n", 13, 16);
            }
          } else if (c1 == 0 && c4 == 2) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              for (int c6 = 0; c6 <= min(-c3 + 1, c5); c6 += 1) {
                for (int c7 = max(max(c3, -c5 + 1), c6); c7 <= min(-c3 + 2, c5 + c6 + 1); c7 += 1) {
                  if (c7 >= 1) {
                    if (c3 == 0 && c5 == 1 && c6 == 0 && c7 == 1) {
                      fprintf(f, "x q[%u];\n", 15);
                    }
                    for (int c9 = max(max(c3 + 8, c6 + 8), c7 + 7); c9 <= 9; c9 += 1) {
                      if (c3 == 0 && c5 == 1 && c6 == 0 && c7 == 1 && c9 == 9) {
                        fprintf(f, "cx q[%u], q[%u];\n", 19, 15);
                        fprintf(f, "x q[%u];\n", 0);
                      }
                      if (c9 == 9) {
                        if (c6 == 0 && c7 == 1) {
                          for (int c11 = c5 - 1; c11 <= -c3 + c5; c11 += 1) {
                            if (c3 == 0 && c5 == 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -4 * c11 + 17, 14 * c11 + 2);
                              fprintf(f, "x q[%u];\n", 15 * c11 + 2);
                            }
                            fprintf(f, "x q[%u];\n", 7 * c3 - 14 * c5 + 14 * c11 + 16);
                            if (c3 == 0 && c5 == 0 && c11 == 0) {
                              fprintf(f, "x q[%u];\n", 16);
                            }
                            if (c3 == 0 && c11 == 0) {
                              fprintf(f, "x q[%u];\n", 16);
                              if (c5 == 1) {
                                fprintf(f, "x q[%u];\n", 16);
                              }
                            }
                          }
                          if (c3 == 0 && c5 == 0) {
                            fprintf(f, "x q[%u];\n", 17);
                          }
                        } else if (c7 == 2) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 15 * c11 + 2);
                            if (c6 == 0 && c11 == 0) {
                              fprintf(f, "x q[%u];\n", 16);
                            }
                          }
                        } else {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 15 * c11 + 2);
                          }
                        }
                      } else {
                        fprintf(f, "x q[%u];\n", -15 * c5 + 17);
                      }
                    }
                    if (c3 == 0 && c5 == 1 && c7 == c6 + 1) {
                      for (int c9 = 10; c9 <= -c6 + 11; c9 += 1) {
                        if (c6 == 0 && c9 == 11) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c11);
                          }
                          fprintf(f, "x q[%u];\n", 19);
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c11 + 2);
                          }
                          fprintf(f, "cx q[%u], q[%u];\n", 4, 17);
                        } else if (c6 == 1) {
                          fprintf(f, "x q[%u];\n", 17);
                        } else {
                          fprintf(f, "cx q[%u], q[%u];\n", 4, 17);
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c11 + 2);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -16 * c11 + 19, 8 * c11);
                          }
                        }
                      }
                      if (c6 == 0) {
                        for (int c9 = 12; c9 <= 13; c9 += 1) {
                          if (c9 == 13) {
                            fprintf(f, "x q[%u];\n", 4);
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 14 * c11 + 2);
                            }
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              for (int c12 = 0; c12 <= -c11 + 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 4 * c11 + 2 * c12 + 11);
                              }
                            }
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c11 + 3);
                            }
                            fprintf(f, "x q[%u];\n", 17);
                          } else {
                            fprintf(f, "x q[%u];\n", 15);
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 14 * c11 + 2);
                            }
                            fprintf(f, "cx q[%u], q[%u];\n", 13, 11);
                            fprintf(f, "x q[%u];\n", 17);
                            fprintf(f, "x q[%u];\n", 4);
                            fprintf(f, "cx q[%u], q[%u];\n", 7, 3);
                          }
                        }
                      }
                    }
                    if (c3 == 0 && c5 == 1 && c6 == 0 && c7 == 1) {
                      fprintf(f, "x q[%u];\n", 4);
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", c11 + 17);
                      }
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c11 + 3);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 7, 12);
                      fprintf(f, "cx q[%u], q[%u];\n", 17, 2);
                    }
                  }
                  if (c3 == 0 && c6 == 0 && c7 <= 1) {
                    for (int c11 = 0; c11 < c5 + c7; c11 += 1) {
                      fprintf(f, "x q[%u];\n", -12 * c5 - 12 * c7 + 5 * c11 + 31);
                    }
                    if (c5 == 1 && c7 == 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 2, 19);
                      fprintf(f, "cx q[%u], q[%u];\n", 17, 2);
                    } else if (c5 == 1 && c7 == 0) {
                      fprintf(f, "x q[%u];\n", 3);
                      fprintf(f, "x q[%u];\n", 3);
                      fprintf(f, "x q[%u];\n", 3);
                      fprintf(f, "x q[%u];\n", 3);
                      for (int c9 = 0; c9 <= 1; c9 += 1) {
                        fprintf(f, "x q[%u];\n", -15 * c9 + 19);
                      }
                      fprintf(f, "x q[%u];\n", 3);
                    }
                  }
                }
              }
            }
            if (c3 == 1) {
              fprintf(f, "x q[%u];\n", 9);
            } else {
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                for (int c12 = 0; c12 <= -c11 + 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c11 + 2 * c12 + 11);
                }
              }
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                fprintf(f, "x q[%u];\n", 2 * c11 + 11);
              }
              for (int c7 = 0; c7 <= 1; c7 += 1) {
                if (c7 == 1) {
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c11);
                  }
                }
                if (c7 == 0) {
                  fprintf(f, "x q[%u];\n", 15);
                  for (int c9 = 16; c9 <= 17; c9 += 1) {
                    if (c9 == 17) {
                      fprintf(f, "x q[%u];\n", 12);
                    } else {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c11 + 7);
                      }
                    }
                  }
                } else {
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c11);
                  }
                }
                for (int c9 = -16 * c7 + 20; c9 <= -18 * c7 + 23; c9 += 1) {
                  if (c7 == 1 && c9 == 5) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c11 + 7);
                    }
                  } else {
                    if (c7 == 1 && c9 == 4) {
                      fprintf(f, "x q[%u];\n", 0);
                    }
                    if (19 * c7 + c9 == 23) {
                      fprintf(f, "x q[%u];\n", 12);
                    } else if (c9 == 22) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -4 * c11 + 16, -5 * c11 + 7);
                      }
                    } else if (c9 == 21) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -5 * c11 + 10, 6 * c11 + 12);
                      }
                    } else {
                      fprintf(f, "x q[%u];\n", 10);
                    }
                  }
                }
                if (c7 == 1) {
                  for (int c9 = 6; c9 <= 8; c9 += 1) {
                    if (c9 == 8) {
                      fprintf(f, "cx q[%u], q[%u];\n", 12, 2);
                    } else if (c9 == 7) {
                      fprintf(f, "x q[%u];\n", 2);
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 9 * c11 + 7);
                      }
                    } else {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 9 * c11 + 7);
                      }
                    }
                  }
                  for (int c9 = 9; c9 <= 10; c9 += 1) {
                    if (c9 == 10) {
                      fprintf(f, "x q[%u];\n", 15);
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c11 + 2);
                      }
                    } else {
                      fprintf(f, "x q[%u];\n", 15);
                    }
                  }
                  for (int c9 = 11; c9 <= 13; c9 += 1) {
                    if (c9 == 13) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c11 + 2);
                      }
                    } else if (c9 == 12) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10, 2);
                      fprintf(f, "cx q[%u], q[%u];\n", 8, 19);
                    } else {
                      fprintf(f, "x q[%u];\n", 2);
                    }
                  }
                }
                if (c7 == 0) {
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c9 + 5);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c9 + 5);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c9 + 5);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    for (int c10 = 0; c10 <= 1; c10 += 1) {
                      fprintf(f, "x q[%u];\n", -2 * c9 + 13 * c10 + 5);
                      if (c9 == 0) {
                        fprintf(f, "cx q[%u], q[%u];\n", 11 * c10 + 5, 4 * c10 + 3);
                      }
                    }
                  }
                  for (int c9 = 0; c9 <= 2; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c9 + 3);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c9 + 3);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c9 + 3);
                  }
                  for (int c9 = 0; c9 <= 1; c9 += 1) {
                    fprintf(f, "x q[%u];\n", -9 * c9 + 11);
                  }
                }
              }
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                fprintf(f, "x q[%u];\n", 8 * c11 + 2);
              }
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c11 + 8);
              }
            }
          } else if (2 * c1 + c4 == 1) {
            for (int c5 = 1; c5 <= 2; c5 += 1) {
              if (c1 == 0 && c5 == 2) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 10 * c11 + 1);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c11 + 10);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c11 + 10);
                }
              }
              if (c1 == 0) {
                for (int c7 = 0; c7 <= -c5 + 2; c7 += 1) {
                  if (c5 == 1 && c7 == 1) {
                    fprintf(f, "x q[%u];\n", 18);
                    for (int c9 = 2; c9 <= 4; c9 += 1) {
                      if (c9 == 4) {
                        for (int c11 = 0; c11 <= 1; c11 += 1) {
                          fprintf(f, "x q[%u];\n", 9 * c11 + 9);
                        }
                      } else if (c9 == 3) {
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 9);
                      } else {
                        fprintf(f, "x q[%u];\n", 18);
                      }
                    }
                  }
                  if (c5 == 1) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c11);
                    }
                    if (c7 == 1) {
                      fprintf(f, "x q[%u];\n", 13);
                    }
                  }
                  if (c7 == 0) {
                    if (c5 == 1) {
                      fprintf(f, "x q[%u];\n", 15);
                    }
                    fprintf(f, "x q[%u];\n", -5 * c5 + 20);
                  }
                  if (c5 + c7 == 2) {
                    for (int c9 = 10; c9 <= -c5 + 12; c9 += 1) {
                      if (c5 == 1 && c9 == 11) {
                        for (int c11 = 0; c11 <= 1; c11 += 1) {
                          fprintf(f, "x q[%u];\n", 4 * c11 + 15);
                        }
                        fprintf(f, "x q[%u];\n", 8);
                        fprintf(f, "x q[%u];\n", 5);
                        for (int c11 = 0; c11 <= 1; c11 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", 7 * c11 + 6, 10 * c11 + 1);
                        }
                      } else if (c5 == 1) {
                        fprintf(f, "x q[%u];\n", 13);
                        fprintf(f, "cx q[%u], q[%u];\n", 19, 15);
                        fprintf(f, "cx q[%u], q[%u];\n", 14, 5);
                      } else {
                        fprintf(f, "x q[%u];\n", 10);
                      }
                    }
                    if (c5 == 1) {
                      for (int c9 = 12; c9 <= 17; c9 += 1) {
                        if (c9 == 17) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 7 * c11 + 7);
                          }
                        } else if (c9 == 16) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c11 + 3);
                          }
                        }
                        if (c9 >= 16) {
                          fprintf(f, "cx q[%u], q[%u];\n", -9 * c9 + 158, 2 * c9 - 25);
                        } else if (c9 == 15) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c11 + 5);
                          }
                        } else if (c9 == 14) {
                          fprintf(f, "cx q[%u], q[%u];\n", 0, 15);
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c11 + 5);
                          }
                        } else if (c9 == 13) {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c11 + 3);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c11);
                          }
                          fprintf(f, "x q[%u];\n", 19);
                        } else {
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c11 + 3);
                          }
                          for (int c11 = 0; c11 <= 1; c11 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c11 + 15);
                          }
                        }
                      }
                    }
                    if (c5 == 1) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 6 * c11 + 8, 7 * c11);
                      }
                    }
                    for (int c11 = 0; c11 <= 2; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                    }
                    if (c5 == 1) {
                      for (int c11 = 0; c11 <= 2; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c11);
                      }
                    }
                    if (c5 == 1) {
                      for (int c11 = 0; c11 <= 2; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c11);
                      }
                    }
                  } else {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", c11 + 18);
                    }
                    fprintf(f, "x q[%u];\n", 18);
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", c11 + 7);
                    }
                  }
                }
                if (c5 == 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 14, 5);
                }
              }
              if (c1 == 0 && c5 == 2) {
                for (int c11 = 0; c11 <= 2; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c11 + 1);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c11 + 1);
                }
              }
              for (int c11 = 0; c11 <= 1; c11 += 1) {
                for (int c12 = 0; c12 <= -c11 + 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 13 * c11 + 5 * c12 + 1);
                }
              }
              if (c1 == 1 && c5 == 1) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                }
              }
            }
          } else if (c1 == 1 && c4 == 2) {
            fprintf(f, "x q[%u];\n", 15);
            for (int c7 = 0; c7 <= 1; c7 += 1) {
              if (c7 == 1) {
                fprintf(f, "x q[%u];\n", 1);
              }
              fprintf(f, "x q[%u];\n", 15);
            }
            for (int c9 = 5; c9 <= 10; c9 += 1) {
              if (c9 == 9) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c11 + 1);
                }
              } else if (c9 == 8) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c11 + 1);
                }
              } else if (c9 == 7) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -11 * c11 + 12, 10 * c11 + 8);
                }
              } else if (c9 == 6) {
                fprintf(f, "x q[%u];\n", 1);
              } else {
                fprintf(f, "x q[%u];\n", (3 * c9 / 5) + 12);
              }
            }
          } else {
            for (int c5 = 0; c5 <= 2; c5 += 1) {
              if (c5 == 2) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 17 * c11 + 2);
                }
              } else if (c5 == 1) {
                for (int c9 = 0; c9 <= 2; c9 += 1) {
                  fprintf(f, "x q[%u];\n", 2 * c9 + 11);
                }
              }
              if (c5 == 2) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c11 + 2);
                }
                for (int c9 = 11; c9 <= 12; c9 += 1) {
                  fprintf(f, "x q[%u];\n", -6 * c9 + 85);
                  if (c9 == 11) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c11 + 11);
                    }
                  }
                }
                fprintf(f, "x q[%u];\n", 13);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c11 + 5);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 11, 5);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c11 + 5);
                }
              }
              if (c5 == 2) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c11 + 5);
                }
              }
              if (c5 >= 1) {
                for (int c9 = 3; c9 <= 4; c9 += 1) {
                  if (c5 == 2 && c9 == 4) {
                    fprintf(f, "x q[%u];\n", 0);
                  }
                  if (c9 == 4) {
                    fprintf(f, "x q[%u];\n", 9 * c5 - 8);
                  } else if (c5 == 2) {
                    fprintf(f, "cx q[%u], q[%u];\n", 17, 10);
                  } else {
                    for (int c11 = 0; c11 <= 2; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c11 + 1);
                    }
                  }
                }
              } else {
                for (int c11 = 0; c11 <= 2; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c11 + 2);
                }
              }
              for (int c9 = 5; c9 <= min(8, 5 * c5 + 5); c9 += 1) {
                if (c9 == 5) {
                  fprintf(f, "x q[%u];\n", -c5 + 2);
                } else if (c5 == 2 && c9 == 8) {
                  fprintf(f, "x q[%u];\n", 18);
                  fprintf(f, "x q[%u];\n", 10);
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -12 * c11 + 12, 13 * c11 + 2);
                  }
                } else if (c5 == 1 && c9 == 8) {
                  fprintf(f, "cx q[%u], q[%u];\n", 12, 8);
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", c11 + 3);
                  }
                } else if (c5 == 2 && c9 == 7) {
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 17 * c11);
                  }
                  fprintf(f, "x q[%u];\n", 12);
                } else if (c5 == 1 && c9 == 7) {
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -8 * c11 + 12, 11 * c11 + 3);
                  }
                } else if (c5 == 2) {
                  fprintf(f, "x q[%u];\n", 12);
                  fprintf(f, "cx q[%u], q[%u];\n", 9, 0);
                } else {
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 13 * c11 + 1);
                  }
                }
              }
              if (c5 == 2) {
                fprintf(f, "x q[%u];\n", 10);
                fprintf(f, "x q[%u];\n", 18);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c11);
                }
                fprintf(f, "x q[%u];\n", 3);
                fprintf(f, "x q[%u];\n", 18);
                fprintf(f, "x q[%u];\n", 10);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", -2 * c11 + 4);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c11);
                }
                for (int c9 = 11; c9 <= 12; c9 += 1) {
                  if (c9 == 12) {
                    fprintf(f, "cx q[%u], q[%u];\n", 16, 7);
                    fprintf(f, "x q[%u];\n", 10);
                    fprintf(f, "x q[%u];\n", 3);
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 13 * c11 + 2);
                    }
                    fprintf(f, "x q[%u];\n", 13);
                  } else {
                    fprintf(f, "x q[%u];\n", 10);
                    fprintf(f, "x q[%u];\n", 13);
                    fprintf(f, "cx q[%u], q[%u];\n", 7, 3);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 10 * c9 - 2 * c11 - 106);
                  }
                  if (c9 == 12) {
                    fprintf(f, "x q[%u];\n", 9);
                  } else {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", -2 * c11 + 14);
                    }
                  }
                }
                fprintf(f, "cx q[%u], q[%u];\n", 18, 9);
                fprintf(f, "x q[%u];\n", 10);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c11 + 7);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c11 + 12);
                }
                fprintf(f, "x q[%u];\n", 3);
                for (int c9 = 14; c9 <= 15; c9 += 1) {
                  if (c9 == 15) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", -7 * c11 + 19);
                    }
                    fprintf(f, "x q[%u];\n", 3);
                  } else {
                    fprintf(f, "cx q[%u], q[%u];\n", 10, 12);
                    fprintf(f, "x q[%u];\n", 15);
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c11 + 9);
                    }
                    fprintf(f, "x q[%u];\n", 3);
                  }
                }
              } else {
                for (int c11 = 0; c11 <= -c5 + 2; c11 += 1) {
                  fprintf(f, "x q[%u];\n", -13 * c5 + c11 + 16);
                }
                if (c5 == 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", 5, 9);
                }
                for (int c9 = -c5 + 11; c9 <= 12; c9 += 1) {
                  if (c5 == 1 && c9 == 12) {
                    fprintf(f, "cx q[%u], q[%u];\n", 18, 9);
                  }
                  if (c5 == 1) {
                    fprintf(f, "x q[%u];\n", -6 * c9 + 79);
                    if (c9 == 12) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c11 + 8);
                      }
                    }
                  }
                  if (c9 == 12) {
                    for (int c11 = c5; c11 <= c5 + 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", -14 * c5 + 14 * c11 + 2);
                    }
                    if (c5 == 1) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 11 * c11 + 6, 5 * c11 + 5);
                      }
                      fprintf(f, "x q[%u];\n", 0);
                    }
                  } else {
                    if (c5 == 1 && c9 == 11) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c11 + 5);
                      }
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c11);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 14, 6);
                      fprintf(f, "x q[%u];\n", 19);
                    }
                    if (c9 == 11) {
                      fprintf(f, "x q[%u];\n", -15 * c5 + 16);
                    }
                    if (c5 == 1 && c9 == 11) {
                      fprintf(f, "x q[%u];\n", 9);
                    } else if (c5 == 1 && c9 == 10) {
                      fprintf(f, "x q[%u];\n", 4);
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c11 + 1);
                      }
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -7 * c11 + 12, c11 + 8);
                      }
                      for (int c11 = 0; c11 <= 2; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c11 + 7);
                      }
                    }
                  }
                }
                if (c5 == 1) {
                  for (int c9 = 13; c9 <= 15; c9 += 1) {
                    if (c9 == 15) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c11 + 6);
                      }
                    } else if (c9 == 14) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c11 + 6);
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 16, 4);
                      fprintf(f, "x q[%u];\n", 10);
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 9 * c11 + 2);
                      }
                    } else {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 4 * c11 + 6);
                      }
                      for (int c11 = 0; c11 <= 2; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 3 * c11 + 13);
                      }
                      fprintf(f, "x q[%u];\n", 12);
                    }
                  }
                }
              }
              if (c5 >= 1) {
                for (int c9 = 16; c9 <= 17; c9 += 1) {
                  if (c5 == 2 && c9 == 17) {
                    fprintf(f, "cx q[%u], q[%u];\n", 8, 19);
                  }
                  if (c9 == 17) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 10 * c11 + 4);
                    }
                  } else if (c5 == 2) {
                    fprintf(f, "x q[%u];\n", 15);
                  }
                  if (c5 == 2) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", -4 * c9 + 10 * c11 + 68);
                    }
                    if (c9 == 16) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -9 * c11 + 19, 12 * c11);
                      }
                    }
                  } else {
                    if (c9 == 17) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "x q[%u];\n", 12 * c11 + 5);
                      }
                    }
                    if (c9 == 16) {
                      for (int c11 = 0; c11 <= 1; c11 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 12 * c11 + 5, c11 + 9);
                      }
                    }
                  }
                }
                if (c5 == 2) {
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c11 + 11);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c11 + 10);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -4 * c11 + 8, 14 * c11);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c11 + 10);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 8 * c11 + 11);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c11);
                  }
                  for (int c11 = 0; c11 <= 1; c11 += 1) {
                    fprintf(f, "x q[%u];\n", 4 * c11 + 4);
                  }
                }
              }
              if (c5 == 2) {
                fprintf(f, "x q[%u];\n", 19);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c11 + 7);
                }
                fprintf(f, "x q[%u];\n", 8);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c11 + 17, 5 * c11 + 2);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 7, 8);
                fprintf(f, "x q[%u];\n", 8);
              } else if (c5 == 1) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c11 + 5);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c11 + 5);
                }
              }
              if (c5 == 2) {
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c11 + 9);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c11 + 9);
                }
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c11 + 9);
                }
                fprintf(f, "x q[%u];\n", 18);
                fprintf(f, "cx q[%u], q[%u];\n", 5, 18);
                for (int c11 = 0; c11 <= 1; c11 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -c11 + 19, 9 * c11);
                }
                for (int c9 = 20; c9 <= 25; c9 += 1) {
                  if (c9 == 24) {
                    fprintf(f, "cx q[%u], q[%u];\n", 7, 8);
                  } else if (c9 == 23) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 7 * c11);
                    }
                  } else if (c9 == 22) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", -5 * c11 + 9, 7 * c11);
                    }
                  } else if (c9 == 21) {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c11);
                    }
                  } else {
                    for (int c11 = 0; c11 <= 1; c11 += 1) {
                      fprintf(f, "x q[%u];\n", (-11 * c9 / 5) + c11 + 62);
                    }
                    if (c9 == 20) {
                      fprintf(f, "cx q[%u], q[%u];\n", 9, 0);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (c1 == 0) {
      for (int c3 = 0; c3 <= 3; c3 += 1) {
        fprintf(f, "x q[%u];\n", 18);
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -3 * c1 + 3, 6 * c1 + 9);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", -2 * c1 + 10);
  }
  fprintf(f, "x q[%u];\n", 13);
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", -7 * c1 + 7);
  }
}
fclose(f);
return 0;
}