// Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
// Author: Diego Lee
// Date: 2018-09-16
//
// Description:
// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

#include <iostream>
#include <vector>
#include <cassert>

#define Nil -1

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* _prev;
public:
    Solution() : _prev(NULL) {}

    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);
        root->right = _prev;
        root->left = NULL;
        _prev = root;
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
    TreeNode* root = NULL;
    int i = 0;
    buildTreeHelp(vec, i, root);
    return root;
}

std::vector<int> convertToVector(TreeNode* root) {
    std::vector<int> result;
    TreeNode* next = root;
    while (next != NULL) {
        result.push_back(next->val);
        next = next->right;
    }
    return result;
}

void testFlatten() {
    std::vector<int> vec = {1, 2, 3, Nil, Nil, 4, Nil, Nil, 5, Nil, 6};
    TreeNode* root = buildTree(vec);

    Solution s;
    s.flatten(root);
    std::vector<int> result = convertToVector(root);
    assert(result == std::vector<int>({1, 2, 3, 4, 5, 6}));
}

int main() {
    testFlatten();
    return 0;
}
