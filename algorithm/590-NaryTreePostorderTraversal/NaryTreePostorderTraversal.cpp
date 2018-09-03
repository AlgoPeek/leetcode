// Source: https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
// Author: Diego Lee
// Date: 2018-09-03
//
// Description:
// Given an n-ary tree, return the postorder traversal of its nodes' values.
//
// For example, given a 3-ary tree:
// Return its postorder traversal as: [5,6,3,2,4,1].
//
// Note: Recursive solution is trivial, could you do it iteratively?

#include <iostream>
#include <vector>
#include <cassert>

// Definition for a Node.
class Node
{
    public:
        int val;
        std::vector<Node*> children;

        Node() {}

        Node(int _val, std::vector<Node*> _children)
        {
            val = _val;
            children = _children;
        }
};

class Solution
{
    public:
        std::vector<int> postorder(Node* root)
        {
            std::vector<int> result;
            postorderHelp(root, result);
            return result;
        }

        void postorderHelp(Node* root, std::vector<int>& result)
        {
            if (root == NULL)
            {
                return;
            }

            for (Node* node : root->children)
            {
                postorderHelp(node, result);
            }
            result.push_back(root->val);
        }
};

class Tree
{
    public:
        Tree(int val) :
            _root(new Node)
        {
            _root->val = val;
        }

        Node* GetRoot()
        {
            return _root;
        }

        Node* AppendChildren(Node* parent, const std::vector<int>& children)
        {
            if (parent)
            {
                for (auto n : children)
                {
                    Node* node = new Node();
                    node->val = n;
                    parent->children.push_back(node);
                }
            }
            return parent;
        }
    private:
        Node* _root;
};

void testPostorder()
{
    Tree tree(1);
    Node* node = tree.AppendChildren(tree.GetRoot(), std::vector<int>({3, 2, 4}));
    tree.AppendChildren(node->children[0], std::vector<int>({5, 6}));

    Solution s;
    std::vector<int> result = s.postorder(tree.GetRoot());
    assert(result == std::vector<int>({5, 6, 3, 2, 4, 1}));
}

int main()
{
    testPostorder();
    return 0;
}

