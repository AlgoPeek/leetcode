package solution

import (
    "strconv"
)

func evalRPN(tokens []string) int {
    stack := []int{}
    for _, token := range tokens {
        if token == "+" || token == "-" || token == "*" || token == "/" {
            if len(stack) < 2 {
                return -1
            }

            oper1 := stack[len(stack) - 2]
            oper2 := stack[len(stack) - 1]
            stack = stack[:len(stack) - 2]
            curr := 0
            if token == "+" {
                curr = oper1 + oper2
            } else if token == "-" {
                curr = oper1 - oper2
            } else if token == "*" {
                curr = oper1 * oper2
            } else if token == "/" && oper2 != 0 {
                curr = oper1 / oper2
            } else {
                return -1
            }
            stack = append(stack, curr)
        } else {
            curr, _ := strconv.Atoi(token)
            stack = append(stack, curr)
        }
    }

    if len(stack) == 1 {
        return stack[0]
    }
    return -1
}
