/*
 * 题目：计算某年某月有多少天
 * 考点：闰年判断、数组打表
 * 思路：把每月天数存进数组（下标 1 ~ 12，0 号位补 0）；
 *       闰年且月份为 2 时，天数加 1。
 * 复杂度：时间 O(1)，空间 O(1)
 * 易错点：
 *   1. 闰年规则：(year % 4 == 0 && year % 100 != 0) || year % 400 == 0；
 *   2. 数组下标从 1 开始，0 号位要占位；
 *   3. 月份要检查 1 ~ 12。
 */
#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_of_month(int year, int month)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12)
    {
        return -1;
    }

    int day = days[month];
    if (month == 2 && is_leap_year(year))
    {
        day++;
    }
    return day;
}

int main()
{
    int year = 0;
    int month = 0;

    if (scanf("%d %d", &year, &month) != 2)
    {
        return 1;
    }

    int day = days_of_month(year, month);
    if (day == -1)
    {
        printf("invalid month\n");
    }
    else
    {
        printf("%d\n", day);
    }
    return 0;
}
