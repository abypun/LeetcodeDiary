func findingUsersActiveMinutes(logs [][]int, k int) []int {
    uams := make(map[int]map[int]bool)
    for i := 0; i < len(logs); i++ {
        if uams[logs[i][0]] == nil {
            uams[logs[i][0]] = map[int]bool{}
            uams[logs[i][0]][logs[i][1]] = true
        } else {
            uams[logs[i][0]][logs[i][1]] = true
        }
    }
    ret := make([]int, k+1)
    for _, v := range uams {
        ret[len(v)]++
    }
    return ret[1:]
}
