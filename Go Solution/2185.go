func prefixCount(words []string, pref string) int {
	cnt := 0
	for i := 0; i < len(words); i++ {
		if strings.HasPrefix(words[i], pref) {
			cnt++
		}
	}
	return cnt
}