package solution

import (
    "testing"
    "reflect"
)

func TestSolve(t *testing.T) {
    board := [][]byte {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    }
    expected := [][]byte {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
    }

    solve(board)
    if !reflect.DeepEqual(board, expected) {
        t.Errorf("TestSolve failed, got %+v, expected %+v", board, expected)
    }
}
