//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
#include "stdafx.h"

namespace p3 {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int max = 0;
            int left = 0;
            unordered_set<char> seenLetters;
            char badChar = '\0';
            bool dip = false;
            for (int right = 0; right < s.size(); ++right) {
                // new letter
                if (seenLetters.find(s[right]) != seenLetters.end() && seenLetters.size() > 0) {
                    // remove last bad letter
                    badChar = s[right];
                    while (left < right && !dip) {
                        if (badChar == s[left]) {
                            dip = true;
                        }
                        else {
                            seenLetters.erase(s[left]);
                        }
                        ++left;
                    }
                    dip = false;

                }
                seenLetters.emplace(s[right]);

                if (right + 1 - left > max) {
                    max = seenLetters.size();
                }

            }
            return max;
        }
    };
}

