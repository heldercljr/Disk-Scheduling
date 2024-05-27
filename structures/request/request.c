#include "request.h"

Request create_request(uint sector, uint sectors_per_track) {

	uint track = calculate_track(sector, sectors_per_track);

	Request request = { sector, track, False };

	return request;
}

Request* create_requests(uint* sectors, uint requests_amount, uint sectors_per_track) {

	Request* requests = (Request*) malloc(requests_amount * sizeof(Request));

	for (uint index = 0; index < requests_amount; index++) {

		requests[index] = create_request(sectors[index], sectors_per_track);
	}

	return requests;
}
