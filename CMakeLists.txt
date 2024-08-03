cmake_minimum_required(VERSION 3.10)

project(qrane-project VERSION 1.0
	                  DESCRIPTION
		              "Lifting Quantum Assembly to an Affine Intermediate Representation."
	                  LANGUAGES CXX)

# Setup Flex and Bison
find_package(BISON)
find_package(FLEX)
BISON_TARGET(QraneParser qrane_parser.y ${CMAKE_CURRENT_BINARY_DIR}/qrane_parser.c
			 DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/qrane_parser.h)
FLEX_TARGET(QraneScanner qrane_scanner.yy ${CMAKE_CURRENT_BINARY_DIR}/qrane_scanner.c)
ADD_FLEX_BISON_DEPENDENCY(QraneScanner QraneParser)

# Download and build third-party libraries.
add_subdirectory(lib)

# Setup Python
find_package(Python COMPONENTS Development REQUIRED)

# Setup qrane
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
                     src/qrane_routing.cpp
                     src/qrane_statement.cpp
		             src/qrane_utils.cpp)

target_include_directories(qrane PRIVATE src)

target_link_libraries(qrane PRIVATE barvinok)

target_compile_features(qrane PRIVATE cxx_std_17)

add_dependencies(qrane ntl-project)
add_dependencies(qrane barvinok-project)
