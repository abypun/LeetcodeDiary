func minimumPerimeter(neededApples int64) int64 {
	var len, sum int64 = 0, 0
	for sum < neededApples {
		len++
		sum += 12 * len * len
	}
	return 8 * len
}

func minimumPerimeter(neededApples int64) int64 {
	// 外边一圈长度 12|x|^2
	// 10^15最大边长2|x|=125992, |x|=62996
	// 边长为2|x|时的苹果数：2len(len+1)(2len+1)
	var left, right int64 = 0, 62996
	for left <= right {
		var mid int64 = (left + right) / 2
		var sum int64 = 2 * mid * (mid + 1) * (2*mid + 1)
		if sum < neededApples {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return 8 * left
}