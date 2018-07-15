// Source: https://leetcode.com/problems/merge-k-sorted-lists/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

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
        ListNode* mergeKLists(std::vector<ListNode*>& lists)
        {
            ListNode* head = NULL;
            ListNode* curr = NULL;
            ListNode* node = NULL;
            while ((node = popMinListNode(lists)) != NULL)
            {
                if (head == NULL)
                {
                    head = node;
                    curr = head;
                }
                else
                {
                    curr->next = node;
                    curr = curr->next;
                }
            }
            return head;
        }

        ListNode* popMinListNode(std::vector<ListNode*>& lists)
        {
            int index = -1;
            int min = INT_MAX;
            for (size_t i = 0; i < lists.size(); ++i)
            {
                ListNode* node = lists[i];
                if (node != NULL && node->val <= min)
                {
                    min = node->val;
                    index = static_cast<int>(i);
                }
            }

            ListNode* popNode = NULL;
            if (index != -1)
            {
                popNode = lists[index];
                lists[index] = popNode->next;
                popNode->next = NULL;
            }
            return popNode;
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

std::vector<int> convertVector(ListNode* head)
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

void testMergeKLists()
{
    int A1[] = {1, 4, 5};
    int A2[] = {1, 3, 4};
    int A3[] = {2, 6};
    std::vector<ListNode*> lists;
    lists.push_back(buildList(A1, countof(A1)));
    lists.push_back(buildList(A2, countof(A2)));
    lists.push_back(buildList(A3, countof(A3)));
    ListNode* head = Solution().mergeKLists(lists);

    int R[] = {1, 1, 2, 3, 4, 4, 5, 6};
    std::vector<int> expire(std::begin(R), std::end(R));
    std::vector<int> result = convertVector(head);
    assert(expire == result);
}

int main()
{
    testMergeKLists();
    return 0;
}
