#ifndef QRANE_CTR_H
#define QRANE_CTR_H

// Count the number of reconstructed domains.
// This variable is updated in a critical section by
// subcircuit processing threads.
extern unsigned int num_domains;

#endif