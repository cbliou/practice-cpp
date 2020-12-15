//https://leetcode.com/problems/container-with-most-water/

#include "stdafx.h"

namespace p11 {
    
    class Solution {
    public:
        int maxArea(vector<int>& height) {

            int left = 0;
            int right = height.size() - 1;
            int bestArea = 0;
            while (left < right) {
                int area = min(height.at(left), height.at(right)) * (right - left);
                if (area > bestArea) {
                    bestArea = area;
                }
                height.at(left) < height.at(right) ? ++left : --right;
            }
            return bestArea;
        }
    };
}