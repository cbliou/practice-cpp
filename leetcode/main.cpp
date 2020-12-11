#include "validparentheses.cpp"
#include "twosum.cpp"

#include <assert.h>
#include <stdio.h>

void testValidParentheses(void) {
    validparentheses::Solution s;

    assert(s.isValid("()") == true);
    assert(s.isValid("") == true);
    assert(s.isValid("(") == false);
    assert(s.isValid(")") == false);
    assert(s.isValid("[)") == false);
    assert(s.isValid("(]") == false);
    assert(s.isValid("[({})]") == true);
    assert(s.isValid("()[]{}") == true);
    assert(s.isValid("[({])}") == false);
    assert(s.isValid("[(])") == false);
    assert(s.isValid("[[") == false);
    assert(s.isValid("]]") == false);
}

void testTwoSum(void) {

    twosum::Solution s;
    vector<int> nums = { 1,2,3,5,0 };
    vector<int> ans = { 0, 3 };
    assert(s.twoSum(nums, 6) == ans);
    
}

int main()
{
    testValidParentheses();
    testTwoSum();
    printf("Good job; no errors.\n");
    getchar();

}