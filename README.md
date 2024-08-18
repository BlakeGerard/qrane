# QRANE: Lifting QASM Programs to an Affine IR

This project 

## Installation

### Prerequisites

### Build

## Usage

### Getting Started - Executable

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