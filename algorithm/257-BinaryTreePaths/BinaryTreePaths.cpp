// Source: https://leetcode.com/problems/binary-tree-paths/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
// Example:
// Input:
//   1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
//

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <sstream>

#define Nil -1
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
        std::vector<std::string> binaryTreePaths(TreeNode* root)
        {
            std::vector<std::string> result;
            binaryTreePathsHelp(root, "", result);
            return result;
        }

        void binaryTreePathsHelp(TreeNode* root, std::string curr, std::vector<std::string>& vec)
        {
            if (root == NULL)
            {
                return;
            }

            curr += intToStr(root->val);
            if (root->left == NULL && root->right == NULL)
            {
                vec.push_back(curr);
                return;
            }
            curr += "->";
            binaryTreePathsHelp(root->left, curr, vec);
            binaryTreePathsHelp(root->right, curr, vec);
        }

        std::string intToStr(int n)
        {
            std::stringstream ss;
            ss << n;
            return ss.str();
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

void testBinaryTreePaths()
{
    int A[] = {1, 2, Nil, 5, Nil, Nil, 3};
    std::vector<std::string> expire;
    expire.push_back("1->2->5");
    expire.push_back("1->3");
    TreeNode* root = buildTree(A, countof(A));
    Solution s;
    assert(expire == s.binaryTreePaths(root));
}

int main()
{
    testBinaryTreePaths();
    return 0;
}
