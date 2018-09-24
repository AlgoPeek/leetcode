package solution

import (
    "testing"
)

func TestPeakIndexInMountainArray(t *testing.T) {
    nums := []int{0, 2, 1, 0}
    result := PeakIndexInMountainArray(nums)
    if result != 1 {
        t.Errorf("PeakIndexInMoutainArray failed, got %d, expected 1", result)
    }
}
