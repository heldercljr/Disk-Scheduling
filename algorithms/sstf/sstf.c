#include "sstf.h"

void sstf(Request* requests, uint requests_amount, Request current_request, Disk disk, FILE* report) {

	uint current_sector = current_request.sector;
	uint current_track = current_request.track;

	double total_seek_time = 0;
	double total_rotation_time = 0;
	double total_transfer_time = 0;
	double total_io_time;

	fprintf(report, "index,sector,track,seek,rotation,transfer,total\n");

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

		total_seek_time += calculate_seek_time(current_track, requests[minimum_index].track, disk.seek_time);
		total_rotation_time += calculate_rotation_time(current_sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		total_io_time = total_seek_time + total_rotation_time + total_transfer_time;

		fprintf(report, "%u,%u,%u,%.3f,%.3f,%.3f,%.3f\n",step, current_sector, current_track, total_seek_time, total_rotation_time, total_transfer_time,total_io_time);

		current_sector = requests[minimum_index].sector;
		current_track = requests[minimum_index].track;

		requests[minimum_index].served = True;
	}
}
