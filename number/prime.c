/*
 * 题目：输出 100 ~ 200 之间的素数
 * 考点：试除法、循环边界
 * 思路：n < 2 不是素数；
 *       从 2 试除到 n / i，只要有一个因子就返回 0。
 * 复杂度：单次判断 O(sqrt(n))，空间 O(1)
 * 易错点：
 *   1. 1 不是素数，2 是素数；
 *   2. 循环条件写 i <= n / i，不要写 i * i <= n（n 很大时会溢出）；
 *   3. 找到因子立即返回，不要继续循环。
 */
#include <stdio.h>

int is_prime(int n)
{
    if (n < 2)
    {
        return 0;
    }

    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int count = 0;

    for (int n = 100; n <= 200; n++)
    {
        if (is_prime(n))
        {
            printf("%d ", n);
            count++;
        }
    }
    printf("\ncount = %d\n", count);
    return 0;
}
