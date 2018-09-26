package solution

func FindNthDigit(n int) int {
    base := 9
    digits := 1
    for n > base * digits {
        n -= base * digits
        base *= 10
        digits++
    }

    index := n % digits
    if index == 0 {
        index = digits
    }
    num := 1
    for i := 1; i < digits; i++ {
        num *= 10
    }
    if index == digits {
        num += n / digits - 1
    } else {
        num += n / digits
    }

    for i := index; i < digits; i++ {
        num /= 10
    }
    return num % 10
}

