package solution

const FLAG_O byte = 'O'
const FLAG_X byte = 'X'
const FLAG_1 byte = '1'

func solve(board [][]byte)  {
    if len(board) == 0 {
        return
    }

    row := len(board)
    col := len(board[0])
    for i := 0; i < row; i++ {
        if board[i][0] == FLAG_O {
            dfs(i, 1, board)
        }
        if col > 1 && board[i][col-1] == FLAG_O {
            dfs(i, col-2, board)
        }
    }
    for j := 1; j < col - 1; j++ {
        if board[0][j] == FLAG_O {
            dfs(1, j, board)
        }
        if row > 1 && board[row-1][j] == FLAG_O {
            dfs(row-2, j, board)
        }
    }

    for i := 1; i < row - 1; i++ {
        for j := 1; j < col - 1; j++ {
            if board[i][j] == FLAG_O {
                board[i][j] = FLAG_X
            } else if board[i][j] == FLAG_1 {
                board[i][j] = FLAG_O
            }
        }
    }
}

func dfs(i int, j int, board [][]byte) {
    if i <= 0 || j <= 0 || i >= len(board) - 1 || j >= len(board[0]) - 1 || board[i][j] == FLAG_X || board[i][j] == FLAG_1 {
        return
    }

    board[i][j] = FLAG_1
    dfs(i+1, j, board)
    dfs(i-1, j, board)
    dfs(i, j+1, board)
    dfs(i, j-1, board)
}


