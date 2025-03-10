
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
void swap(int *, int *);

void Bubble(int *a, int len);
void insertion(int *a, int len);
void insertion2(int *a, int len);
void selection(int *a, int len);
void print(int *a, int len);

int main()
{
    int a[] = {23, 345, -4356, 3214, -2435, -2341235, -356774, 2342353, 112135, 34, 758, 456, 9, 34, 587, 23, 47, 2345, 876, 88887, 34526};
    int len = sizeof(a) / sizeof(a[0]);

    printf("排序前为：");
    print(a, len);

    printf("排序后为：");
    insertion2(a, len);
    print(a, len);

    system("pause");
    return 0;
}

void Bubble(int *a, int len)
{
    int pass, j;
    for (pass = 0; pass < len - 1; pass++) // n - 1 次排序
    {
        for (j = 0; j < len - pass - 1; j++) // 每次选出这趟中最小的
        {
            if (a[j] > a[j + 1]) // 大的往后走
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void insertion(int *a, int len)
{
    int pass, j, temp;
    for (int pass = 1; pass < len; pass++)
    {
        temp = a[pass];            // 临时保存a[pass]
        for (j = pass; j > 0; j--) // 第n趟要和前边n个元素进行排序  例3 4 9 当9进来时 9 > 4 所以 break
        {
            if (temp < a[j - 1]) // 例如，第一次 a[1] < a[0] 因为插入了所以多了， 所以整体后移
            {                    // 相当于把数组从合适的位置上往后移动了一格，再将temp放到适合它的位置上去
                a[j] = a[j - 1];
            }
            else // 否则不往后移，跳出
            {
                break;
            }
        }
        a[j] = temp;
    }
}

void insertion2(int *a, int len)
{
    int pass, j, temp;
    for (pass = 1; pass < len; pass++)
    {
        temp = a[pass];
        for (j = pass; j > 0 && a[j - 1] > temp; j--)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

void selection(int *a, int len)
{
    int pass, j, min;
    for (pass = 0; pass < len - 1; pass++) // n - 1 次排序
    {
        min = pass; // 选取最小的角标
        for (j = pass + 1; j < len; j++)
        {
            if (a[min] > a[j]) // 让a[min]为最小 大了我就换
            {
                min = j;
            }
        }
        swap(&a[pass], &a[min]); // 每次将最小换到他该在的位置 本例中为最开头放最小 往后依次
    }
}

void print(int *a, int len)
{
    for (int pass = 0; pass < len; pass++)
    {
        printf("%d  ", a[pass]);
    }
    puts(" ");
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}