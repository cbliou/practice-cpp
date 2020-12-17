#include "stdafx.h"

// test odds only
int problem7(int numPrime) {
	int foundPrimes = 1;
	int test = 3;
	while (true) {
		
		if (testPrime(test)) {
			foundPrimes += 1;
		}
		if (foundPrimes == numPrime) {
			return test;
		}
		test += 2;
	}
}