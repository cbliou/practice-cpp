
#include "allheaders.h"
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

void linkedlistequality(ListNode* l1, ListNode* l2) {
    while (l1->next != nullptr) {
        assert(l1->val == l2->val);
        l1 = l1->next;
    }
}

ListNode* arrtolinkedlist(int arr[]) {
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

void freelinkedlist(ListNode* arr) {
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
    ListNode* one = arrtolinkedlist(arr);
    ListNode* two = arrtolinkedlist(arr2);
    ListNode* three = arrtolinkedlist(arr3);

    ListNode* ans = s.mergeTwoLists(one, two);
    linkedlistequality(ans, three);
    freelinkedlist(one);
    freelinkedlist(two);
    freelinkedlist(ans);
    freelinkedlist(three);

}

void testP28(void) {
    p28::Solution s;
    assert(s.strStr("abbabbbbabaaa", "aba") == 8);
}

void testP35(void) {
    p35::Solution s;
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 9};
    assert(s.searchInsert(v, 0) == 0);
    assert(s.searchInsert(v, 1) == 0);
    assert(s.searchInsert(v, -1) == 0);
    assert(s.searchInsert(v, 5) == 4);
    assert(s.searchInsert(v, 10) == 8);
}

void testP36(void) {

    char row1[9] = {'.', '.', '.', '.', '5', '.', '.', '1', '.'};
    char row2[9] = {'.', '4', '.', '3', '.', '.', '.', '.', '.'};
    char row3[9] = {'.', '.', '.', '.', '.', '3', '.', '.', '1'};
    char row4[9] = {'8', '.', '.', '.', '.', '.', '.', '2', '.'};
    char row5[9] = {'.', '.', '2', '.', '7', '.', '.', '.', '.'};
    char row6[9] = {'.', '1', '5', '.', '.', '.', '.', '.', '.'};
    char row7[9] = {'.', '.', '.', '.', '.', '2', '.', '.', '.'};
    char row8[9] = {'.', '2', '.', '9', '.', '.', '.', '.', '.'};
    char row9[9] = {'.', '.', '4', '.', '.', '.', '.', '.', '.'};
    char* arr[9];
    arr[0] = row1;
    arr[1] = row2;
    arr[2] = row3;
    arr[3] = row4;
    arr[4] = row5;
    arr[5] = row6;
    arr[6] = row7;
    arr[7] = row8;
    arr[8] = row9;
    int colSize[9] = { 9,9,9,9,9,9,9,9,9 };
    p36::Solution s;
    assert(s.isValidSudoku(arr, 9, colSize) == false);
}

void testp2(void) {
    p2::Solution s;
    int arr[3] = { 1, 3, 4 };
    int arr2[3] = { 9, 9, 9};
    int arr3[4] = { 0, 3, 2, 1 };
    ListNode* one = arrtolinkedlist(arr);
    ListNode* two = arrtolinkedlist(arr2);
    ListNode* three = arrtolinkedlist(arr3);
    ListNode* ans = s.addTwoNumbers(one, two);
    linkedlistequality(three, ans);
    freelinkedlist(one);
    freelinkedlist(two);
    freelinkedlist(three);
    freelinkedlist(ans);
}

void testp3(void) {
    p3::Solution s;
    assert(s.lengthOfLongestSubstring("adslfj;sdnfewanadl") == 9);
}

void test(void) {
    std::unordered_set<int> x({ 1, 4, 6 });
    assert(x.find(2) == x.end());
    assert(*x.find(4) == 4);
    x.erase(x.begin(), x.end());
    assert(x.size() == 0);
    x.erase(x.begin(), x.end());
    x.emplace(1);
    x.emplace(1);
    printf("Size is %d\n", x.size());

    std::set<int> a = { 0, 2, 6, 1, 4 };
    for (const int i : a) {
        printf("%d ", i);
    }
    printf("\n");
    a.insert(4);
    a.insert(5);
    for (const int i : a) {
        printf("%d ", i);
    }

    printf("%d\n", *a.begin());

    while (*a.begin() < 5) {
        a.erase(a.begin());
    }

    for (const int i : a) {
        printf("%d ", i);
    }

    for (int i = 0; i < (1 << 10); ++i) {
        printf("%d ", i);
    }

}

void testp6(void) {
    p6::Solution s;
    string test1 = "PAYPALISHIRING";
    assert(s.convert(test1, 4) == "PINALSIGYAHRPI");
    assert(s.convert(test1, 3) == "PAHNAPLSIIGYIR");
}

void testp11(void) {
    p11::Solution s;
    vector<int> t1 = { 46,53,93,82,78,20,49,76,43,67,52,41,65,38,97,98,56,32,85,11,49,90,68,95,38,53,96,94,57,36,93,55,89,87,89,67,59,90,96,2,58,0,95,75,38,44,73,94,76,10,57,25,1,25,21,91,30,69,85,39,57,31,95,46,70,84,66,29,75,14,83,85,14,79,60,52,23,85,98,0,96,55,77,49,32,50,92,62,20,78,53,29,9,48,76,79,85,94,60,60,60,43,97,74,74,9,78,98,94,76,50,42,83,79,43,67,30,36,81,2,66,34,31,27,35,59,58,20,53,18,32,13,13,29,39,88,90,17,38,84,45,40,79,80,19,22,99,49,10,80,51,76,67,83,3,2,42,61,74,48,31,6,13,45,87,53,85,77,22,75,13,20,67,92,0,86,67,0,88,77,32,91,6,99,26,61,53,69,75,27,69,6,33,82,3,72,87,40,49,10,15,63,30,82,7,82,21,74,34,9,4,67,0,10,18,27,23,72,48,98,51,69,57,37,3,60,9,91,1,59,53,68,22,35,3,29,69,76,56,4,37,12,23,89,74,41,68,97,65,68,96,17,37,53,54,41,65,63,84,18,22,89,87,96,76,42,78,45,70,34,1,7,46,24,96,20,66,65,69,31,33,65,0,23,70,54,64,36,18,0,54,92,41,93,89,17,87,19,14,57,53,16,64,51,40,61,23,58,78,92,90,63,10,90,86,80,97,2,68,15,2,75,59,95,68,0,64,56,19,79,65,24,47,30,27,87,43,50,46,73,95,88,36,5,30,23,37,27,25,58,94,80,33,6,75,1,6,40,9,26,19,27,50,66,9,30,5,52,80,3,77,27,43,13,84,74,36,22,53,14,80,48,94,65,6,69,18,12,61,80,90,32,7,93,50,16,23,56,20,3,11,97,31,55,10,15,29,99,89,34,13,21,34,59,86,40,28,5,53,42,37,43,74,44,36,25,60,59,33,80,15,44,77,98,51,39,65,32,38,55,67,3,28,1,62,67,42,43,24,47,85,61,90,59,5,79,36,65,90,21,97,5,66,74,55,17,13,21,50,4,28,69,7,56,70,70,23,64,65,99,11,50,60,2,61,65,33,50,82,23,71,79,81,89,5,36,59,71,57,61,75,37,30,34,94,0,56,69,65,21,69,76,71,29,30,85,47,15,35,29,39,6,61,72,48,66,8,7,89,18,68,64,55,98,99,1,50,7,23,15,29,92,44,52,73,26,89,72,42,24,2,33,83,15,5,31,33,65,38,23,83,58,87,91,56,38,44,58,98,67,74,27,11,70,31,85,48,21,57,90,97,11,75,80,78,80,63,12,46,53,35,81,11,74,72,19,65,69,78,63,36,4,42,48,26,73,85,74,46,94,17,44,58,92,24,36,73,40,48,71,93,35,52,57,62,77,28,27,46,6,42,34,62,36,34,88,61,71,63,8,66,32,52,24,24,28,60,49,20,61,20,66,48,73,23,10,2,51,89,0,10,31,34,72,19,69,61,81,40,76,89,58,8,93,82,84,73,95,34,94,8,6,12,56,31,35,19,33,38,8,33,48,40,68,73,11,89,86,92,81,62,33,92,22,78,26,6,52,21,92,98,81,99,10,90,30,97,9,16,87,17,49,36,9,69,61,21,10,47,65,44,61,99,36,83,77,62,41,81,36,86,79,17,37,41,59,67,90,68,83,78,38,85,66,47,6,27,20,17,26,86,61,87,85,97,22,14,59,15,96,47,1,27,65,38,69,24,58,59,45,93,37,83,30,55,30,37,82,3,54,8,89,67,47,74,16,69,40,27,85,36,75,38,64,92,29,85,68,87,96,13,32,86,96,63,41,79,52,24,82,58,84,71,25,32,97,41,1,89,68,38,26,95,77,90,87,6,27,56,45,23,69,77,9,18,92,51,97,96,27,31,54,11,54,79,95,3,72,49,92,93,87,70,88,16,12,28,74,39,84,19,63,5,49,72,75,93,75,24,90,2,55,44,66,61,76,13,64,48,62,9,93,2,79,82,70,92,10,45,83,46,64,46,3,65,71,79,59,98,3,49,53,59,45,19,72,21,84,89,22,99,98,15,1,29,49,23,73,11,68,57,57,85,55,61,50,78,92,9,77,95,10,30,6,56,1,79,77,85,68,99,84,18,67,37,47,16,61,21,28,81,30,85,66,85,98,17,64,42,26,93,38,89,23,96,45,24,75,74,61,95,74,46,13,93,35,13,9,96,86,37,78,16,75,96,53,25,13,69,68 };
    vector<int> t2 = { 0,0,0,0,0,0,0,12331 };
    assert(s.maxArea(t1) == 94080);
    assert(s.maxArea(t2) == 0);
}

int main()
{
    testValidParentheses();
    testTwoSum();
    testProb21();
    testP28();
    testP35();
    testP36();
    testp2();
    testp3();
    testp6();
    testp11();
    //test();
    printf("Good job; no errors.\n");
    getchar();
}