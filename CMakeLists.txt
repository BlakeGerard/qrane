cmake_minimum_required(VERSION 3.12)

project(qrane-project VERSION 1.0
	                  DESCRIPTION
		              "Lifting Quantum Assembly to an Affine Intermediate Representation."
	                  LANGUAGES CXX)

# Find expected system packages.
find_package(Python COMPONENTS Development REQUIRED)
find_package(OpenMP REQUIRED)
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Download and build third-party libraries.
add_subdirectory(lib)

# Setup qrane_parser target
set(PARSER_OUTPUTS_DIR "${CMAKE_CURRENT_BINARY_DIR}/parser")
file(MAKE_DIRECTORY "${PARSER_OUTPUTS_DIR}")
BISON_TARGET(qrane_parser parser/qrane_parser.y
                          ${PARSER_OUTPUTS_DIR}/qrane_parser.c
			              DEFINES_FILE
                          ${PARSER_OUTPUTS_DIR}/qrane_parser.h)

# Setup qrane_lexer target
FLEX_TARGET(qrane_scanner parser/qrane_scanner.yy
                          ${PARSER_OUTPUTS_DIR}/qrane_scanner.c)

ADD_FLEX_BISON_DEPENDENCY(qrane_scanner qrane_parser)

# Setup qrane target
add_executable(qrane src/qrane_argument.cpp
		             src/qrane_codegen.cpp
		             src/qrane_decl.cpp
		             src/qrane_dependence_profile.cpp
		             src/qrane_driver.cpp
		             src/qrane_element.cpp
		             src/qrane_host.cpp
		             src/qrane_parameter.cpp
		             src/qrane_program.cpp
		             src/qrane_qop.cpp
		             src/qrane_reg.cpp
                     #src/qrane_routing.cpp
                     src/qrane_statement.cpp
		             src/qrane_utils.cpp
                     ${BISON_qrane_parser_OUTPUTS}
                     ${FLEX_qrane_scanner_OUTPUTS})

target_include_directories(qrane PRIVATE
                                 src/
                                 ${PARSER_OUTPUTS_DIR}
                                 ${Python_INCLUDE_DIRS})

target_link_libraries(qrane PUBLIC
                            OpenMP::OpenMP_CXX
                            PRIVATE
                            barvinok)

target_compile_features(qrane PRIVATE
                              cxx_std_17)

add_dependencies(qrane ntl-project)
add_dependencies(qrane barvinok-project)
