cmake_minimum_required(VERSION 3.14)

project(qrane-project VERSION 1.0
	                  DESCRIPTION
		              "Lifting Quantum Assembly to an Affine Intermediate Representation."
	                  LANGUAGES CXX)

# Find expected system packages.
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(GMP REQUIRED)
find_package(Python COMPONENTS Development REQUIRED)
find_package(OpenMP REQUIRED)
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Download and build third-party libraries.
add_subdirectory(lib)

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
add_executable(qrane src/qrane_driver.cpp
                     src/qrane_arglist.cc
                     src/qrane_explist.cc
                     src/qrane_argument.cc
                     src/qrane_codegen.cc
                     src/qrane_decl.cc
                     src/qrane_deps.cc
                     src/qrane_domain.cc
                     src/qrane_exp.cc
                     src/qrane_host.cc
                     src/qrane_mainprogram.cc
                     src/qrane_qop.cc
                     src/qrane_statement.cc
                     src/qrane_stmtlist.cc
                     src/qrane_utils.cc
                     ${BISON_qrane_parser_OUTPUTS}
                     ${FLEX_qrane_scanner_OUTPUTS})

target_include_directories(qrane PRIVATE src/
                                         ${CMAKE_CURRENT_BINARY_DIR}
                                         ${BARVINOK_SOURCE_DIR}
                                         ${Python_INCLUDE_DIRS})

target_link_libraries(qrane PRIVATE "${BARVINOK_BINARY_DIR}/lib/libbarvinok.a"
                                    "${BARVINOK_BINARY_DIR}/lib/libisl.a"
                                    "${BARVINOK_BINARY_DIR}/lib/libpolylibgmp.a"
                                    "${NTL_BINARY_DIR}/lib/libntl.a"
                                    ${Python_LIBRARIES}
                                    gmp
                                    OpenMP::OpenMP_CXX)

target_compile_features(qrane PRIVATE cxx_std_17)

add_dependencies(qrane ntl-project)
add_dependencies(qrane barvinok-project)
