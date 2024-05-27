#ifndef FCFS_H
#define FCFS_H

#include "../operations.h"

// Algoritmo de escalonamento FCFS (First-Come, First Served)
Record* fcfs(Disk disk, Request* requests, uint requests_amount, Request current_request);

#endif
