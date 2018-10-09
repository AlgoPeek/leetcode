// Source: https://leetcode.com/problems/clone-graph/description/
// Author: Diego Lee
// Date: 2018-10-09
//
// Description:
// Given the head of a graph, return a deep copy (clone) of the graph. Each node in the graph contains a label (int) and a list (List[UndirectedGraphNode]) of its neighbors. There is an edge between the given node and each of the nodes in its neighbors.
//
// OJ's undirected graph serialization (so you can understand error output):
// Nodes are labeled uniquely.
//
// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
// The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//
// Visually, the graph looks like the following:
//
//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/
// Note: The information about the tree serialization is only meant so that you can understand error output if you get a wrong answer. You don't need to understand the serialization to solve the problem.

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> _hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        _hash.clear();
        return cloneGraphHelp(node);
    }

    UndirectedGraphNode *cloneGraphHelp(UndirectedGraphNode *node) {
        if (node == NULL) {
            return node;
        }

        if (_hash.find(node) != _hash.end()) {
            return _hash[node];
        }

        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        _hash[node] = clone;
        for (auto curr : node->neighbors) {
            clone->neighbors.push_back(cloneGraphHelp(curr));
        }
        return clone;
    }
};

void testCloneGraph(void) {
    // TODO
}

int main() {
    testCloneGraph();
    return 0;
}
