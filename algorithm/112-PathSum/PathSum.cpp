// Source: https://leetcode.com/problems/path-sum/description/
// Author: Diego Lee
// Date: 2018-07-20
//
// Description:
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// Note: A leaf is a node with no children.
//
// Example:
// Given the below binary tree and sum = 22,
//
//      5
//     / \
//    4   8
//   /   / \
//  11  13  4
// /  \      \
//7    2      1
//return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])
#define Nil -1

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
        bool hasPathSum(TreeNode* root, int sum)
        {
            if (root == NULL)
            {
                return false;
            }

            // std::cout << "val=" << root->val << ", sum=" << sum << std::endl;
            if (root->left == NULL && root->right == NULL)
            {
                return (root->val == sum);
            }
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
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

void testHasPathSum()
{
    int A[] = {5, 4, 11, 7, Nil, Nil, 2, Nil, Nil, Nil, 8, 13, Nil, Nil, 4, Nil, 1};
    TreeNode* root = buildTree(A, countof(A));
    assert(Solution().hasPathSum(root, 22) == true);
}

int main()
{
    testHasPathSum();
    return 0;
}
