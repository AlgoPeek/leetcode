package solution

func findMin(nums []int) int {
    length := len(nums)
    if length == 0 {
        return -1
    }

    left := 0
    right := length - 1
    for left < right {
        mid := left + (right - left) / 2
        if nums[mid] > nums[right] {
            left = mid + 1
        } else if nums[mid] < nums[right] {
            right = mid
        } else {
            right -= 1;
        }
    }
    return nums[left]
}
