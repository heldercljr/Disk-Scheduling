#include "fcfs.h"

void fcfs(Request* requests, uint requests_amount, Request current_request, Disk disk, Report* report) {

	for (uint index = 0; index < requests_amount; index++) {

		Log* log = &report->logs[index];

		log->sector = requests[index].sector;
		log->track = requests[index].track;
		log->seek_time = calculate_seek_time(current_request.track, requests[index].track, disk.seek_time);
		log->seek_time = calculate_rotation_time(current_request.sector, requests[index].sector, disk.sectors_per_track, disk.rotation_time);
		log->transfer_time = calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		log->io_time = log->seek_time + log->seek_time + log->transfer_time;

		current_request.sector = requests[index].sector;
		current_request.track = requests[index].track;

		requests[index].served = True;
	}
}
