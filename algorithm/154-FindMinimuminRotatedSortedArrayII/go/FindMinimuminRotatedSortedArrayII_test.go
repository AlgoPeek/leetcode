package solution

import (
    "testing"
)

func TestFinMin(t *testing.T) {
    nums := []int{1,3,5}
    result := findMin(nums)
    expect := 1
    if result != expect {
        t.Errorf("TestFindMin failed, got %d, expect %d", result, expect)
    }
}
