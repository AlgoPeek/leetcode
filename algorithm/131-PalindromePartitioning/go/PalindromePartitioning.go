package solution

func partition(s string) [][]string {
    if len(s) == 0 {
        return [][]string{}
    }

    result := [][]string{}
    length := len(s)
    for i := 1; i <= length; i++ {
        part := s[:i]
        if isPalindrome(part) {
            if i == length {
                result = append(result, []string{part})
            } else {
                curr := partition(s[i:])
                if len(curr) != 0 {
                    for j, _ := range curr {
                        curr[j] = append(curr[j][:0], append([]string{part}, curr[j][0:]...)...)
                        result = append(result, curr[j])
                    }
                }
            }
        }
    }
    return result
}

func isPalindrome(s string) bool {
    left := 0
    right := len(s) - 1
    for left <= right {
        if s[left] != s[right] {
            return false
        }
        left += 1
        right -= 1
    }
    return true
}
