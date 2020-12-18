#include "stdafx.h"
#include <fstream>

// pretty much a paste from 18
int problem67(void) {

	string line;
	fstream file("../data/p067_triangle.txt");
	regex r("[0-9]{2}");
	int row = 1;
	vector<vector<int>> nums;

	if (!file) {
		return 0;
	}

	for (int i = 1; i <= 100; ++i) {
		nums.push_back(vector<int>(i, 0));
	}
	
	
	while (getline(file, line)) {
		auto begin = sregex_iterator(line.begin(), line.end(), r);
		auto end = sregex_iterator();
		int ctr = 1;
		for (sregex_iterator i = begin; i != end; ++i) {
			smatch m = *i;
			nums[row - 1][ctr - 1] = stoi(m.str());

			if (row == ctr) {
				++row;
				ctr = 1;
			}
			else {
				++ctr;
			}

		}

	}

	for (int i = 1; i < nums.size(); ++i) {

		for (int rowidx = 0; rowidx < nums[i].size(); ++rowidx) {

			if (i == 1) {
				nums[i][rowidx] += nums[0][0];
			}
			else if (rowidx == 0) {
				nums[i][rowidx] += nums[i - 1][0];
			}
			else if (rowidx == nums[i].size() - 1) {
				nums[i][rowidx] += nums[i - 1][nums[i - 1].size() - 1];
			}
			else {
				nums[i][rowidx] += max(nums[i - 1][rowidx - 1], nums[i - 1][rowidx]);
			}

		}

	}

	return *max_element(nums[nums.size() - 1].begin(), nums[nums.size() - 1].end());

}