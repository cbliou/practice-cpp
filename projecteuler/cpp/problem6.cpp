#include "stdafx.h"

int problem6(void) {
	int sus = 0;
	int sqs = 0;

	for (int i = 1; i <= 100; ++i) {
		sus += i * i;
		sqs += i;
	}

	return sqs * sqs - sus;
}