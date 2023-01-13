func rearrangeCharacters(s string, target string) int {
    cntTarget := map[byte]int{}
    cntS := map[byte]int{}
    for i := 0; i < len(target); i++ {
        cntTarget[target[i]]++
    }
    for i := 0; i < len(s); i++ {
        if _, ok := cntTarget[s[i]]; ok {
            cntS[s[i]]++
        }
    }
    if len(cntS) < len(cntTarget) {
        return 0
    }
    min := len(s)
    for key, val := range cntS {
        if val / cntTarget[key] < min {
            min = val / cntTarget[key]
        }
    }
    return min
}
