// Source: https://leetcode.com/problems/recover-binary-search-tree/description/
// Author: Diego Lee
// Date: 2018-10-05
//
// Description:
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
// Example 2:
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
// Follow up:
//
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?

#include <iostream>
#include <vector>
#include <cassert>

#define Nil 0

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* _firstNode;
    TreeNode* _secondNode;
    TreeNode* _prevNode;

    public:
        Solution() :
            _firstNode(NULL), _secondNode(NULL), _prevNode(NULL)
        {}

        void recoverTree(TreeNode* root) {
            traverse(root);
            if (_firstNode != NULL && _secondNode != NULL) {
                std::swap(_firstNode->val, _secondNode->val);
            }
        }

        void traverse(TreeNode* node) {
            if (node == NULL) {
                return;
            }

            traverse(node->left);
            if (_firstNode == NULL
                && _prevNode != NULL
                && _prevNode->val >= node->val) {
                _firstNode = _prevNode;
                // std::cout << "first=" << _firstNode->val << std::endl;
            }
            if (_firstNode != NULL
                && _prevNode != NULL
                && _prevNode->val >= node->val) {
                _secondNode = node;
                // std::cout << "second=" << _secondNode->val << std::endl;
            }
            _prevNode = node;
            traverse(node->right);
        }
};

void buildTreeHelp(const std::vector<int>& vec, int& i, TreeNode*& node) {
    if (i >= vec.size()) {
        return;
    }

    if (vec[i] == Nil) {
        ++i;
        return;
    }

    node = new TreeNode(vec[i++]);
    buildTreeHelp(vec, i, node->left);
    buildTreeHelp(vec, i, node->right);
}

TreeNode* buildTree(const std::vector<int>& vec) {
    int i = 0;
    TreeNode* root = NULL;
    buildTreeHelp(vec, i, root);
    return root;
}

void inorderTraverseHelp(TreeNode* node, std::vector<int>& vec) {
    if (node == NULL) {
        return;
    }

    inorderTraverseHelp(node->left, vec);
    vec.push_back(node->val);
    inorderTraverseHelp(node->right, vec);
}

std::vector<int> inorderTraverse(TreeNode* root) {
    std::vector<int> result;
    inorderTraverseHelp(root, result);
    return result;
}

void printVector(const std::vector<int>& vec) {
    for (auto n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

void testRecoverTreeCase1() {
    std::vector<int> nums = {1,3,Nil,2};
    TreeNode* root = buildTree(nums);
    printVector(inorderTraverse(root));

    Solution s;
    s.recoverTree(root);
    std::vector<int> result = inorderTraverse(root);
    printVector(result);
    assert(result == std::vector<int>({1,2,3}));
}

void testRecoverTreeCase2() {
    std::vector<int> nums = {3,1,Nil,Nil,4,2};
    TreeNode* root = buildTree(nums);
    printVector(inorderTraverse(root));

    Solution s;
    s.recoverTree(root);
    std::vector<int> result = inorderTraverse(root);
    printVector(result);
    assert(result == std::vector<int>({1,2,3,4}));
}

void RunTest() {
    testRecoverTreeCase1();
    testRecoverTreeCase2();
}

int main() {
    RunTest();
    return 0;
}
