// https://leetcode.com/problems/two-sum/

#include "stdafx.h"

// brute force lol
namespace twosum {

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> idx{};
            for (unsigned int i = 0; i < nums.size(); ++i) {
                int check = target - nums[i];
                for (unsigned int j = i + 1; j < nums.size(); ++j) {
                    if (i == j) {
                        continue;
                    }
                    if (check == nums[j]) {
                        idx.push_back(i);
                        idx.push_back(j);
                        return idx;
                    }
                }

            }
            return idx;
        }
    };

};