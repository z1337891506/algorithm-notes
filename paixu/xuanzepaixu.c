/*
 * 题目：选择排序（升序）
 * 考点：数组、最小值下标、交换
 * 思路：每一轮在未排序区里找最小值下标 min_index，
 *       再把它和未排序区首位 i 交换；
 *       第 i 轮结束后，前 i + 1 个元素已经有序。
 * 复杂度：时间 O(n^2)，空间 O(1)
 * 易错点：
 *   1. min_index 记录的是下标，不是值；
 *   2. 交换前判断 min_index != i，避免自己和自己交换；
 *   3. 外层只需要 n - 1 轮，最后剩一个元素自然有序。
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
    for (int i = 0; i < n - 1; i++)
    {
        // 先假设未排序区的第一个元素就是最小值
        int min_index = i;

        // 在 arr[i + 1 .. n - 1] 里找更小的元素
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // 最小值不在 i 号位时才交换
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
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
