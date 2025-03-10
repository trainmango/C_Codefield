/**
 * @file D-digui2.c
 * @author your name (you@domain.com)
 * @brief  阶乘
 * @version 0.1
 * @date 2024-06-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
int jiecheng_digui(int);
void jiecheng_feidigui(int);
int main()
{
    printf("递归求出阶乘为：%d\n", jiecheng_digui(5));
    jiecheng_feidigui(5);
    system("pause");
    return 0;
}
int jiecheng_digui(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num * jiecheng_digui(num - 1);
    }
}
void jiecheng_feidigui(int num)
{
    int x = 1;
    for (int i = 1; i <= num; i++)
    {
        x *= i;
    }
    printf("%d阶的非递归求出阶乘为：%d", num, x);
}