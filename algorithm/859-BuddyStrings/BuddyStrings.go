package main

import (
    "fmt"
)

func buddyStrings(A string, B string) bool {
    if len(A) != len(B) {
        return false
    }

    result := false
    if A == B {
        hash := map[byte]int{}
        for i := 0; i < len(A); i++ {
            hash[A[i]] += 1
        }
        for _, val := range hash {
            if val > 1 {
                result = true
            }
        }
    } else {
        first := -1; second := -1
        for i := 0; i < len(A); i++ {
            if A[i] == B[i] {
                continue
            }

            if first == -1 {
                first = i
            } else if second == -1 {
                second = i
            } else {
                return false
            }
        }
        result = (first != -1) && (second != -1) && (A[first] == B[second]) && (B[first] == A[second])
    }
    return result
}

func main() {
    result := buddyStrings("ab", "ba")
    fmt.Println("[ab,ba]=", result)
    result = buddyStrings("aa", "aa")
    fmt.Println("[aa,aa]=", result)
    result = buddyStrings("ab", "ab")
    fmt.Println("[ab,ab]=", result)
}
