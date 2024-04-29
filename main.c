#include <stdio.h>

#include "operations/operations.h"

int main() {

	uint t = calculate_seek_time(0, 10, 1);

	printf("Track: %u\n", t);

	return 0;
}
