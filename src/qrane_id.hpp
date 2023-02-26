#ifndef QRANE_ID_HPP
#define QRANE_ID_HPP

#include <mutex>

namespace qrane {

typedef int ProgramId;
typedef int StatementId;
typedef int QopId;
typedef int QubitId;

/*
  Singleton, thread-safe class for dealing
  out integer ids for qubits, qops, and scops.
  We need thread-safe ids because multiple threads
  may be generating scops at the same time.
*/
class IdMachine {

public:
  ProgramId getProgramId() {
    std::lock_guard<std::mutex> lock(mtx_);
    return programIdCtr_++;
  }

  StatementId getStatementId() {
    std::lock_guard<std::mutex> lock(mtx_);
    return statementIdCtr_++;
  }

  QopId getQopId() {
    std::lock_guard<std::mutex> lock(mtx_);
    return qopIdCtr_++;
  }

  QubitId getQubitId() {
    std::lock_guard<std::mutex> lock(mtx_);
    return qubitIdCtr_++;
  }

private:
  ProgramId programIdCtr_{0};
  StatementId statementIdCtr_{0};
  QopId qopIdCtr_{0};
  QubitId qubitIdCtr_{0};
  std::mutex mtx_;

  static IdMachine id_machine;
};
} // namespace qrane

#endif
