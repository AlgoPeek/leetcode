// Source: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
// Author: Diego Lee
// Date: 2018-08-20
//
// Description:
// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
// Note: There are at least two nodes in this BST.

#include <iostream>
#include <cassert>


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
        int getMinimumDifference(TreeNode* root)
        {
            if (root == NULL)
            {
                return INT_MAX;
            }

            int leftMinDiff = INT_MAX;
            int rightMinDiff = INT_MAX;
            if (root->left)
            {
                int diff = root->val - getMaxVal(root->left);
                leftMinDiff = std::min(diff, getMinimumDifference(root->left));
            }
            if (root->right)
            {
                int diff = getMinVal(root->right) - root->val;
                rightMinDiff = std::min(diff, getMinimumDifference(root->right));
            }
            return std::min(leftMinDiff, rightMinDiff);
        }

        int getMaxVal(TreeNode* node)
        {
            int maxVal = 0;
            while (node != NULL)
            {
                maxVal = node->val;
                node = node->right;
            }
            return maxVal;
        }

        int getMinVal(TreeNode* node)
        {
            int minVal = 0;
            while (node != NULL)
            {
                minVal = node->val;
                node = node->left;
            }
            return minVal;
        }
};

void testGetMinimumDifference()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    Solution s;
    assert(s.getMinimumDifference(root) == 1);
}

int main()
{
    testGetMinimumDifference();
    return 0;
}
