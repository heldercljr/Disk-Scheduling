#ifndef SCHEDULING_H
#define SCHEDULING_H

#include "disk_structures.h"

// Calcula o tempo de seek em milissegundos entre duas trilhas
double calculate_seek_time(uint current_track, uint target_track, double seek_time);

// Calcula o tempo de rotação em milissegundos entre dois setores
double calculate_rotation_time(uint current_sector, uint target_sector, uint sectors_per_track, double rotation_time);

// Calcula o tempo de transferência em milissegundos de uma determinada quantidade de setores
double calculate_transfer_time(uint sectors, uint sector_size, uint transfer_rate);

void sstf(Disk *disk, Request *requests, unsigned int num_requests);

void fscan(Disk *disk, Request *requests, unsigned int num_requests);

void cscan(Disk *disk, Request *requests, unsigned int num_requests);

#endif