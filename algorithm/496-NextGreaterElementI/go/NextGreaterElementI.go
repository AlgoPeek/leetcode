package solution

func NextGreaterElement(findNums []int, nums []int) []int {
    hash := map[int]int{}
    length := len(nums)
    for i := 0; i < length; i++ {
        val := -1
        for j := i + 1; j < length; j++ {
            if nums[j] > nums[i] {
                val = nums[j]
                break
            }
        }
        hash[nums[i]] = val
    }

    result := []int{}
    for i := 0; i < len(findNums); i++ {
        result = append(result, hash[findNums[i]])
    }
    return result
}
