/**
 * @file shellsort.c
 * @author your name (you@domain.com)
 * @brief
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
void shell_sort(int *);
void bianli(int *);
int main()
{
    int arr[NUM] = {3, 4, 1, 6, 7, 5, 2, 9, 8, 10};
    bianli(arr);
    shell_sort(arr);
    bianli(arr);
    system("pause");
    return 0;
}
void bianli(int * a)
{
    for (int i = 0; i < NUM; i++)
    {
        printf("%d  ", a[i]); 
    }
    puts(" ");
}
void shell_sort(int * a)
{
    int pass,j,increment,temp;
    for ( increment = NUM/2; increment > 0 ; increment /= 2)//最终increment = 1，即变成了插入排序
    {
        for ( pass = increment; pass < NUM ; pass++)
        {
            temp = a[pass];
            for ( j = pass; j > 0 && temp < a[j - increment]; j -= increment)
            {
                a[j] = a[j - increment];
            }
            a[j] = temp;
        }
        
    }
    



}