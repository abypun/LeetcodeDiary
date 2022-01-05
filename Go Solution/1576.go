func modifyString(s string) string {
	tmp := []byte(s)
	if len(s) == 1 {
		if s == "?" {
			return "a"
		} else {
			return s
		}
	}
	for i := 0; i < len(s); i++ {
		if tmp[i] == '?' {
			if i == 0 && tmp[i+1] == 'a' {
				tmp[i] = 'b'
			} else if i == 0 && tmp[i+1] != 'a' {
				tmp[i] = 'a'
			} else if i == len(s)-1 && tmp[i-1] == 'a' {
				tmp[i] = 'b'
			} else if i == len(s)-1 && tmp[i-1] != 'a' {
				tmp[i] = 'a'
			} else {
				for _, c := range []byte("abc") {
					if c != tmp[i-1] && c != tmp[i+1] {
						tmp[i] = c
					}
				}
			}
		}
	}
	return string(tmp)
}