/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 */

// @lc code=start


bool canConstruct(char * ransomNote, char * magazine){
    int letters[26] = {0};
    char *letter = magazine;
    while (*letter) {
        letters[*letter-'a']++;
        letter++;
    }
    letter = ransomNote;
    while (*letter) {
        if (letters[*letter-'a']) {
            letters[*letter-'a']--;
        } else {
            return false;
        }
        letter++;
    }
    return true;
}
// @lc code=end

