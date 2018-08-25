// Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Author: Diego Lee
// Date: 2018-08-25
//
// Description:
// Given a binary tree, return the zigzag level order traversal of its nodes' values.
// (ie, from left to right, then right to left for the next level and alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include <iostream>
#include <vector>
#include <cassert>

#define Nil 0
#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;

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
        Matrix zigzagLevelOrder(TreeNode* root)
        {
            Matrix result;
            if (root == NULL)
            {
                return result;
            }

            bool fromLeft = true;
            std::vector<TreeNode*> level(1, root);
            while (!level.empty())
            {
                std::vector<int> curr;
                std::vector<TreeNode*> currLevel;
                currLevel.swap(level);
                for (TreeNode* node : currLevel)
                {
                    curr.push_back(node->val);
                    if (node->left)
                    {
                        level.push_back(node->left);
                    }
                    if (node->right)
                    {
                        level.push_back(node->right);
                    }
                }
                if (!fromLeft)
                {
                    reverseLevel(curr);
                }

                result.push_back(curr);
                fromLeft = !fromLeft;
            }
            return result;
        }

        void reverseLevel(std::vector<int>& level)
        {
            int left = 0;
            int right = level.size() - 1;
            while (left < right)
            {
                std::swap(level[left++], level[right--]);
            }
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

void testZigzagLevelOrder()
{
    int A[] = {3,9,Nil,Nil,20,15,Nil,Nil,7};
    TreeNode* root = buildTree(A, countof(A));

    Solution s;
    Matrix result = s.zigzagLevelOrder(root);
    assert(result.size() == 3);
    assert(result[0] == std::vector<int>({3}));
    assert(result[1] == std::vector<int>({20,9}));
    assert(result[2] == std::vector<int>({15,7}));
}

int main()
{
    testZigzagLevelOrder();
    return 0;
}
