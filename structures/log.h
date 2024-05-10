#ifndef LOG_H
#define LOG_H

#include "uint.h"

typedef struct {
	uint requests_amount;
	double total_seek_time;
	double total_rotation_time;
	double total_transfer_time;
	double total_io_time;
} Log;

#endif
