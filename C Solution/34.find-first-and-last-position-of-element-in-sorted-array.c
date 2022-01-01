/*
 * @lc app=leetcode id=34 lang=c
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int findBorder(int *nums, int numsSize, int left, int right, int target, int flag) {
//     int l = left, r = right, mid;
//     while (l <= r) {
//         mid = (l + r) / 2;
//         if (nums[mid] < target) {
//             l = mid + 1;
//         } else if (nums[mid] > target) {
//             r = mid - 1;
//         } else {
//             if (flag == -1) {
//                 if (mid == 0 || nums[mid-1] != target) {
//                     return mid;
//                 }
//                 r = mid - 1;
//             } else {
//                 if (mid == numsSize-1, || nums[mid+1] != target) {
//                     return mid;
//                 }
//                 l = mid + 1;
//             }
//         }
//     }
// }
// int* solution1(int* nums, int numsSize, int target, int* returnSize){
//     int left = 0, right = numsSize-1, mid;
//     *returnSize = 2;
//     int *result = (int*)malloc(sizeof(int)*(*returnSize));
//     result[0] = result[1] = -1;
//     while (left <= right) {
//         mid = (left + right) / 2;
//         if (nums[mid] < target) {
//             left = mid + 1;
//         } else if(nums[mid] > target) {
//             right = mid - 1;
//         } else {
//             if (mid == 0 || nums[mid-1] != target) {
//                 result[0] = mid; 
//             } else {
//                 result[0] = findBorder(nums, numsSize, left, mid-1, target, -1);
//             }
//             if (mid == numsSize-1 || nums[mid+1] != target) {
//                 result[1] = mid;
//             } else {
//                 result[1] = findBorder(nums, numsSize, mid+1, right, target, 1);
//             }
//     }
//     return result;
// }

int findEdge(int flag, int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, middle;
    if (flag == 0 && nums[0] == target) return 0;
    if (flag == 1 && nums[numsSize-1] == target) return numsSize-1;
    while (left < right) {
        middle = (left + right) / 2;
        if (nums[middle] == target) {
            if (flag == 0 && nums[middle-1] != target) {
                return middle;
            } else if (flag == 1 && nums[middle+1] != target) {
                return middle;
            } else {
                if (flag == 0) right = middle - 1;
                else left = middle + 1;
            }
        } else if (nums[middle] > target){
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    if (nums[left] != target) return -1;
    else return left;
}

int* solution2(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * 2);
    if (numsSize == 0) {
        result[0] = result[1] = -1;
    } else {
        result[0] = findEdge(0, nums, numsSize, target);
        if (result[0] == -1) result[1] = -1;
        else result[1] = findEdge(1, nums, numsSize, target);
    }
    *returnSize = 2;
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    return solution2(nums, numsSize, target, returnSize);
}

// int main() {
//     int nums[] = {5,7,7,8,8,10};
//     int t;
//     int *k = searchRange(nums, 6, 8, &t);
//     printf("%d %d \n", *k, *k+1);
// }
// @lc code=end

