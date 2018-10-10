package solution

import (
    "testing"
    "reflect"
)

func TestPartition(t *testing.T) {
    result := partition("aab")
    if !reflect.DeepEqual(result, [][]string{
        {"a","a","b"},
        {"aa", "b"},
    }) {
        t.Errorf("TestPartition failed")
    }
}
