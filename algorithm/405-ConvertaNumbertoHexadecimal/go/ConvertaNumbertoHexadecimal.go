package solution

func toHex(num int) string {
    if num == 0 {
        return "0"
    }

    hash := []string{"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"}
    n := uint32(num)
    result := ""
    for n != 0 {
        result = hash[n & 0x0f] + result
        n >>= 4
    }
    return result
}


