// Source: https://leetcode.com/problems/sum-of-left-leaves/description/
// Author: Diego Lee
// Date: 2018-08-21
//
// Description:
// Find the sum of all left leaves in a given binary tree.
//
// Example:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

#include <iostream>
#include <vector>
#include <cassert>

#define Nil -1
#define countof(A) (sizeof A / sizeof A[0])

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
        int sumOfLeftLeaves(TreeNode* root)
        {
            return sumOfLeftLeavesHelp(root, false);
        }

        int sumOfLeftLeavesHelp(TreeNode* node, bool isLeft)
        {
            if (node == NULL)
            {
                return 0;
            }

            if (node->left && node->right)
            {
                return sumOfLeftLeavesHelp(node->left, true) + sumOfLeftLeavesHelp(node->right, false);
            }
            else if (node->left)
            {
                return sumOfLeftLeavesHelp(node->left, true);
            }
            else if (node->right)
            {
                return sumOfLeftLeavesHelp(node->right, false);
            }
            else
            {
                return isLeft ? node->val : 0;
            }
        }
};

void buildTreeHelp(int* A, int n, int& i, TreeNode*& node)
{
    if (i >= n)
    {
        return;
    }
    if (A[i] == Nil)
    {
        ++i;
        return;
    }

    node = new TreeNode(A[i++]);
    buildTreeHelp(A, n, i, node->left);
    buildTreeHelp(A, n, i, node->right);
}

TreeNode* buildTree(int* A, int n)
{
    TreeNode* root = NULL;
    int i = 0;
    buildTreeHelp(A, n, i, root);
    return root;
}

void testSumOfLeftLeaves()
{
    int A[] = {3, 9, Nil, Nil, 20, 15, Nil, Nil, 7};
    TreeNode* root = buildTree(A, countof(A));

    Solution s;
    int result = s.sumOfLeftLeaves(root);
    assert(result == 24);
}

int main()
{
    testSumOfLeftLeaves();
    return 0;
}
