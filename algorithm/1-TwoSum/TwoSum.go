// Source: https://leetcode.com/problems/two-sum/description/
// Author: Diego Lee
// Date: 2018-09-11

// Description:
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

package main

import "fmt"

func twoSum(nums []int, target int) []int {
    var result []int
    var dict map[int]int
    dict = make(map[int]int)
    for i, n := range nums {
        val := target - n
        index, ok := dict[val]
        if (ok) {
            result = append(result, index)
            result = append(result, i)
            break
        } else {
            dict[n] = i
        }
    }
    return result
}

func testTwoSum() {
    var nums = []int {2, 7, 11, 15}
    var target int = 9

    result := twoSum(nums, target)
    fmt.Println(result)
}

func main() {
    testTwoSum()
}
