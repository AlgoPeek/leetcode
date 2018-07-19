// Source: https://leetcode.com/problems/remove-linked-list-elements/description/
// Author: Diego Lee
// Date: 2018-07-19
//
// Description:
// Remove all elements from a linked list of integers that have value val.
//
// Example:
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

#include <iostream>
#include <cassert>
#include <vector>

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
        ListNode* removeElements(ListNode* head, int val)
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            while (curr != NULL)
            {
                if (curr->val == val)
                {
                    if (prev == NULL)
                    {
                        curr = curr->next;
                        head = curr;
                    }
                    else
                    {
                        curr = curr->next;
                        prev->next = curr;
                    }
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            return head;
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

void testRemoveElement()
{
    int A[] = {1, 2, 6, 3, 4, 5, 6};
    int R[] = {1, 2, 3, 4, 5};
    ListNode* head = buildList(A, countof(A));
    ListNode* result = Solution().removeElements(head, 6);
    assert(convertToVector(result) == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testRemoveElement();
    return 0;
}
