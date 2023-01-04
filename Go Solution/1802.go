func maxValue(n int, index int, maxSum int) int {
	top := 1
	remain := maxSum - n // 去掉n个1
	left, right := index, index
	for remain > 0 {
		if left == 0 && right == n-1 && remain >= n {
			return top + remain/n
		}
		cost := 1
		cost += index - left
		if left > 0 {
			left -= 1
		}
		cost += right - index
		if right < n-1 {
			right += 1
		}
		if remain >= cost {
			remain -= cost
			top++
		} else {
			break
		}
	}
	return top
}