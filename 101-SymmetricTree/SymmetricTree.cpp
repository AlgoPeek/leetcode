// Source: https://leetcode.com/problems/symmetric-tree/description/
// Author: Diego Lee
// Date: 2018-07-11
//
// Description:
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
// But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//

#include <iostream>
#include <cassert>

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
        bool isSymmetric(TreeNode* root)
        {
            if (root == NULL)
            {
                return true;
            }
            return isSymmetricHelp(root->left, root->right);
        }
    private:
        bool isSymmetricHelp(TreeNode* left, TreeNode* right)
        {
            if (left == NULL && right == NULL)
            {
                return true;
            }
            else if (left != NULL && right != NULL)
            {
                return (left->val == right->val)
                    && isSymmetricHelp(left->left, right->right)
                    && isSymmetricHelp(left->right, right->left);
            }
            else
            {
                return false;
            }
        }
};

void createTreeHelp(int* A, int n, int& i, TreeNode*& node)
{
    if (i >= n)
    {
        return;
    }
    if (A[i] == 0)
    {
        ++i;
        return;
    }
    assert(node == NULL);
    node = new TreeNode(A[i++]);
    createTreeHelp(A, n, i, node->left);
    createTreeHelp(A, n, i, node->right);
}

TreeNode* createTree(int* A, int n)
{
    TreeNode* root = NULL;
    int i = 0;
    createTreeHelp(A, n, i, root);
    return root;
}

void TraverseTree(TreeNode* root)
{
    if (root)
    {
        std::cout << root->val << " ";
        TraverseTree(root->left);
        TraverseTree(root->right);
    }
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

void testIsSymmetricTreeCase(int* A, int n, bool target)
{
    TreeNode* root = createTree(A, n);
//    TraverseTree(root);
    bool result = Solution().isSymmetric(root);
    destroyTree(root);
    assert(result == target);
}

int main()
{
    int A[] = {1,2,3,0,0,4,0,0,2,4,0,0,3,0,0};
    int A1[] = {1,2,0,3,0,0,2,0,3,0,0};
    testIsSymmetricTreeCase(A, countof(A), true);
    testIsSymmetricTreeCase(A1, countof(A1), false);
    return 0;
}
