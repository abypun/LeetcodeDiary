func decodeMessage(key string, message string) string {
	turns := map[byte]byte{}
	current := byte('a')
	for i := 0; i < len(key); i++ {
		if key[i] != ' ' && turns[key[i]] == 0 {
			turns[key[i]] = current
			current++
		}
	}

	ret := make([]byte, 0, 2000)
	for i := 0; i < len(message); i++ {
		if message[i] == ' ' {
			ret = append(ret, ' ')
		} else {
			ret = append(ret, turns[message[i]])
		}
	}
	return string(ret)
}
