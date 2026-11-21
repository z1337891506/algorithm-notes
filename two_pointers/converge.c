/*
 * 题目：字符串从两端向中间汇聚
 * 考点：双指针、字符串、strlen
 * 思路：left 从 0 开始，right 从 len - 1 开始；
 *       每轮把源串两端字符填到目标串，然后 left++、right--，
 *       直到 left > right。
 * 复杂度：时间 O(n)，空间 O(n)
 * 易错点：
 *   1. right = strlen(src) - 1，不是 strlen(src)；
 *   2. 循环条件 left <= right，中间那个字符也要填；
 *   3. 目标串末尾要补 '\0'。
 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char src[] = "welcome to world";
    char dst[MAX_LEN];
    int len = (int)strlen(src);

    // 目标串先全部填 '#'
    for (int i = 0; i < len; i++)
    {
        dst[i] = '#';
    }
    dst[len] = '\0';

    int left = 0;
    int right = len - 1;

    while (left <= right)
    {
        dst[left] = src[left];
        dst[right] = src[right];
        printf("%s\n", dst);
        left++;
        right--;
    }
    return 0;
}
