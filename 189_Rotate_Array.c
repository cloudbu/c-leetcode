/*
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * Note:
 *  Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 *
 */

/* 反转给定数组的区间 */
void Reverse(int nums[],int left,int right){
    int i, j, tmp;
    for(i = left, j = right; i < j; ++i,--j){
        tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

/* 三次反转实现旋转 */
void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) {
        return;
    }
    
    k = k % numsSize;
    if (k <= 0) {
        return;
    }
    Reverse(nums, 0, numsSize - k - 1);
    Reverse(nums, numsSize - k, numsSize - 1);
    Reverse(nums, 0, numsSize - 1);
}
