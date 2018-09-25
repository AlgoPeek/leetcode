package solution

import (
    "testing"
)

func TestBinarySearchCase1(t *testing.T) {
    nums := []int{-1,0,3,5,9,12};
    target := 9
    result := Search(nums, target)
    if result != 4 {
        t.Errorf("Search failed, got %d, expected 4", result)
    }
}

func TestBinarySearchCase2(t *testing.T) {
    nums := []int{-1,0,3,5,9,12}
    target := 2
    result := Search(nums, target)
    if result != -1 {
        t.Errorf("Search failed, got %d, expected -1", result)
    }
}
