#ifndef DISK_H
#define DISK_H

#include <math.h>

#include "../uint.h"

// Estrutura de um disco
typedef struct {
	uint sector_size;			// tamanho de cada setor em bytes
	uint tracks;				// número de trilhas do disco
	uint sectors_per_track;		// número de setores em cada trilha
	double seek_time;			// tempo médio de seek em milissegundos entre trilhas adjacentes
	double rotation_time;		// tempo médio de rotação em milissegundos por volta completa
	uint transfer_rate;			// taxa de transferência em bytes por segundo
} Disk;

// Calcula a trilha de um setor com base na quantidade de setores por trilha
uint calculate_track(uint sector, uint sectors_per_track);

// Calcula o tempo de seek em milissegundos entre duas trilhas
double calculate_seek_time(uint current_track, uint target_track, double seek_time);

// Calcula o tempo de rotação em milissegundos entre dois setores
double calculate_rotation_time(uint current_sector, uint target_sector, uint sectors_per_track, double rotation_time);

// Calcula o tempo de transferência em milissegundos de uma determinada quantidade de setores
double calculate_transfer_time(uint sectors, uint sector_size, uint transfer_rate);

#endif
