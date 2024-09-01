# QRANE: Lifting QASM Programs to an Affine IR

Qrane is a tool that can generate an Affine IR to describe a given OpenQASM 2.0 circuit. Qrane consumes a stream of OpenQASM 2.0 gates and tries to define a set of multi-dimensional loop nests that could have generated that gate stream. The generated IR is composed of several abstractions core to the [Polyhedral Model of compilation](http://polyhedral.info/) that characterize and may be used to optimize such loop nests. Qrane can then generate a new OpenQASM 2.0 program scheduled around a given objective while respecting the dependencies of the original gate stream.

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

Let's get a simple example going by just pointing Qrane to an OpenQASM 2.0 circuit with the required `--qasm` parameter:

```
qrane --qasm example.qasm
```

Qrane will write the reconstructed iteration domains, read/write relations, and "identity" schedule that maps each point (one gate operation) in each iteration domain to its original location in the input file. It will also show a handful of "reconstruction metrics", such as a count of the number of iteration domains of varying dimensions, the number of points (gates) captured in domains of each dimensionality, and the number of domains of each cardinality. It will also print timings for different stages of reconstruction and scheduling.

We can have Qrane run its series of validations of its proposed IR with the --check flag:

```
qrane --qasm example.qasm --check
```

Before all of the aforementioned IR structures and reconstruction metrics are printed out, Qrane will run each check pass in series, stopping execution if any one check fails:

```
<snip>
Checking that all qops have been accounted for ... True
Checking that recovered schedule respects dependences ... True
Checking that all qubits have the same number of accesses ... True
Checking that control-read dependences are a subset of control-write depedence ... True
Checking for isomorphism between original and recovered dependence graphs .. True
```

By default, Qrane produces the _implicit_ schedule that maps each point of every iteration domain back to its original index in the gate stream. Four scheduling options based on different objectives are provided thanks to isl:

```
--isl                            Use isl's default scheduling algorithm.
--minfuse                        Use Pluto minfuse scheduling algorithm.
--maxfuse                        Use Pluto maxfuse scheduling algorithm.
--feautrier                      Use Feautrier's scheduling algorithm.
```

The details of the isl default scheduling approach may be found in section 1.5.3 of the isl manual. "minfuse" and "maxfuse" set specific scheduling options to isl to encourage minimal and maximal fusion of loop domains, respectively. Feautrier's multidimensional scheduling algorithm is documented in [Some efficient solutions to the affine scheduling problem Part II: Multidimensional Time](https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=e27663e907c0a1ffb35dd22078754863632d55a7).

Now that we can reconstruct and validate a possible rescheduled IR, we'd like to generate a new OpenQASM 2.0 file. We just need to direct Qrane to the filepath we want generated via the '--codegen' option:

```
qrane --qasm example.qasm --feautrier --check --codegen="new.qasm"
```

The resultant OpenQASM 2.0 program is ready for import into any other framework that reads OpenQASM 2.0 programs.

## Resources and Documentation

Qrane makes extensive use of the [Integer Set Library (isl)](https://libisl.sourceforge.io/) for its polyhedral needs. Please see the [complete isl manual](https://libisl.sourceforge.io/manual.pdf) for insight on the polyhedral compilation faculties available to Qrane.

## License

Distributed under the CC BY-SA 4.0 License. Please see `LICENSE.txt` for details.

## Contact

Blake Gerard - blake.t.gerard@gmail.com