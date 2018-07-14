// Source: https://leetcode.com/problems/4sum/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d =
// target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
// The solution set must not contain duplicate quadruplets.
//
// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix;
class Solution
{
    public:
        Matrix fourSum(std::vector<int>& nums, int target)
        {
            Matrix result;
            if (nums.size() < 4)
            {
                return result;
            }

            std::sort(nums.begin(), nums.end());
            int cnt = nums.size();
            for (int i = 0; i < cnt - 3; ++i)
            {
                // skip duplication
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                std::vector<int> v(nums.begin() + i + 1, nums.end());
                Matrix r = threeSum(v, target - nums[i]);
                for (int j = 0; j < r.size(); ++j)
                {
                    r[j].insert(r[j].begin(), nums[i]);
                    result.push_back(r[j]);
                }
            }
            return result;
        }

    private:
        Matrix threeSum(std::vector<int>& nums, int target)
        {
            Matrix result;
            std::sort(nums.begin(), nums.end());

            int cnt = nums.size();
            for (int i = 0; i < cnt - 2; ++i)
            {
                // skip duplication
                if (i > 0 && nums[i - 1] == nums[i])
                {
                    continue;
                }

                int left = i + 1;
                int right = cnt - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        std::vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        result.push_back(v);

                        // skip duplication
                        while (left < cnt - 1 && nums[left] == nums[left + 1])
                        {
                            ++left;
                        }
                        while (right > 0 && nums[right] == nums[right - 1])
                        {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                    else if (sum  > target)
                    {
                        while (right > 0 && nums[right] == nums[right - 1])
                        {
                            --right;
                        }
                        --right;
                    }
                    else
                    {
                        while (left < cnt - 1 && nums[left] == nums[left + 1])
                        {
                            ++left;
                        }
                        ++left;
                    }
                }
            }
            return result;
        }
};

void testFourSum()
{
    int A[] = {1, 0, -1, 0, -2, 2};
    std::vector<int> vec(std::begin(A), std::end(A));

    int M[][4] =
    {
        {-2, -1, 1, 2},
        {-2, 0, 0, 2},
        {-1, 0, 0, 1}
    };

    Matrix expire;
    for (int i = 0; i < 3; ++i)
    {
        expire.push_back(std::vector<int>(std::begin(M[i]), std::end(M[i])));
    }
    assert(expire == Solution().fourSum(vec, 0));
}

int main()
{
    testFourSum();
    return 0;
}
