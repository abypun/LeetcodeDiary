func reinitializePermutation(n int) int {
	if n == 2 {
		return 1
	}
	step, pow2 := 1, 2
	for pow2 != 1 {
		step++
		pow2 = pow2 * 2 % (n - 1)
	}
	return step
}
