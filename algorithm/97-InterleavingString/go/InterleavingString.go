package solution

func IsInterleave(s1 string, s2 string, s3 string) bool {
    if len(s3) != len(s1) + len(s2) {
        return false
    }

    m := len(s1)
    n := len(s2)
    dp := make([][]bool, m + 1)
    for i := 0; i < m + 1; i++ {
        dp[i] = make([]bool, n + 1)
    }

    for i := 0; i < m + 1; i++ {
        for j := 0; j < n + 1; j++ {
            if i == 0 && j == 0 {
                dp[i][j] = true
            } else if i == 0 {
                dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1])
            } else if j == 0 {
                dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1])
            } else {
                dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) || (dp[i-1][j] && s1[i-1] == s3[i+j-1])
            }
        }
    }
    return dp[m][n]
}
