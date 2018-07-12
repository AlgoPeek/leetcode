// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Author: Diego Lee
// Date: 2018-07-12
//
// Description:
// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
// For example, given
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
//
// Return the following binary tree:
//     3
//    / \
//   9  20
//     /  \
//    15   7
//

#include <iostream>
#include <cassert>
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
        TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
        {
            TreeNode* root = NULL;
            buildTreeHelp(inorder, 0, inorder.size(), postorder, 0, root);
            return root;
        }
    private:
        void buildTreeHelp(std::vector<int>& inorder, int inStart, int count,
                std::vector<int>& postorder, int postStart, TreeNode*& node)
        {
            if (count <= 0)
            {
                return;
            }

            int mid = -1;
            int inorderVal = postorder[postStart + count - 1];
            for (int i = 0; i < count; ++i)
            {
                int index = inStart + i;
                if (inorder[index] == inorderVal)
                {
                    mid = index;
                    break;
                }
            }
            assert(mid != -1);
            assert(node == NULL);
            node = new TreeNode(inorder[mid]);

            int leftcount = mid - inStart;
            int rightcount = count - leftcount - 1;
            // build left tree
            buildTreeHelp(inorder, inStart, leftcount, postorder, postStart, node->left);

            // build right tree
            buildTreeHelp(inorder, mid + 1, rightcount, postorder, postStart + leftcount, node->right);
        }
};

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

void postOrderTraverseHelp(TreeNode* root, std::vector<int>& vec)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraverseHelp(root->left, vec);
    postOrderTraverseHelp(root->right, vec);
    vec.push_back(root->val);
}

std::vector<int> inOrderTraverse(TreeNode* root)
{
    std::vector<int> result;
    inOrderTraverseHelp(root, result);
    return result;
}

std::vector<int> postOrderTraverse(TreeNode* root)
{
    std::vector<int> result;
    postOrderTraverseHelp(root, result);
    return result;
}

void testBuildTree(void)
{
    int A[] = {9,3,15,20,7};
    int B[] = {9,15,7,20,3};

    std::vector<int> inorder(A, A + countof(A));
    std::vector<int> postorder(B, B + countof(B));
    TreeNode* root = Solution().buildTree(inorder, postorder);
    std::vector<int> result = inOrderTraverse(root);
    assert(result == inorder);
    result = postOrderTraverse(root);
    assert(result == postorder);
}

int main()
{
    testBuildTree();
    return 0;
}
