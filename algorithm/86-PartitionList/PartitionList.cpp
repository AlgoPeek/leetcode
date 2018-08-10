// Source: https://leetcode.com/problems/partition-list/description/
// Author: Diego Lee
// Date: 2018-08-10
//
// Description:
// Given a linked list and a value x, partition it such that all nodes less than x come before
// nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
// Example:
//
// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

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
        ListNode* partition(ListNode* head, int x)
        {
            ListNode fakeNode(0);
            fakeNode.next = head;
            ListNode* prev = &fakeNode;
            ListNode* curr = head;
            ListNode* target = &fakeNode;
            while (curr != NULL)
            {
                if (curr->val < x)
                {
                    if (curr == target->next)
                    {
                        prev = curr;
                        target = curr;
                        curr = curr->next;
                    }
                    else
                    {
                        // break
                        ListNode* next = curr->next;
                        prev->next = next;

                        // insert
                        curr->next = target->next;
                        target->next = curr;

                        // forward target
                        target = target->next;

                        // forward curr
                        curr = next;
                    }
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            return fakeNode.next;
        }
};

ListNode* buildList(int* A, int n)
{
    ListNode fakeNode(0);
    ListNode* curr = &fakeNode;
    for (int i = 0; i < n; ++i)
    {
        curr->next = new ListNode(A[i]);
        curr = curr->next;
    }
    return fakeNode.next;
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

void testPartition()
{
    int A[] = {1,4,3,2,5,2};
    int R[] = {1,2,2,4,3,5};
    ListNode* head = buildList(A, countof(A));

    Solution s;
    ListNode* result = s.partition(head, 3);
    assert(convertToVector(result) == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testPartition();
    return 0;
}

