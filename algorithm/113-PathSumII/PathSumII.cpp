// Source: https://leetcode.com/problems/path-sum-ii/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
//

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])
#define Nil -1

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix pathSum(TreeNode* root, int sum)
        {
            Matrix result;
            std::vector<int> curr;
            pathSumHelp(root, sum, curr, result);
            return result;
        }

        void pathSumHelp(TreeNode* root, int sum, std::vector<int>& curr, Matrix& matrix)
        {
            if (root == NULL)
            {
                return;
            }

            if (root->left == NULL
                    && root->right == NULL
                    && sum == root->val)
            {
                matrix.push_back(curr);
                matrix.back().push_back(root->val);
                return;
            }
            curr.push_back(root->val);
            pathSumHelp(root->left, sum - root->val, curr, matrix);
            pathSumHelp(root->right, sum - root->val, curr, matrix);
            curr.pop_back();
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

void testPathSum()
{
    int A[] = {5, 4, 11, 7, Nil, Nil, 2, Nil, Nil, Nil, 8, 13, Nil, Nil, 4, 5, Nil, Nil, 1};
    int R[2][4] =
    {
        {5,4,11,2},
        {5,8,4,5}
    };
    Matrix expire;
    expire.push_back(std::vector<int>(std::begin(R[0]), std::end(R[0])));
    expire.push_back(std::vector<int>(std::begin(R[1]), std::end(R[1])));

    TreeNode* root = buildTree(A, countof(A));
    Solution s;
    assert(s.pathSum(root, 22) == expire);
}

int main()
{
    testPathSum();
    return 0;
}
