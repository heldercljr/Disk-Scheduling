#include <stdio.h>

#include "util/util.h"

int main() {

	uint t = calculate_seek_time(0, 10, 1);

	printf("Track: %u\n", t);

	return 0;
}
