#ifndef FSCAN_H
#define FSCAN_H

#include "../../operations/operations.h"

#include "../../structures/disk.h"
#include "../../structures/request.h"

// Algoritmo de escalonamento FSCAN (Fixed SCAN)
void fscan(uint* sectors, uint amount, uint current_sector, Disk disk);

#endif
