#include "stdafx.h"

namespace p28 {

    class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (needle == "") {
                return 0;
            }
            else if (needle == haystack) {
                return 0;
            }

            // get some good indices
            vector<int> idxs;
            for (unsigned int idx = 0; idx < haystack.size(); ++idx) {
                if (idx + needle.size() - 1 <= haystack.size()) {
                    if (haystack[idx] == needle[0] && haystack[idx + needle.size() - 1] == needle[needle.size() - 1]) {
                        idxs.push_back(idx);
                    }
                }

            }

            for (const int idx : idxs) {
                for (int i = 0; i < needle.size(); ++i) {
                    if (haystack[idx + i] != needle[i]) {
                        break;
                    }
                    else if (i == needle.size() - 1) {
                        return idx;
                    }
                }
            }

            return -1;

        }
    };

}