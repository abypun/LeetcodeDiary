func areSentencesSimilar(sentence1 string, sentence2 string) bool {
    if len(sentence1) < len(sentence2) {
        sentence1, sentence2 = sentence2, sentence1
    }

    words1 := strings.Split(sentence1, " ")
    words2 := strings.Split(sentence2, " ")

    maxFit := 0
    for ; maxFit < len(words2); maxFit++ {
        if words1[maxFit] != words2[maxFit] {
            break
        }
    }
    for i := 0; i < len(words2)-maxFit; i++ {
        if words1[len(words1)-1-i] != words2[len(words2)-1-i] {
            return false
        }
    }
    return true
}
