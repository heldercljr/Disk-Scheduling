#include <stdio.h>

#include "algorithms/fcfs/fcfs.h"
#include "algorithms/sstf/sstf.h"

#define REQUESTS_AMOUNT 1000	// quantidade de requisições

int main() {

	Disk disk = create_disk(512, 200, 100, 2.0, 3.0, 1000000);

	extern uint random_sectors[REQUESTS_AMOUNT];
	extern uint sequential_sectors[REQUESTS_AMOUNT];

	Request current_request = create_request(7503, disk.sectors_per_track);

	create_report(fcfs, disk, random_sectors, REQUESTS_AMOUNT, current_request, "reports/random_fcfs_report.csv");
	create_report(sstf, disk, random_sectors, REQUESTS_AMOUNT, current_request, "reports/random_sstf_report.csv");
	create_report(fcfs, disk, sequential_sectors, REQUESTS_AMOUNT, current_request, "reports/sequential_fcfs_report.csv");
	create_report(sstf, disk, sequential_sectors, REQUESTS_AMOUNT, current_request, "reports/sequential_sstf_report.csv");

	return 0;
}
