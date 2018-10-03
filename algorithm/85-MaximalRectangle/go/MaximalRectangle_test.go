package solution

import (
    "testing"
)

func TestMaximalRectangle(t *testing.T) {
    matrix := [][]byte {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'},
    }

    result := MaximalRectangle(matrix)
    if result != 6 {
        t.Errorf("MaximalRectangle failed, got %d, expected 6", result)
    }
}
