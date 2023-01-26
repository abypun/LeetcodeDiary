func getSmallestString(n int, k int) string {
    ret := []byte(strings.Repeat("a", n))
    k -= n
    for i := n-1; i >= 0; i-- {
        if k <= 25 {
            ret[i] = ret[i]+byte(k)
            break
        } else {
            ret[i] = 'z'
            k -= 25
        }
    }
    return string(ret)
}
