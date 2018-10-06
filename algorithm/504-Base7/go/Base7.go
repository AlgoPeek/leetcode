package solution

import (
    "fmt"
)

func convertToBase7(num int) string {
    if num == 0 {
        return "0"
    }

    negtive := false
    if num < 0 {
        negtive = true
        num = -num
    }

    result := ""
    base := 7
    for num > 0 {
        mod := num % base
        result = fmt.Sprint(mod) + result
        num /= base
    }
    if negtive {
        result = "-" + result
    }
    return result;
}
