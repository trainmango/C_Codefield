/**
 * @file insertionsort.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 10
void insertionsort(int *);
void insertionsort2(int *);
void insertionsort3(int *);
int *creatarray(int);
void bianli(int *);
int main()
{
    // int *a = creatarray(N);
    int b[N] = {3, 4, 1, 6, 7, 5, 2, 9, 8, 10};

    insertionsort3(b);
    bianli(b);
    system("pause");
    return 0;
}
int *creatarray(int num)
{

    int val;

    int *a = malloc(sizeof(int) * num);
    printf("请依次输入数组中的元素：");
    for (int i = 0; i < num; i++)
    {
        printf("第%d个元素为：", i + 1);
        scanf("%d", &val);
        a[i] = val;
    }
    return a;
}
void bianli(int *a)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d  ", a[i]);
    }
    puts(" ");
}
void insertionsort(int *a)
{
    int pass; // 插入排序的 趟数
    int temp; //临时保存a[pass]相当于每次新插入的，第一层for最后会将它放在何适的位置
    int i; // 3, 4, 1, 6, 7, 5, 2, 9, 8, 10
    /* 第一层for                 第二层for

       第一次： temp = a[1] = 4   for循环一次        a[i - 1]【即a[0] = 3】 不大于temp所以不交换    此时 3,4
       第二次： temp = a[2] = 1   for循环中的第一次： a[i - 1]【即a[1] = 4】 大于temp    此时 3,4,4【即把a[1]的值给a[2]了】   i--后i=1 【此时还没换 第二层for还没走完】
                                 for循环中的第二次： a[i - 1]【即a[1] = 4】 大于temp  所以a[0]的值赋给a[1] 3,3,4 然后a[0] = 1; 此时1,3,4  【第一层for中才a[i] = temp;】
       第三次：…………………………
       第四次：…………………………
    */
    for (pass = 1; pass < N; pass++) // n个数的插入排序需要n - 1趟排序
    {
        temp = a[pass];                               // 临时保存
        for (i = pass; i > 0 && a[i - 1] > temp; i--) // 第n趟要和前边n个元素进行排序  例3 4 9 当9进来时直接不满足循环的条件而退出
        {
            a[i] = a[i - 1];
        }
        a[i] = temp; // 此时a[2] = temp = 9;
    }
}
void insertionsort2(int *a)
{
    int pass; // 插入排序的 趟数
    int temp;
    int i; // 3, 4, 1, 6, 7, 5, 2, 9, 8, 10

    for (pass = 1; pass < N; pass++) // n个数的插入排序需要n - 1趟排序
    {
        temp = a[pass];            // 临时保存
        for (i = pass; i > 0; i--) // 第n趟要和前边n个元素进行排序
        {
            if (temp < a[i - 1])
            {
                a[i] = a[i - 1];
            }
            else
            {
                break; // break是为了例如 第二次 3 4 9， 插入9的时候不要进行任何交换，因为9大于4时 一定大于4前边的数
                       // 所以用break直接跳出循环【不需要交换】
            }
        }
        a[i] = temp; // 相当于把数组从合适的位置上往后移动了一格，再将temp放到适合它的位置上去
    }
}
void insertionsort3(int *a)
{
    int pass, temp, j;
    for (pass = 1; pass < N; pass++) // N个数需要 n - 1次排序
    {
        temp = a[pass];
        j = pass - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}