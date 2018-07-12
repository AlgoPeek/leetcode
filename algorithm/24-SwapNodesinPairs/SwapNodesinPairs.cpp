// Source: https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Author: Diego Lee
// Date: 2018-07-12
//
// Description:
// Given a linked list, swap every two adjacent nodes and return its head.
//
// Example:
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Note:
// Your algorithm should use only constant extra space.
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

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
        ListNode* swapPairs(ListNode* head)
        {
            ListNode* pNewHead = head;
            ListNode* prev = NULL;
            ListNode* curr = head;
            while (curr != NULL && curr->next != NULL)
            {
                ListNode* next = curr->next;
                curr->next = next->next;
                next->next = curr;
                if (prev == NULL)
                {
                    pNewHead = next;
                }
                else
                {
                    prev->next = next;
                }
                prev = curr;
                curr = curr->next;
            }
            return pNewHead;
        }
};

ListNode* buildList(int* A, int n)
{
    ListNode* head = NULL;
    ListNode* next = NULL;
    for (int i = 0; i < n; ++i)
    {
        if (head == NULL)
        {
            head = new ListNode(A[i]);
            next = head;
        }
        else
        {
            next->next = new ListNode(A[i]);
            next = next->next;
        }
    }
    return head;
}

std::vector<int> convertListToVector(ListNode* head)
{
    std::vector<int> result;
    ListNode* next = head;
    while (next != NULL)
    {
        result.push_back(next->val);
        next = next->next;
    }
    return result;
}

void printList(ListNode* head)
{
    ListNode* next = head;
    while (next != NULL)
    {
        std::cout << next->val << " ";
        next = next->next;
    }
    std::cout << std::endl;
}

void testSwapPair()
{
    int A[] = {1, 2, 3, 4};
    ListNode* head = buildList(A, countof(A));
    // printList(head);
    ListNode* pNewHead = Solution().swapPairs(head);
    // printList(pNewHead);
    std::vector<int> result = convertListToVector(pNewHead);
    int B[] = {2, 1, 4, 3};
    assert(result == std::vector<int>(B, B + countof(B)));
}

int main(void)
{
    testSwapPair();
    return 0;
}
