#include "sstf.h"

double sstf(uint* sectors, uint sectors_amount, uint current_sector, Disk disk) {

	Request* requests = create_requests(sectors, sectors_amount, disk.sectors_per_track);

	uint current_track = calculate_track(current_sector, disk.sectors_per_track);

	double total_seek_time = 0.0;

	double total_rotation_time = 0.0;

	double total_transfer_time = 0.0;

	for (uint step = 0; step < sectors_amount; step++) {

		uint minimum_index = 0;

		uint minimum_difference = disk.tracks;

		for (uint index = 0; index < sectors_amount; index++) {

			Request request = requests[index];

			if (!request.served) {

				uint tracks_difference = abs(current_track - request.track);

				if (tracks_difference < minimum_difference) {

					minimum_difference = tracks_difference;

					minimum_index = index;
				}
			}
		}

		total_seek_time += calculate_seek_time(current_track, requests[minimum_index].track, disk.seek_time);
		total_rotation_time += calculate_rotation_time(current_sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);

		current_track = requests[minimum_index].track;

		requests[minimum_index].served = True;
	}

	free(requests);

	return total_seek_time + total_rotation_time + total_transfer_time;
}
