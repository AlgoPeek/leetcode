// Source: https://leetcode.com/problems/reverse-linked-list-ii/description/
// Author: Diego Lee
// Date: 2018-07-25
//
// Description:
// Reverse a linked list from position m to n. Do it in one-pass.
//
// Note: 1 ≤ m ≤ n ≤ length of list.
//
// Example:
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

#include <iostream>
#include <vector>
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
        ListNode* reverseBetween(ListNode* head, int m, int n)
        {
            if (m == n)
            {
                return head;
            }

            n -= m;
            ListNode fakeNode(0);
            fakeNode.next = head;
            ListNode* prev = &fakeNode;
            while (--m > 0)
            {
                prev = prev->next;
            }
            ListNode* curr = prev->next;
            while (n-- > 0)
            {
                ListNode* node = curr->next;
                curr->next = node->next;
                node->next = prev->next;
                prev->next = node;
            }
            return fakeNode.next;
        }
};

ListNode* buildList(int* A, int n)
{
    ListNode* head = NULL;
    ListNode* curr = NULL;
    for (int i = 0; i < n; ++i)
    {
        if (head == NULL)
        {
            head = new ListNode(A[i]);
            curr = head;
        }
        else
        {
            curr->next = new ListNode(A[i]);
            curr = curr->next;
        }
    }
    return head;
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

void testReverseBetween()
{
    int A[] = {1, 2, 3, 4, 5};
    int R[] = {1, 4, 3, 2, 5};

    ListNode* head = buildList(A, sizeof(A) / sizeof(int));
    // printList(head);
    Solution s;
    ListNode* result = s.reverseBetween(head, 2, 4);
    // printList(result);
    assert(convertToVector(result) == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testReverseBetween();
    return 0;
}

