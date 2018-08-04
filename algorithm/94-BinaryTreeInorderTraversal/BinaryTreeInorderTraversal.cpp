// Source: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <assert.h>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        std::vector<int> inorderTraversal(TreeNode* root)
        {
            std::vector<int> vec;
            inorderTraversalAux(root, vec);
            return vec;
        }

    private:
        void inorderTraversalAux(TreeNode* root, std::vector<int>& vec)
        {
            if (NULL == root)
            {
                return ;
            }

            inorderTraversalAux(root->left, vec);
            vec.push_back(root->val);
            inorderTraversalAux(root->right, vec);
        }
};

void makeBinaryTree(TreeNode*& node, int* a, int r, int n)
{
    if (r >= n)
    {
        return ;
    }

    int val = a[r];
    node = val == -1 ? NULL : new TreeNode(val);
    if (node == NULL)
    {
        return ;
    }
    makeBinaryTree(node->left, a, 2 * r + 1, n);
    makeBinaryTree(node->right, a, 2 * r + 2, n);
}

void printBinaryTreeHelp(TreeNode* root)
{
    if (NULL == root)
    {
        return ;
    }
    std::cout << root->val << " ";
    printBinaryTreeHelp(root->left);
    printBinaryTreeHelp(root->right);
}

void printBinaryTree(TreeNode* root)
{
    printBinaryTreeHelp(root);
    std::cout << std::endl;
}

void testInorderTraversal()
{
    int a[] = {1, -1, 2, -1, -1, 3};
    TreeNode* root = NULL;
    makeBinaryTree(root, a, 0, sizeof(a) / sizeof(a[0]));
    // printBinaryTree(root);

    Solution s;
    std::vector<int> vec = s.inorderTraversal(root);
    assert(vec.size() == 3);
    assert(vec[0] == 1);
    assert(vec[1] == 3);
    assert(vec[2] == 2);
}

int main()
{
    testInorderTraversal();
    return 0;
}
