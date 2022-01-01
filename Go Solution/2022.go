func construct2DArray(original []int, m int, n int) [][]int {
    if len(original) != m*n {
        return [][]int{}
    }
    result := make([][]int, 0, m)
    for i := 0; i < m; i++ {
        row := make([]int, n, n)
        copy(row, original)
        result = append(result, row)
        original = original[n:]
    }
    return result
}
