#ifndef REQUEST_H
#define REQUEST_H

#include "uint.h"

// Estrutura de uma requisição
typedef struct {
	uint track;					// número da trilha
	uint sector;				// número do setor
} Request;

#endif