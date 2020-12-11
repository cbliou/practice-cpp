//https://leetcode.com/problems/add-two-numbers/
#include "stdafx.h"

namespace p2 {

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if (l1->next == nullptr && l2->next == nullptr) {
                int sum = l1->val + l2->val;
                if (sum >= 10) {
                    return new ListNode(sum % 10, new ListNode(1, nullptr));
                }
            }

            int carry = 0;
            ListNode* current = new ListNode(0, nullptr);
            ListNode* start = current;
            while (l1 != nullptr && l2 != nullptr) {
                int sum = l1->val + l2->val + carry;
                current->val = sum % 10;
                carry = sum >= 10 ? 1 : 0;
                l1 = l1->next;
                l2 = l2->next;
                if (l1 == nullptr && l2 == nullptr && carry == 0) {
                    break;
                }
                current->next = new ListNode(carry, nullptr);
                current = current->next;

            }

            // if uneven, the trailing number will be put already
            if (l1 == nullptr) {
                while (l2 != nullptr) {
                    int sum = current->val + l2->val;
                    current->val = sum % 10;
                    carry = sum >= 10 ? 1 : 0;
                    l2 = l2->next;
                    if (l2 == nullptr && carry == 0) {
                        break;
                    }
                    current->next = new ListNode(carry, nullptr);
                    current = current->next;
                }
            }
            else {
                while (l1 != nullptr) {
                    int sum = current->val + l1->val;
                    current->val = sum % 10;
                    carry = sum >= 10 ? 1 : 0;
                    l1 = l1->next;
                    if (l1 == nullptr && carry == 0) {
                        break;
                    }
                    current->next = new ListNode(carry, nullptr);
                    current = current->next;
                }
            }

            return start;

        }

        // worse implementation with length checking (which is unneeded)
        ListNode* addTwoNumbersSlower(ListNode* l1, ListNode* l2) {
            int oneLength = 1, twoLength = 1;
            struct ListNode* t1 = l1;
            struct ListNode* t2 = l2;
            while (t1->next != NULL) {
                t1 = t1->next;
                oneLength += 1;
            }

            while (t2->next != NULL) {
                t2 = t2->next;
                twoLength += 1;
            }

            ListNode* longer = oneLength > twoLength ? l1 : l2;
            ListNode* shorter = oneLength <= twoLength ? l1 : l2;
            ListNode* current = new ListNode(0, nullptr);
            ListNode* start = current;
            int carry = 0;
            while (shorter != nullptr) {

                int sum = current->val + shorter->val + longer->val;
                current->val = sum % 10;
                carry = sum >= 10 ? 1 : 0;
                shorter = shorter->next;
                longer = longer->next;

                if (shorter == nullptr) {

                    if (oneLength != twoLength) {
                        current->next = new ListNode(carry, nullptr);
                        current = current->next;
                        carry = 0;
                    }


                    break;
                }
                current->next = new ListNode(carry, nullptr);
                current = current->next;

            }

            while (longer != nullptr) {
                int sum = current->val + longer->val;
                current->val = sum % 10;
                carry = sum >= 10 ? 1 : 0;
                longer = longer->next;
                if (longer == nullptr) {
                    break;
                }
                current->next = new ListNode(carry, nullptr);
                current = current->next;

            }
            if (carry == 1) {
                current->next = new ListNode(carry, nullptr);
            }

            return start;
        }

    };

}

