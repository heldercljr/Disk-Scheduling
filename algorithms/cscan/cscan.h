#ifndef CSCAN_H
#define CSCAN_H

#include "../../operations/operations.h"

#include "../../structures/disk.h"
#include "../../structures/request.h"

// Algoritmo de escalonamento CSCAN (Circular SCAN)
void cscan(uint* sectors, uint amount, uint current_sector, Disk disk);

#endif
