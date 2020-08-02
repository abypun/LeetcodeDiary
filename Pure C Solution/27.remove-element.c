/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start

// 113/113 4ms
// 69.8%
// 79.37% 5.6MB
// @Author: Rufeer
int removeElement(int* nums, int numsSize, int val){ 
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            cnt++;
        } else {
            nums[i - cnt] = nums[i];
        }
    }

    return numsSize - cnt;
}
// @lc code=end

