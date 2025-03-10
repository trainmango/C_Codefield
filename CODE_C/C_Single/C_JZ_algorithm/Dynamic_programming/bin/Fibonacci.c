/**
 * @file Fibonacci.c
 * @author
 * @brief 斐波那契数列的递归和非递归实现
 * @version 0.1
 * @date 2024-06-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

int digui_feb(int n);
int feidigui_feb(int n);

int main()
{
    int n;
    printf("(递归的方式)请输入想要求解的斐波那契数的第几位：");
    scanf("%d", &n);
    printf("第%d位的斐波那契数是：%d\n", n, digui_feb(n));

    printf("(非递归的方式)请输入想要求解的斐波那契数的第几位：");
    scanf("%d", &n);
    printf("第%d位的斐波那契数是：%d\n", n, feidigui_feb(n));

    system("pause");
    return 0;
}

int digui_feb(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return digui_feb(n - 1) + digui_feb(n - 2);
    }
}

int feidigui_feb(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }

    int f1 = 1, f2 = 1, f3;
    for (int i = 3; i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}