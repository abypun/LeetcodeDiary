/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

// @lc code=start


int singleNumber(int* nums, int numsSize){
    int single = 0;
    for (int i = 0; i < numsSize; i++) {
        single ^= nums[i];
    }
    return single;
}
// @lc code=end

