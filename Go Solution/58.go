func lengthOfLastWord(s string) int {
	cnt := 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == ' ' && cnt == 0 {
			continue
		} else if s[i] != ' ' {
			cnt++
		} else {
			break
		}
	}
	return cnt
}