/*
 * @lc app=leetcode id=205 lang=c
 *
 * [205] Isomorphic Strings
 */

// @lc code=start

bool solution1(char * s, char * t) {
    char map[128] = {0}, flag[128] = {0};
    for (int i = 0; i < strlen(s); i++) {
        if (!map[s[i]]) {
            if (flag[t[i]]) return false;
            map[s[i]] = t[i];
            flag[t[i]] = 1;
        }
        else {
            if (map[s[i]] == t[i]) continue;
            return false;
        }
    }
    return true;
}


bool isIsomorphic(char * s, char * t){
    return solution1(s, t);
}
// @lc code=end

