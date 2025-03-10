/**
 * @file selectionsort.c
 * @author your name (you@domain.com)
 * @brief  选择排序
 * @version 0.1
 * @date 2024-06-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define Size 10
void bianli(int *, int);
// void selection(int *, int);
void selection2(int *, int);
int main()
{
    int a[Size] = {-12, 214, 425, 56, 34, -23, -343443, 23, 543, 78};
    bianli(a, Size);
    selection2(a, Size);
    bianli(a, Size);
    system("pause");
    return 0;
}
void bianli(int *a, int val)
{
    for (int i = 0; i < val; i++)
    {
        printf("%d  ", a[i]);
    }
    puts(" ");
}
// void selection(int *a, int len) // 这样写不好，交换此时太多了，按照选择排序的思想，应该定义一个min置为最小值，最终交换到前面
// {
//     int i, j, temp;
//     for (i = 0; i < len - 1; i++)     // n个数 一共需要n - 1次比较 i最大到8  本例中 len = 10
//     {                                 // j最大到9 【8+1】【即数组最后一位】
//         for (j = i + 1; j < len; j++) // 例：第一次中 j = 1
//         {
//             if (a[i] > a[j]) // 第一次中： a[0] 和 a[1] 再然后 a[0] 和 a[2] 再a[0] 和 a[3]…………………………最后把最小的放在了最开始
//             {                // a[i] > a[j] 若改成a[i] < a[j]则会把最大的放开始，即最终会从大到小排列
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
// }
void selection2(int *a, int len)//相当于选择一个最小的，然后放第一位，再选择次小的，放第二位………………
{
    int i, j, min, temp;
    for (i = 0; i < len - 1; i++)//n个数一共需要 n - 1 次 
    {
        min = i;
        for (j = i + 1; j < len; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}