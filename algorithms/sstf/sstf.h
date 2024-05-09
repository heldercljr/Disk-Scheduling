#ifndef SSTF_H
#define SSTF_H

#include "../../operations/operations.h"

#include "../../structures/disk.h"
#include "../../structures/log.h"
#include "../../structures/request.h"

// Algoritmo de escalonamento SSTF (Shortest Seek Time First)
void sstf(Request* requests, Request current_request, uint requests_amount, Disk disk, Log* log);

#endif
