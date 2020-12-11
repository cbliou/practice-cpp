#include "validparentheses.cpp"
#include "twosum.cpp"
#include "mergetwosortedlists.cpp"
#include "implementstrstr.cpp"

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

void prob21Equality(ListNode* l1, ListNode* l2) {
    while (l1->next != nullptr) {
        assert(l1->val == l2->val);
        l1 = l1->next;
    }
}

ListNode* prob21Create(int arr[]) {
    ListNode* dummy = new ListNode();
    ListNode* ptr = dummy;
    for (unsigned int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        dummy->next = new ListNode(arr[i]);
        dummy = dummy->next;
    }
    ListNode* tmp = ptr->next;
    free(ptr);
    return tmp;
}

void prob21Free(ListNode* arr) {
    while (arr->next != nullptr) {
        ListNode* tmp = arr;
        arr = arr->next;
        free(tmp);
    }
}

void testProb21(void) {

    prob21::Solution s;
    int arr[3] = { -21, -5, -2 };
    int arr2[3] = { -20, -4, 0 };
    int arr3[6] = { -21, -20, -5, -4, -2, 0 };
    ListNode* one = prob21Create(arr);
    ListNode* two = prob21Create(arr2);
    ListNode* three = prob21Create(arr3);

    ListNode* ans = s.mergeTwoLists(one, two);
    prob21Equality(ans, three);
    prob21Free(one);
    prob21Free(two);
    prob21Free(ans);
    prob21Free(three);

}

void testP28(void) {
    p28::Solution s;
    assert(s.strStr("abbabbbbabaaa", "aba") == 8);
}

int main()
{
    testValidParentheses();
    testTwoSum();
    testProb21();
    testP28();
    printf("Good job; no errors.\n");
    getchar();

}