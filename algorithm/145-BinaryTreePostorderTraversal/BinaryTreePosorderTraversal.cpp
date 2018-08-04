// Source: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Given a binary tree, return the postorder traversal of its nodes' values.
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
// Output: [3,2,1]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <algorithm>
#include <vector>

#define Nil 0

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {}
};

class Solution
{
    public:
        std::vector<int> postorderTraversal(TreeNode* root)
        {
            std::vector<int> v;
            postorderTraversalHelp(root, v);
            return v;
        }
    private:
        void postorderTraversalHelp(TreeNode* root, std::vector<int>& v)
        {
            if (root == NULL)
            {
                return ;
            }
            postorderTraversalHelp(root->left, v);
            postorderTraversalHelp(root->right, v);
            v.push_back(root->val);
        }
};

void createTreeHelp(int* A, int n, int& i, TreeNode*& node)
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

void testPostorderTraversal()
{
    int A[] = {1, Nil, 2, 3};
    int R[] = {3, 2, 1};
    TreeNode* root = createTree(A, sizeof(A) / sizeof(int));
    Solution s;
    std::vector<int> result = s.postorderTraversal(root);
    assert(result == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testPostorderTraversal();
    return 0;
}
