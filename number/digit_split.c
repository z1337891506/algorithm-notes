/*
 * 题目：拆分数字（逐位输出）
 * 考点：取模、整除、循环
 * 思路：n % 10 取末位并输出，n /= 10 去掉末位，
 *       直到 n 变成 0。
 * 复杂度：时间 O(log10 n)，空间 O(1)
 * 易错点：
 *   1. n = 0 时循环一次也不执行，要单独输出 0；
 *   2. 负数先输出负号，再取绝对值；
 *   3. 这种写法输出是逆序的（个位在前）；
 *   4. INT_MIN 直接取反会溢出，严谨写法用 long long。
 */
#include <stdio.h>

int main()
{
    int n = 0;

    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    if (n < 0)
    {
        printf("-");
        n = -n;
    }

    if (n == 0)
    {
        printf("0\n");
        return 0;
    }

    while (n > 0)
    {
        printf("%d ", n % 10);
        n /= 10;
    }
    printf("\n");
    return 0;
}
