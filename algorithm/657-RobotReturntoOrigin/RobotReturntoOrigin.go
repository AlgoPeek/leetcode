package main

import (
    "fmt"
)

func judgeCircle(moves string) bool {
    x := 0
    y := 0
    for i := 0; i < len(moves); i++ {
        if moves[i] == 'L' {
            x -= 1
        } else if moves[i] == 'U' {
            y -= 1
        } else if moves[i] == 'R' {
            x += 1
        } else if moves[i] == 'D' {
            y += 1
        }
    }
    return x == 0 && y == 0
}

func main() {
    r := judgeCircle("UD")
    fmt.Println("UD: ", r)
    r = judgeCircle("LL")
    fmt.Println("LL: ", r)
}

