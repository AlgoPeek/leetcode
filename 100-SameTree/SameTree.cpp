// Source: https://leetcode.com/problems/same-tree/description/
// Author: Diego Lee
// Date: 2018-07-10
//
// Description:
// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
// Example 1:
// Input:     1         1
//           / \       / \
//          2   3     2   3
//         [1,2,3],   [1,2,3]
// Output: true
//
// Example 2:
// Input:     1         1
//           /           \
//          2             2
//        [1,2],     [1,null,2]
// Output: false
//
// Example 3:
// Input:     1         1
//           / \       / \
//          2   1     1   2
//        [1,2,1],   [1,1,2]
// Output: false
//

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) sizeof(A) / sizeof(A[0])

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode()
    {
        // std::cout << this << "(" << val << ")" " Destroyed" << std::endl;
    }
 };

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p != NULL && q != NULL)
        {
            return p->val == q->val
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
};

void createTreeHelp(int* A, int n, int& i, TreeNode*& node)
{
    if (i >= n)
    {
        return;
    }
    if (A[i] == 0)
    {
        ++i;
        return;
    }

    assert(node == NULL);
    node = new TreeNode(A[i++]);
    createTreeHelp(A, n, i, node->left);
    createTreeHelp(A, n, i, node->right);
}

TreeNode* createTree(int* A, int n)
{
    TreeNode* root = NULL;
    int index = 0;
    createTreeHelp(A, n, index, root);
    return root;
}

void DestroyTree(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
}

bool testIsSameTree(int* A1, int n1, int* A2, int n2)
{
    TreeNode* tree1 = createTree(A1, n1);
    TreeNode* tree2 = createTree(A2, n2);
    bool bSame = Solution().isSameTree(tree1, tree2);
    DestroyTree(tree1);
    DestroyTree(tree2);
    tree1 = NULL;
    tree2 = NULL;
    return bSame;
}

int main(void)
{
    int A1[] = {1, 2, 3};
    int A2[] = {1, 2, 3};
    assert(testIsSameTree(A1, countof(A1), A2, countof(A2)) == true);

    int A3[] = {1, 2};
    int A4[] = {1, 0, 2};
    assert(testIsSameTree(A3, countof(A3), A4, countof(A4)) == false);

    int A5[] = {1, 2, 1};
    int A6[] = {1, 1, 2};
    assert(testIsSameTree(A5, countof(A5), A6, countof(A6)) == false);
    return 0;
}
