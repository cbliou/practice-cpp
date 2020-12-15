#include "stdafx.h"
#include "util.h"



int problem2(void) {
	int sum = 0;
	vector<int> fib;
	generateFib(fib, 4000000);

	for (int i : fib) {
		if (i % 2 == 0) {
			sum += i;
		}
	}
	return sum;
}