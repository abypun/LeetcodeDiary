func minimumPerimeter(neededApples int64) int64 {
	var len, sum int64 = 0, 0
	for sum < neededApples {
		len++
		sum += 12 * len * len
	}
	return 8 * len
}