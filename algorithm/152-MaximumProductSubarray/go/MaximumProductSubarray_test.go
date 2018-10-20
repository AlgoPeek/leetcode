package solution

import (
    "testing"
)

func TestMaxProduct(t * testing.T) {
    nums := []int{2,3,-2,4}
    result := maxProduct(nums)
    expect := 6
    if result != expect {
       t.Errorf("TestMaxProduct failed, got %d, expect %d", result, expect)
    }
}
