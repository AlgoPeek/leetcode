package solution

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func longestConsecutive(nums []int) int {
    s := map[int]bool{}
    for _, n := range nums {
        s[n] = true
    }

    maxlen := 0
    for n, _ := range s {
        if !s[n-1] {
            k := n + 1
            for s[k] == true {
                k += 1
            }
            maxlen = max(maxlen, k - n)
        }
    }
    return maxlen
}
