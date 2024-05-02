#include "sstf.h"

double sstf(uint* sectors, uint current_sector, Disk disk) {

	uint amount = sizeof(sectors) / sizeof((sectors)[0]);

	Request* requests = create_requests(sectors, amount, disk.sectors_per_track);

	uint current_track = calculate_track(current_sector, disk.sectors_per_track);

	uint minimum_difference = disk.tracks;

	uint minimum_index = 0;

	double total_time = 0.0;

	for (uint step = 0; step < amount; step++) {

		for (uint index = 0; index < amount; index++) {

			if (requests[index].served == False) {

				uint current_difference = abs(current_track - requests[index].track);

				if (current_difference < minimum_difference) {

					minimum_difference = current_difference;

					minimum_index = index;
				}
			}

			current_track = requests[minimum_index].track;
		}

		total_time += calculate_seek_time(current_track, requests[minimum_index].track, disk.seek_time);
		total_time += calculate_rotation_time(current_sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		total_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);

		requests[minimum_index].served = True;
	}

	free(requests);

	return total_time;
}
