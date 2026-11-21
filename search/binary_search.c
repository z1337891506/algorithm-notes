/*
 * 题目：二分查找（有序数组）
 * 考点：折半、区间收缩、边界
 * 思路：在闭区间 [left, right] 内查找 target；
 *       arr[mid] < target 时 left = mid + 1；
 *       arr[mid] > target 时 right = mid - 1；
 *       相等返回下标，区间为空返回 -1。
 * 复杂度：时间 O(log n)，空间 O(1)
 * 易错点：
 *   1. 循环条件是 left <= right，闭区间；
 *   2. mid 写成 left + (right - left) / 2，防止 left + right 溢出；
 *   3. 数组必须有序，否则结果无意义。
 */
#include <stdio.h>

#define MAX_SIZE 1000

int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int arr[MAX_SIZE];
    int n = 0;
    int target = 0;

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d", &target) != 1)
    {
        return 1;
    }

    int index = binary_search(arr, n, target);
    if (index == -1)
    {
        printf("not found\n");
    }
    else
    {
        printf("%d\n", index);
    }
    return 0;
}
