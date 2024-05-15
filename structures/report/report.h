#ifndef REPORT_H
#define REPORT_H

#include <stdlib.h>

#include "../uint.h"

typedef struct {
	uint sector;
	uint track;
	double seek_time;
	double rotation_time;
	double transfer_time;
	double io_time;
} Log;

typedef struct {
	Log* logs;
	uint amount;
} Report;

// Cria um relatório com base na quantidade de requisições
Report* create_report(uint amount);

#endif
