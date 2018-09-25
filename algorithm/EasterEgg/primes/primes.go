package main

import (
    "fmt"
    "os"
)

var goal int

func primetask(c chan int) {
    p := <-c

    if p > goal {
        fmt.Println()
        os.Exit(0)
    }

    fmt.Printf("%d ", p)

    nc := make(chan int)
    go primetask(nc)
    for {
        i := <-c
        if i % p != 0 {
            nc <- i
        }
    }
}

func main() {
    goal = 100
    fmt.Println("goal=", goal)

    c := make(chan int)
    go primetask(c)
    for i := 2;; i++ {
        c <- i
    }
}
