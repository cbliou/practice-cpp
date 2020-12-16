#include "stdafx.h"
#include "util.h"

int problem12(void) {
	int start = 1;
	int itor = 2;
	while (true) {
		start += itor;
		int numdiv = getNumDivisors(start);
		if (numdiv > 500) {
			return start;
		}
		++itor;
	}
};