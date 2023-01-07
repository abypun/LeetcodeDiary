func minOperations(nums []int, x int) int {
	left, right := 0, len(nums)-1
	sum, minOp := 0, -1
	for left < len(nums) && sum+nums[left] <= x {
		sum += nums[left]
		left++
	}
	for ; left >= 0; left-- {
		for right >= left && sum+nums[right] <= x {
			sum += nums[right]
			right--
		}
		if sum == x {
			if minOp == -1 || left+len(nums)-1-right < minOp {
				minOp = left + len(nums) - 1 - right
			}
		}
		if left > 0 {
			sum -= nums[left-1]
		}
	}
	return minOp
}