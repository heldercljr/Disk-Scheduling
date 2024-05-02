#ifndef SSTF_H
#define SSTF_H

#include "../../operations/operations.h"

#include "../../structures/disk.h"
#include "../../structures/request.h"

// Algoritmo de escalonamento SSTF (Shortest Seek Time First)
double sstf(uint* sectors, uint current_sector, Disk disk);

#endif
