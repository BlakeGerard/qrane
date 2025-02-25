cmake_minimum_required(VERSION 3.14)

# Setup qrane_parser target
BISON_TARGET(qrane_parser parser/qrane_parser.y
                          ${CMAKE_CURRENT_BINARY_DIR}/qrane_parser.cc
			              DEFINES_FILE
                          ${CMAKE_CURRENT_BINARY_DIR}/qrane_parser.h)

# Setup qrane_scanner target
FLEX_TARGET(qrane_scanner parser/qrane_scanner.yy
                          ${CMAKE_CURRENT_BINARY_DIR}/qrane_scanner.cc
                          DEFINES_FILE
                          ${CMAKE_CURRENT_BINARY_DIR}/qrane_scanner.h)

ADD_FLEX_BISON_DEPENDENCY(qrane_scanner qrane_parser)

# Setup qrane executable target
add_executable(qrane qrane_driver.cpp
                     qrane_arglist.cc
                     qrane_explist.cc
                     qrane_argument.cc
                     qrane_codegen.cc
                     qrane_decl.cc
                     qrane_deps.cc
                     qrane_domain.cc
                     qrane_exp.cc
                     qrane_host.cc
                     qrane_mainprogram.cc
                     qrane_qop.cc
                     qrane_statement.cc
                     qrane_stmtlist.cc
                     qrane_utils.cc
                     "${BISON_qrane_parser_OUTPUTS}"
                     "${FLEX_qrane_scanner_OUTPUTS}")

target_include_directories(qrane PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                         ${CMAKE_CURRENT_BINARY_DIR}
                                         ${BARVINOK_SOURCE_DIR}
                                         ${Python_INCLUDE_DIRS})

target_link_libraries(qrane PRIVATE "${BARVINOK_BINARY_DIR}/lib/libbarvinok.a"
                                    "${BARVINOK_BINARY_DIR}/lib/libisl.a"
                                    "${BARVINOK_BINARY_DIR}/lib/libpolylibgmp.a"
                                    "${NTL_BINARY_DIR}/lib/libntl.a"
                                    ${Python_LIBRARIES}
                                    gmp
                                    OpenMP::OpenMP_CXX
                                    argparse)

target_compile_features(qrane PRIVATE cxx_std_17)

add_dependencies(qrane ntl-project)
add_dependencies(qrane barvinok-project)
