#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>
#include <stdlib.h>

#include "../uint.h"

#include "../request/request.h"

// Define um registro para o relatório
typedef struct {
	uint sector;				// número do setor
	uint track;					// número da trilha
	double seek_time;			// tempo de seek
	double rotation_time;		// tempo de rotação
	double transfer_time;		// tempo de transferência
	double io_time;				// tempo total de I/O
} Record;

// Define um tipo de algoritmo de escalonamento
typedef Record* (*SchedulingAlgorithm)(Disk, Request*, uint, Request);

// Gera um relatório completo
void create_report(SchedulingAlgorithm algorithm, Disk disk, uint* sectors, uint requests_amount, Request current_request, char* filename);

#endif
