// Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
// Author: Diego Lee
// Date: 2018-09-08
//
// Description:
// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
// Given the sorted linked list: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5

#include <iostream>
#include <vector>
#include <cassert>


// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        TreeNode* sortedListToBST(ListNode* head)
        {
            std::vector<int> vec = convertToVector(head);
            if (vec.empty())
            {
                return NULL;
            }

            TreeNode* root = NULL;
            sortedListToBSTHelp(vec, 0, vec.size(), root);
            return root;
        }

        void sortedListToBSTHelp(const std::vector<int> vec, int start, int len, TreeNode*& node)
        {
            if (len <= 0)
            {
                return;
            }

            int mid = start + len / 2;
            if (mid < static_cast<int>(vec.size()))
            {
                node = new TreeNode(vec[mid]);
                int leftcnt = mid - start;
                sortedListToBSTHelp(vec, start, leftcnt, node->left);
                sortedListToBSTHelp(vec, mid + 1, len - leftcnt - 1, node->right);
            }
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
};

ListNode* buildList(const std::vector<int>& vec)
{
    ListNode fakeNode(0);
    ListNode* curr = &fakeNode;
    for (auto n : vec)
    {
        curr->next = new ListNode(n);
        curr = curr->next;
    }
    return fakeNode.next;
}

void traverseTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    std::cout << root->val << " ";
    traverseTree(root->left);
    traverseTree(root->right);
}

void testSortedListToBST()
{
    std::vector<int> vec = {-10,-3,0,5,9};
    ListNode* head = buildList(vec);

    Solution s;
    TreeNode* root = s.sortedListToBST(head);
    assert(root != NULL);
    traverseTree(root);
}

int main()
{
    testSortedListToBST();
    return 0;
}
