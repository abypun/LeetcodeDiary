/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

// @lc code=start

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int solution1(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize/2];
}


int solution2(int* nums, int numsSize){
    int candidateIndex = 0, cnt = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[candidateIndex]) {
            cnt++;
        } else {
            if (cnt == 0) {
                candidateIndex = i;
                cnt = 1;
            } else {
                cnt--;
            }   
        }
    }
    return nums[candidateIndex];
}


int majorityElement(int* nums, int numsSize){
    // return solution1(nums, numsSize);
    return solution2(nums, numsSize);
}
// @lc code=end

