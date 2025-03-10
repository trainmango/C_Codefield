/**
 * @file E_sort.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-07-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
// 郝斌的是选择第一个数的 快排，我写的那个是三数中值法
void printarray(int *a, int num);
void QuickSort(int *a, int low, int high);
int FindPos(int *a, int low, int high);
int FindPos2(int *a, int low, int high);
void swap(int *a, int *b);
int main()
{
    int a[] = {7,4,2,9,3,10};
    printarray(a, 6);
    QuickSort(a, 0, 5); // 第二个参数表示第一个元素下标，第三个参数表示最后一个元素的下标
    printarray(a, 6);
    return 0;
}
void printarray(int *a, int num)
{
    for (size_t i = 0; i < num; i++)
    {
        printf("%d  ", a[i]);
    }
    puts(" ");
}

void QuickSort(int *a, int low, int high)
{
    int pos;

    if (low < high)
    {
        pos = FindPos2(a, low, high);
        QuickSort(a, low, pos - 1);
        QuickSort(a, pos + 1, high);
    }
}
// 这是郝斌原样的
int FindPos(int *a, int low, int high)
{
    int val = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= val)
        {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= val)
        {
            ++low;
        }
        a[high] = a[low];
    } // 终止while循环之后 ， low和high一定是相等的
    a[low] = val;
    return low;
}

// 在数组中找到枢纽元素的正确位置  这是用swap的
int FindPos2(int arr[], int left, int right)
{
    int pivot = arr[left]; // 选择左边第一个元素作为枢纽
    int i = left;
    int j = right;

    while (i < j)
    {
        // 从右边开始找到第一个小于等于pivot的元素
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        // 从左边开始找到第一个大于等于pivot的元素
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }
        // 交换这两个元素
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    // 将枢纽元素放到正确的位置
    arr[left] = arr[i];
    arr[i] = pivot;

    return i; // 返回枢纽元素的位置
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
