package solution

import (
    "testing"
)

func TestIsInterleaveCase1(t *testing.T) {
    s1 := "aabcc"
    s2 := "dbbca"
    s3 := "aadbbcbcac"
    result := IsInterleave(s1, s2, s3)
    if result != true {
        t.Errorf("IsInterleave failed, got false, expected true")
    }
}

func TestIsInterleaveCase2(t *testing.T) {
    s1 := "aabcc"
    s2 := "dbbca"
    s3 := "aadbbbaccc"
    result := IsInterleave(s1, s2, s3)
    if result != false {
        t.Errorf("IsInterleave failed, got true, expected false")
    }
}
