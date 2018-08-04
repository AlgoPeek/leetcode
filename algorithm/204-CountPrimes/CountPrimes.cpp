// Source: https://leetcode.com/problems/count-primes/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Count the number of prime numbers less than a non-negative number, n.
//
// Example:
//
// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

#include <iostream>
#include <cassert>
#include <vector>

class Solution
{
    public:
        int countPrimes(int n)
        {
            std::vector<bool> isPrime(n, true);
            for (int i = 2; i * i < n; ++i)
            {
                if (!isPrime[i])
                {
                    continue;
                }
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }

            int count = 0;
            for (int i = 2; i < n; ++i)
            {
                if (isPrime[i])
                {
                    ++count;
                }
            }
            return count;
        }
};

void testCountPrimes()
{
    Solution s;
    assert(0 == s.countPrimes(2));
    assert(1 == s.countPrimes(3));
    assert(3 == s.countPrimes(7));
    assert(4 == s.countPrimes(11));
}

int main()
{
    testCountPrimes();
    return 0;
}
