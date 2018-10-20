package solution

import (
    "testing"
)

func TestFindMin(t *testing.T) {
    nums := []int{3,4,5,1,2}
    result := findMin(nums)
    expect := 1
    if result != expect {
        t.Errorf("TestFindMin failed, got %d, expect %d", result, expect)
    }
}
