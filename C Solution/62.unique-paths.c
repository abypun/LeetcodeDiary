/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 */

// @lc code=start


int uniquePaths(int m, int n){
    int cnt[105][105];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || j == 1) {
                cnt[i][j] = 1;
            } else {
                cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
            }
        }
    }
    return cnt[m][n];   
}
// @lc code=end

