#include "stdafx.h"

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

void testUtil() {
	assert(determinePalindrome(121) == true);
	assert(determinePalindrome(11) == true);
	assert(determinePalindrome(1) == true);
	assert(determinePalindrome(12321) == true);
	assert(determinePalindrome(12831) == false);
	assert(determinePalindrome(1122) == false);
	assert(determinePalindrome(2345432) == true);
	assert(determinePalindrome(995599) == true);
	assert(determinePalindrome(88988) == true);
	assert(determinePalindrome(99398) == false);

	assert(testPrime(24) == false);
	assert(testPrime(14) == false);
	assert(testPrime(145) == false);
	assert(testPrime(149) == true);
	assert(testPrime(13) == true);
	assert(testPrime(3) == true);
	assert(testPrime(5) == true);
	assert(testPrime(7) == true);
	assert(testPrime(11) == true);
	assert(testPrime(17) == true);
}