// https://leetcode.com/problems/valid-parentheses/

#include "stdafx.h"
namespace validparentheses {

    class Solution {
    public:
        bool isValid(string s) {

            std::vector<char> stack;
            std::unordered_map<char, char> close_check{ {')', '('}, {']', '['}, {'}', '{'} };

            if (s.length() == 1) {
                return false;
            }

            for (char i : s) {

                // if left hand, push on the stack
                if ((i == '(') || (i == '{') || (i == '[')) {
                    stack.push_back(i);
                }
                // if closing, pop one off and compare
                else if ((i == ')') || (i == '}') || (i == ']')) {

                    // if stack empty, no matches
                    if (stack.size() == 0) {
                        return false;
                    }

                    char check = stack.back();
                    stack.pop_back();

                    //if incorrect parentheses, false
                    if (close_check.at(i) != check) {
                        return false;
                    }
                }
            }

            if (stack.size() > 0)
                return false;

            return true;

        }
    };

};
