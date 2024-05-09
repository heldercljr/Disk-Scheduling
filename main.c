#include <stdio.h>

#include "algorithms/sstf/sstf.h"

#define REQUESTS_AMOUNT 1000		// quantidade de requisições

int main() {

	Disk disk = {
		.sector_size = 512,			// bytes
		.tracks = 200,				// total de trilhas
		.sectors_per_track = 100,	// setores por trilha
		.seek_time = 2.0,			// ms
		.rotation_time = 3.0,		// ms
		.transfer_rate = 1000000	// bytes/s (1 MB/s no exemplo)
	};

	Log log = {
		.number_of_requests = REQUESTS_AMOUNT,
		.total_seek_time = 0, 		// ms
		.total_rotation_time = 0,	// ms
		.total_transfer_time = 0,	// ms
		.total_io_time = 0			// ms
	};

	extern uint random_numbers[REQUESTS_AMOUNT];
	extern uint sequential_numbers[REQUESTS_AMOUNT];

	Request* requests = create_requests(sequential_numbers, REQUESTS_AMOUNT, disk.sectors_per_track);

	Request current_request = {
		.sector = 7503,				// setor atual
		.track = calculate_track(current_request.sector, disk.sectors_per_track),
		.served = True
	};

	sstf(requests, current_request, REQUESTS_AMOUNT, disk, &log);

	printf("Tempo total de seek: %.2f ms\n", log.total_seek_time);
	printf("Tempo total de rotacao: %.2f ms\n", log.total_rotation_time);
	printf("Tempo total de transferencia: %.2f ms\n", log.total_transfer_time);
	printf("Tempo total: %.2f ms\n", log.total_io_time);

	return 0;
}
