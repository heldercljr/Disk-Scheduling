#include "fcfs.h"

void fcfs(Request* requests, Request current_request, uint requests_amount, Disk disk, Log* log) {

	uint current_sector = current_request.sector;
	uint current_track = current_request.track;

	for (uint index = 0; index < requests_amount; index++) {

		Request request = requests[index];

		if (!request.served) {

			log->total_seek_time += calculate_seek_time(current_track, request.track, disk.seek_time);
			log->total_rotation_time += calculate_rotation_time(current_sector, request.sector, disk.sectors_per_track, disk.rotation_time);
			log->total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);

			current_sector = request.sector;
			current_track = request.track;

			request.served = True;
		}
	}

	log->total_io_time = log->total_seek_time + log->total_rotation_time + log->total_transfer_time;
}
