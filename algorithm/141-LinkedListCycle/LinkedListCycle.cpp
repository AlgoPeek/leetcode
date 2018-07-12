// Source: https://leetcode.com/problems/linked-list-cycle/description/
// Author: Diego Lee
// Date: 2018-07-10
//
// Description:
// Given a linked list, determine if it has a cycle in it.
//
// Follow up:
// Can you solve it without using extra space?
//

#include <iostream>


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
        bool hasCycle(ListNode *head)
        {
            ListNode* slow = head;
            ListNode* fast = head;
            while (slow != NULL && fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                {
                    return true;
                }
            }
            return false;
        }
};

ListNode* createList(int* A, int n)
{
    ListNode* pHead = NULL;
    ListNode** ppNext = &pHead;
    for (int i = 0; i < n; ++i)
    {
        *ppNext = new ListNode(A[i]);
        ppNext = &(*ppNext)->next;
    }
    return pHead;
}

void DestroyList(ListNode* head)
{
    ListNode* node = head;
    while (node)
    {
        ListNode* next = node->next;
        delete node;
        node = next;
    }
}

void PrintList(ListNode* head)
{
    ListNode* node = head;
    while (node)
    {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void testHasCycle(void)
{
    Solution s;

    int A[] = {1, 2};
    ListNode* head = createList(A, sizeof(A) / sizeof(int));
    PrintList(head);
    assert(false == s.hasCycle(head));
    DestroyList(head);

    head = new ListNode(1);
    head->next = head;
    assert(true == s.hasCycle(head));
    head->next = NULL;
    DestroyList(head);
    head = NULL;
}

int main()
{
    testHasCycle();
    return 0;
}
