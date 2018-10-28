package solution

import (
    "testing"
)

func TestMaxProfit(t *testing.T) {
    nums := []int{3,3,5,0,0,3,1,4}
    result := maxProfit(nums)
    expect := 6
    if result != expect {
        t.Errorf("TestMaxProfit failed, got %d, expect %d", result, expect)
    }
}
