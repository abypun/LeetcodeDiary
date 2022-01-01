/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start

// m:Row - 3, n:Col - 4;
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row, col, left = 0, right = matrixSize*(*matrixColSize)-1, mid;
    if (matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
    while (left <= right) {
        mid = (left + right) / 2;
        row = mid / (*matrixColSize);
        col = mid % (*matrixColSize);
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
// @lc code=end

