#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "scheduling.h"

double calculate_seek_time(uint current_track, uint target_track, double seek_time) {

	return fabs(target_track - current_track) * seek_time;
}

double calculate_rotation_time(uint current_sector, uint target_sector, uint sectors_per_track, double rotation_time) {

	uint sectors = abs(target_sector - current_sector) % sectors_per_track;

	return (sectors / sectors_per_track) * rotation_time;
}

double calculate_transfer_time(uint sectors, uint sector_size, uint transfer_rate) {

	return (sectors * sector_size) / transfer_rate;
}

void sstf(Disk *disk, Request *requests, uint num_requests) {

}

void fscan(Disk *disk, Request *requests, uint num_requests) {

}

void cscan(Disk *disk, Request *requests, uint num_requests) {

}
