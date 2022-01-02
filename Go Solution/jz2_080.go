func dfs(n, k, i int, cur []int, used []bool, result *[][]int) {
	if i == k {
		c := make([]int, k, 21)
		copy(c, cur)
		*result = append(*result, c)
		return
	}
	var j int
	if i == 0 {
		j = 1
	} else {
		j = cur[i-1] + 1
	}
	for ; j <= n; j++ {
		if used[j] {
			continue
		}

		cur[i] = j
		used[j] = true
		dfs(n, k, i+1, cur, used, result)
		cur[i] = 0
		used[j] = false
	}
}

func combine(n int, k int) [][]int {
	result := make([][]int, 0, 1024)
	used := make([]bool, 21, 21)
	cur := make([]int, 21, 21)
	dfs(n, k, 0, cur, used, &result)
	return result
}