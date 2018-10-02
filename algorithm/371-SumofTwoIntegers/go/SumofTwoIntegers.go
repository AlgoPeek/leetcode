package solution

func GetSum(a int, b int) int {
    for b != 0 {
        carry := a & b
        a ^= b
        b = carry << 1
    }
    return a
}
