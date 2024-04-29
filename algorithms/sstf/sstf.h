#ifndef SSTF_H
#define SSTF_H

#include "../operations/operations.h"

#include "../../structures/request.h"

// Algoritmo de escalonamento SSTF (Shortest Seek Time First)
void sstf(uint sectors[], uint current_sector, uint sectors_per_track);

#endif
