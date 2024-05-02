#include "sstf.h"

double sstf(uint* sectors, uint amount, uint current_sector, Disk disk) {

	Request* requests = create_requests(sectors, amount, disk.sectors_per_track);

	uint current_track = calculate_track(current_sector, disk.sectors_per_track);

	double total_time = 0.0;

	for (uint step = 0; step < amount; step++) {

		uint minimum_index = 0;

		uint minimum_difference = disk.tracks;

		for (uint index = 0; index < amount; index++) {

			if (!requests[index].served) {

				uint current_difference = abs(current_track - requests[index].track);
				printf("Indice: %d\n", index);
				printf("Diferenca minima: %d\n", minimum_difference);
				printf("Trilha atual: %d\n", current_track);
				printf("Trilha solicitada: %d\n", requests[index].track);
				printf("Diferenca: %d\n\n", current_difference);

				if (current_difference < minimum_difference) {

					minimum_difference = current_difference;

					minimum_index = index;
				}
			}
		}

		total_time += calculate_seek_time(current_track, requests[minimum_index].track, disk.seek_time);
		// printf("Tempo de seek: %.2f ms\n", total_time);
		total_time += calculate_rotation_time(current_sector, requests[minimum_index].sector, disk.sectors_per_track, disk.rotation_time);
		// printf("Tempo de rotacao: %.2f ms\n", total_time);
		total_time += calculate_transfer_time(1, disk.sector_size, disk.transfer_rate);
		// printf("Tempo de transferencia: %.2f ms\n", total_time);

		current_track = requests[minimum_index].track;

		requests[minimum_index].served = True;
	}

	free(requests);

	return total_time;
}
