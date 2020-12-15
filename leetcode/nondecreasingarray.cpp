//https://leetcode.com/problems/non-decreasing-array/
#include "stdafx.h"

namespace p665 {

    class Solution {
    public:
        bool checkPossibility(vector<int>& nums) {
            if (nums.size() == 1) {
                return true;
            }
            bool flag = false;

            for (int i = 0; i < nums.size() - 1; ++i) {

                // either set self, or set next
                if (nums[i] > nums[i + 1]) {
                    if (flag) {
                        return false;
                    }
                    // only case for self set
                    if (i == 0) {
                        nums[i] = nums[i + 1] - 1;
                        flag = true;
                    }

                    else {
                        int savei;
                        // set us first
                        savei = nums[i];
                        nums[i] = nums[i - 1];
                        // if failed, set next
                        if (nums[i] > nums[i + 1]) {
                            nums[i] = savei;
                            nums[i + 1] = nums[i];
                        }
                        flag = true;
                    }
                }
            }
            return true;
        }
    };

}