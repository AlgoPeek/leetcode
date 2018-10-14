package solution

import (
    "testing"
    "reflect"
)

func buildList(array []int) *ListNode {
    head := ListNode {
        Val: 0,
        Next: nil,
    }
    curr := &head
    for _, val := range array {
        curr.Next = &ListNode {
            Val: val,
            Next: nil,
        }
        curr = curr.Next
    }
    return head.Next
}

func convertToArray(head *ListNode) []int {
    array := []int{}
    curr := head
    for curr != nil {
        array = append(array, curr.Val)
        curr = curr.Next
    }
    return array
}

func TestSortList(t *testing.T) {
    array := []int {4, 2, 1, 3}
    head := buildList(array)
    result := sortList(head)
    sortArray := convertToArray(result)
    expected := []int{1,2,3,4}
    if !reflect.DeepEqual(sortArray, expected) {
       t.Errorf("TestSortList failed, got %+v, expected %+v", sortArray, expected)
    }
}

