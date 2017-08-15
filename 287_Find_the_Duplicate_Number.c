// 给定一个包含n + 1个整数的数组，其中每一个整数均介于[1, n]之间，证明其中至少有一个重复元素存在。
// 假设只有一个数字出现重复，找出这个重复的数字。

/*
 *  Note:
 *   不可以修改数组（假设数组是只读的）
 *   只能使用常数空间
 *   运行时间复杂度应该小于O(n2)
 *   数组中只存在一个重复数，但是可能重复多次
 */

/* 二分查找 */
int findDuplicate(int* nums, int numsSize) {
    int low, high, mid, k, count;
    
    low = 1;
    high = numsSize - 1;
    
    while (high >= low) {
        mid = (low + high) >> 1;
        count = 0;
        for (k=0; k < numsSize; k++) {
            if (nums[k] <= mid) {
                count += 1;
            }
        }
        if (count > mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        } 
    }
    return low;
}