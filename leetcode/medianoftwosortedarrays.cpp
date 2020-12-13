#include "stdafx.h"

class Solution {
public:
    // do the recursive one soon

    // no storing
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = (nums1.size() + nums2.size()) / 2;
        int currElement = 0;
        int lastElement = 0;
        int ctr = 0;
        bool odd = (nums1.size() + nums2.size()) % 2 == 1 ? true : false;
        while (nums1.size() > 0 && nums2.size() > 0) {

            if (*nums1.begin() > * nums2.begin()) {
                lastElement = currElement;
                currElement = *nums2.begin();
                nums2.erase(nums2.begin());
            }
            else {
                lastElement = currElement;
                currElement = *nums1.begin();
                nums1.erase(nums1.begin());
            }
            if (ctr == sz) {
                if (odd) {
                    return currElement;
                }
                else {
                    return (double)(lastElement + currElement) / 2;
                }
            }
            ++ctr;
        }

        for (auto i : nums1) {
            lastElement = currElement;
            currElement = i;
            if (ctr == sz) {
                if (odd) {
                    return currElement;
                }
                else {
                    return (double)(lastElement + currElement) / 2;
                }
            }
            ++ctr;
        }
        for (auto i : nums2) {
            lastElement = currElement;
            currElement = i;
            if (ctr == sz) {
                if (odd) {
                    return currElement;
                }
                else {
                    return (double)(lastElement + currElement) / 2;
                }
            }
            ++ctr;
        }

        return 0.0;
    }


    double findMedianSortedArraysTry1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m;
        merge(m, nums1, nums2);
        return m.size() % 2 == 0 ? (double)(m[m.size() / 2] + m[m.size() / 2 - 1]) / 2 : m[m.size() / 2];
    }

    void merge(vector<int>& ret, vector<int>& n1, vector<int>& n2) {

        while (n1.size() > 0 && n2.size() > 0) {
            if (*n1.begin() > * n2.begin()) {
                ret.push_back(*n2.begin());
                n2.erase(n2.begin());
            }
            else {
                ret.push_back(*n1.begin());
                n1.erase(n1.begin());
            }
        }
        for (auto i : n1) {
            ret.push_back(i);
        }
        for (auto i : n2) {
            ret.push_back(i);
        }
    }

};




