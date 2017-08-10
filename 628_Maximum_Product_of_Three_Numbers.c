/*
 *  Given an integer array, find three numbers whose product is maximum and output the maximum product.
 *  给定数组的3个数相乘最大值
 */

/* 对给定数组原地排序 */
void my_sort(int* nums1, int nums1Size)
{
	double shrink_factor = 0.8;
	int gap = nums1Size, swapped = 1, i, j;
	int temp;
	while (gap > 1 || swapped) {
		if (gap > 1)
			gap *= shrink_factor;
		swapped = 0;
		for (i = 0; gap + i < nums1Size; i++) {
			if (nums1[i] > nums1[i + gap]) {
				temp = nums1[i];
				nums1[i] = nums1[i + gap];
				nums1[i + gap] = temp;
				swapped = 1;
			}
        }
    }    
}


int maximumProduct(int* nums, int numsSize) {
    int a, b;
    my_sort(nums, numsSize);
    
    /* 最小两个数和最大数的乘积 -- 考虑到可能出现负数 */
    a = nums[0] * nums[1] * nums[numsSize-1];
    b = nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3];
    
    return (a > b) ? a : b;
}