// Source: https://leetcode.com/problems/binary-search-tree-iterator
// Author: Diego Lee
// Date: 2018-11-04
//
// Description:
// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
// Calling next() will return the next smallest number in the BST.
//
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
//
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

#include <vector>
#include <iostream>
#include <cassert>

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    std::vector<TreeNode*> _queue;
public:
    BSTIterator(TreeNode *root) {
        pushNextNode(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_queue.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (!hasNext()) {
            return 0;
        }

        TreeNode* node = _queue.back();
        _queue.pop_back();
        pushNextNode(node->right);
        return node->val;
    }

    void pushNextNode(TreeNode* node) {
        TreeNode* curr = node;
        while (curr != NULL) {
            _queue.push_back(curr);
            curr = curr->left;
        }
    }
};

void testBSTIterator() {
    // TODO
}

int main() {
    testBSTIterator();
    return 0;
}
