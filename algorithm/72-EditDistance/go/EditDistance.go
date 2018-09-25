package solution

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func MinDistance(word1 string, word2 string) int {
    m := len(word1)
    n := len(word2)
    dp := [][]int{}
    for i := 0; i < m + 1; i++ {
        t := make([]int, n + 1)
        dp = append(dp, t)
    }

    for i := 1; i <= m; i++ {
        dp[i][0] = i
    }
    for j := 1; j <= n; j++ {
        dp[0][j] = j
    }

    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            if word1[i-1] == word2[j-1] {
                dp[i][j] = dp[i-1][j-1]
            } else {
                dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1))
            }
        }
    }
    return dp[m][n]
}
