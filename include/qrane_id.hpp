#ifndef QRANE_ID_HPP
#define QRANE_ID_HPP

#include <mutex>

namespace qrane {

typedef int program_id;
typedef int statement_id;
typedef int qop_id;
typedef int qubit_id;

/*
	Singleton, thread-safe class for dealing 
	out integer ids for qubits, qops, and scops.
	We need thread-safe ids because multiple threads
	may be generating scops at the same time.

	TODO?: May need to generate UUIDs instead of 
	incremental IDs if needed in the future.
*/
class IdMachine {

public:
	program_id get_program_id() {
		std::lock_guard<std::mutex> lock(mtx_);
        program_id ret = program_id_ctr_;
        program_id_ctr_++;
        return ret;
	}

	statement_id get_statement_id() {
		std::lock_guard<std::mutex> lock(mtx_);
        statement_id ret = statement_id_ctr_;
        statement_id_ctr_++;
        return ret;
    };

	 qop_id get_qop_id() {
		std::lock_guard<std::mutex> lock(mtx_);
		qop_id ret = qop_id_ctr_;
        qop_id_ctr_++;
        return ret;
    };

    qubit_id get_qubit_id() {
		std::lock_guard<std::mutex> lock(mtx_);
    	qubit_id ret = qubit_id_ctr_;
        qubit_id_ctr_++;
        return ret;
    };

private:
	program_id program_id_ctr_;
    statement_id statement_id_ctr_; 
	qop_id qop_id_ctr_;
    qubit_id qubit_id_ctr_;
	std::mutex mtx_;

    IdMachine() {
		program_id_ctr_ = 0;
		statement_id_ctr_ = 0;
		qop_id_ctr_ = 0;
    	qubit_id_ctr_ = 0;
    };
            
    static IdMachine id_machine;
};
}

#endif
