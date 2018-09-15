// Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
// Author: Diego Lee
// Date: 2018-09-15
//
// Description:
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:
//
// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.

#include <iostream>
#include <vector>
#include <cassert>

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
        int sumNumbers(TreeNode* root)
        {
            int sum = 0;
            sumNumbersHelp(root, 0, sum);
            return sum;
        }

        void sumNumbersHelp(TreeNode* node, int curr, int& sum)
        {
            if (node == NULL)
            {
                return;
            }

            curr = curr * 10 + node->val;
            if (node->left == NULL && node->right == NULL)
            {
                sum += curr;
            }
            else
            {
                sumNumbersHelp(node->left, curr, sum);
                sumNumbersHelp(node->right, curr, sum);
            }
        }
};

void buildTreeHelp(const std::vector<int>& vec, int& i, TreeNode*& node)
{
    if (i >= vec.size())
    {
        return;
    }
    if (vec[i] == Nil)
    {
        ++i;
        return;
    }
    node = new TreeNode(vec[i++]);
    buildTreeHelp(vec, i, node->left);
    buildTreeHelp(vec, i, node->right);
}

TreeNode* buildTree(const std::vector<int>& vec)
{
    TreeNode* root = NULL;
    int i = 0;
    buildTreeHelp(vec, i, root);
    return root;
}

void testSumNumbers()
{
    std::vector<int> vec = {1, 2, Nil, Nil, 3};
    TreeNode* root = buildTree(vec);

    Solution s;
    int sum = s.sumNumbers(root);
    assert(sum == 25);
}

int main()
{
    testSumNumbers();
    return 0;
}
