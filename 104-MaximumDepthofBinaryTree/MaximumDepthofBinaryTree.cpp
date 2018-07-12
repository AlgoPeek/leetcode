// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// Author: Diego Lee
// Date: 2018-07-12
//
// Description:
// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// Note: A leaf is a node with no children.
//
// Example:
// Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its depth = 3.
//
#include <iostream>
#include <cassert>

#define NODE_NULL -1
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
        int maxDepth(TreeNode* root)
        {
            if (root == NULL)
            {
                return 0;
            }
            return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
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

void destroyTree(TreeNode* node)
{
    if (node == NULL)
    {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void testMaxDepth()
{
    int A[] = {3, 9, NODE_NULL, NODE_NULL, 20, 15, NODE_NULL, NODE_NULL, 7};
    TreeNode* root = buildTree(A, countof(A));
    int maxDepth = Solution().maxDepth(root);
    destroyTree(root);
    root = NULL;
    assert(maxDepth == 3);
}

int main()
{
    testMaxDepth();
    return 0;
}
