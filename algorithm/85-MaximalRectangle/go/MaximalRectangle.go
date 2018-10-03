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

func MaximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }

    m := len(matrix)
    n := len(matrix[0])
    left := make([]int, n)
    right := make([]int, n)
    height := make([]int, n)
    for j := 0; j < n; j++ {
        right[j] = n
    }

    var maxArea int = 0
    for i := 0; i < m; i++ {
        // compute height
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                height[j]++
            } else {
                height[j] = 0
            }
        }

        // compute left, from left to right
        curr_left := 0
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                left[j] = max(left[j], curr_left)
            } else {
                left[j] = 0
                curr_left = j + 1
            }
        }

        // compute right, from right to left
        curr_right := n
        for j := n - 1; j >= 0; j-- {
            if matrix[i][j] == '1' {
                right[j] = min(right[j], curr_right)
            } else {
                right[j] = n
                curr_right = j
            }
        }

        // compute max area
        for j := 0; j < n; j++ {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j])
        }
    }
    return maxArea
}
