#include "fcfs.h"

Record* fcfs(Disk disk, Request* requests, uint requests_amount, Request current_request) {

	Record* records = (Record*) malloc(requests_amount * sizeof(Record));

	for (uint index = 0; index < requests_amount; index++) {

		Record* record = &records[index];

		record->sector = requests[index].sector;
		record->track = requests[index].track;
		record->seek_time = calculate_seek_time(current_request.track, requests[index].track, disk.seek_time);
		record->rotation_time = calculate_rotation_time(current_request.sector, requests[index].sector, disk.sectors_per_track, disk.rotation_time);
		record->transfer_time = calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		record->io_time = record->seek_time + record->rotation_time + record->transfer_time;

		current_request.sector = requests[index].sector;
		current_request.track = requests[index].track;

		requests[index].served = True;
	}

	return records;
}
