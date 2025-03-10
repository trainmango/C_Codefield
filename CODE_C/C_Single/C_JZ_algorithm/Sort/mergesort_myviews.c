/**
 * @file mergesortmyviews.c
 * @author your name (you@domain.com)
 * @brief  归并排序,自我设想。按两个有序数组简单实现一下,不是递归彻底实现所有的
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define NUM 10
int *mergesimple(int *, int *);
void bianli(int *, int);
int main()
{
    int a[4] = {1, 13, 24, 26};
    int b[4] = {2, 15, 27, 38};
    int totalsize = sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]); // 合并后两数组长度
    int *c = mergesimple(a, b);
    bianli(c, totalsize);
    system("pause");
    return 0;
}
int *mergesimple(int *a, int *b)
{

    int totalsize = sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]); // 合并后两数组长度
    int Aptr = 0;
    int Bptr = 0;
    int Cptr = 0;
    int bit; // bit = 1是Aptr先走空  bit = 2是Bptr先走空
    int *c = malloc(sizeof(totalsize));
    while (1)
    {
        if (a[Aptr] < b[Bptr])
        {
            c[Cptr] = a[Aptr];
            Aptr++;
        }
        else if (b[Bptr] < a[Aptr])
        {
            c[Cptr] = b[Bptr];
            Bptr++;
        }
        Cptr++;
        if (Aptr == 4)
        {
            bit = 1;
            break;
        }
        if (Bptr == 4)
        {
            bit = 2;
            break;
        }
    }
    /**
     * @brief 
     * 从mergesort中 可知，不用设置bit位
     * 而直接
     *  while (Bptr <= 4)
        {
            c[Aptr + Bptr] = b[Bptr];
            Bptr++;
        }
        while (Aptr <= 4)
        {
            c[Aptr + Bptr] = a[Aptr];
            Aptr++;
        }
     * 更好一点，判断没有问题
     * 
     */
    if (bit = 1) // a先走完            
    {  
        while (Bptr <= 4)
        {
            c[Aptr + Bptr] = b[Bptr];
            Bptr++;
        }
    }
    if (bit = 2) // b先走完
    {
        while (Aptr <= 4)
        {
            c[Aptr + Bptr] = a[Aptr];
            Aptr++;
        }
    }
    return c;
}

void bianli(int *c, int totalize)
{
    for (int i = 0; i < totalize; i++)
    {
        printf("%d  ", c[i]);
    }
    puts(" ");
}