/**
 * @file Msort.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void Msort(int *, int *, int, int);
void Mergesort(int *, int);
void bianli(int *, int);
void Merge(int *, int *, int, int, int);
int main()
{ // 也有些写的程序，它没有temp参数，而是在函数中自己再创建了辅助数组
    int a[] = {23, 35, 46, 23234, -23434, -235, -47, 23456, 52};
    int size = sizeof(a) / sizeof(a[0]);
    bianli(a, size);
    Mergesort(a, size);
    bianli(a, size);
    system("pause");
    return 0;
}
void Msort(int *a, int *temp, int left, int right)
{
    int center;
    if (left < right) // 当数组内的元素数大于1时进行二分操作，只有一个元素的时候，不作任何处理只需要归并即可
    {
        center = (left + right) / 2;
        // 递归划分左半区
        Msort(a, temp, left, center);
        // 递归划分右半区
        Msort(a, temp, center + 1, right);
        // 合并已排序的部分
        Merge(a, temp, left, center, right); // 把两个有序数组合在一起 可以参考mergesortmyviews.c
    }
}
// 归并排序入口
void Mergesort(int *a, int num)
{
    int *temp;
    temp = malloc(num * sizeof(int)); // 临时数组大小为num，和a数组一样
    if (temp == NULL)
    {
        puts("error, out of space");
        return;
    }
    else
    {
        Msort(a, temp, 0, num - 1); // 初始角标最左0 最右num - 1 //且传入a数组 与 同等容量的 temp数组
        free(temp);
    }
}
void bianli(int *c, int totalize)
{
    for (int i = 0; i < totalize; i++)
    {
        printf("%d  ", c[i]);
    }
    puts(" ");
}
void Merge(int *a, int *temp, int left, int mid, int right) // 将两个已排序的数组合并
{
    // 标记左半区第一个未排序的元素
    int l_pos = left;
    // 标记右半区第一个未排序的元素
    int r_pos = mid + 1;
    // 临时数组元素的下标
    int pos = left;
    // 合并
    while (l_pos <= mid && r_pos <= right)
    {
        if (a[l_pos] < a[r_pos]) // 左半区第一个剩余元素更小
        {
            temp[pos++] = a[l_pos++];
        }
        else // 右半区第一个剩余元素更小
        {
            temp[pos++] = a[r_pos++];
        }
    }
    // 合并左半区剩余元素   【即右边的完了】
    while (l_pos <= mid)
    {
        temp[pos++] = a[l_pos++];
    }
    // 合并右半区剩余元素   【即左边的完了】
    while (r_pos <= right)
    {
        temp[pos++] = a[r_pos++];
    }
    // 把临时数组中合并后的元素复制回原来的数组
    while (left <= right)
    {
        a[left] = temp[left];
        left++;
    }
    // 复制回去也可以用for
    // for (int i = left; i <= right; i++)
    // {
    //     a[i] = temp[i];
    // }
    
}
