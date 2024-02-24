cmake_minimum_required(VERSION 3.14)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

include(ExternalProject)

ExternalProject_Add(
    ntl-project
    
    GIT_REPOSITORY https://github.com/libntl/ntl.git
    GIT_TAG v11.5.1

    CONFIGURE_COMMAND cd <SOURCE_DIR>/src/ && ./configure PREFIX=<BINARY_DIR> NTL_GMP_LIP=on NTL_THREADS=on NTL_THREAD_BOOST=on NTL_STD_CXX11=on
    BUILD_COMMAND cd <SOURCE_DIR>/src/ && $(MAKE)
    INSTALL_COMMAND cd <SOURCE_DIR>/src/ && $(MAKE) install
)

ExternalProject_Get_Property(ntl-project BINARY_DIR)
set(NTL_INSTALL_PATH ${BINARY_DIR})
set(NTL_INC_PATH ${NTL_INSTALL}/include/NTL)
set(NTL_LIB_PATH ${NTL_INSTALL}/lib)

ExternalProject_Add(
    barvinok-project

    GIT_REPOSITORY https://repo.or.cz/barvinok.git
    GIT_TAG barvinok-0.41.7

    CONFIGURE_COMMAND cd <SOURCE_DIR> && ./get_submodules.sh && sh autogen.sh && ./configure --prefix=<BINARY_DIR> --with-ntl-prefix=${NTL_INSTALL_PATH}
    BUILD_COMMAND cd <SOURCE_DIR> && $(MAKE)
    INSTALL_COMMAND cd <SOOURCE_DIR> && $(MAKE) install
)

