#include "fcfs.h"

void fcfs(Request* requests, uint requests_amount, Request current_request, Disk disk, FILE* report) {

	uint current_sector = current_request.sector;
	uint current_track = current_request.track;

	double total_seek_time = 0;
	double total_rotation_time = 0;
	double total_transfer_time = 0;
	double total_io_time;

	fprintf(report, "sector,track,seek,rotation,transfer,total\n");

	for (uint index = 0; index < requests_amount; index++) {

		total_seek_time += calculate_seek_time(current_track, requests[index].track, disk.seek_time);
		total_rotation_time += calculate_rotation_time(current_sector, requests[index].sector, disk.sectors_per_track, disk.rotation_time);
		total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		total_io_time = total_seek_time + total_rotation_time + total_transfer_time;

		fprintf(report, "%u,%u,%.3f,%.3f,%.3f,%.3f\n",current_sector, current_track, total_seek_time, total_rotation_time, total_transfer_time,total_io_time);

		current_sector = requests[index].sector;
		current_track = requests[index].track;

		requests[index].served = True;
	}
}
