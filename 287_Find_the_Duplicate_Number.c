// ����һ������n + 1�����������飬����ÿһ������������[1, n]֮�䣬֤������������һ���ظ�Ԫ�ش��ڡ�
// ����ֻ��һ�����ֳ����ظ����ҳ�����ظ������֡�

/*
 *  Note:
 *   �������޸����飨����������ֻ���ģ�
 *   ֻ��ʹ�ó����ռ�
 *   ����ʱ�临�Ӷ�Ӧ��С��O(n2)
 *   ������ֻ����һ���ظ��������ǿ����ظ����
 */

/* ���ֲ��� */
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