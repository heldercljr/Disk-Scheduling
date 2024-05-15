#include "disk.h"

uint calculate_track(uint sector, uint sectors_per_track) {

	return sector / sectors_per_track;
}

double calculate_seek_time(uint current_track, uint target_track, double seek_time) {

	return abs(target_track - current_track) * seek_time;
}

double calculate_rotation_time(uint current_sector, uint target_sector, uint sectors_per_track, double rotation_time) {

	uint sectors_amount = abs(target_sector - current_sector) % sectors_per_track;

	return (double) (sectors_amount) / sectors_per_track * rotation_time;
}

double calculate_transfer_time(uint sectors_amount, uint sector_size, uint transfer_rate) {

	return ((double) (sectors_amount * sector_size) / transfer_rate * 1000);
}
