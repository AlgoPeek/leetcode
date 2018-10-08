// Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
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
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// Example:
//
// Given the following perfect binary tree,
//
//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// After calling your function, the tree should look like:
//
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

#include <iostream>
#include <vector>
#include <cassert>

#define Nil 0

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

            std::vector<TreeLinkNode*> S;
            S.push_back(root);
            while (!S.empty()) {
                std::vector<TreeLinkNode*> level;
                for (size_t i = 0; i < S.size(); ++i) {
                    if (i == S.size() - 1) {
                        S[i]->next = NULL;
                    }
                    else {
                        S[i]->next = S[i+1];
                    }
                    if (S[i]->left != NULL) {
                        level.push_back(S[i]->left);
                    }
                    if (S[i]->right != NULL) {
                        level.push_back(S[i]->right);
                    }
                }
                S.clear();
                S.swap(level);
            }
        }
};

void buildBinTreeHelp(const std::vector<int>& vec, int& i, TreeLinkNode*& node) {
    if (i >= vec.size()) {
        return;
    }

    if (vec[i] == Nil) {
        ++i;
        return;
    }

    node = new TreeLinkNode(vec[i++]);
    buildBinTreeHelp(vec, i, node->left);
    buildBinTreeHelp(vec, i, node->right);
}

TreeLinkNode* buildBinTree(const std::vector<int>& vec) {
    TreeLinkNode* root = NULL;
    int i = 0;
    buildBinTreeHelp(vec, i, root);
    return root;
}

std::vector<int> levelTraverse(TreeLinkNode* root) {
    TreeLinkNode* first = root;
    std::vector<int> result;
    while (first != NULL) {
        TreeLinkNode* curr = first;
        while (curr != NULL) {
            result.push_back(curr->val);
            curr = curr->next;
        }
        first = first->left;
    }
    return result;
}

void printVector(const std::vector<int>& vec) {
    for (auto n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

void testConnect(void) {
    std::vector<int> nums = {1, 2, 4,  Nil, Nil, 5, Nil, Nil, 3, 6, Nil, Nil, 7};
    TreeLinkNode* root = buildBinTree(nums);

    Solution s;
    s.connect(root);
    std::vector<int> level = levelTraverse(root);
    // printVector(level);
    assert(level == std::vector<int>({1,2,3,4,5,6,7}));
}

int main() {
    testConnect();
    return 0;
}
