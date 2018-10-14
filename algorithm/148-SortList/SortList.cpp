// Source: https://leetcode.com/problems/sort-list/description/
// Author: Diego Lee
// Date: 2018-10-14
//
// Description:
// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

#include <iostream>
#include <vector>
#include <cassert>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }

            // 1. cut list to two halves
            ListNode* prev = NULL;
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != NULL && fast->next != NULL) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if (prev != NULL)
            {
                prev->next = NULL;
            }
            ListNode* L1 = sortList(head);
            ListNode* L2 = sortList(slow);

            // 2. merge list
            return mergeList(L1, L2);
        }

        ListNode* mergeList(ListNode* L1, ListNode* L2) {
            ListNode fakeNode(0);
            ListNode* curr = &fakeNode;
            while (L1 != NULL && L2 != NULL) {
                if (L1->val < L2->val) {
                    curr->next = L1;
                    L1 = L1->next;
                }
                else {
                    curr->next = L2;
                    L2 = L2->next;
                }
                curr = curr->next;
            }
            if (L1 != NULL) {
                curr->next = L1;
            }
            if (L2 != NULL) {
                curr->next = L2;
            }
            return fakeNode.next;
        }
};

ListNode* buildList(const std::vector<int>& vec) {
    ListNode fakeNode(0);
    ListNode* curr = &fakeNode;
    for (auto n : vec) {
        curr->next = new ListNode(n);
        curr = curr->next;
    }
    return fakeNode.next;
}

std::vector<int> convertToVector(ListNode* head) {
    std::vector<int> result;
    ListNode* curr = head;
    while (curr != NULL) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

void testSortList(void) {
    ListNode* head = buildList(std::vector<int>({4,2,1,3}));
    Solution s;
    ListNode* result = s.sortList(head);
    assert(convertToVector(result) == std::vector<int>({1,2,3,4}));
}

int main() {
    testSortList();
    return 0;
}
