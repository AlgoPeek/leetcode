// Source: https://leetcode.com/problems/balanced-binary-tree/description/
// Author: Diego Lee
// Date: 2018-07-18
//
// Description:
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example 1:
// Given the following tree [3,9,20,null,null,15,7]:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.
//
// Example 2:
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])
#define NODE_NULL -1

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
        bool isBalanced(TreeNode* root)
        {
            if (root == NULL)
            {
                return true;
            }

            if (std::abs(getMaxDepth(root->left) - getMaxDepth(root->right)) > 1)
            {
                return false;
            }
            return isBalanced(root->left) && isBalanced(root->right);
        }

        int getMaxDepth(TreeNode* root)
        {
            if (root == NULL)
            {
                return 0;
            }
            return 1 + std::max(getMaxDepth(root->left), getMaxDepth(root->right));
        }
};

void buildTreeHelp(int* A, int n, int& i, TreeNode*& node)
{
    if (i >= n)
    {
        return;
    }
    if (A[i] == NODE_NULL)
    {
        ++i;
        return;
    }
    assert(node == NULL);
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

void destroyTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

void testIsBalanced()
{
    int A1[] = {3, 9, NODE_NULL, NODE_NULL, 20, 15, NODE_NULL, NODE_NULL, 7};
    int A2[] = {1, 2, 3, 4, NODE_NULL, NODE_NULL, 4, NODE_NULL, NODE_NULL,
        3, NODE_NULL, NODE_NULL, 2, NODE_NULL, NODE_NULL};
    TreeNode* root1 = buildTree(A1, countof(A1));
    TreeNode* root2 = buildTree(A2, countof(A2));
    assert(Solution().isBalanced(root1) == true);
    assert(Solution().isBalanced(root2) == false);
    destroyTree(root1);
    destroyTree(root2);
}

int main()
{
    testIsBalanced();
    return 0;
}
