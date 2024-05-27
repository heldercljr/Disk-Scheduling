#include "report.h"

void create_report(SchedulingAlgorithm algorithm, Disk disk, uint* sectors, uint requests_amount, Request current_request, char* filename) {

	Request* requests = create_requests(sectors, requests_amount, disk.sectors_per_track);

	Record* records = algorithm(disk, requests, requests_amount, current_request);

	free(requests);

	FILE* report_file = fopen(filename, "w");

	fprintf(report_file, "index,sector,track,seek,rotation,transfer,total\n");

	for (uint index = 0; index < requests_amount; index++) {

		Record* record = &records[index];

		fprintf(report_file, "%u,%u,%u,%.3f,%.3f,%.3f,%.3f\n",index, record->sector, record->track, record->seek_time, record->rotation_time, record->transfer_time, record->io_time);
	}

	fclose(report_file);
}
