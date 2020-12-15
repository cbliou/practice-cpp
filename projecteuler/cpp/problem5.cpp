#include "stdafx.h"

/*
This problem does not require any code.

Here is the logic:

We need to test numbers 1 - 20 and we just need to pick a minimal set of numbers in order to get all the factors smaller numbers account for.

For example, if 2 and 3 are included, then 6 does not need to be included as a factor.

Thus we can rule out
- 20 (because of 2, 2, 3, 5)
- 18 (2, 3, 3)
- 16 (2, 2, 2, 2)
- 15 (3, 5)
- 13 (2, 7)
- 12 (2, 2, 3)
- 10 (2, 5)
- 9 (3, 3)

Now observe that we need four 2's, two 3's, and one 5 to satisfy these conditions. Thus we must pick
- 6 (three 2's left, one 3 left)
- 8 (accounts for the rest of the 2's)

and the rest are primes.

Here's some code to solve it tho
*/

int problem5(void) {

	// necessary choices
	int test = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
	while (true) {
		
		int div = 0;
		
		for (int i = 2; i <= 20; ++i) {
			div += test % i;
		}

		if (div == 0) {
			return test;
		}

		test += 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
	}

}

