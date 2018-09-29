package solution

import (
    "testing"
)

func TestFindMaxAverage(t *testing.T) {
    result := FindMaxAverage([]int{1,12,-5,-6,50,3}, 4)
    if result != 12.75 {
        t.Errorf("FindMaxAverage failed, got %f, expected 12.75", result)
    }
}
