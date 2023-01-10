func crackSafe(n int, k int) string {
	kn, kn1 := int(math.Pow(float64(k), float64(n))), int(math.Pow(float64(k), float64(n-1)))
	num := make([]int, kn1, kn1)
	for i := 0; i < kn1; i++ {
		num[i] = k - 1
	}
	s := make([]byte, kn+n-1, kn+n-1)
	for i := 0; i < kn+n-1; i++ {
		s[i] = '0'
	}
	for i, node := n-1, 0; i < len(s); i++ {
		s[i] = byte(num[node]) + '0'
		num[node]--
		node = node*k - int((byte(s[i-n+1])-'0'))*kn1 + num[node] + 1
	}
	return string(s)
}
