func countAsterisks(s string) int {
    inLine := false
    cnt := 0
    for i := 0; i < len(s); i++ {
        if s[i] == '|' {
            inLine = !inLine
        } else if s[i] == '*' && !inLine {
            cnt++
        }
    }
    return cnt
}
