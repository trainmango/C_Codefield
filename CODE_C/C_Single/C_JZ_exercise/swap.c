/**
 * @file swap.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
void swap1(int *, int *);
void swap2(int *, int *);
void bianli(int *, int);
void reverse_array(int *, int);
int main()
{
    int a[] = {3, 4};
    int b[] = {6, 9};
    int c[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    swap1(&a[0], &a[1]);
    swap2(&b[0], &b[1]);
    bianli(a, 2);
    bianli(b, 2);
    reverse_array(c, 10);
    bianli(c, 10);
    system("pause");
    return 0;
}
void swap1(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*
   与通常的交换两个数值的技术不一样，当移动一个值时，我们不需要第三个位置来临时存储另一个值
   这种交换方式没有性能优势，仅仅只是一个智力游戏
*/
void swap2(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
void bianli(int *a, int val)
{
    for (int i = 0; i < val; i++)
    {
        printf("%d  ", a[i]);
    }
    puts(" ");
}
void reverse_array(int *a, int cnt)
{
    int farst, last;
    for (farst = 0, last = cnt - 1; farst < last; farst++, last--)
    {
        if (farst < last)
        {
            swap2(&a[farst], &a[last]);
        }
    }
}