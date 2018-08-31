// Source: https://leetcode.com/problems/reorder-list/description/
// Author: Diego Lee
// Date: 2018-08-31
//
// Description:
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
//

#include <vector>
#include <iostream>
#include <cassert>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        void reorderList(ListNode* head)
        {
            ListNode* prev = NULL;
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != NULL && fast->next != NULL)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if (prev)
            {
                prev->next = NULL;
                head = mergeList(head, reverseList(slow));
                // printList(head);
            }
        }

        ListNode* reverseList(ListNode* head)
        {
            ListNode fakeHead(0);
            ListNode* curr = head;
            while (curr != NULL)
            {
                ListNode* next = curr->next;
                curr->next = fakeHead.next;
                fakeHead.next = curr;
                curr = next;
            }
            return fakeHead.next;
        }

        ListNode* mergeList(ListNode* head1, ListNode* head2)
        {
            ListNode fakeHead(0);
            ListNode* curr = &fakeHead;
            ListNode* curr1 = head1;
            ListNode* curr2 = head2;
            while (curr1 != NULL && curr2 != NULL)
            {
                ListNode* next1 = curr1->next;
                ListNode* next2 = curr2->next;

                curr->next = curr1;
                curr1->next = curr2;
                curr2->next = NULL;

                curr = curr2;
                curr1 = next1;
                curr2 = next2;
            }
            if (curr1 != NULL)
            {
                curr->next = curr1;
            }
            if (curr2 != NULL)
            {
                curr->next = curr2;
            }
            return fakeHead.next;
        }

        void printList(ListNode* head)
        {
            ListNode* curr = head;
            while (curr != NULL)
            {
                std::cout << curr->val << " ";
                curr = curr->next;
            }
            std::cout << std::endl;
        }
};

ListNode* buildList(const std::vector<int>& vec)
{
    ListNode fakeHead(0);
    ListNode* curr = &fakeHead;
    for (auto n : vec)
    {
        curr->next = new ListNode(n);
        curr = curr->next;
    }
    return fakeHead.next;
}

std::vector<int> convertToVector(ListNode* head)
{
    std::vector<int> result;
    ListNode* curr = head;
    while (curr != NULL)
    {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

void testReorderList()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {1, 2};
    std::vector<int> nums3 = {1};
    std::vector<int> expect = {1, 4, 2, 3};
    std::vector<int> expect1 = {1, 3, 2};
    std::vector<int> expect2 = {1, 2};
    std::vector<int> expect3 = {1};

    Solution s;
    ListNode* head = buildList(nums);
    s.reorderList(head);
    assert(convertToVector(head) == expect);

    head = buildList(nums1);
    s.reorderList(head);
    assert(convertToVector(head) == expect1);

    head = buildList(nums2);
    s.reorderList(head);
    assert(convertToVector(head) == expect2);

    head = buildList(nums3);
    s.reorderList(head);
    assert(convertToVector(head) == expect3);
}

int main()
{
    testReorderList();
    return 0;
}
