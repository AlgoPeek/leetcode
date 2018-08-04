// Source: https://leetcode.com/problems/invert-binary-tree/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Desciption:
// Invert a binary tree.
//
// Example:
//
// Input:
//
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Output:
//
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
// Trivia:
// This problem was inspired by this original tweet by Max Howell:
//
// Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

#include <iostream>
#include <vector>
#include <cassert>

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
        TreeNode* invertTree(TreeNode* root)
        {
            invertTreeHelp(root);
            return root;
        }

    private:
        void invertTreeHelp(TreeNode* root)
        {
            if (root == NULL)
            {
                return ;
            }

            invertTreeHelp(root->left);
            invertTreeHelp(root->right);

            TreeNode* pNode = root->left;
            root->left = root->right;
            root->right = pNode;
        }
};

void makeTree(TreeNode*& root, const std::vector<int>& nodes, int index)
{
    if (index >= nodes.size())
    {
        return ;
    }

    root = (-1 != nodes[index]) ? new TreeNode(nodes[index]) : NULL;
    if (root != NULL)
    {
        makeTree(root->left, nodes, 2 * index + 1);
        makeTree(root->right, nodes, 2 * index + 2);
    }
}

void convertToVectorByPreorder(TreeNode* root, std::vector<int>& vec)
{
    if (root == NULL)
    {
        return;
    }

    vec.push_back(root->val);
    convertToVectorByPreorder(root->left, vec);
    convertToVectorByPreorder(root->right, vec);
}

void testInvertTree()
{
    int a[] = {4, 2, 7, 1, 3, 6, 9};
    int r[] = {4, 7, 9, 6, 2, 3, 1};
    std::vector<int> nodes(a, a + sizeof(a) / sizeof(a[0]));

    TreeNode* root = NULL;
    makeTree(root, nodes, 0);

    Solution s;
    TreeNode* newRoot = s.invertTree(root);
    std::vector<int> result;
    convertToVectorByPreorder(newRoot, result);
    assert(result == std::vector<int>(std::begin(r), std::end(r)));
}

int main()
{
    testInvertTree();
    return 0;
}
