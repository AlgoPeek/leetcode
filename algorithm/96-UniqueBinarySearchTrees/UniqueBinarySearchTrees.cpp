// Source: https://leetcode.com/problems/unique-binary-search-trees/description/
// Author: Diego Lee
// Date: 2018-08-07
//
// Description:
// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <vector>
#include <cassert>

// Given a sequence 1…n, to construct a Binary Search Tree (BST) out of the sequence,
// we could enumerate each number i in the sequence, and use the number as the root.
// naturally, the subsequence 1…(i-1) on its left side would lay on the left branch of
// the root, and similarly the right subsequence (i+1)…n lay on the right branch of the root.
// We then can construct the subtree from the subsequence recursively. Through the above
// approach, we could ensure that the BST that we construct are all unique, since they have unique roots.
class Solution
{
    public:
        int numTrees(int n)
        {
            if (n <= 0)
            {
                return 0;
            }

            std::vector<int> dp(n + 1);
            dp[0] = dp[1] = 1;
            for (int i = 2; i <= n; ++i)
            {
                for (int j = 1; j <= i; ++j)
                {
                    dp[i] += dp[j-1] * dp[i-j];
                }
            }
            return dp.back();
        }
};

void testNumTrees()
{
    Solution s;
    assert(s.numTrees(3) == 5);
}

int main()
{
    testNumTrees();
    return 0;
}
