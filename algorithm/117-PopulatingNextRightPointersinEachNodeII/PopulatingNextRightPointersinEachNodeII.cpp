// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
// Author: Diego Lee
// Date: 2018-10-08
//
// Description:
// Given a binary tree
//
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.
// Example:
//
// Given the following binary tree,
//
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL

#include <iostream>
#include <vector>
#include <cassert>

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if (root == NULL) {
                return;
            }

            std::vector<TreeLinkNode*> level;
            level.push_back(root);
            while (!level.empty()) {
                std::vector<TreeLinkNode*> curr;
                curr.swap(level);
                for (size_t i = 0, len = curr.size(); i < len; ++i) {
                    if (i == len - 1) {
                        curr[i]->next = NULL;
                    }
                    else {
                        curr[i]->next = curr[i+1];
                    }

                    if (curr[i]->left != NULL) {
                        level.push_back(curr[i]->left);
                    }
                    if (level[i]->right != NULL) {
                        level.push_back(curr[i]->right);
                    }
                }
            }
        }
};

void testConnect(void) {
    // TODO
}

int main() {
    testConnect();
    return 0;
}
