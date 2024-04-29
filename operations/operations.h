#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "../structures/disk.h"
#include "../structures/request.h"
#include "../structures/uint.h"

// Calcula a qual trilha um setor pertence
uint calculate_track(uint sector, uint sectors_per_track);

// Calcula o tempo de seek em milissegundos entre duas trilhas
double calculate_seek_time(uint current_track, uint target_track, double seek_time);

// Calcula o tempo de rotação em milissegundos entre dois setores
double calculate_rotation_time(uint current_sector, uint target_sector, uint sectors_per_track, double rotation_time);

// Calcula o tempo de transferência em milissegundos de uma determinada quantidade de setores
double calculate_transfer_time(uint sectors, uint sector_size, uint transfer_rate);

#endif