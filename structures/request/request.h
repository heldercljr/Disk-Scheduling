#ifndef REQUEST_H
#define REQUEST_H

#include <stdlib.h>

#include "../disk/disk.h"

#include "../boolean.h"
#include "../uint.h"

// Estrutura de uma requisição
typedef struct {
	uint sector;				// número do setor
	uint track;					// número da trilha
	boolean served;				// flag de atendimento
} Request;

// Cria uma requisição com base em um setor e a quantidade de setores por trilha
Request create_request(uint sector, uint sectors_per_track);

// Cria um array de requisições com base em um array de setores e a quantidade de setores por trilha
Request* create_requests(uint* sectors, uint requests_amount, uint sectors_per_track);

#endif