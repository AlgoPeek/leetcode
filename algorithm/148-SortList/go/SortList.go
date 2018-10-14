package solution

// Definition for singly-linked list.
type ListNode struct {
    Val int
    Next *ListNode
}

func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    var prev *ListNode
    slow := head
    fast := head
    for fast != nil && fast.Next != nil {
        prev = slow
        slow = slow.Next
        fast = fast.Next.Next
    }

    prev.Next = nil
    return mergeList(sortList(head), sortList(slow))
}

func mergeList(head1 *ListNode, head2 *ListNode) *ListNode {
    fakeNode := &ListNode {
        Val: 0,
        Next: nil,
    }

    curr := fakeNode
    L1 := head1
    L2 := head2
    for L1 != nil && L2 != nil {
        if L1.Val < L2.Val {
            curr.Next = L1
            L1 = L1.Next
        } else {
            curr.Next = L2
            L2 = L2.Next
        }
        curr = curr.Next
    }
    if L1 != nil {
        curr.Next = L1
    }
    if L2 != nil {
        curr.Next = L2
    }
    return fakeNode.Next
}
