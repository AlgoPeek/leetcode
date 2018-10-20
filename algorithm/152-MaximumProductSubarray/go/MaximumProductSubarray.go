package solution

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func maxProduct(nums []int) int {
    if len(nums) == 0 {
        return 0;
    }

    length := len(nums)
    dp_min := make([]int, length)
    dp_max := make([]int, length)
    m := nums[0]; dp_min[0] = nums[0]; dp_max[0] = nums[0]
    for i := 1; i < length; i++ {
        dp_min[i] = min(dp_min[i-1] * nums[i], min(dp_max[i-1] * nums[i], nums[i]))
        dp_max[i] = max(dp_max[i-1] * nums[i], max(dp_min[i-1] * nums[i], nums[i]))
        m = max(m, dp_max[i])
    }
    return m
}
