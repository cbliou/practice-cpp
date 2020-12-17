#include "stdafx.h"

int problem4(void) {

	int largest = 0;
	for (int i = 100; i < 1000; ++i) {
		for (int j = 100; j < 1000; ++j) {
			if (determinePalindrome(i * j) && i * j > largest) {
				largest = i * j;
			}
		}
	}

	return largest;

}