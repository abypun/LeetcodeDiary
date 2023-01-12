func evaluate(s string, knowledge [][]string) string {
	keys := make(map[string]int)
	for i := 0; i < len(knowledge); i++ {
		keys[knowledge[i][0]] = i
	}

	ret := ""
	last := 0
	for i := 0; i < len(s); i++ {
		j := i + 2
		if s[i] == '(' {
			for s[j] != ')' {
				j++
			}
		} else {
			continue
		}
		if value, ok := keys[s[i+1:j]]; ok {
			ret += s[last:i] + knowledge[value][1]
		} else {
			ret += s[last:i] + "?"
		}
		last = j + 1
		i = j
	}
	ret += s[last:]
	return ret
}
