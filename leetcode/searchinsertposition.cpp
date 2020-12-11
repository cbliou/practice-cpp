//https://leetcode.com/problems/search-insert-position/
#include "stdafx.h"

namespace p35 {

    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if (nums.size() == 0) {
                return 0;
            }
            else if (nums.size() == 1) {
                if (nums[0] >= target)
                    return 0;
                else
                    return 1;
            }
            else if (target > nums[nums.size() - 1]) {
                return nums.size();
            }
            for (unsigned int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] == target) {
                    return i;
                }
                if (nums[i] < target && target <= nums[i + 1])
                    return i + 1;
            }
            return 0;
        }
    };

}