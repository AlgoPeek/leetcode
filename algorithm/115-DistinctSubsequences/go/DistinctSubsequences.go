package solution

func numDistinct(s string, t string) int {
    slen := len(s)
    tlen := len(t)
    dp := [][]int{}
    for i := 0; i < tlen + 1; i++ {
        dp = append(dp, make([]int, slen + 1))
    }
    for j := 0; j < slen + 1; j++ {
        dp[0][j] = 1
    }

    for i := 0; i < tlen; i++ {
        for j := 0; j < slen; j++ {
            if t[i] == s[j] {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j]
            } else {
                dp[i+1][j+1] = dp[i+1][j]
            }
        }
    }

    return dp[tlen][slen]
}
