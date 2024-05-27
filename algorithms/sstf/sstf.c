#include "sstf.h"

Record* sstf(Disk disk, Request* requests, uint requests_amount, Request current_request) {

	Record* records = (Record*) malloc(requests_amount * sizeof(Record));

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

		Record* record = &records[step];

		record->sector = requests[minimum_index].sector;
		record->track = requests[minimum_index].track;
		record->seek_time = calculate_seek_time(current_request.track, requests[minimum_index].track, disk.seek_time);
		record->rotation_time = calculate_rotation_time(current_request.sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		record->transfer_time = calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		record->io_time = record->seek_time + record->rotation_time + record->transfer_time;

		current_request.sector = requests[minimum_index].sector;
		current_request.track = requests[minimum_index].track;

		requests[minimum_index].served = True;
	}

	return records;
}
