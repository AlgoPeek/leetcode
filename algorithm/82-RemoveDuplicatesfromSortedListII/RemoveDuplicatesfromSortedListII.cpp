// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
// Example 1:
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
//
// Example 2:
// Input: 1->1->1->2->3
// Output: 2->3

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
        ListNode* deleteDuplicates(ListNode* head)
        {
            if (head == NULL)
            {
                return head;
            }

            ListNode* pNewHead = head;
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = curr->next;
            int count = 1;
            while (next != NULL)
            {
                if (curr->val == next->val)
                {
                    ++count;
                    next = next->next;
                }
                else
                {
                    if (count > 1)
                    {
                        curr = next;
                        next = next->next;
                        if (prev != NULL)
                        {
                            prev->next = curr;
                        }
                        else
                        {
                            pNewHead = curr;
                        }
                    }
                    else
                    {
                        prev = curr;
                        curr = next;
                        next = curr->next;
                    }
                    count = 1;
                }
            }

            if (count > 1)
            {
                curr = next;
                if (prev != NULL)
                {
                    prev->next = curr;
                }
                else
                {
                    pNewHead = curr;
                }
            }
            return pNewHead;
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

void testDeleteDuplicates()
{
    int A[] = {1, 2, 3, 3, 4, 4, 5};
    int R[] = {1, 2, 5};
    ListNode* head = Solution().deleteDuplicates(buildList(A, countof(A)));
    std::vector<int> result = convertToVector(head);
    assert(result == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testDeleteDuplicates();
    return 0;
}
