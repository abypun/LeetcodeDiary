/*
 * @lc app=leetcode id=455 lang=c
 *
 * [455] Assign Cookies
 */

// @lc code=start

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i = 0, j = 0, contentChildNum = 0;
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            contentChildNum++;
            i++, j++;
        } else {
            i++;
        }
    }
    return contentChildNum;
}
// @lc code=end

