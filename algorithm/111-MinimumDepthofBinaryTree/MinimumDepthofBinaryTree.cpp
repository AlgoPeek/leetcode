// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
// Author: Diego Lee
// Date: 2018-07-13
//
// Description:
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.
//
// Example:
// Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its minimum depth = 2
//

#include <iostream>
#include <algorithm>

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
        int minDepth(TreeNode* root)
        {
            if (root == NULL)
            {
                return 0;
            }

            if (root->left == NULL)
            {
                return 1 + minDepth(root->right);
            }
            else if (root->right == NULL)
            {
                return 1 + minDepth(root->left);
            }
            else
            {
                return 1 + std::min(minDepth(root->left), minDepth(root->right));
            }
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

void testMinDepth(void)
{
    int A[] = {3, 9, NODE_NULL, NODE_NULL, 20, 15, NODE_NULL, NODE_NULL, 7};
    TreeNode* root = buildTree(A, sizeof(A) / sizeof(int));
    assert(Solution().minDepth(root) == 2);
}

int main()
{
    testMinDepth();
    return 0;
}
