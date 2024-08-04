cmake_minimum_required(VERSION 3.14)

include(ExternalProject)
include(CMakePrintHelpers)

ExternalProject_Add(
    ntl-project
    
    GIT_REPOSITORY https://github.com/libntl/ntl.git
    GIT_TAG v11.5.1

    UPDATE_COMMAND ""
    CONFIGURE_COMMAND cd <SOURCE_DIR>/src/
                      && ./configure
                      PREFIX=<BINARY_DIR>
                      NTL_GMP_LIP=on
                      NTL_THREADS=on
                      NTL_THREAD_BOOST=on
    BUILD_COMMAND cd <SOURCE_DIR>/src/ && $(MAKE)
    INSTALL_COMMAND cd <SOURCE_DIR>/src/ && $(MAKE) install
)

ExternalProject_Get_Property(ntl-project BINARY_DIR)
set(NTL_INSTALL_PATH ${BINARY_DIR})
set(NTL_INC_PATH ${NTL_INSTALL_PATH}/include/NTL)
set(NTL_LIB_PATH ${NTL_INSTALL_PATH}/lib)

set(POLYLIB_CFLAGS "-Wno-implicit-function-declaration -Wno-int-conversion")
ExternalProject_Add(
    barvinok-project

    GIT_REPOSITORY https://repo.or.cz/barvinok.git
    GIT_TAG barvinok-0.41.6

    UPDATE_COMMAND ""
    CONFIGURE_COMMAND cd <SOURCE_DIR>
                      && <SOURCE_DIR>/get_submodules.sh
                      && <SOURCE_DIR>/autogen.sh
                      COMMAND <SOURCE_DIR>/configure
                      --prefix=<BINARY_DIR>
                      --with-ntl-prefix=${NTL_INSTALL_PATH}
                      "CFLAGS=${CMAKE_C_FLAGS} ${POLYLIB_CFLAGS}"
    BUILD_COMMAND $(MAKE)
    INSTALL_COMMAND $(MAKE) install
)

ExternalProject_Get_Property(barvinok-project SOURCE_DIR)
SET(BARVINOK_SOURCE_DIR "${SOURCE_DIR}" CACHE INTERNAL "barvinok source dir")

add_dependencies(barvinok-project ntl-project)
