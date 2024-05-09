#ifndef FCFS_H
#define FCFS_H

#include "../../operations/operations.h"

#include "../../structures/disk.h"
#include "../../structures/log.h"
#include "../../structures/request.h"

// Algoritmo de escalonamento FCFS (First-Come, First Served)
void fcfs(Request* requests, Request current_request, uint requests_amount, Disk disk, Log* log);

#endif
