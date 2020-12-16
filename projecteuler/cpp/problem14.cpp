#include "stdafx.h"

int problem14(void) {
	int largest = 0;
	int ans = 0;
	for (uint64_t i = 1; i < 1000000; ++i) {
		int chain = 1;
		uint64_t j = i;
		while (j != 1) {
			if (j % 2 == 0) {
				j = j / 2;
			}
			else {
				j = 3 * j + 1;
			}
			++chain;
		}
		
		if (chain > largest) {
			ans = i;
			largest = chain;
		}
	}
	return ans;
}