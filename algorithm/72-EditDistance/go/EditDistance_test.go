package solution

import (
    "testing"
)

func TestMinDistanceCase1(t* testing.T) {
    result := MinDistance("horse", "ros")
    if result != 3 {
        t.Errorf("MinDistance('horse', 'ros') failed, got %d, expected 3", result)
    }
}

func TestMinDistanceCase2(t* testing.T) {
    result := MinDistance("intention", "execution")
    if result != 5 {
        t.Errorf("MinDistance('intention', 'execution') failed, got %d, expected 5", result)
    }
}
