func areNumbersAscending(s string) bool {
    last, curr := -1, 0
    isdigit := func(i byte) bool {
        return '0' <= i && i <= '9'
    }
    for i := 0; i < len(s); i++ {
        if isdigit(s[i]) {
            curr = curr * 10 + int(s[i] - '0')
        } else if i > 0 && isdigit(s[i-1]) {
            if curr <= last {
                return false
            }
            last = curr
            curr = 0
        }
    }
    if isdigit(s[len(s)-1]) {
        return curr > last
    }
    return true
}