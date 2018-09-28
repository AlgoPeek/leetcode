package solution

import (
    "testing"
    "reflect"
)

func TestFindErrorNums(t *testing.T) {
    result := FindErrorNums([]int{1, 2, 2, 4})
    expected := []int{2, 3}
    if !reflect.DeepEqual(result, expected) {
        t.Errorf("FindErrorNums failed, got %+v, expected %+v", result, expected)
    }
}
