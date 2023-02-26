cmake_minimum_required(VERSION 3.10)

project(Qrane VERSION 1.0
	      DESCRIPTION
		"Lifting Quantum Assembly to an Affine Intermediate Representation."
	      LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


# Setup Flex and Bison
find_package(BISON)
find_package(FLEX)
BISON_TARGET(QraneParser qrane_parser.y ${CMAKE_CURRENT_BINARY_DIR}/qrane_parser.c
			 DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/qrane_parser.h)
FLEX_TARGET(QraneScanner qrane_scanner.yy ${CMAKE_CURRENT_BINARY_DIR}/qrane_scanner.c)
ADD_FLEX_BISON_DEPENDENCY(QraneScanner QraneParser)

# Setup NTL
find_library(NTL_LIB ntl
		     PATHS "${CMAKE_SOURCE_DIR}/lib/ntl/lib")
		     
find_path(NTL_INC config.h
	             PATHS "${CMAKE_SOURCE_DIR}/lib/ntl/include/NTL")

# Setup Barvinok
find_library(BARVINOK_LIB barvinok
			  PATHS "${CMAKE_SOURCE_DIR}/lib/barvinok/lib")

find_path(BARVINOK_INC barvinok.h
		       PATHS "${CMAKE_SOURCE_DIR}/lib/barvinok/include/barvinok")

# Setup Python
find_package(Python COMPONENTS Development REQUIRED)

# Setup Qrane
add_executable(qrane src/qrane_argument.cpp
		     src/qrane_codegen.cpp
		     src/qrane_decl.cpp
		     src/qrane_dependence_profile.cpp
		     src/qrane_driver.cpp # Main
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

target_link_libraries(qrane PRIVATE "${NTL_LIB}")
target_include_directories(qrane PRIVATE "${NTL_INC}")

target_link_libraries(qrane PRIVATE "${BARVINOK_LIB}")
target_include_directories(qrane PRIVATE "${BARVINOK_INC}")

target_link_libraries(qrane PRIVATE "${Python_LIBRARIES}")
target_include_directories(qrane PRIVATE "${Python_INCLUDE_DIRS}")
