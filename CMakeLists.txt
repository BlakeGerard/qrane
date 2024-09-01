cmake_minimum_required(VERSION 3.14)

project(qrane-project VERSION 1.0
	                  DESCRIPTION
		              "Lifting Quantum Assembly to an Affine Intermediate Representation."
	                  LANGUAGES CXX)

# Find required system packages.
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(GMP REQUIRED)
find_package(Python COMPONENTS Development REQUIRED)
find_package(OpenMP REQUIRED)
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Download and build third-party libraries.
add_subdirectory(deps)

# Build qrane executable.
add_subdirectory(src)
