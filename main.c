#include <stdio.h>

#include "algorithms/fcfs/fcfs.h"
#include "algorithms/sstf/sstf.h"

#define LOGS_AMOUNT 4			// quantidade de logs
#define REQUESTS_AMOUNT 1000	// quantidade de requisições

int main() {

	Disk disk = {
		.sector_size = 512,
		.tracks = 200,
		.sectors_per_track = 100,
		.seek_time = 2.0,
		.rotation_time = 3.0,
		.transfer_rate = 1000000
	};

	Request current_request = {
		.sector = 7503,			// setor atual
		.track = calculate_track(current_request.sector, disk.sectors_per_track),
		.served = True
	};

	extern uint random_numbers[REQUESTS_AMOUNT];
	extern uint sequential_numbers[REQUESTS_AMOUNT];

	Request* random_requests = create_requests(random_numbers, REQUESTS_AMOUNT, disk.sectors_per_track);
	Request* sequential_requests = create_requests(sequential_numbers, REQUESTS_AMOUNT, disk.sectors_per_track);

	FILE *sequential_sstf_report = fopen("reports/report_sstf_sequential.csv", "w");
	FILE *random_sstf_report = fopen("reports/report_sstf_random.csv", "w");
	FILE *sequential_fcfs_report = fopen("reports/report_fcfs_sequential.csv", "w");
	FILE *random_fcfs_report = fopen("reports/report_fcfs_random.csv", "w");

	sstf(sequential_requests, REQUESTS_AMOUNT, current_request, disk, sequential_sstf_report);
	sstf(random_requests, REQUESTS_AMOUNT, current_request, disk, random_sstf_report);
	fcfs(sequential_requests, REQUESTS_AMOUNT, current_request, disk, sequential_fcfs_report);
	fcfs(random_requests, REQUESTS_AMOUNT, current_request, disk, random_fcfs_report);

	fclose(sequential_sstf_report);
	fclose(random_sstf_report);
	fclose(sequential_fcfs_report);
	fclose(random_fcfs_report);

	return 0;
}
