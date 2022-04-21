#ifndef QRANE_CTR_H
#define QRANE_CTR_H

// Count the number of reconstructed domains.
// This variable is updated in a critical section by 
// subcircuit processing threads.
extern unsigned int num_domains;

#include "omp.h"

namespace qrane {

    typedef int qubit_id;
    typedef int qop_id;
    typedef int domain_id;

    class IdMachine {
        private:
            qubit_id qubit_id_ctr_;
            qop_id qop_id_ctr_;
            domain_id domain_id_ctr_; 

            IdMachine() {
                qubit_id_ctr_ = 0;
                qop_id_ctr_ = 0;
                domain_id_ctr_ = 0;
            };
            
            static IdMachine id_machine;

        public:

            qubit_id get_qubit_id() {
                #pragma omp critical 
                {
                    qubit_id ret = qubit_id_ctr_;
                    qubit_id_ctr_++;
                    return ret;
                }
            };

            qop_id get_qop_id() {
                #pragma omp critical 
                {
                    qop_id ret = qop_id_ctr_;
                    qop_id_ctr_++;
                    return ret;
                }
            };

            domain_id get_domain_id() {
                #pragma omp critical 
                {
                    domain_id ret = domain_id_ctr_;
                    domain_id_ctr_++;
                    return ret;
                }
            };
    };
}



#endif