#include "sstf.h"

void sstf(Request* requests, Request current_request, uint requests_amount, Disk disk, Log* log) {

	uint current_sector = current_request.sector;
	uint current_track = current_request.track;

	for (uint step = 0; step < requests_amount; step++) {

		uint minimum_index = 0;

		uint minimum_difference = disk.tracks;

		for (uint index = 0; index < requests_amount; index++) {

			if (!requests[index].served) {

				uint tracks_difference = abs(current_track - requests[index].track);

				if (tracks_difference < minimum_difference) {

					minimum_difference = tracks_difference;

					minimum_index = index;
				}
			}
		}

		log->total_seek_time += calculate_seek_time(current_track, requests[minimum_index].track, disk.seek_time);
		log->total_rotation_time += calculate_rotation_time(current_sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		log->total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);

		current_sector = requests[minimum_index].sector;
		current_track = requests[minimum_index].track;

		requests[minimum_index].served = True;
	}

	log->total_io_time = log->total_seek_time + log->total_rotation_time + log->total_transfer_time;
}
