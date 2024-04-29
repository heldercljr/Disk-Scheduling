#ifndef DISK_STRUCTURES_H
#define DISK_STRUCTURES_H

typedef unsigned int uint;

typedef struct {
	uint sector_size;			// tamanho de cada setor em bytes
	uint tracks;				// número de trilhas do disco
	uint sectors_per_track;		// número de setores em cada trilha
	double seek_time;			// tempo médio de seek em milissegundos entre trilhas adjacentes
	double rotation_time;		// tempo médio de rotação em milissegundos por volta completa
	uint transfer_rate;			// taxa de transferência em bytes por segundo
} Disk;

typedef struct {
	uint track;					// número da trilha
	uint sector;				// número do setor
} Request;

#endif
