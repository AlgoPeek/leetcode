package solution

import (
    "testing"
)

func TestGetSumCase1(t *testing.T) {
    sum := GetSum(1, 2)
    if sum != 3 {
        t.Errorf("GetSum(1,2) failed, got %d, expected 3", sum)
    }
}

func TestGetSumCase2(t *testing.T) {
    sum := GetSum(-2, 3)
    if sum != 1 {
        t.Errorf("GetSum(-2, 3) failed, got %d, expected 1", sum)
    }
}
