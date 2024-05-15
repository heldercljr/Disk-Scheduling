#ifndef SSTF_H
#define SSTF_H

#include "../../operations.h"

// Algoritmo de escalonamento SSTF (Shortest Seek Time First)
void sstf(Request* requests, uint requests_amount, Request current_request, Disk disk, Report* report);

#endif
