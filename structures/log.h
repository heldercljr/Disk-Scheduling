#ifndef LOG_H
#define LOG_H

#include "uint.h"

typedef struct {
	uint sector;
	uint track;
	double seek_time;
	double rotation_time;
	double transfer_time;
	double io_time;
} Log;

#endif
