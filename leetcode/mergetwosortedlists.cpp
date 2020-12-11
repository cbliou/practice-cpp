/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace prob21 {

    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (!l1 && !l2) {
                return l1;
            }

            else if (!l1) {
                return l2;
            }
            else if (!l2) {
                return l1;
            }

            ListNode* start = new ListNode(0, nullptr);
            ListNode* ptr = start;
            while (true) {
                if (l1->val < l2->val) {
                    start->next = new ListNode(l1->val);
                    start = start->next;
                    l1 = l1->next;
                    if (l1 == nullptr) {
                        break;
                    }
                }
                else if (l1->val > l2->val) {
                    start->next = new ListNode(l2->val);
                    start = start->next;
                    l2 = l2->next;
                    if (l2 == nullptr) {
                        break;
                    }
                }
                else {
                    start->next = new ListNode(l1->val);
                    start = start->next;
                    l1 = l1->next;
                    start->next = new ListNode(l2->val);
                    start = start->next;
                    l2 = l2->next;

                    if (l1 == nullptr || l2 == nullptr) {
                        break;
                    }

                }

            }

            // add the rest
            if (l1 == nullptr && l2 != nullptr) {
                while (true) {
                    start->next = new ListNode(l2->val);
                    start = start->next;
                    if (l2->next == nullptr) {
                        break;
                    }
                    l2 = l2->next;
                }
            }
            else if (l1 != nullptr && l2 == nullptr) {
                while (true) {
                    start->next = new ListNode(l1->val);
                    start = start->next;
                    if (l1->next == nullptr) {
                        break;
                    }
                    l1 = l1->next;
                }
            }

            return ptr->next;

        }
    };

}