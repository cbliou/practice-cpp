#pragma once
#include "util.h"

bool testPrime(int i) {
	if (i == 2) {
		return true;
	}
	else if (i % 2 == 0) {
		return false;
	}

	for (int j = 3; j <= sqrt(i); j += 2) {
		if (i % j == 0) {
			return false;
		}
	}

	return true;

}

void generateFib(vector<int>& n, int limit) {
	n.push_back(1);
	n.push_back(1);
	while (n.at(n.size() - 1) < limit) {
		n.push_back(n.at(n.size() - 1) + n.at(n.size() - 2));
	}
}

bool determinePalindrome(int i) {

	int check = 0;
	int tmp = i;
	// reverse the digits
	while (i > 0) {
		check = check * 10 + i % 10;
		i /= 10;
	}
	return tmp == check;

}

void reshapeGrid(vector<int>& init, vector<vector<int>>& v, int dim) {
	int idx = 0;
	for (int row = 0; row < dim; ++row) {
		for (int col = 0; col < dim; ++col) {
			v[row][col] = init[idx];
			++idx;
		}
	}
}

uint64_t triangleNumber(int nth) {
	if (nth <= 0) {
		return 0;
	}
	else if (nth == 1) {
		return 1;
	}
	return nth + triangleNumber(nth - 1);
}

// i think you'd be able to check up to sqrt(i), then return 2 * found number. 
// if it's a perfect square, then you'd need to return + 1 more because checking up until sqrt(i) only gets stuff below, you're missing the sqrt one
int getNumDivisors(uint64_t i) {
	if (i == 1) {
		return 1;
	}

	int n = 0;
	for (int test = 1; test < sqrt(i); ++test) {
		if (i % test == 0) {
			++n;
		}
	}
	return (double)sqrt(i) == (int)sqrt(i) ? n * 2 + 1 : n * 2;
}

uint64_t sumProperDivisors(uint64_t i) {
	if (i == 1) {
		return 0;
	}
	
	uint64_t sum = 0;
	for (uint64_t j = 1; j <= i / 2; ++j) {
		if (i % j == 0) {
			sum += j;
		}
	}

	return sum;

}