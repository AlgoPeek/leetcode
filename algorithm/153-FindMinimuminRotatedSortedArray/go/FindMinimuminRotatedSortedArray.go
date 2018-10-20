package solution

func findMin(nums []int) int {
    length := len(nums)
    if length == 1 {
        return nums[0]
    }

    left := 0
    right := length - 1
    for left <= right {
        mid := left + (right - left) / 2
        if (mid < right) && (nums[mid] > nums[mid+1]) {
            return nums[mid+1]
        } else if (mid > left) && (nums[mid] < nums[mid-1]) {
            return nums[mid]
        } else if (nums[right] > nums[left]) {
            return nums[left]
        } else if nums[mid] > nums[left] {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    return 0;
}
