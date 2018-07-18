// Source: https://leetcode.com/problems/palindrome-linked-list/description/
// Author: Diego Lee
// Date: 2018-07-18
//
// Description:
// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
// Input: 1->2
// Output: false
//
// Example 2:
// Input: 1->2->2->1
// Output: true
//
// Follow up:
// Could you do it in O(n) time and O(1) space?

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
        bool isPalindrome(ListNode* head)
        {
            if (head == NULL)
            {
                return true;
            }

            ListNode* prevmid = NULL;
            ListNode* slow = head;
            ListNode* fast = head;
            while (slow != NULL && fast != NULL && fast->next != NULL)
            {
                prevmid = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if (slow == fast)
            {
                // only one node
                return true;
            }

            // find mid of the link, split it and reverse the right part
            prevmid->next = NULL;
            ListNode* left = head;
            ListNode* node = reverseList(slow);
            ListNode* right = node;
            while (left != NULL && right != NULL)
            {
                if (left->val == right->val)
                {
                    left = left->next;
                    right = right->next;
                }
                else
                {
                    break;
                }
            }

            // recover link
            node = reverseList(node);
            prevmid->next = node;
            return (left == NULL || right == NULL);
        }

    private:
        ListNode* reverseList(ListNode* head)
        {
            if (head == NULL)
            {
                return head;
            }

            ListNode* pNewHead = head;
            ListNode* curr = head->next;
            pNewHead->next = NULL;
            while (curr != NULL)
            {
                ListNode* next = curr->next;
                curr->next = pNewHead;
                pNewHead = curr;
                curr = next;
            }
            return pNewHead;
        }
};

ListNode* buildList(int* A, int n)
{
    ListNode* head = NULL;
    ListNode* curr = head;
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

void testIsPalindrome(void)
{
    int A1[] = {1, 2};
    int A2[] = {1, 2, 1};
    ListNode* head1 = buildList(A1, countof(A1));
    ListNode* head2 = buildList(A2, countof(A2));
    assert(Solution().isPalindrome(head1) == false);
    assert(Solution().isPalindrome(head2) == true);
}

int main()
{
    testIsPalindrome();
    return 0;
}
