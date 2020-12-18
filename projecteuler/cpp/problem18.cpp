#include "stdafx.h"

int problem18(void) {
	string txt =
		"75"
		"95 64"
		"17 47 82"
		"18 35 87 10"
		"20 04 82 47 65"
		"19 01 23 75 03 34"
		"88 02 77 73 07 63 67"
		"99 65 04 28 06 16 70 92"
		"41 41 26 56 83 40 80 70 33"
		"41 48 72 33 47 32 37 16 94 29"
		"53 71 44 65 25 43 91 52 97 51 14"
		"70 11 33 28 77 73 17 78 39 68 17 57"
		"91 71 52 38 17 14 91 43 58 50 27 29 48"
		"63 66 04 68 89 53 67 30 73 16 69 87 40 31"
		"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

	/*
	
	we can use dynamic programming: 
	
	a_{i,j} = max(a_{i,j} + a_{i-1, j - 1} , a_{i,j} + a_{i-1, j})

	with three edge cases : 
	- top of pyramid  
	- right end of each row
	- left end

	notice that string setup up there is misleading.

	*/

	// initialize with triangle of 0's
	vector<vector<int>> nums;
	for (int i = 1; i <= 15; ++i) {
		nums.push_back(vector<int>(i, 0));
	}

	int row = 1;
	int ctr = 1;
	regex r("[0-9]{2}");
	auto begin = sregex_iterator(txt.begin(), txt.end(), r);
	auto end = sregex_iterator();
	for (sregex_iterator i = begin; i != end; ++i) {
		smatch m = *i;
		nums[row - 1][ctr - 1]= stoi(m.str());

		if (row == ctr) {
			++row;
			ctr = 1;
		}
		else {
			++ctr;
		}
		
	}

	// technically, we could have done the dp logic in the previous loop.
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