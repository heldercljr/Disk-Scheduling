#ifndef CSCAN_H
#define CSCAN_H

#include "../operations/operations.h"

#include "../../structures/request.h"

// Algoritmo de escalonamento CSCAN (Circular SCAN)
void cscan(Request requests[], uint num_requests);

#endif
