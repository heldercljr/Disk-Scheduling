#include "report.h"

Report* create_report(uint amount) {

	Report* report = (Report*) malloc(sizeof(Report));

	report->logs = (Log*) malloc(amount * sizeof(Log));
	report->amount = amount;

	return report;
}

void write_report(Report* report, char* filename) {

	FILE* report_file = fopen(filename, "w");

	fprintf(report_file, "index,sector,track,seek,rotation,transfer,total\n");

	for (uint index = 0; index < report->amount; index++) {

		Log log = report->logs[index];

		fprintf(report_file, "%u,%u,%u,%.3f,%.3f,%.3f,%.3f\n",index, log.sector, log.track, log.seek_time, log.rotation_time, log.transfer_time, log.io_time);
	}

	fclose(report_file);
}
