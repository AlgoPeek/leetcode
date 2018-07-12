// Source: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// Author: Diego Lee
// Date: 2018-07-11
//
// Description:
// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
// return its level order traversal as:
// [
//  [3],
//  [9,20],
//  [15,7]
// ]
//

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

#define LEAF_NODE -1
#define countof(A) (sizeof A/ sizeof A[0])

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef std::vector<std::vector<int>> Matrix;

class Solution {
    public:
        Matrix levelOrder(TreeNode* root) {
            Matrix matrix;
            if (root == NULL)
            {
                return matrix;
            }

            std::vector<int> level;
            std::queue<TreeNode*> Q;
            Q.push(root);
            while (!Q.empty())
            {
                level.clear();
                int size = Q.size();
                while (size-- > 0)
                {
                    TreeNode* node = Q.front();
                    if (node->left)
                    {
                        Q.push(node->left);
                    }
                    if (node->right)
                    {
                        Q.push(node->right);
                    }
                    level.push_back(node->val);
                    Q.pop();
                }
                if (!level.empty())
                {
                    matrix.push_back(level);
                }
            }
            return matrix;
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

void printMaxtrix(const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        std::for_each(matrix[i].begin(), matrix[i].end(), [&](int v){
                std::cout << v << " ";
                });
        std::cout << std::endl;
    }
}

void testLevelOrder()
{
    int A[] = {3, 9, LEAF_NODE, LEAF_NODE, 20, 15, LEAF_NODE, LEAF_NODE, 7};
    TreeNode* root = buildTree(A, countof(A));
    Matrix result = Solution().levelOrder(root);
    destroyTree(root);
    root = NULL;

    assert(result.size() == 3);
    // printMaxtrix(result);
    assert(result[0].size() == 1 && result[0][0] == 3);
    assert(result[1].size() == 2 && result[1][0] == 9 && result[1][1] == 20);
    assert(result[2].size() == 2 && result[2][0] == 15 && result[2][1] == 7);
}

int main()
{
    testLevelOrder();
    return 0;
}

