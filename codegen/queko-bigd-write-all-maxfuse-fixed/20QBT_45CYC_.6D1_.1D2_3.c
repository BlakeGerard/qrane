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
FILE *f = fopen("codegen/queko-bigd-write-all-maxfuse-fixed/20QBT_45CYC_.6D1_.1D2_3.qasm", "w");
fprintf(f, "OPENQASM 2.0;\ninclude \"qelib1.inc\";\nqreg q[20];\n");
for (int c0 = 0; c0 <= 14; c0 += 1) {
  if (c0 >= 6) {
    for (int c1 = 0; c1 <= min(c0 - 7, -2 * c0 + 22); c1 += 1) {
      if (c1 + 8 >= c0) {
        if (c0 >= 9) {
          if (c0 == 9 && c1 == 1) {
            fprintf(f, "x q[%u];\n", 0);
            for (int c13 = 0; c13 <= 1; c13 += 1) {
              fprintf(f, "x q[%u];\n", 10 * c13 + 5);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", -7 * c14 + 12);
            }
          }
          if (c0 == 9) {
            fprintf(f, "x q[%u];\n", 5);
            if (c1 == 1) {
              fprintf(f, "x q[%u];\n", 2);
              fprintf(f, "x q[%u];\n", 2);
              fprintf(f, "x q[%u];\n", 2);
            }
          } else {
            fprintf(f, "x q[%u];\n", 7);
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 9 * c14 + 7);
            }
          }
          if (c0 == 9 && c1 == 2) {
            fprintf(f, "x q[%u];\n", 3);
          }
        } else {
          for (int c3 = 0; c3 < c0 + c1 - 6; c3 += 1) {
            if (c1 == 0 && c3 == 0) {
              if (c0 == 8) {
                fprintf(f, "cx q[%u], q[%u];\n", 1, 12);
                for (int c6 = 0; c6 <= 7; c6 += 1) {
                  fprintf(f, "x q[%u];\n", 1);
                  if (c6 == 6) {
                    fprintf(f, "x q[%u];\n", 1);
                  }
                }
              } else {
                fprintf(f, "cx q[%u], q[%u];\n", 3, 7);
                fprintf(f, "x q[%u];\n", 7);
                fprintf(f, "x q[%u];\n", 7);
                fprintf(f, "x q[%u];\n", 7);
                fprintf(f, "x q[%u];\n", 7);
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 4 * c14 + 3);
                }
              }
            }
            if (c0 == 8 && c3 <= 1) {
              if (c1 == 0 && c3 == 1) {
                fprintf(f, "cx q[%u], q[%u];\n", 10, 4);
                fprintf(f, "cx q[%u], q[%u];\n", 10, 4);
              } else if (c1 == 0 && c3 == 0) {
                for (int c6 = -1; c6 <= 6; c6 += 1) {
                  if (c6 == 6) {
                    fprintf(f, "x q[%u];\n", 12);
                  }
                  fprintf(f, "x q[%u];\n", 12);
                }
              }
              for (int c5 = max(-c1 + 1, c1 + c3 - 1); c5 <= min(c1 + 1, -c1 - c3 + 3); c5 += 1) {
                if (c1 + c3 == 1 && c5 <= 1) {
                  for (int c7 = -3 * c5 + 3; c7 <= -3 * c1 - 3 * c5 + 6; c7 += 1) {
                    if (c1 + c5 == 1 && c7 >= 1) {
                      if (c1 == 0) {
                        for (int c13 = 0; c13 <= 1; c13 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c13 + 7);
                        }
                      }
                      if (c7 == 3) {
                        for (int c12 = 0; c12 <= 1; c12 += 1) {
                          fprintf(f, "x q[%u];\n", 5 * c12 + 7);
                        }
                        if (c1 == 1) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 5 * c14 + 7);
                          }
                        }
                      }
                    } else if (c1 == 0) {
                      for (int c12 = 20; c12 <= 24; c12 += 1) {
                        if (c12 == 23) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", 6 * c14 + 4);
                          }
                        } else if (c12 == 22) {
                          fprintf(f, "cx q[%u], q[%u];\n", 10, 4);
                        } else if (c12 == 21) {
                          fprintf(f, "x q[%u];\n", 10);
                        } else {
                          fprintf(f, "x q[%u];\n", -2 * c12 + 52);
                        }
                      }
                      fprintf(f, "x q[%u];\n", 4);
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                      }
                      fprintf(f, "x q[%u];\n", 4);
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 8 * c14 + 4);
                      }
                      for (int c13 = 0; c13 <= 1; c13 += 1) {
                        fprintf(f, "x q[%u];\n", 5 * c13 + 7);
                      }
                    } else {
                      for (int c8 = 0; c8 <= 3; c8 += 1) {
                        if (c8 == 3) {
                          for (int c10 = -1; c10 <= 0; c10 += 1) {
                            fprintf(f, "x q[%u];\n", -14 * c10);
                            fprintf(f, "x q[%u];\n", -14 * c10);
                          }
                          for (int c9 = 0; c9 <= 2; c9 += 1) {
                            if (c9 == 2) {
                              fprintf(f, "x q[%u];\n", 14);
                              fprintf(f, "x q[%u];\n", 14);
                            }
                            for (int c10 = max(-1, -c9); c10 <= 0; c10 += 1) {
                              if (c10 == 0) {
                                fprintf(f, "x q[%u];\n", -2 * c9 + 18);
                                fprintf(f, "x q[%u];\n", -2 * c9 + 18);
                                fprintf(f, "x q[%u];\n", -2 * c9 + 18);
                                fprintf(f, "x q[%u];\n", -2 * c9 + 18);
                                if (c9 <= 1) {
                                  fprintf(f, "x q[%u];\n", 16 * c9);
                                  fprintf(f, "x q[%u];\n", 16 * c9);
                                  fprintf(f, "x q[%u];\n", 16 * c9);
                                }
                              }
                              if ((c9 + c10) % 2 == 0) {
                                for (int c13 = 0; c13 <= 1; c13 += 1) {
                                  fprintf(f, "x q[%u];\n", 18 * c13);
                                }
                              }
                            }
                          }
                        }
                        for (int c9 = 5; c9 <= c8 / 3 + 5; c9 += 1) {
                          if (c9 == 5) {
                            if (c8 == 0) {
                              fprintf(f, "cx q[%u], q[%u];\n", 2, 19);
                            }
                            for (int c13 = 0; c13 <= 1; c13 += 1) {
                              fprintf(f, "x q[%u];\n", 17 * c13 + 2);
                            }
                          } else {
                            for (int c13 = 0; c13 <= 1; c13 += 1) {
                              fprintf(f, "x q[%u];\n", 18 * c13);
                            }
                            fprintf(f, "x q[%u];\n", 1);
                            for (int c14 = 0; c14 <= 1; c14 += 1) {
                              fprintf(f, "x q[%u];\n", 18 * c14);
                            }
                            fprintf(f, "x q[%u];\n", 15);
                          }
                          if (c8 == 3) {
                            for (int c10 = 0; c10 <= 1; c10 += 1) {
                              if (c9 == 5) {
                                for (int c12 = 17; c12 <= -c10 + 18; c12 += 1) {
                                  if (c10 == 0 && c12 == 18) {
                                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                                      fprintf(f, "x q[%u];\n", 17 * c14 + 2);
                                    }
                                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                                      fprintf(f, "x q[%u];\n", 7 * c14 + 9);
                                    }
                                  }
                                  fprintf(f, "x q[%u];\n", 7 * c10 + 2 * c12 - 25);
                                  if (c10 == 0 && c12 == 17) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 11, 16);
                                  }
                                }
                                if (c10 == 0) {
                                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                                    fprintf(f, "x q[%u];\n", 7 * c14 + 9);
                                  }
                                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                                    fprintf(f, "x q[%u];\n", 17 * c14 + 2);
                                  }
                                  for (int c12 = 20; c12 <= 23; c12 += 1) {
                                    if (c12 == 23) {
                                      fprintf(f, "x q[%u];\n", 19);
                                    } else if (c12 == 22) {
                                      fprintf(f, "x q[%u];\n", 19);
                                      fprintf(f, "x q[%u];\n", 16);
                                    } else if (c12 == 21) {
                                      fprintf(f, "x q[%u];\n", 19);
                                      fprintf(f, "x q[%u];\n", 16);
                                    } else {
                                      fprintf(f, "x q[%u];\n", 19);
                                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                                        fprintf(f, "x q[%u];\n", 7 * c14 + 9);
                                      }
                                    }
                                  }
                                }
                              } else if (c10 == 1) {
                                for (int c14 = 0; c14 <= 1; c14 += 1) {
                                  fprintf(f, "x q[%u];\n", 4 * c14 + 9);
                                }
                              }
                              if (c9 >= c10 + 5) {
                                if (c9 == 6 && c10 == 0) {
                                  fprintf(f, "cx q[%u], q[%u];\n", 15, 9);
                                  fprintf(f, "x q[%u];\n", 7);
                                }
                                fprintf(f, "cx q[%u], q[%u];\n", -14 * c9 + 13 * c10 + 84, -17 * c9 + 7 * c10 + 104);
                                if (c9 == 6 && c10 == 0) {
                                  for (int c12 = 21; c12 <= 22; c12 += 1) {
                                    if (c12 == 22) {
                                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                                        fprintf(f, "x q[%u];\n", 5 * c14 + 7);
                                      }
                                      fprintf(f, "cx q[%u], q[%u];\n", 15, 9);
                                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                                        fprintf(f, "x q[%u];\n", 17 * c14 + 1);
                                      }
                                    } else {
                                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                                        fprintf(f, "cx q[%u], q[%u];\n", -2 * c14 + 9, 2 * c14 + 10);
                                      }
                                      fprintf(f, "cx q[%u], q[%u];\n", 2, 18);
                                    }
                                  }
                                }
                                if (c9 == 6) {
                                  for (int c12 = 23; c12 <= -c10 + 32; c12 += 1) {
                                    if (c12 == 31) {
                                      fprintf(f, "x q[%u];\n", -5 * c10 + 9);
                                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                                        fprintf(f, "x q[%u];\n", -4 * c10 + 4 * c14 + 13);
                                      }
                                    } else if (c12 % 8 == 0) {
                                      fprintf(f, "x q[%u];\n", (-c12 / 4) - 11 * c10 + 21);
                                      if (c10 == 0 && c12 == 32) {
                                        fprintf(f, "x q[%u];\n", 9);
                                      }
                                      if (c10 == 0 && c12 == 24) {
                                        fprintf(f, "cx q[%u], q[%u];\n", 18, 1);
                                      }
                                    } else {
                                      if (c10 == 0 && c12 == 30) {
                                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                                          fprintf(f, "x q[%u];\n", 4 * c14 + 13);
                                        }
                                      }
                                      if (c12 == 30) {
                                        fprintf(f, "x q[%u];\n", -5 * c10 + 9);
                                        if (c10 == 0) {
                                          fprintf(f, "cx q[%u], q[%u];\n", 10, 4);
                                        }
                                      } else {
                                        if (c10 == 0 && c12 == 28) {
                                          fprintf(f, "x q[%u];\n", 1);
                                        }
                                        if (c12 == 28) {
                                          fprintf(f, "x q[%u];\n", -5 * c10 + 9);
                                        } else if (c12 == 27) {
                                          fprintf(f, "x q[%u];\n", -11 * c10 + 15);
                                        }
                                        if (c10 == 0 && c12 == 29) {
                                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                                            fprintf(f, "x q[%u];\n", 4 * c14 + 13);
                                          }
                                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                                            fprintf(f, "x q[%u];\n", 2 * c14 + 10);
                                          }
                                        }
                                        if (c12 == 29) {
                                          fprintf(f, "x q[%u];\n", -5 * c10 + 9);
                                        } else if (c10 == 0 && c12 == 28) {
                                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                                            fprintf(f, "x q[%u];\n", 2 * c14 + 10);
                                          }
                                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                                            fprintf(f, "x q[%u];\n", 15 * c14 + 3);
                                          }
                                        } else if (c10 == 0 && c12 == 27) {
                                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                                            fprintf(f, "x q[%u];\n", 15 * c14 + 3);
                                          }
                                          fprintf(f, "x q[%u];\n", 1);
                                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                                            fprintf(f, "x q[%u];\n", 2 * c14 + 10);
                                          }
                                        } else {
                                          if (c10 == 0 && c12 == 26) {
                                            fprintf(f, "x q[%u];\n", 16);
                                            fprintf(f, "x q[%u];\n", 1);
                                          } else {
                                            if (c10 == 0 && c12 == 25) {
                                              for (int c14 = 0; c14 <= 1; c14 += 1) {
                                                fprintf(f, "x q[%u];\n", 15 * c14 + 3);
                                              }
                                              for (int c14 = 0; c14 <= 1; c14 += 1) {
                                                fprintf(f, "x q[%u];\n", -15 * c14 + 16);
                                              }
                                            }
                                            if (c12 == 25) {
                                              fprintf(f, "x q[%u];\n", -11 * c10 + 15);
                                            }
                                          }
                                          if (c12 == 26) {
                                            fprintf(f, "x q[%u];\n", -11 * c10 + 15);
                                            if (c10 == 0) {
                                              for (int c14 = 0; c14 <= 1; c14 += 1) {
                                                fprintf(f, "x q[%u];\n", 15 * c14 + 3);
                                              }
                                            }
                                          }
                                        }
                                      }
                                      if (c10 == 0 && c12 == 23) {
                                        fprintf(f, "x q[%u];\n", 15);
                                      }
                                      if (c12 == 23) {
                                        for (int c14 = c10; c14 <= 1; c14 += 1) {
                                          fprintf(f, "x q[%u];\n", -5 * c10 + 11 * c14 + 1);
                                        }
                                      }
                                    }
                                  }
                                  if (c10 == 0) {
                                    for (int c12 = 33; c12 <= 34; c12 += 1) {
                                      if (c12 == 34) {
                                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                                          fprintf(f, "x q[%u];\n", 9 * c14);
                                        }
                                        fprintf(f, "x q[%u];\n", 3);
                                      } else {
                                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                                          fprintf(f, "cx q[%u], q[%u];\n", -6 * c14 + 15, 3 * c14);
                                        }
                                      }
                                    }
                                  } else if (c10 == 1) {
                                    fprintf(f, "x q[%u];\n", 4);
                                  }
                                  if (c10 == 0) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 9, 10);
                                  }
                                  for (int c14 = 0; c14 <= -c10 + 1; c14 += 1) {
                                    fprintf(f, "x q[%u];\n", 16 * c10 + 15 * c14);
                                  }
                                  if (c10 == 0) {
                                    for (int c12 = 36; c12 <= 40; c12 += 1) {
                                      if (c12 == 40) {
                                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                                          fprintf(f, "cx q[%u], q[%u];\n", -6 * c14 + 9, 6 * c14 + 10);
                                        }
                                      } else if (c12 == 39) {
                                        fprintf(f, "x q[%u];\n", 3);
                                        fprintf(f, "x q[%u];\n", 4);
                                      } else if (c12 == 38) {
                                        fprintf(f, "cx q[%u], q[%u];\n", 10, 3);
                                      } else if (c12 == 37) {
                                        fprintf(f, "cx q[%u], q[%u];\n", 9, 10);
                                      } else {
                                        fprintf(f, "x q[%u];\n", 10);
                                        fprintf(f, "x q[%u];\n", 3);
                                      }
                                    }
                                    fprintf(f, "x q[%u];\n", 16);
                                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                                      fprintf(f, "x q[%u];\n", 7 * c14 + 3);
                                    }
                                    fprintf(f, "cx q[%u], q[%u];\n", 9, 10);
                                  }
                                  for (int c14 = 0; c14 <= c10; c14 += 1) {
                                    fprintf(f, "x q[%u];\n", -c10 + 4 * c14 + 10);
                                  }
                                  if (c10 == 0) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 13, 9);
                                  }
                                  if (c10 == 0) {
                                    fprintf(f, "cx q[%u], q[%u];\n", 13, 9);
                                  }
                                }
                              }
                              if (c9 == 5 && c10 == 0) {
                                for (int c14 = 0; c14 <= 1; c14 += 1) {
                                  fprintf(f, "x q[%u];\n", 5 * c14 + 14);
                                }
                                for (int c14 = 0; c14 <= 1; c14 += 1) {
                                  fprintf(f, "x q[%u];\n", 5 * c14 + 14);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                } else if (c1 == 1 && c3 == 0 && c5 == 2) {
                  for (int c14 = 0; c14 <= 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c14 + 14);
                  }
                  fprintf(f, "x q[%u];\n", 14);
                  fprintf(f, "x q[%u];\n", 14);
                  fprintf(f, "x q[%u];\n", 14);
                } else if (c1 == 1 && c3 == 1) {
                  fprintf(f, "x q[%u];\n", 0);
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    for (int c14 = 0; c14 <= -c10 + 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 16 * c10 + 15 * c14);
                    }
                    if (c10 == 0) {
                      fprintf(f, "x q[%u];\n", 0);
                    }
                  }
                } else {
                  fprintf(f, "cx q[%u], q[%u];\n", 7, 12);
                  fprintf(f, "x q[%u];\n", 7);
                  fprintf(f, "x q[%u];\n", 7);
                }
              }
            }
            if (c0 == 8 && c1 == 1 && c3 >= 1) {
              if (c3 == 1) {
                for (int c10 = -1; c10 <= 0; c10 += 1) {
                  for (int c14 = 0; c14 <= c10 + 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", -c10 + 4 * c14 + 9);
                  }
                }
                for (int c12 = 21; c12 <= 22; c12 += 1) {
                  fprintf(f, "x q[%u];\n", 3 * c12 - 53);
                }
              }
              if (c3 == 1) {
                for (int c8 = 0; c8 <= 2; c8 += 1) {
                  fprintf(f, "x q[%u];\n", 13);
                }
              }
              if (c3 == 2) {
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  if (c10 == 1) {
                    for (int c12 = 14; c12 <= 23; c12 += 1) {
                      if (c12 == 21) {
                        fprintf(f, "x q[%u];\n", 5);
                      } else {
                        if (c12 == 19) {
                          fprintf(f, "x q[%u];\n", 10);
                        } else if (c12 == 18) {
                          fprintf(f, "x q[%u];\n", 5);
                        }
                        if (c12 >= 18 && c12 <= 19) {
                          fprintf(f, "cx q[%u], q[%u];\n", -5 * c12 + 100, 14 * c12 - 249);
                        } else if (c12 == 23) {
                          fprintf(f, "x q[%u];\n", 5);
                        } else if (c12 == 22) {
                          fprintf(f, "x q[%u];\n", 5);
                        } else if (c12 == 20) {
                          fprintf(f, "x q[%u];\n", 4);
                          fprintf(f, "x q[%u];\n", 5);
                        } else if (c12 == 17) {
                          fprintf(f, "cx q[%u], q[%u];\n", 9, 3);
                          fprintf(f, "x q[%u];\n", 5);
                        } else if (c12 == 16) {
                          fprintf(f, "x q[%u];\n", 5);
                        } else if (c12 == 15) {
                          fprintf(f, "x q[%u];\n", 5);
                        } else {
                          fprintf(f, "x q[%u];\n", 5);
                        }
                      }
                    }
                  } else {
                    for (int c12 = 13; c12 <= 31; c12 += 1) {
                      if (c12 == 30) {
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c12 == 29) {
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c12 == 28) {
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c12 == 26) {
                        fprintf(f, "x q[%u];\n", 19);
                      } else if (c12 == 25) {
                        fprintf(f, "x q[%u];\n", 8);
                        fprintf(f, "x q[%u];\n", 19);
                      } else if (c12 == 24) {
                        fprintf(f, "x q[%u];\n", 19);
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c12 == 22) {
                        fprintf(f, "x q[%u];\n", 19);
                        fprintf(f, "x q[%u];\n", 5);
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c12 == 21) {
                        fprintf(f, "x q[%u];\n", 5);
                        fprintf(f, "x q[%u];\n", 19);
                        fprintf(f, "x q[%u];\n", 8);
                      } else if (c12 == 19) {
                        for (int c14 = 0; c14 <= 1; c14 += 1) {
                          fprintf(f, "x q[%u];\n", 18 * c14 + 1);
                        }
                        fprintf(f, "x q[%u];\n", 5);
                        fprintf(f, "x q[%u];\n", 8);
                      } else {
                        if (c12 == 18) {
                          fprintf(f, "x q[%u];\n", 8);
                        }
                        if ((c12 - 5) % 13 == 0) {
                          fprintf(f, "x q[%u];\n", (3 * c12 + 11) / 13);
                          if (c12 == 18) {
                            fprintf(f, "cx q[%u], q[%u];\n", 19, 1);
                          }
                        } else if (c12 == 17) {
                          fprintf(f, "x q[%u];\n", 8);
                        } else if (c12 == 16) {
                          fprintf(f, "x q[%u];\n", 8);
                        } else if ((c12 - 3) % 10 == 0) {
                          fprintf(f, "x q[%u];\n", (-3 * c12 + 119) / 10);
                          if (c12 == 23) {
                            fprintf(f, "x q[%u];\n", 8);
                            fprintf(f, "x q[%u];\n", 19);
                          }
                        } else if (c12 == 20) {
                          fprintf(f, "x q[%u];\n", 5);
                          fprintf(f, "x q[%u];\n", 19);
                        } else if (c12 == 15) {
                          fprintf(f, "x q[%u];\n", 8);
                        } else if (c12 == 14) {
                          fprintf(f, "x q[%u];\n", 8);
                        }
                      }
                    }
                  }
                }
              } else {
                for (int c9 = -1; c9 <= 4; c9 += 2) {
                  int c10 = c9 == -1 ? 0 : (c9 - 3) / 2;
                  fprintf(f, "x q[%u];\n", 16);
                }
              }
              for (int c9 = -c3 + 6; c9 <= 5; c9 += 1) {
                if (c3 == 1 && c9 == 5) {
                  fprintf(f, "x q[%u];\n", 13);
                }
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  if (c3 == 1 && c9 == 5) {
                    for (int c12 = 0; c12 <= c10; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 2 * c10 + 7 * c12 + 4);
                    }
                    if (c10 == 0) {
                      fprintf(f, "cx q[%u], q[%u];\n", 10, 3);
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c14 + 9, 3 * c14 + 3);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c14 + 6);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 7 * c14 + 6);
                      }
                      fprintf(f, "x q[%u];\n", 4);
                      fprintf(f, "x q[%u];\n", 2);
                      fprintf(f, "cx q[%u], q[%u];\n", 2, 11);
                    }
                  }
                  for (int c14 = 0; c14 <= -c10 + 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 7 * c10 + 9 * c14 + 2);
                  }
                }
                if (c3 == 1 && c9 == 5) {
                  fprintf(f, "x q[%u];\n", 16);
                }
                if (c9 == 5) {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    if (c3 == 1) {
                      for (int c12 = 0; c12 <= c10; c12 += 1) {
                        fprintf(f, "x q[%u];\n", -12 * c10 + 15 * c12 + 12);
                      }
                      for (int c12 = 0; c12 <= c10; c12 += 1) {
                        fprintf(f, "x q[%u];\n", -12 * c10 + 15 * c12 + 12);
                      }
                    }
                    for (int c12 = 0; c12 <= -c10 + 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 16 * c10 + 15 * c12);
                    }
                    if (c3 == 2 && c10 == 0) {
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "x q[%u];\n", 17);
                      fprintf(f, "cx q[%u], q[%u];\n", 5, 15);
                      fprintf(f, "x q[%u];\n", 15);
                    } else if (c3 == 1 && c10 == 0) {
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 15 * c14);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 15 * c14);
                      }
                      fprintf(f, "x q[%u];\n", 18);
                      fprintf(f, "x q[%u];\n", 18);
                    }
                  }
                } else {
                  for (int c10 = 0; c10 <= 1; c10 += 1) {
                    for (int c12 = 0; c12 <= 1; c12 += 1) {
                      fprintf(f, "x q[%u];\n", 9 * c12 + 2);
                    }
                    if (c10 == 0) {
                      fprintf(f, "cx q[%u], q[%u];\n", 18, 1);
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 17 * c14 + 1);
                      }
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "x q[%u];\n", 17 * c14 + 1);
                      }
                    }
                  }
                }
              }
              if (c3 == 2) {
                for (int c5 = 1; c5 <= 2; c5 += 1) {
                  fprintf(f, "x q[%u];\n", 16);
                }
              } else {
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 15 * c14);
                }
                for (int c14 = 0; c14 <= 1; c14 += 1) {
                  fprintf(f, "x q[%u];\n", 15 * c14);
                }
              }
            }
          }
          if (c0 == 8 && c1 == 1) {
            for (int c3 = 3; c3 <= 7; c3 += 1) {
              if (c3 == 3) {
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  for (int c14 = 0; c14 <= -c10 + 1; c14 += 1) {
                    fprintf(f, "x q[%u];\n", 7 * c10 + 9 * c14 + 2);
                  }
                }
                for (int c10 = 0; c10 <= 1; c10 += 1) {
                  for (int c12 = 0; c12 <= 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", 9 * c12 + 2);
                  }
                  for (int c12 = 0; c12 <= -c10 + 1; c12 += 1) {
                    fprintf(f, "x q[%u];\n", -2 * c10 + 9 * c12 + 2);
                  }
                }
              } else if (c3 % 2 == 0) {
                for (int c9 = 4; c9 <= 6; c9 += 2) {
                  for (int c10 = 0; c10 <= (-c9 / 2) + 3; c10 += 1) {
                    fprintf(f, "x q[%u];\n", 5 * c9 + 5 * c10 - 15);
                  }
                }
              }
            }
          }
        }
        if (c1 == 1) {
          for (int c10 = 0; c10 <= 1; c10 += 1) {
            if (c0 == 8) {
              fprintf(f, "x q[%u];\n", 5 * c10 + 5);
            }
            fprintf(f, "x q[%u];\n", c10 + 9);
            if (c10 == 0) {
              for (int c13 = 0; c13 <= -c0 + 9; c13 += 1) {
                fprintf(f, "x q[%u];\n", 4 * c0 + 10 * c13 - 27);
              }
            }
          }
        } else if (c0 == 8 && c1 == 0) {
          for (int c14 = 0; c14 <= 2; c14 += 1) {
            fprintf(f, "x q[%u];\n", 3 * c14 + 8);
          }
        } else if (c0 == 10 && c1 == 2) {
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 11 * c14);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 11 * c14);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 11 * c14);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 11 * c14);
          }
          fprintf(f, "x q[%u];\n", 0);
          fprintf(f, "x q[%u];\n", 4);
          for (int c5 = 1; c5 <= 2; c5 += 1) {
            fprintf(f, "x q[%u];\n", 4);
          }
          fprintf(f, "x q[%u];\n", 4);
        }
      } else if (c0 <= 10) {
        if (c0 == 10 && c1 == 1) {
          fprintf(f, "x q[%u];\n", 9);
        }
        if (c0 == 10 && c1 == 1) {
          fprintf(f, "x q[%u];\n", 4);
          fprintf(f, "x q[%u];\n", 4);
          fprintf(f, "cx q[%u], q[%u];\n", 0, 11);
        } else {
          if (c0 == 10) {
            fprintf(f, "x q[%u];\n", 3);
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "cx q[%u], q[%u];\n", -8 * c14 + 11, 9 * c14 + 7);
            }
            for (int c14 = 0; c14 <= 2; c14 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c14 + 3);
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 13 * c14 + 3);
            }
          }
          for (int c10 = 0; c10 <= -c0 + 10; c10 += 1) {
            if (c0 == 9) {
              for (int c12 = 0; c12 <= -c10 + 1; c12 += 1) {
                fprintf(f, "x q[%u];\n", -2 * c10 + 9 * c12 + 2);
              }
            }
            if (c10 == 0) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c0 + 9 * c14 - 43);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 5 * c0 + 9 * c14 - 43);
              }
              if (c0 == 9) {
                fprintf(f, "cx q[%u], q[%u];\n", 3, 11);
              }
            }
          }
          if (c0 == 10) {
            fprintf(f, "x q[%u];\n", 16);
          } else {
            fprintf(f, "x q[%u];\n", 0);
          }
        }
      } else {
        fprintf(f, "x q[%u];\n", 0);
      }
      if (c0 == 9 && c1 == 1) {
        for (int c3 = 0; c3 <= 1; c3 += 1) {
          fprintf(f, "x q[%u];\n", -7 * c3 + 10);
        }
      }
    }
    if (c0 <= 8 && c0 % 2 == 0) {
      if (c0 == 8) {
        for (int c14 = 0; c14 <= 1; c14 += 1) {
          fprintf(f, "x q[%u];\n", 17 * c14 + 1);
        }
        for (int c14 = 0; c14 <= 1; c14 += 1) {
          fprintf(f, "x q[%u];\n", 17 * c14 + 1);
        }
        for (int c14 = 0; c14 <= 1; c14 += 1) {
          fprintf(f, "x q[%u];\n", 17 * c14 + 1);
        }
        fprintf(f, "x q[%u];\n", 1);
        fprintf(f, "x q[%u];\n", 1);
        for (int c14 = 0; c14 <= 1; c14 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c14 + 6);
        }
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
        fprintf(f, "x q[%u];\n", 14);
      } else {
        fprintf(f, "x q[%u];\n", 16);
        fprintf(f, "x q[%u];\n", 16);
        fprintf(f, "cx q[%u], q[%u];\n", 17, 9);
        for (int c3 = 0; c3 <= 2; c3 += 1) {
          if (c3 == 1) {
            for (int c14 = 0; c14 <= 3; c14 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c14 + 3);
            }
            for (int c14 = 0; c14 <= 4; c14 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c14 + 3);
            }
            for (int c14 = 0; c14 <= 2; c14 += 1) {
              fprintf(f, "x q[%u];\n", 4 * c14 + 7);
            }
          }
          if (c3 <= 1) {
            fprintf(f, "x q[%u];\n", c3 + 6);
          } else {
            for (int c10 = -2; c10 <= 1; c10 += 1) {
              if (c10 <= 0) {
                for (int c12 = 0; c12 <= 1; c12 += 1) {
                  fprintf(f, "x q[%u];\n", -8 * c10 + c12 + 2);
                }
              }
              if (c10 <= 0) {
                if (c10 == 0) {
                  for (int c12 = 12; c12 <= 17; c12 += 1) {
                    if (c12 == 17) {
                      for (int c14 = 0; c14 <= 2; c14 += 1) {
                        fprintf(f, "x q[%u];\n", c14 + 6);
                      }
                    } else if (c12 == 16) {
                      fprintf(f, "x q[%u];\n", 8);
                    } else if (c12 == 13) {
                      fprintf(f, "x q[%u];\n", 8);
                    } else if (c12 == 12) {
                      fprintf(f, "x q[%u];\n", 8);
                    }
                  }
                }
                for (int c12 = 18; c12 <= 23; c12 += 1) {
                  if (c10 == 0 && c12 == 18) {
                    for (int c14 = 0; c14 <= 1; c14 += 1) {
                      fprintf(f, "x q[%u];\n", 8 * c14);
                    }
                  }
                  if (c12 == 18) {
                    fprintf(f, "x q[%u];\n", -3 * c10 + 13);
                    if (c10 == 0) {
                      fprintf(f, "x q[%u];\n", 6);
                    }
                  } else {
                    if (c10 == 0 && c12 == 23) {
                      fprintf(f, "x q[%u];\n", 5);
                      for (int c14 = 0; c14 <= 1; c14 += 1) {
                        fprintf(f, "cx q[%u], q[%u];\n", 4 * c14 + 13, 4 * c14 + 6);
                      }
                    } else {
                      if (c10 == 0 && c12 == 21) {
                        fprintf(f, "x q[%u];\n", 13);
                      } else {
                        if (c10 == 0 && c12 == 20) {
                          for (int c14 = 0; c14 <= 1; c14 += 1) {
                            fprintf(f, "x q[%u];\n", c14 + 5);
                          }
                        }
                        if (c12 == 20) {
                          fprintf(f, "x q[%u];\n", -3 * c10 + 8);
                        } else if (c12 == 19) {
                          fprintf(f, "x q[%u];\n", -3 * c10 + 8);
                        } else if (c10 == 0 && c12 == 22) {
                          fprintf(f, "x q[%u];\n", 5);
                          fprintf(f, "x q[%u];\n", 13);
                        }
                      }
                      if (c12 >= 21 && c12 <= 22) {
                        fprintf(f, "x q[%u];\n", -3 * c10 + 3 * c12 - 58);
                      }
                    }
                    if (c12 == 23) {
                      fprintf(f, "x q[%u];\n", -3 * c10 + 8);
                    } else if (c12 == 21) {
                      fprintf(f, "x q[%u];\n", -3 * c10 + 8);
                    } else if (c10 == 0 && c12 == 20) {
                      fprintf(f, "x q[%u];\n", 13);
                    }
                  }
                }
                if (c10 == 0) {
                  for (int c12 = 24; c12 <= 33; c12 += 1) {
                    if (c12 == 33) {
                      fprintf(f, "x q[%u];\n", 2);
                    } else if (c12 == 32) {
                      fprintf(f, "x q[%u];\n", 2);
                    } else if (c12 == 24) {
                      fprintf(f, "x q[%u];\n", 5);
                    }
                  }
                }
              } else {
                for (int c12 = 6; c12 <= 16; c12 += 5) {
                  fprintf(f, "x q[%u];\n", (-3 * c12 + 88) / 5);
                }
              }
            }
          }
        }
      }
      if (c0 == 6) {
        for (int c14 = 0; c14 <= 1; c14 += 1) {
          fprintf(f, "x q[%u];\n", 7 * c14 + 6);
        }
      }
    } else if (c0 == 7) {
      for (int c1 = 1; c1 <= 2; c1 += 1) {
        if (c1 == 1) {
          fprintf(f, "x q[%u];\n", 15);
          fprintf(f, "x q[%u];\n", 15);
        }
        for (int c4 = 0; c4 < c1; c4 += 1) {
          if (c4 == 0) {
            if (c1 == 1) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 6);
              }
            }
            for (int c14 = 0; c14 <= 1; c14 += 1) {
              fprintf(f, "x q[%u];\n", 7 * c14 + 6);
            }
            if (c1 == 2) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c14 + 6);
              }
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 11 * c14 + 6);
              }
              fprintf(f, "x q[%u];\n", 6);
              fprintf(f, "x q[%u];\n", 6);
              fprintf(f, "x q[%u];\n", 6);
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 6);
              }
            }
          } else {
            fprintf(f, "x q[%u];\n", 17);
            fprintf(f, "x q[%u];\n", 17);
            fprintf(f, "x q[%u];\n", 17);
          }
          if (c1 == 2) {
            fprintf(f, "x q[%u];\n", 11 * c4 + 6);
            if (c4 == 0) {
              for (int c14 = 0; c14 <= 1; c14 += 1) {
                fprintf(f, "x q[%u];\n", 7 * c14 + 6);
              }
            }
          }
        }
        if (c1 == 2) {
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 11 * c14 + 6);
          }
          for (int c14 = 0; c14 <= 1; c14 += 1) {
            fprintf(f, "x q[%u];\n", 4 * c14 + 13);
          }
        }
      }
    }
    if (c0 == 14) {
      fprintf(f, "x q[%u];\n", 4);
    }
  } else if (c0 % 2 == 0) {
    if (c0 == 0) {
      for (int c14 = 0; c14 <= 2; c14 += 1) {
        fprintf(f, "x q[%u];\n", 4 * c14 + 3);
      }
      for (int c14 = 0; c14 <= 2; c14 += 1) {
        fprintf(f, "x q[%u];\n", 5 * c14 + 3);
      }
    }
    fprintf(f, "x q[%u];\n", (-c0 / 2) + 8);
  }
}
fclose(f);
return 0;
}