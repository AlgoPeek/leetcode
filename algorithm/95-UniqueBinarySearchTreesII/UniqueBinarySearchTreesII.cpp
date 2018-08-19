// Source: https://leetcode.com/problems/unique-binary-search-trees-ii/description/
// Author: Diego Lee
// Date: 2018-08-19
//
// Description:
// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
// Example:
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <vector>
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
        std::vector<TreeNode*> generateTrees(int n)
        {
            if (n <= 0)
            {
                return std::vector<TreeNode*>();
            }
            return generateTreesHelp(1, n);
        }

        std::vector<TreeNode*> generateTreesHelp(int start, int end)
        {
            std::vector<TreeNode*> result;
            if (start > end)
            {
                TreeNode* node = NULL;
                result.push_back(node);
                return result;
            }

            for (int i = start; i <= end; ++i)
            {
                std::vector<TreeNode*> leftTrees = generateTreesHelp(start, i - 1);
                std::vector<TreeNode*> rightTrees = generateTreesHelp(i + 1, end);
                for (TreeNode* left : leftTrees)
                {
                    for (TreeNode* right : rightTrees)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = left;
                        root->right = right;
                        result.push_back(root);
                    }
                }
            }
            return result;
        }
};

void convertToVector(TreeNode* node, std::vector<int>& vec)
{
    if (node == NULL)
    {
        return;
    }

    vec.push_back(node->val);
    convertToVector(node->left, vec);
    convertToVector(node->right, vec);
}

void printVector(const std::vector<int>& vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void testGenerateTrees()
{
    std::vector<std::vector<int>> expire =
    {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {3, 1, 2},
        {3, 2, 1}
    };

    Solution s;
    std::vector<TreeNode*> result = s.generateTrees(3);
    assert(result.size() == 5);
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::vector<int> tree;
        convertToVector(result[i], tree);
        // printVector(tree);
        assert(tree == expire[i]);
    }
}

int main()
{
    testGenerateTrees();
    return 0;
}
