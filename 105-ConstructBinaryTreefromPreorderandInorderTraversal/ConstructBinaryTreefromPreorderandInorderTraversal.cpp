// Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// Author: Diego Lee
// Date: 2018-07-12
//
// Description:
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
// For example, given
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
#include <iostream>
#include <vector>

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
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
        {
            TreeNode* root = NULL;
            buildTreeHelp(preorder, 0, inorder, 0, inorder.size(), root);
            return root;
        }

    private:
        void buildTreeHelp(const std::vector<int>& preorder, int preStart,
                const std::vector<int>& inorder, int inStart, int count, TreeNode*& node)
        {
            if (count <= 0)
            {
                return;
            }

            int mid = -1;
            for (int k = 0; k < count; ++k)
            {
                int index = inStart + k;
                if (inorder[index] == preorder[preStart])
                {
                    mid = index;
                    break;
                }
            }
            assert(mid != -1);
            assert(node == NULL);
            node = new TreeNode(inorder[mid]);

            int leftcount = mid - inStart;
            buildTreeHelp(preorder, preStart + 1, inorder, inStart, leftcount, node->left);
            buildTreeHelp(preorder, preStart + leftcount + 1, inorder, mid + 1,
                    count - leftcount - 1, node->right);
        }
};

void preOrderTraverseHelp(TreeNode* root, std::vector<int>& vec)
{
    if (root == NULL)
    {
        return;
    }

    vec.push_back(root->val);
    preOrderTraverseHelp(root->left, vec);
    preOrderTraverseHelp(root->right, vec);
}

void inOrderTraverseHelp(TreeNode* root, std::vector<int>& vec)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraverseHelp(root->left, vec);
    vec.push_back(root->val);
    inOrderTraverseHelp(root->right, vec);
}

std::vector<int> preOrderTraverse(TreeNode* root)
{
    std::vector<int> result;
    preOrderTraverseHelp(root, result);
    return result;
}

std::vector<int> inOrderTraverse(TreeNode* root)
{
    std::vector<int> result;
    inOrderTraverseHelp(root, result);
    return result;
}

void testBuildTree()
{
    int A[] = {3,9,20,15,7};
    int B[] = {9,3,15,20,7};
    std::vector<int> preorder(A, A + countof(A));
    std::vector<int> inorder(B, B + countof(B));

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    std::vector<int> result = preOrderTraverse(root);
    assert(result == preorder);
    result = inOrderTraverse(root);
    assert(result == inorder);
}

int main(void)
{
    testBuildTree();
    return 0;
}
