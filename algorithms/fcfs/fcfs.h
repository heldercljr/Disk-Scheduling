#ifndef FCFS_H
#define FCFS_H

#include "../../operations/operations.h"

#include "../../structures/disk.h"
#include "../../structures/report.h"
#include "../../structures/request.h"

// Algoritmo de escalonamento FCFS (First-Come, First Served)
void fcfs(Request* requests, uint requests_amount, Request current_request, Disk disk, Report* report);

#endif
