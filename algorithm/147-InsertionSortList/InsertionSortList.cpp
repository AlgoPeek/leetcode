// Source: https://leetcode.com/problems/insertion-sort-list/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Sort a linked list using insertion sort.
// Algorithm of Insertion Sort:
//
// Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
// It repeats until no input elements remain.

#include <iostream>
#include <vector>
#include <cassert>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* insertionSortList(ListNode* head)
        {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode* pNewHead = NULL;
            while (head != NULL)
            {
                ListNode* pHead = head;
                head = head->next;

                ListNode** ppTail = &pNewHead;
                while (*ppTail && pHead->val > (*ppTail)->val)
                {
                    ppTail = &(*ppTail)->next;
                }
                pHead->next = *ppTail;
                *ppTail = pHead;
            }
            return pNewHead;
        }
};

ListNode* createLinkList(int* A, int n)
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
            ListNode* node = new ListNode(A[i]);
            next->next = node;
            next = node;
        }
    }
    return head;
}

void printLinkList(ListNode* head)
{
    ListNode* next = head;
    while (next)
    {
        std::cout << next->val << " ";
        next = next->next;
    }
    std::cout << std::endl;
}

std::vector<int> convertListToVector(ListNode* head)
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

void testInsertionSortList()
{
    int A[] = {4,2,1,3};
    int R[] = {1,2,3,4};
    std::vector<int> result(std::begin(R), std::end(R));
    ListNode* head = createLinkList(A, sizeof(A) / sizeof(int));
    // printLinkList(head);

    Solution s;
    ListNode* pNewHead = s.insertionSortList(head);
    // printLinkList(pNewHead);
    assert(result == convertListToVector(pNewHead));
}

int main(void)
{
    testInsertionSortList();
    return 0;
}
