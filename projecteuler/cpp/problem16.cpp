#include "stdafx.h"

int problem16(void) {
	ubigint two("2");
	int sum = 0;

	// let's implement exponentiation sometime..
	for (unsigned int i = 0; i < 999; ++i) {
		two = two * ubigint("2");
	}

	return two.sumDigits();

}