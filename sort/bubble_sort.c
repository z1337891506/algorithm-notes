/*
 * 题目：冒泡排序（升序）
 * 考点：数组、相邻元素交换、循环边界
 * 思路：每一轮从前往后比较相邻两个元素，逆序就交换；
 *       一轮结束后，未排序区的最大值一定被"冒"到末尾。
 *       第 i 轮结束后，末尾 i 个元素已经有序。
 * 复杂度：时间 O(n^2)，空间 O(1)
 * 易错点：
 *   1. 内层边界写成 j < n 会访问 arr[n]，正确写法是 j < n - 1 - i；
 *   2. 交换必须借助 temp，直接覆盖会丢数据；
 *   3. 外层 n - 1 轮即可，最后剩一个元素自然有序。
 *
 * 优化：如果某一轮一次交换都没发生，说明数组已经有序，可以提前结束。
 *       做法：每轮开始前 int swapped = 0; 交换时置 1；
 *       内层结束后 if (!swapped) break;
 */
#include <stdio.h>

#define MAX_SIZE 1000

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void output(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[], int n)
{
    int temp = 0;

    // 外层：一共 n - 1 轮，每轮锁定一个最大值
    for (int i = 0; i < n - 1; i++)
    {
        // 内层：只比较未排序区间的相邻元素
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n = 0;

    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE)
    {
        return 1;
    }

    input(arr, n);
    sort(arr, n);
    output(arr, n);
    return 0;
}
