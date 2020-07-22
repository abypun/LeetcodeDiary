/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        return "";
    } else if (strsSize == 1) {
        return strs[0];
    } else {
        char *tmp = (char *)malloc(1005);
        int len = strlen(strs[0]);
        strcpy(tmp, strs[0]);
        for (int i = 1; i < strsSize; i++) {
            int j = 0;
            for (; j < strlen(strs[i]); j++) {
                if (strs[i][j] != tmp[j]) {
                    break;
                }
            }
            if (j < len) {
                len = j;
            }
        }
        tmp[len] = '\0';
        return tmp;
    }
}
// @lc code=end

