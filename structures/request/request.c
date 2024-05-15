#include "request.h"

Request* create_requests(uint* sectors, uint requests_amount, uint sectors_per_track) {

	Request* requests = (Request*) malloc(requests_amount * sizeof(Request));

	for (uint i = 0; i < requests_amount; i++) {

		requests[i].sector = sectors[i];
		requests[i].track = calculate_track(sectors[i], sectors_per_track);
		requests[i].served = False;
	}

	return requests;
}
