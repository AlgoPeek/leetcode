// Source: https://leetcode.com/problems/add-two-numbers/description/
// Author: Diego Lee
// Date: 2018-07-09
//
// Description:
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
//

#include <assert.h>
#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* L1, ListNode* L2)
    {
		ListNode* L3 = new ListNode(0);
		ListNode* p1 = L1;
		ListNode* p2 = L2;
		ListNode* p3 = L3;
		int carry = 0;
		while (p1 || p2)
        {
			if (p1)
            {
				carry += p1->val;
				p1 = p1->next;
			}
			if (p2)
            {
				carry += p2->val;
				p2 = p2->next;
			}
			p3->next = new ListNode(carry % 10);
			p3 = p3->next;
			carry /= 10;
		}

		if (carry > 0)
        {
			p3->next = new ListNode(carry);
		}
		return L3->next;
	}
};

void CreateList(ListNode** root, int* vals, int pos, int len)
{
	if (pos < len)
    {
		ListNode*& _root = *root;
		_root = new ListNode(vals[pos]);
		CreateList(&_root->next, vals, pos + 1, len);
	}
}

void PrintList(ListNode* root)
{
    ListNode* next = root;
	while (next)
    {
		std::cout << root->val << " ";
		next = next->next;
	}
	std::cout << std::endl;
}

void testAddTwoNumbers()
{
	int a1[] = {1, 8};
	int a2[] = {0};
	ListNode* L1 = NULL;
	ListNode* L2 = NULL;
	CreateList(&L1, a1, 0, sizeof(a1) / sizeof(a1[0]));
	CreateList(&L2, a2, 0, sizeof(a2) / sizeof(a2[0]));
	PrintList(L1);
	PrintList(L2);

	ListNode* L3 = Solution().addTwoNumbers(L1, L2);
	PrintList(L3);
	assert(L3->val == 1);
	assert(L3->next->val == 8);
}

int main()
{
	testAddTwoNumbers();
	return 0;
}

