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

	Log* logs = create_logs(LOGS_AMOUNT);

	sstf(sequential_requests, REQUESTS_AMOUNT, current_request, disk, &logs[0]);
	sstf(random_requests, REQUESTS_AMOUNT, current_request, disk, &logs[1]);
	fcfs(sequential_requests, REQUESTS_AMOUNT, current_request, disk, &logs[2]);
	fcfs(random_requests, REQUESTS_AMOUNT, current_request, disk, &logs[3]);

	for (uint i = 0; i < LOGS_AMOUNT; i++) {

		printf("Seek: %.2fms, ", logs[i].total_seek_time);
		printf("Rotacao: %.2fms, ", logs[i].total_rotation_time);
		printf("Transferencia: %.2fms, ", logs[i].total_transfer_time);
		printf("Total: %.2fms\n", logs[i].total_io_time);
	}

	return 0;
}
