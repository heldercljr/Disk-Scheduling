#include "sstf.h"

void sstf(uint sectors[], uint current_sector, uint sectors_per_track, uint tracks) {

	uint amount = ARRAY_SIZE(sectors);

	Request requests[] = create_requests(sectors, amount, sectors_per_track);

	uint current_track = calculate_track(current_sector, sectors_per_track);

	uint minimum_difference = tracks;

	uint minimum_index = 0;

	for (uint index = 0; index < amount; index++) {

		uint current_difference = abs(current_track - requests[index].track);

		if (current_difference < minimum_difference) {

			minimum_difference = current_difference;

			minimum_index = index;
		}
	}

	// To do: implementar o resto do algoritmo
}
