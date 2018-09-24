package solution

func PeakIndexInMountainArray(A []int) int {
    n := len(A)
    if n < 3 {
        return -1
    }

    left := 0
    right := n - 1
    for left <= right {
        mid := (left + right) / 2
        if mid > 0 && mid < n - 1 && A[mid] > A[mid-1] && A[mid] > A[mid+1] {
            return mid
        } else if mid == 0 || A[mid] > A[mid - 1] {
            left = mid + 1
        } else if mid == n - 1 || A[mid] > A[mid + 1] {
            right = mid - 1
        } else {
            break
        }
    }
    return -1
}

