// Source: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
// Example:
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.

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
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            int sequence = 0;
            ListNode* prev = NULL;
            ListNode* first = head;
            ListNode* last = first;
            while (last != NULL)
            {
                if (++sequence == k)
                {
                    ListNode* tmpprev = first;
                    ListNode* tmpfirst = first;
                    ListNode* tmplast = last;
                    last = last->next;
                    first = last;
                    sequence = 0;
                    while (tmpfirst != tmplast)
                    {
                        ListNode* node = tmpfirst;
                        tmpfirst = tmpfirst->next;
                        node->next = tmplast->next;
                        tmplast->next = node;
                    }
                    if (prev != NULL)
                    {
                        prev->next = tmplast;
                    }
                    else
                    {
                        head = tmplast;
                    }
                    prev = tmpprev;
                }
                else
                {
                    last = last->next;
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

void printVector(const std::vector<int>& vec)
{
    std::for_each(vec.begin(), vec.end(), [&](int v){
            std::cout << v << " ";
            });
    std::cout << std::endl;
}

void testReverseKGroup()
{
    int A[] = {1, 2, 3, 4, 5};
    int R2[] = {2, 1, 4, 3, 5};
    int R3[] = {3, 2, 1, 4, 5};
    ListNode* head1 = buildList(A, countof(A));
    ListNode* head2 = buildList(A, countof(A));

    Solution s;
    std::vector<int> result2 = convertToVector(s.reverseKGroup(head1, 2));
    // printVector(result2);
    std::vector<int> result3 = convertToVector(s.reverseKGroup(head2, 3));
    // printVector(result3);
    assert(result2 == std::vector<int>(std::begin(R2), std::end(R2)));
    assert(result3 == std::vector<int>(std::begin(R3), std::end(R3)));
}

int main()
{
    testReverseKGroup();
    return 0;
}
