func isLeapYear(year int) bool {
	return year%100 == 0 && year%400 == 0 || year%4 == 0 && year%100 != 0
}

func dayOfTheWeek(day int, month int, year int) string {
	week := []string{
		"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday",
	}
	monthDays := []int{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	}
	// 1971.1.1 Friday
	days := 0
	var i int
	for i = 1971; i < year; i++ {
		if isLeapYear(i) {
			days += 366
		} else {
			days += 365
		}
	}

	for i = 1; i < month; i++ {
		days += monthDays[i]
	}

	if i > 2 && isLeapYear(year) {
		days++
	}

	days += day - 1

	return week[(days+4)%7]
}