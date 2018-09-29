package solution

func FindMaxAverage(nums []int, k int) float64 {
    if k <= 0 || k > len(nums) {
        return float64(0)
    }

    var sum int = 0
    for i := 0; i < k; i++ {
        sum += nums[i]
    }

    maxAverage := float64(sum) / float64(k)
    for i := k; i < len(nums); i++ {
        sum += (nums[i] - nums[i-k])
        aver := float64(sum) / float64(k)
        if aver > maxAverage {
            maxAverage = aver
        }
    }
    return maxAverage
}
