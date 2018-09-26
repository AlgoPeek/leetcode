package solution

import (
    "testing"
)

func TestFindNthDigit(t *testing.T) {
    result := FindNthDigit(11)
    if result != 0 {
        t.Errorf("FindNthDigit(11) failed, got %d, expected 0", result)
    }
}

