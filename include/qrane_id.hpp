#ifndef QRANE_ID_H
#define QRANE_ID_H

#include <mutex>

// Count the number of reconstructed domains.
// This variable is updated in a critical section by 
// subcircuit processing threads.
extern unsigned int num_domains;

namespace qrane {

typedef int qubit_id;
typedef int qop_id;
typedef int scop_id;

/*
	Singleton, thread-safe class for dealing 
	out integer ids for qubits, qops, and scops.
	We need thread-safe ids because multiple threads
	may be generating scops at the same time.
*/
class IdMachine {

public:
    qubit_id get_qubit_id() {
		std::lock_guard<std::mutex> lock(mtx_);
    	qubit_id ret = qubit_id_ctr_;
        qubit_id_ctr_++;
        return ret;
    };

    qop_id get_qop_id() {
		std::lock_guard<std::mutex> lock(mtx_);
		qop_id ret = qop_id_ctr_;
        qop_id_ctr_++;
        return ret;
    };

    scop_id get_scop_id() {
		std::lock_guard<std::mutex> lock(mtx_);
        scop_id ret = scop_id_ctr_;
        scop_id_ctr_++;
        return ret;
    };

private:
    qubit_id qubit_id_ctr_;
    qop_id qop_id_ctr_;
    scop_id scop_id_ctr_; 
	std::mutex mtx_;

    IdMachine() {
    	qubit_id_ctr_ = 0;
        qop_id_ctr_ = 0;
        scop_id_ctr_ = 0;
		mtx_ = std::mutex();
    };
            
    static IdMachine id_machine;
};
}

#endif