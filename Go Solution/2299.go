func strongPasswordCheckerII(password string) bool {
    if len(password) < 8 {
        return false
    }

    hasLowerCaseLetter := false
    hasUpperCaseLetter := false
    hasNumber          := false
    for i := 0; i < len(password); i++ {
        if i != 0 && password[i] == password[i-1] {
            return false
        }
        if 'a' <= password[i] && password[i] <= 'z' {
            hasLowerCaseLetter = true
        } else if 'A' <= password[i] && password[i] <= 'Z' {
            hasUpperCaseLetter = true
        } else if '0' <= password[i] && password[i] <= '9' {
            hasNumber = true
        }
    }
    return hasLowerCaseLetter && hasUpperCaseLetter && hasNumber &&
        strings.ContainsAny(password, "!@#$%^&*()-+")
}
