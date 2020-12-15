//https://leetcode.com/problems/zigzag-conversion/

#include "stdafx.h"

namespace p6 {

    class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }

            int window = numRows * 2 - 2;
            string candidate = "";

            // read vertically
            for (int i = 0; i < numRows; ++i) {

                // read horizontally
                for (int col = 0; col < s.size(); col += window) {

                    // only reading the top level
                    if (i == 0) {
                        candidate += s[col];
                    }
                    // now you can read the inner, but guard against too long strings
                    else {

                        if ((col + i) % (numRows - 1) == 0 && col + i < s.size()) {
                            cout << candidate << "\n";
                            cout << col << " " << i << "\n";
                            
                            candidate += s[col + i];
                            continue;
                        }
                        if (col + i < s.size()) {
                            candidate += s[col + i];
                        }
                        if (col + window - i < s.size()) {
                            candidate += s[col + window - i];
                        }
                    }
                }
            }
            return candidate;
        }
    };
}