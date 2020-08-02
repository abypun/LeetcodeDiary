/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

double solution1(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 首先最容易想到的是：合并两个有序数组，再二分查找 这样最终复杂度为O(n),假设从小到大
    // 但不符合题意，显然需要找到更为高效的解法
    int *nums = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            nums[k++] = nums1[i++];
        } else {
            nums[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        nums[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        nums[k++] = nums2[j++];
    }
    
    if (k % 2 == 1) {
        return (double)nums[k / 2];
    } else {
        return ((double)nums[k / 2] + nums[k / 2 - 1]) / 2; 
    }
}

double getMiddle(int* nums1, int l, int r) {
    if ((r - l + 1) % 2 == 0) {
        return (double)nums1[(r - l) / 2] / 2 + (double)nums1[(r - l) / 2 + 1] / 2;
    } else {
        return (double)nums1[(r - l) / 2];
    }
}

double solution2(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // 其次想到，二分的具体操作，是在每次决策中去掉一半，留下一半
    // 对应这道题目，是否有一种操作，可以在两个不等长的数组中，去掉正好一半
    // 于是想到每个数组取一半，决定两个数组中留下的部分，就能正好得到一半长度
    // 然后思考怎么去掉一半：可以对比中值大小，来决定留下哪部分
    // 对于 x x a x x 和
    //      x x b x x 这样两个数组，当b>a时，b一定在中值的右边，a一定在中值的左边（待补充）
    // 即可以去掉a左b右，正好一半的数组容量，达到二分的目的
    // TODO
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    return solution1(nums1, nums1Size, nums2, nums2Size);
}
// @lc code=end

 