package solution

func FindErrorNums(nums []int) []int {
    dict := map[int]int{}
    for _, n := range nums {
        if cnt, exist := dict[n]; !exist {
            dict[n] = 1
        } else {
            dict[n] = cnt + 1
        }
    }

    dup := -1
    miss := -1
    n := len(nums)
    for i := 1; i <= n; i++ {
        cnt, exits := dict[i]
        if !exits {
            miss = i
        } else if cnt == 2 {
            dup = i
        }
    }
    return []int{dup, miss}
}
