#include "stdafx.h"

int problem9(void) {

	// a = i
	// remain = 1000 - i
	// b = j in 1000 - i
	// c = leftovers

	for (int a = 1; a < 1000; ++a) {
		for (int b = 1; b < 1000 - a; ++b) {
			int c = 1000 - a - b;
			if (a * a + b * b == c * c) {
				return a * b * c;
			}
		}
	}

}