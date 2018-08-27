// Source: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
// Author: Diego Lee
// Date: 2018-08-27
//
// Description:
// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example, given a 3-ary tree:
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
//
// Note:
//
// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

// Definition for a Node.
class Node
{
    public:
        int val;
        std::vector<Node*> children;

        Node(): val(0) {}

        Node(int _val, std::vector<Node*> _children)
        {
            val = _val;
            children = _children;
        }
};

class Solution
{
    public:
        std::vector<std::vector<int>> levelOrder(Node* root)
        {
            std::vector<std::vector<int>> result;
            if (root == NULL)
            {
                return result;
            }

            std::vector<Node*> level;
            level.push_back(root);
            while (!level.empty())
            {
                result.push_back(std::vector<int>());
                std::vector<Node*> nextLevel;
                for (Node* node : level)
                {
                    result.back().push_back(node->val);
                    for (Node* child : node->children)
                    {
                        nextLevel.push_back(child);
                    }
                }
                level.clear();
                level.swap(nextLevel);
            }
            return result;
        }
};

std::vector<Node*> convertToNodeVector(const std::vector<int>& vec)
{
    std::vector<Node*> children;
    for (auto val : vec)
    {
        Node* node = new Node();
        node->val = val;
        children.push_back(node);
    }
    return children;
}

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (auto vec : matrix)
    {
        for (auto val : vec)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void testLevelOrder()
{
    Node* root = new Node();
    root->val = 1;
    root->children = convertToNodeVector(std::vector<int>({3, 2, 4}));
    root->children[0]->children = convertToNodeVector(std::vector<int>({5, 6}));

    Solution s;
    std::vector<std::vector<int>> result = s.levelOrder(root);
    // printMatrix(result);
    assert(result.size() == 3);
    assert(result[0] == std::vector<int>({1}));
    assert(result[1] == std::vector<int>({3, 2, 4}));
    assert(result[2] == std::vector<int>({5, 6}));
}

int main()
{
    testLevelOrder();
    return 0;
}
