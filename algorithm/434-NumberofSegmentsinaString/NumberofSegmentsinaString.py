#!/usr/bin/env python
# encoding: utf-8

'''
Source: https://leetcode.com/problems/number-of-segments-in-a-string/description/
Author: Diego Lee
Date: 2018-08-17

Description:
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
'''

import unittest

class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = 0
        pos = 0
        n = len(s)
        for i in xrange(n):
            if s[i] == ' ':
                if i != pos:
                    cnt += 1
                pos = i + 1
            elif i == n - 1:
                cnt += 1
        return cnt

class TestSolution(unittest.TestCase):
    def testCountSegments(self):
        result = Solution().countSegments("Hello, my name is John")
        self.assertEqual(result, 5)

if __name__ == '__main__':
    unittest.main()
