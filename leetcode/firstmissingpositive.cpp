#include "stdafx.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int firstmissing = 1;
        int secondmissing = 2;
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > firstmissing) {
                seen.emplace(nums[i]);
            }
            if (nums[i] == firstmissing || nums[i] == secondmissing) {
                if (nums[i] == firstmissing) {
                    firstmissing = secondmissing;
                }

                ++secondmissing;
                while (seen.find(secondmissing) != seen.end()) {
                    seen.erase(secondmissing);
                    ++secondmissing;
                }
            }

        }

        return firstmissing;
    }
    
    int firstMissingPositiveNlogN(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        int smallestSeen = INT_MAX;
        int maxSeen = INT_MIN;
        int firstmissing = 1;
        set<int> numQueue;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > firstmissing) {
                numQueue.insert(nums[i]);
            }
        }
        while (*numQueue.begin() == firstmissing) {
            ++firstmissing;
            numQueue.erase(numQueue.begin());
        }
        return firstmissing;
    }
    
};