#ifndef SSTF_H
#define SSTF_H

#include "../../structures/request.h"

// Algoritmo de escalonamento SSTF (Shortest Seek Time First)
void sstf(Request requests[], uint num_requests);

#endif
