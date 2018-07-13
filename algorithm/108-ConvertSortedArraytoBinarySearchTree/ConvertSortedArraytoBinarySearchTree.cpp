// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
// Author: Diego Lee
// Date: 2018-07-13
//
// Description:
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never
// differ by more than 1.
//
// Example:
// Given the sorted array: [-10,-3,0,5,9],
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//      0
//     / \
//   -3   9
//   /   /
// -10  5
//

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
        TreeNode* sortedArrayToBST(std::vector<int>& nums)
        {
            TreeNode* root = NULL;
            sortedArrayToBSTHelp(nums, 0, nums.size(), root);
            return root;
        }

        void sortedArrayToBSTHelp(std::vector<int>& nums, int start, int count, TreeNode*& node)
        {
            if (count <= 0)
            {
                return ;
            }

            int mid = count / 2;
            int leftcount = mid;
            // std::cout << "start=" << start <<  ", count=" << count << ", mid=" << mid << std::endl;
            node = new TreeNode(nums[start + mid]);
            sortedArrayToBSTHelp(nums, start, leftcount, node->left);
            sortedArrayToBSTHelp(nums, start + mid + 1, count - leftcount - 1, node->right);
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

std::vector<int> preOrderTraverse(TreeNode* root)
{
    std::vector<int> result;
    preOrderTraverseHelp(root, result);
    return result;
}

void testSortedArrayToBSTR(void)
{
    int A[] = {-10,-3,0,5,9};
    std::vector<int> nums(std::begin(A), std::end(A));
    TreeNode* root = Solution().sortedArrayToBST(nums);
    std::vector<int> result = preOrderTraverse(root);
    int B[] = {0,-3,-10,9,5};
    assert(result == std::vector<int>(std::begin(B), std::end(B)));
}

int main()
{
    testSortedArrayToBSTR();
    return 0;
}
