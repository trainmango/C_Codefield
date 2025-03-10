/**
 * @file mergesort_frank.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void merge(int *, int, int, int);
void mergesort(int *, int, int);
void bianli(int *, int);
int main()
{
    int a[] = {23423, 45634, -24353, -23452345, -654745, -435, -23, 12, 456};
    int asize = sizeof(a) / sizeof(a[0]);
    bianli(a, asize);
    mergesort(a, 0, asize - 1);
    bianli(a, asize);
    system("pause");
    return 0;
}
// Merges the two sorted arrays : array[left...mid] , array[mid + 1, right]
void merge(int *a, int left, int mid, int right)
{
    int left_size = mid - left + 1; // 以数组{23423, 45634, -24353, -23452345, -654745, -435, -23, 12, 456}为例：左边的大小为 5 ，右边为4
    int right_size = right - mid;   // 8 - 4 = 4
    // 两临时数组
    int *left_array = malloc(left_size * sizeof(int));
    int *right_array = malloc(right_size * sizeof(int));
    // 相当于把a[]砍半，一半放入左边，一半放入右边
    for (int i = 0; i < left_size; i++)
    {
        left_array[i] = a[left + i];
    }
    // 放右边
    for (int i = 0; i < right_size; i++)
    {
        right_array[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, temp = left;

    while (i < left_size && j < right_size)
    {
        if (left_array[i] <= right_array[j])
        {
            a[temp] = left_array[i]; // 也可以a[temp++] = left_array[i++];
            i++;
        }
        else
        {
            a[temp] = right_array[j]; // 也可以a[temp++] = right_array[j++];
            j++;
        }
        temp++;
    }

    while (i < left_size)
    {
        a[temp] = left_array[i];
        i++;
        temp++;
    }
    while (j < right_size)
    {
        a[temp] = right_array[j];
        j++;
        temp++;
    }
}
void mergesort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
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