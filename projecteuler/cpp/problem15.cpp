#include "stdafx.h"

uint64_t problem15(void) {

	// dp solution
	vector<vector<uint64_t>> grid (21, vector<uint64_t>(21, 0));
	grid[0][0] = 1;

	for (int row = 0; row < grid.size(); ++row) {
		for (int col = 0; col < grid[row].size(); ++col) {
			if (row >= 1) {
				grid[row][col] += grid[row - 1][col];
			}
			if (col >= 1) {
				grid[row][col] += grid[row][col - 1];
			}
			cout << grid[row][col] << " ";
		}
		cout << "\n";
	}

	return grid[20][20];

	/*
	counting solution
	each down can be represented w/ the letter D, each right can be represented with the letter R
	then we need to fill out 40 slots, which we can use 20 D's and 20 R's.
	the multinomial coefficient does the job: 40! / (20! * 20!)
	*/


}