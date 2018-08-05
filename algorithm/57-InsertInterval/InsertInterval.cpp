// Source: https://leetcode.com/problems/insert-interval/description/
// Author: Diego Lee
// Date: 2018-08-01
//
// Description
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

#define countof(A) (sizeof A / sizeof A[0])

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
        std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval)
        {
            intervals.push_back(newInterval);
            int j = intervals.size() - 1;
            while (j > 0 && intervals[j] < intervals[j-1])
            {
                std::swap(intervals[j], intervals[j-1]);
                --j;
            }

            std::vector<Interval> result;
            result.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); ++i)
            {
                Interval& last = result.back();
                Interval& curr = intervals[i];
                if (curr.start <= last.end)
                {
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

void testInsert()
{
    std::vector<Interval> intervals1;
    intervals1.push_back(Interval(1,3));
    intervals1.push_back(Interval(6,9));

    std::vector<Interval> intervals2;
    intervals2.push_back(Interval(1,2));
    intervals2.push_back(Interval(3,5));
    intervals2.push_back(Interval(6,7));
    intervals2.push_back(Interval(8,10));
    intervals2.push_back(Interval(12,16));

    Solution s;
    std::vector<Interval> result = s.insert(intervals1, Interval(2,5));
    assert(result.size() == 2);
    assert(result[0] == Interval(1,5));
    assert(result[1] == Interval(6,9));

    result = s.insert(intervals2, Interval(4,8));
    assert(result.size() == 3);
    assert(result[0] == Interval(1,2));
    assert(result[1] == Interval(3,10));
    assert(result[2] == Interval(12,16));
}

int main()
{
    testInsert();
    return 0;
}
