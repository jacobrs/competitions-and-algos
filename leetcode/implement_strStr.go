package main

func strStr(haystack string, needle string) int {

	if len(needle) > 0 {
		for i, c := range haystack {
			if c == rune(needle[0]) {
				for j, n := range needle {
					if j+i >= len(haystack) {
						break
					}
					if j == len(needle)-1 && n == rune(haystack[i+j]) {
						return i
					} else if n != rune(haystack[i+j]) {
						break
					}
				}
			}
		}
	} else {
		return 0
	}

	return -1

}
