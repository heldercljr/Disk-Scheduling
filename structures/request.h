#ifndef REQUEST_H
#define REQUEST_H

#include "boolean.h"
#include "uint.h"

// Estrutura de uma requisição
typedef struct {
	uint track;					// número da trilha
	uint sector;				// número do setor
	boolean served;				// flag de atendimento
} Request;

#endif