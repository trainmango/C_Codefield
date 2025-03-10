/**
 * @file feibo.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-25 12点51分
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
int feb(int n);
int feb2(int n);
int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", feb(n));
    system("pause");
    return 0;
}
int feb(int n)
{

    if (n >= 3)
    {
        return feb(n - 1) + feb(n - 2);
    }
    else
    {
        return 1;
    }
}
int feb2(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return feb2(n - 1) + feb2(n - 2);
    }
}