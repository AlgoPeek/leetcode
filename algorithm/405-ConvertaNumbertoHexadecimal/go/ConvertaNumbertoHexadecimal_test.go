package solution

import (
    "testing"
)

func TestToHex(t *testing.T) {
    result := toHex(26)
    expected := "1a"
    if result != expected {
        t.Errorf("TestToHex failed, got %s, expected %s", result, expected)
    }
}
