func repeatedCharacter(s string) byte {
	record := make(map[byte]bool)
	for i := 0; i < len(s); i++ {
		if _, ok := record[s[i]]; ok {
			return s[i]
		} else {
			record[s[i]] = true
		}
	}
	return 0
}