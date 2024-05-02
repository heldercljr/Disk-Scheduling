#include <stdio.h>

#include "algorithms/sstf/sstf.h"

int main() {

	Disk disk = {
		.sector_size = 512, // bytes
		.tracks = 200,
		.sectors_per_track = 100,
		.seek_time = 5.0, // ms
		.rotation_time = 3.0, // ms
		.transfer_rate = 1000000 // bytes/s (1 MB/s no exemplo)
	};

	uint sectors[] = {9, 85, 419, 8573, 312, 25, 17422, 17590, 37, 8599};

	uint current_sector = 100;

	double total_time = sstf(sectors, current_sector, disk);

	printf("Tempo total: %.2f ms\n", total_time);

	return 0;
}
