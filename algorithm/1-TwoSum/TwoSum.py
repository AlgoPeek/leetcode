#!/usr/bin/env python
# encoding: utf-8

__author__ = 'Diego Lee'

'''
Source: https://leetcode.com/problems/two-sum/description/

Description:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

import unittest

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        dic = {}
        result = []
        for i in xrange(len(nums)):
            val = target - nums[i];
            if (dic.has_key(val)):
                result.append(dic[val])
                result.append(i);
                break
            else:
                dic[nums[i]] = i
        return result;

class TestSolution(unittest.TestCase):
    def testTwoSum(self):
        result = Solution().twoSum([2, 7, 11, 15], 9)
        self.assertEqual(result, [0, 1])

if __name__ == '__main__':
    unittest.main()
