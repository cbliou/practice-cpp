#include "stdafx.h"

int problem3() {

	unsigned long long a = 600851475143;
	int largest = 1;
	for (int odd = 3; odd < a / 3; odd += 2) {
		while (a % odd == 0) {
			a /= odd;
			largest = odd;// > largest ? odd : largest;
		}
	}

	return a > largest ? a : largest;

}