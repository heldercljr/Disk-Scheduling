#ifndef FSCAN_H
#define FSCAN_H

#include "../operations/operations.h"

#include "../../structures/request.h"

// Algoritmo de escalonamento FSCAN (Fixed SCAN)
void fscan(Request requests[], uint num_requests);

#endif
