/**
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 * 
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 * 
 * Example 1:
 *   Input: [1, 2, 2, 3, 1]
 *   Output: 2
 * Explanation: 
 *   The input array has a degree of 2 because both elements 1 and 2 appear twice.
 *   Of the subarrays that have the same degree:
 *   [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 *   The shortest length is 2. So return 2.
 * Example 2:
 *   Input: [1,2,2,3,1,4,2]
 *   Output: 6
 * Note:
 *   nums.length will be between 1 and 50,000.
 *   nums[i] will be an integer between 0 and 49,999.
 */

/* 使用hashmap，记录每个数出现的次数，最小位置 和 最大位置 三个信息 */
int findShortestSubArray(int* nums, int numsSize) {
    int hashmap[50000][3], i, count, ret;
    memset(hashmap, 0 , sizeof(int) * 50000 * 3);
    for (i = 0; i < numsSize; i++) {
        hashmap[nums[i]][0]++;
        if (hashmap[nums[i]][1] == 0) {
            hashmap[nums[i]][1] = i + 1;
        } else {
            hashmap[nums[i]][2] = i + 1;
        }
    }
    count = 0;
    ret = 0;
    for (i = 0; i < 50000; i++) {
        if (hashmap[i][0] > count) {
            count = hashmap[i][0];
            ret = i;
        } else if (hashmap[i][0] == count) {
            if ((hashmap[i][2] - hashmap[i][1]) < (hashmap[ret][2] - hashmap[ret][1])) {
                count = hashmap[i][0];
                ret = i;
            }
        }
    }
    
    if (hashmap[ret][2] == 0) {
       return 1;
    }
    
    return hashmap[ret][2] - hashmap[ret][1] + 1;
}


int maximumProduct(int* nums, int numsSize) {
    int a, b;
    my_sort(nums, numsSize);
    
    /* 最小两个数和最大数的乘积 -- 考虑到可能出现负数 */
    a = nums[0] * nums[1] * nums[numsSize-1];
    b = nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3];
    
    return (a > b) ? a : b;
}