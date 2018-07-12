// Source: https://leetcode.com/problems/plus-one/description/
// Author: Diego Lee
// Date: 2018-07-11
//
// Description:
// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
// Example 2:
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//

#include <iostream>
#include <cassert>
#include <vector>

class Solution
{
    public:
        std::vector<int> plusOne(std::vector<int>& digits)
        {
            std::vector<int> result;
            if (digits.empty())
            {
                return result;
            }

            int carry = 1;
            int index = static_cast<int>(digits.size()) - 1;
            while (index >= 0 || carry > 0)
            {
                int s = carry;
                if (index >= 0)
                {
                    s += digits[index--];
                }
                carry = s / 10;
                s %= 10;
                result.push_back(s);
            }
            reverseInteger(result);
            return result;
        }
    private:
        void reverseInteger(std::vector<int>& v)
        {
            int left = 0;
            int right = static_cast<int>(v.size()) - 1;
            while (left < right)
            {
                std::swap(v[left++], v[right--]);
            }
        }
};

void testPlusOne()
{
    int A[] = {1, 2, 3};
    std::vector<int> digits(A, A + sizeof(A) / sizeof(int));
    std::vector<int> result = Solution().plusOne(digits);
    assert(result.size() == 3);
    assert(result[0] == 1 && result[1] == 2 && result[2] == 4);
}

int main()
{
    testPlusOne();
    return 0;
}
