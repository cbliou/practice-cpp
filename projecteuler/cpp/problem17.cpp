#include "stdafx.h"

int problem17(void) {
	unordered_map <int, string> ones{ {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"} };
	unordered_map <int, string> tens{ {2, "twenty"}, {3, "thirty"}, {4, "forty"}, {5, "fifty"}, {6, "sixty"}, {7, "seventy"}, {8, "eighty"}, {9, "ninety"} };
	int hundred = 7;
	int numletters = 0;

	for (int i = 1; i < 1000; ++i) {
		int j = i;
		int numplaces;
		if (j / 10 == 0) {
			numplaces = 1;
		}
		else if (j / 100 == 0) {
			numplaces = 2;
		}
		else {
			numplaces = 3;
		}

		while (numplaces > 0) {
			if (j == 0) {
				break;
			}
			else if (1 <= j && j < 10) {
				numletters += ones[j].size();
			}
			else if (10 <= j && j < 20) {
				if (j == 14 || j == 16 || j == 17 || j == 19) {
					numletters += ones[j % 10].size() + 4;
				}
				else if (j == 10) {
					numletters += 3;
				}
				else if (j == 11 || j == 12) {
					numletters += 6;
				}
				else if (j == 13 || j == 18) {
					numletters += 8;
				}
				else if (j == 15) {
					numletters += 7;
				}
				break;
			}
			else if (20 <= j && j < 100) {
				numletters += tens[j / 10].size();
			}
			else {
				if (j % 100 != 0) {
					// for "and"
					numletters += 3;
				}
				numletters += ones[j / 100].size() + 7;
			}

			//	864	- 800
			//	64	- 60
			//	4	- 4
			j = numplaces > 1 ? j - (int)(j / pow(10, numplaces - 1)) * pow(10, numplaces - 1) : 0;
			--numplaces;

			// catch the case x01 -x09
			if (1 <= j && j < 10) {
				numplaces = 1;
			}
		}
	}
	return numletters + 3 + 8;
}