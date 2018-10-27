package solution

import (
    "testing"
)

func TestNumDistinct(t *testing.T) {
    s1 := "rabbbit"
    t1 := "rabbit"
    result := numDistinct(s1, t1)
    expect := 3
    if result != expect {
        t.Errorf("TestNumDistinct failed, got %d, expect %d", result, expect)
    }
}
