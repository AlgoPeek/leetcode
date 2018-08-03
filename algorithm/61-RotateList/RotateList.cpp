// Source: https://leetcode.com/problems/rotate-list/description/
// Author: Diego Lee
// Date: 2018-08-02
//
// Description:
// Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
// Example 2:
//
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL

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
        ListNode* rotateRight(ListNode* head, int k)
        {
            int count = getListCount(head);
            if (count == 0 || k % count == 0)
            {
                return head;
            }

            k %= count;
            ListNode* prev = this->move(head, count - k - 1);
            ListNode* curr = prev->next;
            ListNode* last = this->move(prev, k);
            prev->next = NULL;
            last->next = head;
            return curr;
        }

        int getListCount(ListNode* head)
        {
            int count = 0;
            ListNode* curr = head;
            while (curr != NULL)
            {
                ++count;
                curr = curr->next;
            }
            return count;
        }

        ListNode* move(ListNode* curr, int step)
        {
            ListNode* node = curr;
            for (int i = 1; i <= step; ++i)
            {
                node = node->next;
            }
            return node;
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

void testRotateRight()
{
    int A1[] = {1, 2, 3, 4, 5};
    int A2[] = {0, 1, 2};
    int A3[] = {1};
    int R1[] = {4, 5, 1, 2, 3};
    int R2[] = {2, 0, 1};
    int R3[] = {1};

    Solution s;
    ListNode* head = s.rotateRight(buildList(A1, countof(A1)), 2);
    assert(convertToVector(head) == std::vector<int>(std::begin(R1), std::end(R1)));

    head = s.rotateRight(buildList(A2, countof(A2)), 4);
    assert(convertToVector(head) == std::vector<int>(std::begin(R2), std::end(R2)));

    head = s.rotateRight(buildList(A3, countof(A3)), 1);
    assert(convertToVector(head) == std::vector<int>(std::begin(R3), std::end(R3)));
}

int main()
{
    testRotateRight();
    return 0;
}
