#include "fcfs.h"

void fcfs(Request* requests, uint requests_amount, Request current_request, Disk disk, FILE* report) {

	double total_seek_time = 0;
	double total_rotation_time = 0;
	double total_transfer_time = 0;
	double total_io_time;

	fprintf(report, "index,sector,track,seek,rotation,transfer,total\n");

	for (uint index = 0; index < requests_amount; index++) {

		total_seek_time += calculate_seek_time(current_request.track, requests[index].track, disk.seek_time);
		total_rotation_time += calculate_rotation_time(current_request.sector, requests[index].sector, disk.sectors_per_track, disk.rotation_time);
		total_transfer_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		total_io_time = total_seek_time + total_rotation_time + total_transfer_time;

		fprintf(report, "%u,%u,%u,%.3f,%.3f,%.3f,%.3f\n",index, current_request.sector, current_request.track, total_seek_time, total_rotation_time, total_transfer_time,total_io_time);

		current_request.sector = requests[index].sector;
		current_request.track = requests[index].track;

		requests[index].served = True;
	}
}
