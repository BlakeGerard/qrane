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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.4D1_.4D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
{
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -4 * c1 + 7, 8 * c1 + 9);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -13 * c1 + 16, 5 * c1 + 12);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", -10 * c1 + 15, 2 * c1 + 14);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    for (int c2 = 0; c2 <= 2; c2 += 1) {
      if ((c2 % 2) + c1 <= 1) {
        if (c1 == 0) {
          if (c2 == 0) {
            for (int c6 = 0; c6 <= 4; c6 += 1) {
              if (c6 == 3) {
                fprintf(f, "x q[%u];\n", 12);
              }
              if (c6 <= 3) {
                if (c6 == 3) {
                  for (int c10 = 8; c10 <= 10; c10 += 1) {
                    if (c10 == 10) {
                      fprintf(f, "cx q[%u], q[%u];\n", 1, 2);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "cx q[%u], q[%u];\n", 9, 4);
                    } else if (c10 == 9) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c12 + 3);
                      }
                    } else {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c12 + 9);
                      }
                    }
                  }
                  for (int c10 = 11; c10 <= 12; c10 += 1) {
                    if (c10 == 12) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 11 * c12 + 2, 3 * c12 + 3);
                      }
                      fprintf(f, "x q[%u];\n", 12);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 14 * c12 + 1);
                      }
                    } else {
                      fprintf(f, "cx q[%u], q[%u];\n", 4, 15);
                      fprintf(f, "cx q[%u], q[%u];\n", 3, 17);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", c12 + 1);
                      }
                    }
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 10 * c12 + 3);
                  }
                }
                for (int c10 = max(13, 7 * c6 - 1); c10 <= min(20, 3 * c6 + c6 / 2 + 13); c10 += 1) {
                  if ((c10 + 1) % 7 == 0) {
                    fprintf(f, "x q[%u];\n", ((10 * c10 - 102) / 7) - 2 * c6);
                    if (c6 == 0 && c10 == 13) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -12 * c12 + 15, 3 * c12 + 14);
                      }
                    }
                  } else if (c6 == 2 && c10 >= 15 && c10 <= 17) {
                    {
                      int c12 = c10 <= 16 ? 0 : 1;
                      fprintf(f, "x q[%u];\n", -17 * c10 + 34 * c12 + 273);
                    }
                    if (c10 == 17) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 5 * c12 + 6, 2 * c12 + 8);
                      }
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 12 * c12 + 1);
                      }
                    } else if (c10 == 16) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c12 + 11);
                      }
                    } else {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 11 * c12);
                      }
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", 12 * c12 + 1);
                      }
                    }
                  } else {
                    if (c6 == 2 && c10 == 18) {
                      fprintf(f, "cx q[%u], q[%u];\n", 5, 13);
                    }
                    if (c6 == 2 && c10 == 14) {
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", c12);
                      }
                    }
                  }
                }
                if (c6 == 0) {
                  fprintf(f, "cx q[%u], q[%u];\n", 4, 15);
                }
                if (c6 == 3) {
                  for (int c8 = 0; c8 <= 1; c8 += 1) {
                    fprintf(f, "x q[%u];\n", -12 * c8 + 16);
                  }
                  for (int c8 = 0; c8 <= 1; c8 += 1) {
                    fprintf(f, "x q[%u];\n", -c8 + 4);
                  }
                } else if (c6 == 2) {
                  for (int c8 = 0; c8 <= 1; c8 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 3 * c8 + 2, 16 * c8);
                  }
                } else if (c6 == 1) {
                  for (int c8 = 0; c8 <= 1; c8 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 17 * c8 + 2, 2 * c8 + 7);
                  }
                }
              } else {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c12 + 9);
                }
              }
              if (c6 % 4 == 0) {
                fprintf(f, "x q[%u];\n", (5 * c6 / 4) + 4);
                if (c6 == 0) {
                  fprintf(f, "x q[%u];\n", 16);
                }
              }
            }
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -3 * c12 + 12, c12 + 14);
            }
            for (int c6 = 4; c6 <= 5; c6 += 1) {
              for (int c12 = 0; c12 <= 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", 6 * c12 + 9);
              }
            }
            for (int c10 = 7; c10 <= 8; c10 += 1) {
              if (c10 == 8) {
                fprintf(f, "x q[%u];\n", 6);
              }
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c10 + 68, 9 * c10 - 57);
            }
          }
          if (c2 % 2 == 0) {
            for (int c4 = 1; c4 <= 3; c4 += 1) {
              if (c2 == 0 && c4 == 2) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 13 * c12 + 5);
                }
                fprintf(f, "x q[%u];\n", 18);
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 5 * c12 + 13);
                }
              } else if ((c4 + 1) % 2 == 0) {
                if (c2 == 0 && c4 == 3) {
                  fprintf(f, "x q[%u];\n", 19);
                  for (int c8 = 0; c8 <= 1; c8 += 1) {
                    if (c8 == 1) {
                      fprintf(f, "x q[%u];\n", 19);
                    }
                    if (c8 == 1) {
                      for (int c10 = 9; c10 <= 10; c10 += 1) {
                        if (c10 == 10) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c12 + 14);
                          }
                          fprintf(f, "x q[%u];\n", 19);
                          fprintf(f, "x q[%u];\n", 10);
                        } else {
                          fprintf(f, "cx q[%u], q[%u];\n", 19, 7);
                        }
                      }
                    }
                    fprintf(f, "x q[%u];\n", 3);
                    if (c8 == 1) {
                      fprintf(f, "x q[%u];\n", 19);
                      fprintf(f, "cx q[%u], q[%u];\n", 9, 16);
                      fprintf(f, "cx q[%u], q[%u];\n", 6, 14);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 9 * c12 + 2, 10 * c12);
                      }
                    }
                    if (c8 == 1) {
                      for (int c10 = 12; c10 <= 19; c10 += 1) {
                        if (c10 == 17) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c12 + 7);
                          }
                        } else if (c10 == 16) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c12 + 7);
                          }
                          fprintf(f, "x q[%u];\n", 3);
                        } else {
                          if (c10 == 15) {
                            fprintf(f, "cx q[%u], q[%u];\n", 4, 15);
                          }
                          if (c10 >= 14 && c10 <= 15) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c10 + 2 * c12 - 84);
                            }
                          } else if (c10 == 19) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c12 + 2);
                            }
                            fprintf(f, "x q[%u];\n", 10);
                          }
                          if (c10 == 15) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 3 * c12 + 7);
                            }
                          } else if (c10 == 14) {
                            fprintf(f, "cx q[%u], q[%u];\n", 19, 9);
                          } else if (c10 == 13) {
                            fprintf(f, "cx q[%u], q[%u];\n", 6, 14);
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -11 * c12 + 12, 11 * c12 + 8);
                            }
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 10 * c12);
                            }
                          }
                        }
                        if ((c10 + 1) % 3 == 0) {
                          fprintf(f, "cx q[%u], q[%u];\n", -c10 + 20, (-8 * c10 + 136) / 3);
                          if (c10 == 14) {
                            fprintf(f, "cx q[%u], q[%u];\n", 10, 4);
                          }
                        } else {
                          if (c10 % 6 == 0) {
                            fprintf(f, "cx q[%u], q[%u];\n", -2 * c10 + 38, (-c10 / 6) + 10);
                            if (c10 == 18) {
                              fprintf(f, "x q[%u];\n", 10);
                            } else if (c10 == 12) {
                              fprintf(f, "cx q[%u], q[%u];\n", 19, 11);
                            }
                          }
                          if (c10 <= 15 && c10 % 3 == 0) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 3 * c10 + 10 * c12 - 36);
                            }
                            if (c10 == 15) {
                              fprintf(f, "x q[%u];\n", 2);
                            } else if (c10 == 12) {
                              fprintf(f, "cx q[%u], q[%u];\n", 9, 15);
                            }
                          }
                        }
                      }
                    }
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 2, 3);
                  fprintf(f, "x q[%u];\n", 2);
                  fprintf(f, "x q[%u];\n", 7);
                  for (int c6 = 1; c6 <= 3; c6 += 1) {
                    if (c6 >= 2) {
                      for (int c8 = 0; c8 <= 1; c8 += 1) {
                        if (c6 == 2 && c8 == 1) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c12 + 1);
                          }
                        }
                        if (c6 == 3 && c8 == 1) {
                          fprintf(f, "x q[%u];\n", 13);
                          fprintf(f, "x q[%u];\n", 11);
                          fprintf(f, "x q[%u];\n", 19);
                          fprintf(f, "x q[%u];\n", 7);
                          fprintf(f, "cx q[%u], q[%u];\n", 7, 11);
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 7 * c12 + 7);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c12 + 3);
                          }
                          fprintf(f, "cx q[%u], q[%u];\n", 18, 13);
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 7 * c12 + 7);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            for (int c13 = c12 - 1; c13 <= c12; c13 += 1) {
                              fprintf(f, "x q[%u];\n", 13 * c12 - 11 * c13 + 1);
                            }
                            if (c12 == 0) {
                              fprintf(f, "cx q[%u], q[%u];\n", 12, 14);
                            }
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -c12 + 19, 2 * c12 + 11);
                          }
                        }
                        if (c6 == 3 && c8 == 1) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 6 * c12 + 13);
                          }
                          fprintf(f, "x q[%u];\n", 1);
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", c12 + 18);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c12 + 1);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -3 * c12 + 4, 4 * c12 + 15);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c12 + 14);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 3 * c12 + 1);
                          }
                          fprintf(f, "x q[%u];\n", 17);
                        }
                        for (int c12 = 0; c12 <= c8; c12 += 1) {
                          fprintf(f, "x q[%u];\n", -7 * c8 + 11 * c12 + 11);
                        }
                        if (c6 == 2 && c8 == 1) {
                          for (int c10 = 14; c10 <= 15; c10 += 1) {
                            if (c10 == 15) {
                              fprintf(f, "cx q[%u], q[%u];\n", 5, 13);
                            } else {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 5 * c12 + 13);
                              }
                            }
                          }
                          fprintf(f, "x q[%u];\n", 13);
                        } else if (c6 == 3 && c8 == 0) {
                          fprintf(f, "x q[%u];\n", 19);
                          fprintf(f, "x q[%u];\n", 11);
                          fprintf(f, "cx q[%u], q[%u];\n", 3, 17);
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c12 + 3);
                          }
                        }
                      }
                    } else {
                      fprintf(f, "x q[%u];\n", 7);
                    }
                  }
                } else {
                  if (c2 == 0 && c4 == 1) {
                    for (int c10 = 15; c10 <= 19; c10 += 1) {
                      if (c10 == 18) {
                        fprintf(f, "x q[%u];\n", 18);
                      } else if (c10 == 16) {
                        fprintf(f, "x q[%u];\n", 1);
                      } else if ((c10 + 1) % 4 == 0) {
                        fprintf(f, "cx q[%u], q[%u];\n", (17 * c10 - 251) / 4, (11 * c10 - 157) / 4);
                      }
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 5 * c12 + 9);
                    }
                    fprintf(f, "x q[%u];\n", 8);
                    for (int c8 = 0; c8 <= 1; c8 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10 * c8 + 7, 2 * c8 + 11);
                    }
                  } else if (c2 == 2 && c4 == 1) {
                    for (int c6 = 0; c6 <= 1; c6 += 1) {
                      if (c6 == 0) {
                        fprintf(f, "x q[%u];\n", 2);
                      }
                      fprintf(f, "x q[%u];\n", 2);
                      if (c6 == 1) {
                        fprintf(f, "x q[%u];\n", 2);
                      }
                    }
                  }
                  if (c4 == 1 && c2 % 2 == 0) {
                    for (int c6 = 2; c6 <= 3; c6 += 1) {
                      if (c2 == 2) {
                        fprintf(f, "x q[%u];\n", 5 * c6 - 8);
                        if (c6 == 3) {
                          fprintf(f, "cx q[%u], q[%u];\n", 9, 15);
                          fprintf(f, "cx q[%u], q[%u];\n", 7, 11);
                          fprintf(f, "cx q[%u], q[%u];\n", 7, 11);
                          fprintf(f, "cx q[%u], q[%u];\n", 7, 0);
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", 4 * c12 + 3, 11 * c12);
                          }
                          fprintf(f, "x q[%u];\n", 7);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", -7 * c6 + 32, 4 * c6 - 3);
                        if (c6 == 3) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c12 + 9);
                          }
                        }
                      }
                      if (c2 == 2 && c6 == 2) {
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 5);
                        for (int c10 = 8; c10 <= 10; c10 += 1) {
                          if (c10 == 10) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 5 * c12 + 2);
                            }
                            fprintf(f, "x q[%u];\n", 18);
                          } else if (c10 == 9) {
                            fprintf(f, "cx q[%u], q[%u];\n", 2, 7);
                          } else {
                            fprintf(f, "x q[%u];\n", 10);
                          }
                        }
                        for (int c10 = 11; c10 <= 12; c10 += 1) {
                          if (c10 == 12) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 6 * c12 + 3, 4 * c12);
                            }
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", c12 + 1);
                            }
                          } else {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -c12 + 2, 16 * c12 + 3);
                            }
                          }
                        }
                      } else {
                        if (c2 == 0 && c6 == 2) {
                          for (int c10 = 3; c10 <= 8; c10 += 5) {
                            fprintf(f, "cx q[%u], q[%u];\n", (4 * c10 + 23) / 5, 2 * c10 - 6);
                          }
                        }
                        if (c2 == 2 && c6 == 3) {
                          fprintf(f, "x q[%u];\n", 18);
                          fprintf(f, "cx q[%u], q[%u];\n", 3, 17);
                        }
                      }
                      if (c2 == 2 && c6 == 3) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", -11 * c12 + 14);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 0, 5);
                      }
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", (-9 * c2 / 2) + c12 + 10);
                      }
                      if (c2 == 2 && c6 == 2) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 6 * c12 + 3);
                        }
                      }
                      if (c2 == 2 && c6 == 3) {
                        for (int c10 = 4; c10 <= 6; c10 += 1) {
                          if (c10 == 6) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c12 + 7);
                            }
                            fprintf(f, "cx q[%u], q[%u];\n", 19, 9);
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 13 * c12 + 2);
                            }
                            fprintf(f, "x q[%u];\n", 11);
                            fprintf(f, "cx q[%u], q[%u];\n", 0, 12);
                          } else if (c10 == 5) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 13 * c12 + 2);
                            }
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -2 * c12 + 7, 13 * c12);
                            }
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c12 + 9);
                            }
                          } else {
                            fprintf(f, "x q[%u];\n", 7);
                            fprintf(f, "cx q[%u], q[%u];\n", 2, 3);
                            fprintf(f, "x q[%u];\n", 0);
                          }
                        }
                      }
                      if (c2 == 2) {
                        for (int c10 = -7 * c6 + 28; c10 <= -11 * c6 + 40; c10 += 1) {
                          if (c6 == 2 && c10 == 17) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 12 * c12 + 4);
                            }
                          } else if (c6 == 2 && c10 == 15) {
                            fprintf(f, "cx q[%u], q[%u];\n", 4, 15);
                          } else if (c6 == 2 && c10 == 14) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c12);
                            }
                            fprintf(f, "cx q[%u], q[%u];\n", 9, 16);
                          } else {
                            if (c6 == 3 && c10 == 7) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 13 * c12 + 2);
                              }
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", -13 * c12 + 13);
                              }
                            }
                            if (9 * c6 + c10 == 34) {
                              fprintf(f, "cx q[%u], q[%u];\n", 3 * c6 + 10, 7 * c6 - 10);
                              if (c6 == 3) {
                                fprintf(f, "cx q[%u], q[%u];\n", 17, 5);
                              }
                            }
                            if (11 * c6 + c10 == 40) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                for (int c13 = 0; c13 <= c12; c13 += 1) {
                                  fprintf(f, "x q[%u];\n", -6 * c12 + 12 * c13 + 10);
                                }
                              }
                              if (c6 == 3) {
                                fprintf(f, "cx q[%u], q[%u];\n", 7, 9);
                              }
                            }
                          }
                        }
                        if (c6 == 3) {
                          for (int c10 = 8; c10 <= 13; c10 += 1) {
                            if (c10 == 11) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", 3 * c12, c12 + 16);
                              }
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 13 * c12 + 5);
                              }
                            } else if (c10 == 10) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 7 * c12 + 9);
                              }
                            }
                            if (c10 >= 10 && c10 <= 11) {
                              fprintf(f, "cx q[%u], q[%u];\n", -5 * c10 + 68, c10 - 5);
                              if (c10 == 10) {
                                fprintf(f, "x q[%u];\n", 15);
                              }
                            } else {
                              if (c10 == 9) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", -3 * c12 + 18);
                                }
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 5 * c12 + 11, 3 * c12 + 9);
                                }
                              } else if (c10 == 8) {
                                for (int c13 = 0; c13 <= 1; c13 += 1) {
                                  fprintf(f, "x q[%u];\n", 3 * c13 + 16);
                                }
                                fprintf(f, "cx q[%u], q[%u];\n", 4, 15);
                              }
                              if (c10 <= 9) {
                                fprintf(f, "cx q[%u], q[%u];\n", 6 * c10 - 41, 6 * c10 - 48);
                              }
                            }
                            if (c10 >= 9 && c10 <= 10) {
                              fprintf(f, "x q[%u];\n", 2 * c10 - 13);
                              if (c10 == 10) {
                                fprintf(f, "cx q[%u], q[%u];\n", 13, 6);
                                fprintf(f, "x q[%u];\n", 17);
                              } else {
                                fprintf(f, "x q[%u];\n", 4);
                              }
                            } else {
                              if (c10 == 13) {
                                fprintf(f, "cx q[%u], q[%u];\n", 0, 5);
                              }
                              if (c10 == 8) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", c12 + 2);
                                }
                              }
                            }
                            if (c10 <= 9) {
                              fprintf(f, "cx q[%u], q[%u];\n", 2 * c10 + 1, 2 * c10 - 11);
                              if (c10 == 9) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", 17 * c12);
                                }
                                fprintf(f, "x q[%u];\n", 3);
                              }
                            } else {
                              if (c10 == 12) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", 3 * c12);
                                }
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", 7 * c12 + 6);
                                }
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", -9 * c12 + 16, 5 * c12 + 4);
                                }
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", 13 * c12 + 5);
                                }
                              }
                              if ((c10 + 1) % 2 == 0) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "x q[%u];\n", -c10 + 2 * c12 + 20);
                                }
                              }
                            }
                          }
                        }
                      }
                      if (c2 == 2 && c6 == 2) {
                        fprintf(f, "x q[%u];\n", 7);
                      }
                      if (c2 == 2 && c6 == 3) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", -3 * c12 + 12);
                        }
                        fprintf(f, "x q[%u];\n", 5);
                        fprintf(f, "x q[%u];\n", 1);
                      } else {
                        if (c2 == 0 && c6 == 2) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 7 * c12);
                          }
                        }
                        if (c6 == 2) {
                          for (int c8 = 0; c8 <= c2 / 2; c8 += 1) {
                            fprintf(f, "x q[%u];\n", (-7 * c2 / 2) + 18 * c8 + 8);
                          }
                        }
                      }
                    }
                  }
                }
                if (c2 == 0 && (c4 + 1) % 2 == 0) {
                  if (c4 == 3) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 11 * c12 + 4);
                    }
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", c4 + 4 * c12 + 12);
                  }
                  if (c4 == 1) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 16 * c12 + 1);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 13 * c12 + 5, c12 + 12);
                    }
                    fprintf(f, "x q[%u];\n", 18);
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c12 + 5);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c12 + 5);
                    }
                  }
                  if (c4 == 3) {
                    for (int c8 = 1; c8 <= 2; c8 += 1) {
                      if (c8 == 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 0, 16);
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", c12, 3 * c12 + 16);
                        }
                        for (int c10 = 3; c10 <= 5; c10 += 1) {
                          if (c10 == 4) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -8 * c12 + 9, 3 * c12 + 16);
                            }
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 9 * c12 + 3, 6 * c12);
                            }
                          } else {
                            if (c10 == 5) {
                              fprintf(f, "x q[%u];\n", 9);
                            }
                            fprintf(f, "cx q[%u], q[%u];\n", (-c10 + 27) / 2, (c10 + 13) / 2);
                            if (c10 == 5) {
                              for (int c13 = 0; c13 <= 1; c13 += 1) {
                                fprintf(f, "x q[%u];\n", 3 * c13 + 8);
                              }
                            }
                            if (c10 == 5) {
                              fprintf(f, "x q[%u];\n", 11);
                            }
                            if (c10 == 3) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 16 * c12);
                              }
                            }
                          }
                        }
                      }
                      if (c8 == 1) {
                        for (int c10 = 5; c10 <= 6; c10 += 1) {
                          if (c10 == 6) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 3 * c12 + 3);
                            }
                            fprintf(f, "cx q[%u], q[%u];\n", 9, 4);
                          } else {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c12);
                            }
                            fprintf(f, "cx q[%u], q[%u];\n", 5, 16);
                          }
                        }
                      }
                      for (int c10 = 7; c10 <= -2 * c8 + 12; c10 += 1) {
                        if (c10 == 8) {
                          fprintf(f, "x q[%u];\n", -8 * c8 + 16);
                          if (c8 == 1) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -c12 + 6, 2 * c12 + 14);
                            }
                          }
                        } else if (c8 == 1 && c10 == 7) {
                          fprintf(f, "cx q[%u], q[%u];\n", 14, 8);
                        }
                        if (c8 == 1 && c10 <= 8) {
                          fprintf(f, "x q[%u];\n", 8 * c10 - 52);
                          fprintf(f, "cx q[%u], q[%u];\n", -8 * c10 + 68, 9 * c10 - 57);
                        } else {
                          if (c8 == 1 && c10 == 9) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -9 * c12 + 9, 8 * c12 + 4);
                            }
                          }
                          if (c8 == 1 && c10 >= 9) {
                            fprintf(f, "cx q[%u], q[%u];\n", 6 * c10 - 48, 6 * c10 - 46);
                            if (c10 == 10) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 2 * c12 + 6);
                              }
                            }
                          }
                          if (3 * c8 + c10 == 13) {
                            fprintf(f, "x q[%u];\n", 0);
                          }
                          if (c8 == 1 && c10 == 9) {
                            fprintf(f, "x q[%u];\n", 16);
                          }
                        }
                      }
                      if (c8 == 1) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 6 * c12 + 8);
                        }
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -2 * c12 + 17, 9 * c12 + 5);
                        }
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 4 * c12 + 8);
                        }
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 10 * c12 + 5);
                        }
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -5 * c12 + 18, c12 + 5);
                        }
                        for (int c10 = 14; c10 <= 17; c10 += 1) {
                          if (c10 == 17) {
                            fprintf(f, "cx q[%u], q[%u];\n", 14, 8);
                          } else if (c10 == 16) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", 11 * c12 + 6, 5 * c12 + 8);
                            }
                          } else if (c10 == 15) {
                            fprintf(f, "cx q[%u], q[%u];\n", 12, 14);
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", 12 * c12 + 6);
                            }
                          }
                          if ((c10 + 1) % 3 == 0) {
                            fprintf(f, "x q[%u];\n", (5 * c10 - 34) / 3);
                          }
                        }
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 6 * c12 + 8);
                        }
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          for (int c13 = 0; c13 <= c12; c13 += 1) {
                            fprintf(f, "x q[%u];\n", -2 * c12 + 6 * c13 + 10);
                          }
                        }
                      }
                      if (c8 == 1) {
                        for (int c9 = 1; c9 <= 3; c9 += 1) {
                          fprintf(f, "x q[%u];\n", 16);
                          if (c9 == 3) {
                            fprintf(f, "cx q[%u], q[%u];\n", 5, 16);
                          }
                        }
                      }
                    }
                  } else {
                    for (int c10 = 8; c10 <= 13; c10 += 1) {
                      if (c10 == 12) {
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 5);
                      } else if (c10 == 11) {
                        fprintf(f, "cx q[%u], q[%u];\n", 17, 5);
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 13);
                      } else if (c10 == 10) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c12 + 12);
                        }
                        fprintf(f, "cx q[%u], q[%u];\n", 18, 5);
                      } else if (c10 == 9) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "cx q[%u], q[%u];\n", -5 * c12 + 17, c12 + 5);
                        }
                      } else {
                        for (int c12 = 0; c12 < (c10 - 3) / 5; c12 += 1) {
                          fprintf(f, "x q[%u];\n", ((-c10 + 38) / 5) + 13 * c12);
                        }
                        if (c10 == 8) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -7 * c12 + 12, 2 * c12 + 14);
                          }
                        }
                      }
                    }
                  }
                  if (c4 == 3) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c12 + 8);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c12 + 8);
                    }
                    for (int c8 = 0; c8 <= 1; c8 += 1) {
                      fprintf(f, "x q[%u];\n", 8);
                    }
                    fprintf(f, "x q[%u];\n", 8);
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "cx q[%u], q[%u];\n", 2 * c12 + 12, 2 * c12 + 6);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c12 + 6);
                    }
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 6 * c12 + 6);
                    }
                  }
                } else if (c2 == 2 && c4 == 1) {
                  for (int c6 = 4; c6 <= 6; c6 += 1) {
                    if (c6 == 6) {
                      fprintf(f, "cx q[%u], q[%u];\n", 1, 2);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", c12 + 1);
                      }
                    } else if (c6 == 4) {
                      fprintf(f, "x q[%u];\n", 15);
                      fprintf(f, "x q[%u];\n", 1);
                      for (int c12 = 0; c12 <= 1; c12 += 1) {
                        fprintf(f, "x q[%u];\n", -3 * c12 + 12);
                      }
                      for (int c10 = -1; c10 <= 14; c10 += 1) {
                        if (c10 == 13) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -9 * c12 + 12, c12 + 6);
                          }
                        } else if (c10 == 12) {
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", c12 + 18, 2 * c12 + 5);
                          }
                          for (int c12 = 0; c12 <= 1; c12 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c12 + 6);
                          }
                        } else {
                          if (c10 >= 11 && (c10 + 1) % 3 == 0) {
                            for (int c12 = 0; c12 <= 1; c12 += 1) {
                              fprintf(f, "x q[%u];\n", -4 * c10 + 4 * c12 + 59);
                            }
                          } else {
                            if (c10 >= 1 && c10 <= 3 && (c10 + 1) % 2 == 0) {
                              fprintf(f, "cx q[%u], q[%u];\n", c10 + 15, (c10 + 23) / 2);
                              if (c10 == 1) {
                                fprintf(f, "x q[%u];\n", 4);
                              }
                            }
                            if (c10 <= 1 && (c10 + 1) % 2 == 0) {
                              fprintf(f, "cx q[%u], q[%u];\n", (15 * c10 + 23) / 2, -2 * c10 + 13);
                            }
                          }
                          if ((c10 + 1) % 12 == 0) {
                            fprintf(f, "x q[%u];\n", (-3 * c10 + 65) / 4);
                            if (c10 == 11) {
                              fprintf(f, "x q[%u];\n", 6);
                            }
                            if (c10 == -1) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "cx q[%u], q[%u];\n", -11 * c12 + 12, 11 * c12 + 8);
                              }
                            }
                          } else {
                            if (c10 == 10) {
                              fprintf(f, "x q[%u];\n", 8);
                            } else if (c10 == 3) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 16 * c12);
                              }
                            } else if (c10 == 0) {
                              for (int c12 = 0; c12 <= 1; c12 += 1) {
                                fprintf(f, "x q[%u];\n", 11 * c12 + 8);
                              }
                            }
                            if (c10 <= 2 && c10 % 2 == 0) {
                              fprintf(f, "cx q[%u], q[%u];\n", 13 * c10 / 2, -3 * c10 + 12);
                              if (c10 == 2) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", -3 * c12 + 3, 9 * c12 + 7);
                                }
                                fprintf(f, "x q[%u];\n", 12);
                              }
                              if (c10 == 0) {
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", -10 * c12 + 13, 11 * c12 + 6);
                                }
                                fprintf(f, "cx q[%u], q[%u];\n", 16, 4);
                              }
                            } else {
                              if (c10 == 1) {
                                fprintf(f, "x q[%u];\n", 13);
                                for (int c12 = 0; c12 <= 1; c12 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 3 * c12, 12 * c12 + 5);
                                }
                              }
                              if (c10 >= 4 && c10 <= 9 && (c10 + 1) % 5 == 0) {
                                fprintf(f, "x q[%u];\n", (4 * c10 + 59) / 5);
                              }
                            }
                          }
                        }
                      }
                      fprintf(f, "cx q[%u], q[%u];\n", 6, 8);
                    }
                  }
                }
                if (c2 == 2 && c4 == 3) {
                  fprintf(f, "x q[%u];\n", 15);
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", -3 * c12 + 18, c12 + 13);
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c12 + 18, 2 * c12 + 5);
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", c12 + 13);
                  }
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", c12 + 13, 2 * c12 + 6);
                  }
                  fprintf(f, "cx q[%u], q[%u];\n", 5, 13);
                }
                if (c2 == 2 && c4 == 1) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    for (int c13 = 0; c13 <= c12; c13 += 1) {
                      fprintf(f, "x q[%u];\n", -9 * c12 + c13 + 10);
                    }
                  }
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "x q[%u];\n", 3 * c6 + 16);
                  }
                  for (int c6 = 0; c6 <= 1; c6 += 1) {
                    fprintf(f, "x q[%u];\n", -16 * c6 + 19);
                  }
                }
              }
            }
          }
          if (c2 == 1) {
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", 6 * c12 + 6);
            }
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -9 * c12 + 14, 5 * c12 + 8);
            }
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -12 * c12 + 17, 3 * c12 + 13);
            }
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c12 + 13);
            }
            fprintf(f, "x q[%u];\n", 6);
            for (int c6 = 3; c6 <= 4; c6 += 1) {
              if (c6 == 4) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c12 + 13);
                }
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  for (int c13 = 0; c13 <= c12; c13 += 1) {
                    fprintf(f, "x q[%u];\n", -2 * c12 + 6 * c13 + 10);
                  }
                }
              }
              fprintf(f, "x q[%u];\n", 8 * c6 - 18);
            }
            fprintf(f, "x q[%u];\n", 10);
          }
        } else {
          if (c2 == 2) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              if (c4 == 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 11, 10);
                fprintf(f, "x q[%u];\n", 4);
                fprintf(f, "x q[%u];\n", 4);
                fprintf(f, "cx q[%u], q[%u];\n", 11, 9);
                for (int c10 = 9; c10 <= 10; c10 += 1) {
                  if (c10 == 10) {
                    fprintf(f, "cx q[%u], q[%u];\n", 9, 4);
                  }
                  fprintf(f, "x q[%u];\n", 2 * c10 - 9);
                }
              }
              fprintf(f, "x q[%u];\n", -4 * c4 + 15);
            }
          }
          if (c2 == 0) {
            for (int c12 = 0; c12 <= 1; c12 += 1) {
              for (int c13 = 0; c13 <= c12; c13 += 1) {
                fprintf(f, "x q[%u];\n", -9 * c12 + c13 + 10);
              }
            }
            for (int c6 = 0; c6 <= 1; c6 += 1) {
              for (int c8 = 1; c8 <= 2; c8 += 1) {
                fprintf(f, "x q[%u];\n", 10);
              }
              if (c6 == 0) {
                for (int c8 = 0; c8 <= 1; c8 += 1) {
                  fprintf(f, "x q[%u];\n", c8 + 1);
                }
              }
            }
            for (int c6 = 4; c6 <= 5; c6 += 1) {
              fprintf(f, "x q[%u];\n", 10);
            }
            for (int c4 = 1; c4 <= 3; c4 += 1) {
              if (c4 == 3) {
                for (int c6 = 4; c6 <= 5; c6 += 1) {
                  fprintf(f, "x q[%u];\n", 9);
                }
                fprintf(f, "cx q[%u], q[%u];\n", 16, 12);
              } else if (c4 == 1) {
                fprintf(f, "x q[%u];\n", 10);
              }
            }
          }
        }
        if (c1 == 0 && c2 == 0) {
          for (int c4 = 0; c4 <= 1; c4 += 1) {
            fprintf(f, "x q[%u];\n", -8 * c4 + 11);
          }
        }
      }
    }
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "x q[%u];\n", 17);
  }
  for (int c1 = 0; c1 <= 1; c1 += 1) {
    fprintf(f, "cx q[%u], q[%u];\n", 14 * c1 + 2, 5 * c1 + 7);
  }
  fprintf(f, "x q[%u];\n", 18);
}
fclose(f);
return 0;
}