package solution

import (
    "testing"
)

func TestLongestConsecutive(t *testing.T) {
    nums := []int{100,4,200,1,3,2}
    result := longestConsecutive(nums)
    expect := 4
    if result != expect {
        t.Errorf("TestLongestConsecutive failed, got %d, expect %d", result, expect)
    }
}
