#include "fcfs.h"

void fcfs(Request* requests, uint requests_amount, Request current_request, Disk disk, Log* log) {

	uint current_sector = current_request.sector;
	uint current_track = current_request.track;

	for (uint index = 0; index < requests_amount; index++) {

		log->total_seek_time += calculate_seek_time(current_track, requests[index].track, disk.seek_time);
		log->total_rotation_time += calculate_rotation_time(current_sector, requests[index].sector, disk.sectors_per_track, disk.rotation_time);
		log->total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);

		current_sector = requests[index].sector;
		current_track = requests[index].track;

		requests[index].served = True;
	}

	log->total_io_time = log->total_seek_time + log->total_rotation_time + log->total_transfer_time;
}
