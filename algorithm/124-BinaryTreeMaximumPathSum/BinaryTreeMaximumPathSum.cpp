// Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author: Diego Lee
// Date: 2018-11-04
//
// Description:
// Given a non-empty binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// Example 1:
//
// Input: [1,2,3]
//
//        1
//       / \
//      2   3
//
// Output: 6
// Example 2:
//
// Input: [-10,9,20,null,null,15,7]
//
//    -10
//    / \
//   9  20
//     /  \
//    15   7
//
// Output: 42

#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            int maxsum = INT_MIN;
            maxPathSumHelp(root, maxsum);
            return maxsum;
        }

        int maxPathSumHelp(TreeNode* node, int& maxsum) {
            if (node == NULL) {
                return 0;
            }

            int leftmax = std::max(0, maxPathSumHelp(node->left, maxsum));
            int rightmax = std::max(0, maxPathSumHelp(node->right, maxsum));
            maxsum = std::max(maxsum, leftmax + rightmax + node->val);
            return std::max(leftmax, rightmax) + node->val;
        }
};

void testMaxPathSum() {
    // TODO
}

int main() {
    testMaxPathSum();
    return 0;
}
