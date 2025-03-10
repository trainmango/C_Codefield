/**
 * @file D-digui3.c
 * @author your name (you@domain.com)
 * @brief
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
int digui_f1_100_(int);
void feidigui_f1_100_(int);
int main()
{
    printf("递归算出1~100的和为：%d\n", digui_f1_100_(100));
    feidigui_f1_100_(100);
    system("pause");
    return 0;
}
int digui_f1_100_(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num + digui_f1_100_(num - 1);
    }
}
void feidigui_f1_100_(int num)
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }
    printf("非递归算出1~100和为：%d\n", sum);
}