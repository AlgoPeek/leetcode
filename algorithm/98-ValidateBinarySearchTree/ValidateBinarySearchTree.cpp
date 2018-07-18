// Source: https://leetcode.com/problems/validate-binary-search-tree/description/
// Author: Diego Lee
// Date: 2018-07-19
//
// Description:
// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
// Input:
//     2
//    / \
//   1   3
// Output: true
// Example 2:
//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
// is 5 but its right child's value is 4.

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
        bool isValidBST(TreeNode* root)
        {
            return isValidBSTHelp(root, NULL, NULL);
        }

        bool isValidBSTHelp(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
        {
            if (root == NULL)
            {
                return true;
            }

            if ((minNode != NULL && root->val <= minNode->val)
                    || (maxNode != NULL && root->val >= maxNode->val))
            {
                return false;
            }
            return isValidBSTHelp(root->left, minNode, root) && isValidBSTHelp(root->right, root, maxNode);
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

void testIsValidBST()
{
    int A1[] = {2, 1, NODE_NULL, NODE_NULL, 3};
    int A2[] = {5, 1, NODE_NULL, NODE_NULL, 4, 3, NODE_NULL, NODE_NULL, 6};
    TreeNode* root1 = buildTree(A1, countof(A1));
    TreeNode* root2 = buildTree(A2, countof(A2));
    assert(Solution().isValidBST(root1) == true);
    assert(Solution().isValidBST(root2) == false);
}

int main()
{
    testIsValidBST();
    return 0;
}
