#include "sstf.h"

void sstf(Request* requests, uint requests_amount, Request current_request, Disk disk, Report* report) {

	for (uint step = 0; step < requests_amount; step++) {

		uint minimum_index = 0;

		uint minimum_difference = disk.tracks;

		for (uint index = 0; index < requests_amount; index++) {

			if (!requests[index].served) {

				uint tracks_difference = abs(current_request.track - requests[index].track);

				if (tracks_difference < minimum_difference) {

					minimum_difference = tracks_difference;

					minimum_index = index;
				}
			}
		}

		Log* log = &report->logs[step];

		log->sector = requests[minimum_index].sector;
		log->track = requests[minimum_index].track;
		log->seek_time = calculate_seek_time(current_request.track, requests[minimum_index].track, disk.seek_time);
		log->rotation_time = calculate_rotation_time(current_request.sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		log->transfer_time = calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		log->io_time = log->seek_time + log->rotation_time + log->transfer_time;

		current_request.sector = requests[minimum_index].sector;
		current_request.track = requests[minimum_index].track;

		requests[minimum_index].served = True;
	}
}
