# QRANE: Lifting QASM Programs to an Affine IR

Qrane is a tool that can generate an Affine IR to describe a given OpenQASM 2.0 circuit. Qrane consumes a stream of OpenQASM 2.0 gates and tries to define a set of multi-dimensional loop nests that could have generated that gate stream. The generated IR is composed of several abstractions core to the [Polyhedral Model of compilation](http://polyhedral.info/) that characterize and potentially optimize such loop nests. Qrane may then use its Affine IR to deliver a newly scheduled OpenQASM 2.0 gate stream based around some objective.

For a closer look at our methodology, please see our paper from *Compiler Construction 2022*: https://dl.acm.org/doi/10.1145/3497776.3517775

## Installation

### Prerequisites

Qrane's primary dependency is on the [Integer Set Library (isl)](https://libisl.sourceforge.io/), which the build system is configured to procure through the installation of the [barvinok library](https://barvinok.sourceforge.io/). Barvinok and isl use the [NTL library](https://libntl.org/), which the build system will fetch automatically and build with [GMP](https://gmplib.org/) support, which is a required system dependency.

Qrane uses GNU [Bison](https://www.gnu.org/software/bison/) and [Flex](https://ftp.gnu.org/old-gnu/Manuals/flex-2.5.4/html_mono/flex.html) for parsing OpenQASM 2.0 programs.

Qrane uses [OpenMP](https://www.openmp.org/) for parallelization of its delinearization process.

Qrane currently uses the Python3 C API for its most thorough delinearization validation pass. It relies on the Python [networkx](https://networkx.org/documentation/stable/index.html) library (minimum version 3.2).

### Build

With the repository cloned, Qrane follows a [standard CMake build process](https://cmake.org/cmake/help/latest/manual/cmake.1.html). From the top-level directory of the repository, to build the Qrane executable and its dependencies in a specified subdirectory:

```
mkdir <dir>
cmake -B <dir>
cmake --build <dir> [-- <build-tool-options>]
```

## Usage

### Getting Started - Executable

Let's get a simple example going by just pointing Qrane to an OpenQASM 2.0 circuit with the required `--qasm` parameter:

```
qrane --qasm examples/example.qasm
```

Qrane will write the reconstructed iteration domains, read/write relations, and "identity" schedule that maps each point (one gate operation) in each iteration domain to its original location in the input file. It will also show a handful of "reconstruction metrics", such as a count of the number of iteration domains of varying dimensions, the number of points (gates) captured in domains of each dimensionality, and the number of domains of each cardinality. It will also print timings for different stages of reconstruction and scheduling.

### Getting Started - Library

First, include the "qrane.h" header in your program, which is located in the "src/" directory.

```
void qrane_options_init(qrane_options* opt);
int qrane_options_check(qrane_options* opt);
void qrane_options_free(qrane_options* opt);
void print_qrane_options(qrane_options* opt);
qrane_output_scop* qrane_driver(int argc, char* argv[],
								qrane_options* opt);
```

## Resources and Documentation

Qrane makes extensive use of the [Integer Set Library (isl)](https://libisl.sourceforge.io/) for its polyhedral needs. Please see the [complete isl manual](https://libisl.sourceforge.io/manual.pdf) for insight on the polyhedral compilation faculties available to Qrane, thanks to isl.

## License

Distributed under the CC BY-SA 4.0 License. Please see `LICENSE.txt` for details.

## Contact

Blake Gerard - blake.t.gerard@gmail.com