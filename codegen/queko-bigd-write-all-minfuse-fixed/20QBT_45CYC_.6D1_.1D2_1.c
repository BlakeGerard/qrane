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
FILE *f = fopen("codegen/queko-bigd-write-all-minfuse-fixed/20QBT_45CYC_.6D1_.1D2_1.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 3; c0 += 1) {
  if (c0 <= 2) {
    for (int c1 = 0; c1 <= min(c0, -c0 + (c0 + 1) / 2 + 1); c1 += 1) {
      if (c0 == 0 && c1 == 0) {
        for (int c2 = 0; c2 <= 1; c2 += 1) {
          if (c2 == 1) {
            for (int c5 = 1; c5 <= 2; c5 += 1) {
              if (c5 == 2) {
                for (int c10 = 0; c10 <= 2; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 8 * c10);
                }
                for (int c10 = 0; c10 <= 2; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 9 * c10);
                }
                for (int c10 = 0; c10 <= 2; c10 += 1) {
                  fprintf(f, "x q[%u];\n", c10);
                }
              }
              for (int c10 = 0; c10 <= 2; c10 += 1) {
                fprintf(f, "x q[%u];\n", c5 + 5 * c10 - 1);
              }
            }
          } else {
            for (int c8 = 24; c8 <= 27; c8 += 1) {
              fprintf(f, "x q[%u];\n", -3 * c8 + 87);
            }
          }
        }
      }
      for (int c2 = 2; c2 <= 4; c2 += 1) {
        if (2 * c0 + c2 <= 6 && (c2 % 2) + c1 <= 1) {
          if (c0 == 0 && c1 == 0 && c2 == 4) {
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 6 * c10 + 13);
            }
          }
          for (int c4 = 0; c4 <= min(min(-c0 + 1, c2 - 2), -c2 + 4); c4 += 1) {
            if (c1 == 0) {
              if (c0 == 0 && c2 == 4 && c4 == 0) {
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 12 * c10 + 6);
                }
              } else if (c0 == 0 && c2 == 3 && c4 == 0) {
                fprintf(f, "x q[%u];\n", 4);
              }
              for (int c5 = max(c0 + c2 + c4 - 3, -c0 + c4 + 1); c5 <= min(c0 + 2, -c2 + 5); c5 += 1) {
                if (c0 == 1 && c2 == 2 && c4 == 0 && c5 == 1) {
                  fprintf(f, "x q[%u];\n", 3);
                  fprintf(f, "x q[%u];\n", 3);
                }
                if (c0 == 1 && c2 == 2 && c4 == 0 && c5 <= 1) {
                  if (c5 == 1) {
                    for (int c10 = 0; c10 <= 1; c10 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c10 + 11);
                    }
                    for (int c8 = 25; c8 <= 28; c8 += 1) {
                      if (c8 == 28) {
                        fprintf(f, "x q[%u];\n", 15);
                      } else if (c8 == 27) {
                        fprintf(f, "x q[%u];\n", 3);
                      } else if (c8 == 26) {
                        fprintf(f, "x q[%u];\n", 15);
                        fprintf(f, "x q[%u];\n", 3);
                      } else {
                        fprintf(f, "x q[%u];\n", 15);
                      }
                    }
                  }
                  for (int c10 = 0; c10 <= c5; c10 += 1) {
                    fprintf(f, "cx q[%u], q[%u];\n", 4 * c5 - 2 * c10 + 11, -12 * c5 + 8 * c10 + 15);
                  }
                  if (c5 == 0) {
                    for (int c10 = 0; c10 <= 1; c10 += 1) {
                      fprintf(f, "x q[%u];\n", 4 * c10 + 11);
                    }
                  }
                }
                if (c5 >= c4 + 1) {
                  if (c4 == 0 && c2 + c5 <= 4) {
                    if (c0 == 0 && c2 == 2 && c5 == 2) {
                      for (int c8 = 12; c8 <= 13; c8 += 1) {
                        if (c8 == 13) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 16);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c10 + 1);
                          }
                        } else {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10 + 7);
                          }
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -8 * c10 + 14, 15 * c10 + 3);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 16 * c10 + 1);
                      }
                      for (int c8 = 15; c8 <= 21; c8 += 1) {
                        if (c8 == 21) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 7);
                          }
                        } else if (c8 == 20) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 7);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 15 * c10 + 2);
                          }
                        } else if (c8 == 19) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 7);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 15 * c10 + 2);
                          }
                        } else if (c8 == 18) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 7);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 15 * c10 + 2);
                          }
                        } else if (c8 == 17) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c10 + 1);
                          }
                        } else if (c8 == 16) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c10 + 1);
                          }
                        } else {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 16 * c10 + 1);
                          }
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c10 + 2);
                      }
                      for (int c8 = 23; c8 <= 25; c8 += 1) {
                        if (c8 == 25) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10 + 2);
                          }
                        } else if (c8 == 24) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10 + 2);
                          }
                        } else {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10 + 2);
                          }
                        }
                      }
                    } else {
                      if (c0 == 1 && c2 == 2 && c5 == 2) {
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 2 * c10 + 11);
                        }
                        for (int c8 = 14; c8 <= 15; c8 += 1) {
                          if (c8 == 15) {
                            fprintf(f, "cx q[%u], q[%u];\n", 11, 3);
                          } else {
                            fprintf(f, "cx q[%u], q[%u];\n", 11, 15);
                          }
                        }
                      } else if (c0 == 0 && c2 == 3) {
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 14 * c10 + 2);
                        }
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 14 * c10 + 2);
                        }
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 14 * c10 + 2);
                        }
                      }
                      if (c0 == 0 && c5 == 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 3 * c2 + 7, 13 * c2 - 22);
                        if (c2 == 2) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c10);
                          }
                        }
                      } else if (c2 == 3 && c5 == 1) {
                        fprintf(f, "x q[%u];\n", 11);
                      }
                    }
                    if (c2 == 2 && c5 == 2) {
                      for (int c10 = 0; c10 <= -c0 + 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 9 * c0 + 14 * c10 + 2);
                      }
                      if (c0 == 1) {
                        fprintf(f, "x q[%u];\n", 13);
                        fprintf(f, "x q[%u];\n", 13);
                      }
                    } else {
                      if (c0 == 0 && c2 == 3) {
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 12 * c10 + 4);
                        }
                        fprintf(f, "x q[%u];\n", 4);
                      }
                      if (c0 == 0 && c2 == 3) {
                        for (int c8 = 10; c8 <= 28; c8 += 1) {
                          if (c8 == 25) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              for (int c11 = 0; c11 <= -c10 + 1; c11 += 1) {
                                fprintf(f, "x q[%u];\n", 2 * c10 + 9 * c11 + 2);
                              }
                            }
                          }
                          if (c8 >= 22) {
                            for (int c10 = 0; c10 <= -c8 + 23; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c8 + 17 * c10 - 42);
                            }
                          }
                          if (c8 >= 20) {
                            for (int c10 = 0; c10 <= -c8 + 21; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c8 + 17 * c10 - 38);
                            }
                            if (c8 >= 21) {
                              for (int c10 = 0; c10 <= -c8 + 22; c10 += 1) {
                                fprintf(f, "x q[%u];\n", 2 * c8 + 17 * c10 - 40);
                              }
                              if (c8 == 26) {
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  for (int c11 = 0; c11 <= -c10 + 1; c11 += 1) {
                                    fprintf(f, "x q[%u];\n", 2 * c10 + 10 * c11 + 2);
                                  }
                                }
                              }
                              if (c8 >= 23) {
                                for (int c10 = 0; c10 <= -c8 + 24; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", 2 * c8 + 9 * c10 - 44);
                                }
                                if (c8 == 28) {
                                  fprintf(f, "x q[%u];\n", 4);
                                } else if (c8 == 27) {
                                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                                    for (int c11 = 0; c11 <= -c10 + 1; c11 += 1) {
                                      fprintf(f, "x q[%u];\n", 2 * c10 + 17 * c11 + 2);
                                    }
                                  }
                                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                                    fprintf(f, "x q[%u];\n", 8 * c10 + 5);
                                  }
                                } else if (c8 == 24) {
                                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                                    fprintf(f, "x q[%u];\n", 10 * c10 + 2);
                                  }
                                }
                              }
                            }
                          } else if (c8 == 17) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c8 == 16) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c8 == 15) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c8 == 14) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c8 == 13) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c8 == 12) {
                            fprintf(f, "x q[%u];\n", 4);
                          } else if (c8 == 11) {
                            fprintf(f, "x q[%u];\n", 4);
                          }
                          if ((c8 + 8) % 18 == 0) {
                            for (int c10 = 0; c10 < (c8 + 8) / 18; c10 += 1) {
                              fprintf(f, "x q[%u];\n", ((-c8 + 46) / 9) + 10 * c10);
                            }
                          }
                          if (c8 >= 19) {
                            for (int c10 = 0; c10 <= -c8 + 20; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 2 * c8 + 17 * c10 - 36);
                            }
                            if (c8 == 26) {
                              fprintf(f, "cx q[%u], q[%u];\n", 13, 5);
                            } else if (c8 == 19) {
                              fprintf(f, "x q[%u];\n", 4);
                            }
                          } else if (c8 == 18) {
                            fprintf(f, "x q[%u];\n", 4);
                          }
                        }
                      }
                    }
                    if (c0 + c2 <= 3 && c2 + c5 == 4) {
                      if (c0 == 0) {
                        for (int c10 = 0; c10 < c2 - 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 13 * c2 - 13 * c10 - 22);
                        }
                        if (c2 == 3) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c10 + 2);
                          }
                        }
                      } else {
                        fprintf(f, "x q[%u];\n", 13);
                      }
                    } else if (c0 == 1) {
                      if (c2 == 3) {
                        fprintf(f, "x q[%u];\n", 11);
                      } else {
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 8 * c10 + 3);
                        }
                      }
                    }
                    if (c0 + c2 == 3 && c5 == 1) {
                      for (int c8 = max(30, 21 * c0 + 10); c8 <= min(39, -18 * c0 + 49); c8 += 1) {
                        if (c0 == 0 && c8 == 30) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 10 * c10 + 2);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", -13 * c10 + 17);
                          }
                        } else {
                          if (c0 == 0 && c8 >= 34 && (c8 - 1) % 3 == 0) {
                            for (int c10 = 0; c10 <= (-c8 + 37) / 3; c10 += 1) {
                              fprintf(f, "x q[%u];\n", ((4 * c8 - 136) / 3) + 10 * c10);
                            }
                            if (c8 == 37) {
                              for (int c10 = 0; c10 <= 1; c10 += 1) {
                                fprintf(f, "x q[%u];\n", 7 * c10 + 10);
                              }
                            }
                          } else if (c0 == 0 && c8 == 33) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              for (int c11 = 0; c11 <= -c10 + 1; c11 += 1) {
                                fprintf(f, "x q[%u];\n", 2 * c10 + 10 * c11 + 2);
                              }
                            }
                          }
                          if (c0 == 0 && c8 >= 35 && (c8 + 1) % 3 == 0) {
                            for (int c10 = 0; c10 <= (-c8 + 38) / 3; c10 += 1) {
                              fprintf(f, "x q[%u];\n", ((4 * c8 - 140) / 3) + 10 * c10);
                            }
                            if (c8 == 38) {
                              for (int c10 = 0; c10 <= 1; c10 += 1) {
                                fprintf(f, "x q[%u];\n", 7 * c10 + 10);
                              }
                            }
                            if (c8 == 35) {
                              for (int c10 = 0; c10 <= 1; c10 += 1) {
                                for (int c11 = 0; c11 <= -c10 + 1; c11 += 1) {
                                  fprintf(f, "x q[%u];\n", 2 * c10 + 10 * c11 + 2);
                                }
                              }
                            }
                          } else {
                            if (c0 == 0 && c8 == 36) {
                              for (int c10 = 0; c10 <= 1; c10 += 1) {
                                fprintf(f, "x q[%u];\n", 10 * c10);
                              }
                            }
                            if (c0 == 0 && c8 == 34) {
                              for (int c10 = 0; c10 <= 1; c10 += 1) {
                                for (int c11 = 0; c11 <= -c10 + 1; c11 += 1) {
                                  fprintf(f, "x q[%u];\n", 2 * c10 + 10 * c11 + 2);
                                }
                              }
                            } else {
                              if (c0 == 0 && c8 == 33) {
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", 12 * c10 + 6);
                                }
                              } else if (c0 == 0 && c8 == 32) {
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", 10 * c10 + 2);
                                }
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", 10 * c10);
                                }
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  for (int c11 = 0; c11 <= c10; c11 += 1) {
                                    fprintf(f, "x q[%u];\n", -c10 + 15 * c11 + 4);
                                  }
                                }
                              } else if (c0 == 0 && c8 == 31) {
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  fprintf(f, "cx q[%u], q[%u];\n", -7 * c10 + 17, 14 * c10);
                                }
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  for (int c11 = 0; c11 <= c10; c11 += 1) {
                                    fprintf(f, "x q[%u];\n", -c10 + 15 * c11 + 4);
                                  }
                                }
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", 10 * c10 + 2);
                                }
                              } else if (c0 == 1 && c8 == 31) {
                                for (int c10 = 0; c10 <= 1; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", 2 * c10 + 11);
                                }
                              }
                              if (c0 == 0 && c8 % 3 == 0) {
                                for (int c10 = 0; c10 <= (-c8 / 3) + 12; c10 += 1) {
                                  fprintf(f, "x q[%u];\n", (4 * c8 / 3) + 10 * c10 - 44);
                                }
                                if (c8 == 39) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 16, 17);
                                }
                              }
                            }
                          }
                        }
                      }
                      if (c0 == 0) {
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 12 * c10 + 5);
                        }
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          fprintf(f, "x q[%u];\n", 11 * c10 + 5);
                        }
                      }
                      if (c0 == 0) {
                        for (int c8 = 42; c8 <= 44; c8 += 1) {
                          if (c8 == 44) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c10 + 8);
                            }
                          } else if (c8 == 43) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c10 + 8);
                            }
                          } else {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c10 + 8);
                            }
                          }
                        }
                      }
                    } else if (c0 == 0 && c2 == 2 && c5 == 1) {
                      for (int c10 = 0; c10 <= 2; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c10);
                      }
                      for (int c8 = 16; c8 <= 20; c8 += 1) {
                        if (c8 == 20) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c10);
                          }
                        } else if (c8 == 19) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 8 * c10);
                          }
                        } else if (c8 == 18) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c10);
                          }
                        } else if (c8 == 17) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c10);
                          }
                        } else {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 9 * c10);
                          }
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c10 + 1);
                      }
                      fprintf(f, "x q[%u];\n", 12);
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c10 + 1);
                      }
                      for (int c8 = 26; c8 <= 27; c8 += 1) {
                        fprintf(f, "x q[%u];\n", -3 * c8 + 87);
                        if (c8 == 26) {
                          for (int c10 = 0; c10 <= 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10 + 1);
                          }
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 2; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 2; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 2; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c10 + 1);
                      }
                    }
                  } else if (c0 == 0) {
                    if (c2 == 3 && c4 == 0) {
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", -4 * c10 + 19, c10 + 13);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 6 * c10 + 13);
                      }
                      for (int c8 = 18; c8 <= 19; c8 += 1) {
                        if (c8 == 19) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 8);
                          }
                        } else {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", c10 + 8);
                          }
                        }
                      }
                    } else if (c2 == 4 && c4 == 0) {
                      for (int c8 = 0; c8 <= 24; c8 += 1) {
                        if (c8 == 24) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= 1; c11 += 1) {
                              fprintf(f, "x q[%u];\n", c10 + 12 * c11 + 6);
                            }
                          }
                        } else if (c8 == 23) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 7);
                          }
                        } else if (c8 == 22) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c10 + 5);
                          }
                        } else if (c8 == 21) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c10 + 5);
                          }
                        } else if (c8 == 20) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 14 * c10 + 5);
                          }
                        } else if (c8 == 19) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 2 * c10 + 5);
                          }
                        } else if (c8 == 17) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -10 * c10 + 5 * c11 + 10);
                            }
                          }
                        } else if (c8 == 15) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c10 + c11 + 10);
                            }
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10);
                          }
                        } else if (c8 == 14) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c10 + c11 + 10);
                            }
                          }
                        } else if (c8 == 13) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", 2 * c10 + 5, 19 * c10);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", 6 * c10 + c11 + 10);
                            }
                          }
                        } else if (c8 == 0) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 5);
                          }
                        } else if ((c8 + 2) % 7 == 0) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c10 + 5);
                          }
                          if (c8 == 12) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c10 + 15);
                            }
                          }
                        } else if (c8 == 11) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c10 + 5);
                          }
                        } else if (c8 == 10) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -5 * c10 + 11 * c11 + 10);
                            }
                          }
                        } else if (c8 == 9) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c10 + 5);
                          }
                        } else if (c8 == 8) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c10 + 5);
                          }
                        } else if (c8 == 7) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -5 * c10 + 11 * c11 + 10);
                            }
                          }
                        } else if (c8 == 6) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 11 * c10 + 5);
                          }
                        } else if (c8 == 4) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 5);
                          }
                        } else if (c8 == 3) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 5);
                          }
                        } else if (c8 == 2) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 5);
                          }
                        } else if (c8 == 1) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 5);
                          }
                        } else {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c10);
                          }
                        }
                      }
                    }
                    for (int c8 = c2 + 21; c8 <= min(28, -15 * c2 + 85); c8 += 4) {
                      if (c2 == 3) {
                        for (int c10 = 0; c10 <= 1; c10 += 1) {
                          if (c8 == 28 && c10 == 0) {
                            fprintf(f, "x q[%u];\n", c4 + 8);
                            fprintf(f, "x q[%u];\n", c4 + 8);
                            fprintf(f, "x q[%u];\n", c4 + 8);
                          }
                          fprintf(f, "x q[%u];\n", c4 + 8);
                          if (c8 == 24 && c10 == 0) {
                            fprintf(f, "x q[%u];\n", c4 + 8);
                            fprintf(f, "x q[%u];\n", c4 + 8);
                            fprintf(f, "x q[%u];\n", c4 + 8);
                          }
                          if (c8 == 28 && c10 == 0) {
                            fprintf(f, "x q[%u];\n", c4 + 8);
                          }
                        }
                      } else {
                        fprintf(f, "x q[%u];\n", 19);
                        fprintf(f, "x q[%u];\n", 18);
                      }
                    }
                    if (c2 == 3 && c4 == 0) {
                      fprintf(f, "x q[%u];\n", 8);
                    } else if (c2 == 4 && c4 == 0) {
                      for (int c8 = 26; c8 <= 32; c8 += 1) {
                        if (c8 == 32) {
                          fprintf(f, "x q[%u];\n", 17);
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 7 * c10 + 7);
                          }
                        } else if (c8 == 31) {
                          fprintf(f, "x q[%u];\n", 17);
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 7 * c10 + 7);
                          }
                        } else if (c8 == 30) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -10 * c10 + 7 * c11 + 17);
                            }
                          }
                        } else if (c8 == 29) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -10 * c10 + 7 * c11 + 17);
                            }
                          }
                        } else if (c8 == 28) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -10 * c10 + 7 * c11 + 17);
                            }
                          }
                        } else if (c8 == 27) {
                          fprintf(f, "x q[%u];\n", 18);
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            for (int c11 = 0; c11 <= c10; c11 += 1) {
                              fprintf(f, "x q[%u];\n", -10 * c10 + 7 * c11 + 17);
                            }
                          }
                        } else {
                          fprintf(f, "x q[%u];\n", 17);
                          fprintf(f, "x q[%u];\n", 18);
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -7 * c10 + 14, 16 * c10 + 3);
                          }
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c10 + 7);
                      }
                      fprintf(f, "x q[%u];\n", 17);
                      for (int c8 = 34; c8 <= 49; c8 += 1) {
                        if (c8 == 41) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 7);
                          }
                        } else if ((c8 - 1) % 9 == 0) {
                          for (int c10 = 0; c10 < (c8 - 28) / 9; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                          }
                          if (c8 == 37) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 7 * c10 + 7);
                            }
                          }
                        } else if (c8 <= 36) {
                          for (int c10 = 0; c10 < c8 - 34; c10 += 1) {
                            fprintf(f, "x q[%u];\n", -3 * c8 + 7 * c10 + 115);
                          }
                        }
                        if (c8 >= 41 && c8 <= 45 && (c8 - 1) % 4 == 0) {
                          fprintf(f, "x q[%u];\n", (9 * c8 - 329) / 4);
                          if (c8 == 45) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                            }
                          }
                        } else if (c8 == 44) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 7);
                          }
                        } else if (c8 == 43) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 7);
                          }
                        } else if (c8 == 42) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 7);
                          }
                        } else if (c8 == 40) {
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 7);
                          }
                          for (int c10 = 0; c10 <= 1; c10 += 1) {
                            fprintf(f, "cx q[%u], q[%u];\n", -5 * c10 + 15, 11 * c10 + 3);
                          }
                        } else {
                          if (c8 == 38) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 7 * c10 + 7);
                            }
                          } else if (c8 == 34) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 7 * c10 + 7);
                            }
                          } else if ((c8 + 7) % 14 == 0) {
                            for (int c10 = 0; c10 <= (-c8 + 49) / 14; c10 += 1) {
                              fprintf(f, "x q[%u];\n", ((c8 - 21) / 2) + 7 * c10);
                            }
                          }
                          if ((c8 - 2) % 9 == 0) {
                            for (int c10 = 0; c10 < (c8 - 29) / 9; c10 += 1) {
                              fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                            }
                          } else {
                            if ((c8 - 3) % 9 == 0) {
                              for (int c10 = 0; c10 < (c8 - 30) / 9; c10 += 1) {
                                fprintf(f, "x q[%u];\n", 4 * c10 + 10);
                              }
                            }
                            if (c8 <= 39 && c8 % 3 == 0) {
                              for (int c10 = 0; c10 < (c8 / 3) - 11; c10 += 1) {
                                fprintf(f, "x q[%u];\n", -c8 + 7 * c10 + 46);
                              }
                            }
                          }
                        }
                      }
                    }
                  } else if (c2 == 2) {
                    fprintf(f, "x q[%u];\n", 13);
                    fprintf(f, "x q[%u];\n", 13);
                  } else {
                    fprintf(f, "x q[%u];\n", 13);
                  }
                  if (c0 == 0 && c2 <= 3 && c4 == 0 && c5 == 1) {
                    for (int c7 = 0; c7 <= -c2 + 4; c7 += 1) {
                      fprintf(f, "x q[%u];\n", c2 + c7 + 5);
                    }
                  }
                }
              }
              if (c0 == 1 && c2 == 4 && c4 == 0) {
                for (int c5 = -1; c5 <= 1; c5 += 1) {
                  if (c5 == -1) {
                    fprintf(f, "x q[%u];\n", 11);
                  }
                  if (c5 <= 0) {
                    fprintf(f, "x q[%u];\n", 11);
                    if (c5 == 0) {
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 10 * c10 + 3, 5 * c10 + 6);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        for (int c11 = 0; c11 <= c10; c11 += 1) {
                          fprintf(f, "x q[%u];\n", -13 * c10 + 5 * c11 + 19);
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        for (int c11 = 0; c11 <= c10; c11 += 1) {
                          fprintf(f, "x q[%u];\n", -13 * c10 + 7 * c11 + 19);
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        for (int c11 = 0; c11 <= c10; c11 += 1) {
                          fprintf(f, "x q[%u];\n", -8 * c10 + 7 * c11 + 14);
                        }
                      }
                    }
                  }
                  if (c5 >= 0) {
                    for (int c10 = 0; c10 <= 1; c10 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c10 + 11);
                    }
                    if (c5 == 1) {
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c10 + 11);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 2 * c10 + 11);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c10 + 15, 8 * c10 + 3);
                      }
                      for (int c10 = 0; c10 <= 2; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c10 + 3);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 16 * c10 + 3);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 16 * c10 + 3);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        for (int c11 = 0; c11 <= c10; c11 += 1) {
                          fprintf(f, "x q[%u];\n", -11 * c10 + 16 * c11 + 14);
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 16 * c10 + 3);
                      }
                      for (int c8 = 19; c8 <= 21; c8 += 1) {
                        if (c8 <= 20) {
                          fprintf(f, "x q[%u];\n", -10 * c8 + 203);
                          if (c8 == 20) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              fprintf(f, "cx q[%u], q[%u];\n", -2 * c10 + 15, 10 * c10 + 1);
                            }
                          }
                        }
                        if ((c8 + 1) % 2 == 0) {
                          for (int c10 = 0; c10 <= (-c8 + 21) / 2; c10 += 1) {
                            fprintf(f, "x q[%u];\n", 12 * c10 + 3);
                          }
                        }
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 12 * c10 + 1, 5 * c10 + 6);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 10 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 12 * c10 + 1);
                      }
                      for (int c10 = 0; c10 <= 1; c10 += 1) {
                        fprintf(f, "x q[%u];\n", 12 * c10 + 1);
                      }
                    }
                  }
                }
              }
            } else {
              for (int c5 = (-c2 / 2) + 1; c5 <= (-c2 / 2) + 2; c5 += 1) {
                fprintf(f, "x q[%u];\n", 15);
              }
            }
          }
          if (c0 == 1 && c1 == 0 && c2 == 4) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              for (int c5 = 1; c5 <= 2; c5 += 1) {
                fprintf(f, "x q[%u];\n", 15);
                if (c4 == 0 && c5 == 1) {
                  fprintf(f, "x q[%u];\n", 1);
                }
              }
            }
          } else if (c0 == 2 && c1 == 0 && c2 == 2) {
            for (int c5 = 0; c5 <= 1; c5 += 1) {
              if (c5 == 1) {
                fprintf(f, "x q[%u];\n", 3);
              }
              fprintf(f, "x q[%u];\n", 15);
            }
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -9 * c10 + 15, 15 * c10 + 3);
            }
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c10 + 3);
            }
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c10 + 3);
            }
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c10 + 3);
            }
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 12 * c10 + 3);
            }
            for (int c8 = 26; c8 <= 27; c8 += 1) {
              fprintf(f, "x q[%u];\n", -3 * c8 + 84);
            }
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 15 * c10 + 3);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 6, 18);
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 15 * c10 + 3);
            }
            fprintf(f, "cx q[%u], q[%u];\n", 12, 6);
            for (int c7 = 0; c7 <= 3; c7 += 1) {
              fprintf(f, "x q[%u];\n", 18);
            }
            fprintf(f, "x q[%u];\n", 18);
            for (int c10 = 0; c10 <= 1; c10 += 1) {
              fprintf(f, "x q[%u];\n", 6 * c10 + 6);
            }
          }
          if (c0 == 1 && c1 == 0 && c2 == 3) {
            for (int c4 = 0; c4 <= 1; c4 += 1) {
              fprintf(f, "x q[%u];\n", 2 * c4 + 13);
            }
          }
        } else if (c0 == 2 && c1 == 0 && c2 >= 3) {
          if (c2 == 3) {
            for (int c4 = -1; c4 <= 0; c4 += 1) {
              if (c4 == 0) {
                fprintf(f, "x q[%u];\n", 6);
                fprintf(f, "cx q[%u], q[%u];\n", 12, 6);
              }
              for (int c5 = 1; c5 <= 2; c5 += 1) {
                if (c4 == -1 && c5 == 2) {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "x q[%u];\n", 6 * c10 + 6);
                  }
                }
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  fprintf(f, "x q[%u];\n", 6 * c10 + 6);
                }
              }
            }
          }
          fprintf(f, "x q[%u];\n", 6);
          if (c2 == 4) {
            for (int c5 = 1; c5 <= 2; c5 += 1) {
              fprintf(f, "x q[%u];\n", 6);
              if (c5 == 1) {
                fprintf(f, "x q[%u];\n", 1);
              }
            }
            for (int c8 = 24; c8 <= 28; c8 += 1) {
              if (c8 >= 26 && c8 <= 27) {
                fprintf(f, "x q[%u];\n", -3 * c8 + 84);
                if (c8 == 26) {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    fprintf(f, "x q[%u];\n", 2 * c10 + 1);
                  }
                }
              } else if (c8 % 4 == 0) {
                fprintf(f, "x q[%u];\n", 6);
              }
              if (c8 >= 27) {
                fprintf(f, "x q[%u];\n", -3 * c8 + 87);
              } else if (c8 == 25) {
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  fprintf(f, "cx q[%u], q[%u];\n", -2 * c10 + 3, 6 * c10 + 6);
                }
              }
            }
          }
        }
      }
      if (c0 == 0 && c1 == 0) {
        for (int c10 = 0; c10 <= 1; c10 += 1) {
          fprintf(f, "x q[%u];\n", 12 * c10 + 3);
        }
        fprintf(f, "cx q[%u], q[%u];\n", 11, 3);
        fprintf(f, "x q[%u];\n", 15);
      }
    }
  } else {
    fprintf(f, "x q[%u];\n", 18);
    fprintf(f, "x q[%u];\n", 18);
    fprintf(f, "cx q[%u], q[%u];\n", 12, 18);
    for (int c10 = 0; c10 <= 1; c10 += 1) {
      fprintf(f, "x q[%u];\n", 6 * c10 + 12);
    }
    for (int c5 = 1; c5 <= 2; c5 += 1) {
      fprintf(f, "x q[%u];\n", 18);
    }
    for (int c2 = 3; c2 <= 4; c2 += 1) {
      if (c2 == 4) {
        fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
        fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
        for (int c10 = 0; c10 <= 1; c10 += 1) {
          fprintf(f, "x q[%u];\n", 11 * c10 + 1);
        }
      }
      fprintf(f, "x q[%u];\n", 18);
    }
    for (int c8 = 12; c8 <= 14; c8 += 1) {
      if (c8 == 13) {
        for (int c10 = 0; c10 <= 1; c10 += 1) {
          fprintf(f, "x q[%u];\n", -11 * c10 + 12);
        }
      } else {
        fprintf(f, "cx q[%u], q[%u];\n", c8 - 12, (11 * c8 / 2) - 65);
        if (c8 == 12) {
          for (int c10 = 0; c10 <= 1; c10 += 1) {
            fprintf(f, "x q[%u];\n", -6 * c10 + 18);
          }
        }
      }
    }
    for (int c10 = 0; c10 <= 1; c10 += 1) {
      fprintf(f, "x q[%u];\n", 12 * c10);
    }
    for (int c10 = 0; c10 <= 1; c10 += 1) {
      fprintf(f, "cx q[%u], q[%u];\n", 12 * c10, 3 * c10 + 15);
    }
    fprintf(f, "cx q[%u], q[%u];\n", 2, 12);
    for (int c10 = 0; c10 <= 1; c10 += 1) {
      fprintf(f, "x q[%u];\n", 18 * c10);
    }
  }
}
fclose(f);
return 0;
}