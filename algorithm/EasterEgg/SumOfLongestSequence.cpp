#include <iostream>
#include <assert.h>
#include <vector>

class Solution
{
    public:
        int longestSequence(const std::vector<int>& vec)
        {
            int sum = 0;
            int tmpsum = 0;
            for (size_t i = 0; i < vec.size(); ++i)
            {
                tmpsum += vec[i];
                if (tmpsum < 0) {
                    tmpsum = 0;
                }
                if (tmpsum > sum) {
                    sum = tmpsum;
                }
            }
            return sum;
        }
};

void testLongestSequence()
{
    std::vector<int> vec = {2, 1, -4, 2, 3, -1, 3};

    Solution sln;
    int r = sln.longestSequence(vec);
    assert(7 == r);
}

int main()
{
    testLongestSequence();
    return 0;
}

