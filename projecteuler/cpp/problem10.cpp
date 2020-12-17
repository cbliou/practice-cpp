#include "stdafx.h"

uint64_t problem10(void) {
	uint64_t sum = 2;
	for (int i = 3; i <= 2000000; i += 2) {
		if (testPrime(i)) {
			sum += i;
		}
	}

	return sum;
}