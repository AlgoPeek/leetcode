// Source: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Given a binary tree, return the preorder traversal of its nodes' values.
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
// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <vector>

#define Nil 0

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
        std::vector<int> preorderTraversal(TreeNode* root)
        {
            std::vector<int> vec;
            preorderTraversalHelp(root, vec);
            return vec;
        }

        void preorderTraversalHelp(TreeNode* root, std::vector<int>& vec)
        {
            if (root == NULL)
            {
                return ;
            }

            vec.push_back(root->val);
            preorderTraversalHelp(root->left, vec);
            preorderTraversalHelp(root->right, vec);
        }
};

void CreateTreeHelp(int* A, int n, int& i, TreeNode*& node)
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
    CreateTreeHelp(A, n, i, node->left);
    CreateTreeHelp(A, n, i, node->right);
}

TreeNode* CreateTree(int* A, int n)
{
    TreeNode* root = NULL;
    int i = 0;
    CreateTreeHelp(A, n, i, root);
    return root;
}

void testPreorderTraversal()
{
    int A[] = {1, Nil, 2, 3};
    int R[] = {1, 2, 3};
    TreeNode* root = CreateTree(A, sizeof(A) / sizeof(int));
    Solution s;
    std::vector<int> result = s.preorderTraversal(root);
    assert(result == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testPreorderTraversal();
    return 0;
}
