package solution

func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func Min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

// dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
// For k transactions, on i-th day,
// if we don't trade then the profit is same as previous day dp[k, i-1];
// and if we bought the share on j-th day where j=[0..i-1], then sell the share // on i-th day then the profit is prices[i] - prices[j] + dp[k-1, j-1] .
func maxProfit(prices []int) int {
    if len(prices) == 0 {
        return 0
    }

    dp := [][]int{}
    for k := 0; k < 3; k++ {
        dp = append(dp, make([]int, len(prices)))
    }

    for k := 1; k < 3; k++ {
        min := prices[0]
        for i := 1; i < len(prices); i++ {
            min = Min(min, prices[i] - dp[k-1][i-1])
            dp[k][i] = Max(dp[k][i-1], prices[i] - min)
        }
    }
    return dp[2][len(prices) - 1]
}
