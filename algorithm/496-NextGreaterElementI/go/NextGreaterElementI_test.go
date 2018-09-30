package solution

import (
    "testing"
    "reflect"
)

func TestNextGreaterElement(t *testing.T) {
    findNums := []int{4,1,2}
    nums := []int{1,3,4,2}
    result := NextGreaterElement(findNums, nums)
    expected := []int{-1,3,-1}
    if !reflect.DeepEqual(result, expected) {
        t.Errorf("NextGreaterElement failed, got %+v, expected %+v", result, expected)
    }
}
