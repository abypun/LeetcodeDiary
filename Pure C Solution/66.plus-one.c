/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 会内存泄漏
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *result = (int*)malloc((digitsSize+1) * sizeof(int));
    int carry = 1;
    for (int i = digitsSize; i > 0; i--) {
        result[i] = (digits[i-1] + carry) % 10;
        carry = (digits[i-1] + carry) / 10;
    }
    if (carry) {
        *returnSize = digitsSize + 1;
        result[0] = carry;
        return result;
    } else {
        *returnSize = digitsSize;
        return result + 1;
    }
}
// @lc code=end

