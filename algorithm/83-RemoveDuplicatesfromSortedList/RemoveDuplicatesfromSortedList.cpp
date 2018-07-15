// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// Example 1:
// Input: 1->1->2
// Output: 1->2
//
// Example 2:
// Input: 1->1->2->3->3
// Output: 1->2->3

#include <iostream>
#include <cassert>
#include <vector>

#define countof(A) (sizeof A / sizeof A[0])

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode* head)
        {
            if (head == NULL)
            {
                return head;
            }

            ListNode* curr = head;
            ListNode* next = curr->next;
            while (next != NULL)
            {
                if (curr->val == next->val)
                {
                    curr->next = next->next;
                    next = curr->next;
                }
                else
                {
                    curr = next;
                    next = next->next;
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
    while (curr)
    {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
}

void testDeleteDuplicates()
{
    int A1[] = {1, 1, 2};
    int R1[] = {1, 2};
    ListNode* head = buildList(A1, countof(A1));
    ListNode* pResult = Solution().deleteDuplicates(head);
    std::vector<int> result = convertToVector(pResult);
    assert(result == std::vector<int>(std::begin(R1), std::end(R1)));

    int A2[] = {1, 1, 2, 3, 3};
    int R2[] = {1, 2, 3};
    head = buildList(A2, countof(A2));
    pResult = Solution().deleteDuplicates(head);
    result = convertToVector(pResult);
    assert(result == std::vector<int>(std::begin(R2), std::end(R2)));
}

int main()
{
    testDeleteDuplicates();
    return 0;
}

