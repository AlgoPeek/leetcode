// Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
// Author: Diego Lee
// Date: 2018-07-11
//
// Description:
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7]
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its bottom-up level order traversal as:
//
// [
//  [15,7],
//  [9,20],
//  [3]
// ]
//

#include <iostream>
#include <vector>
#include <cassert>

#define LEAF_NODE -1
#define countof(A) (sizeof A / sizeof(A[0]))

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
        Matrix levelOrderBottom(TreeNode* root)
        {
            Matrix result;
            if (root == NULL)
            {
                return result;
            }

            std::vector<TreeNode*> vec;
            vec.push_back(root);
            levelOrderBottomHelp(vec, 0, static_cast<int>(vec.size()), result);
            return result;
        }

    private:
        void levelOrderBottomHelp(std::vector<TreeNode*>& vec, int start, int count,
                Matrix& matrix)
        {
            if (count <= 0)
            {
                return;
            }

            std::vector<int> level;
            for (int i = 0; i < count; ++i)
            {
                TreeNode* node = vec[start + i];
                if (node->left != NULL)
                {
                    vec.push_back(node->left);
                }
                if (node->right != NULL)
                {
                    vec.push_back(node->right);
                }
                level.push_back(node->val);
            }
            start += count;
            int levelcount = static_cast<int>(vec.size()) - start;
            levelOrderBottomHelp(vec, start, levelcount, matrix);
            matrix.push_back(level);
        }
};

void buildTreeHelp(int* A, int n, int& i, TreeNode*& node)
{
    if (i >= n)
    {
        return;
    }
    if (A[i] == LEAF_NODE)
    {
        ++i;
        return;
    }

    assert(node == NULL);
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

void destroyTree(TreeNode* node)
{
    if (node == NULL)
    {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

void testLevelOrderBottom()
{
    int A[] = {3, 9, LEAF_NODE, LEAF_NODE, 20, 15, LEAF_NODE, LEAF_NODE, 7};
    TreeNode* root = buildTree(A, countof(A));
    Matrix result = Solution().levelOrderBottom(root);
    destroyTree(root);
    root = NULL;

    assert(result.size() == 3);
    assert(result[0].size() == 2 && result[0][0] == 15 && result[0][1] == 7);
    assert(result[1].size() == 2 && result[1][0] == 9 && result[1][1] == 20);
    assert(result[2].size() == 1 && result[2][0] == 3);
}

int main()
{
    testLevelOrderBottom();
    return 0;
}
