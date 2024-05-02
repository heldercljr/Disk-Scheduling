#ifndef REQUEST_H
#define REQUEST_H

#include "boolean.h"
#include "uint.h"

// Estrutura de uma requisição
typedef struct {
	uint sector;				// número do setor
	uint track;					// número da trilha
	boolean served;				// flag de atendimento
} Request;

#endif