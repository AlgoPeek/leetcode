// Source: https://leetcode.com/problems/merge-intervals/description/
// Author: Diego Lee
// Date: 2018-07-31
//
// Description:
// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator==(const Interval& lhs, const Interval& rhs)
{
    return (lhs.start == rhs.start) && (lhs.end == rhs.end);
}

bool operator<(const Interval& lhs, const Interval& rhs)
{
    return lhs.start < rhs.start;
}

class Solution
{
    public:
        std::vector<Interval> merge(std::vector<Interval>& intervals)
        {
            std::vector<Interval> result;
            if (intervals.empty())
            {
                return result;
            }

            std::sort(intervals.begin(), intervals.end());
            result.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); ++i)
            {
                Interval& last = result.back();
                Interval& curr = intervals[i];
                if (curr.start <= last.end)
                {
                    // overlapped
                    last.end = std::max(last.end, curr.end);
                }
                else
                {
                    result.push_back(curr);
                }
            }
            return result;
        }
};

void testMerge()
{
    std::vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    Solution s;
    std::vector<Interval> result = s.merge(intervals);
    assert(result.size() == 3);
    assert(result[0] == Interval(1, 6));
    assert(result[1] == Interval(8, 10));
    assert(result[2] == Interval(15, 18));
}

int main()
{
    testMerge();
    return 0;
}
