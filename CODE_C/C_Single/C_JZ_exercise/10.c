/**
 * @file 10.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int value = 44;
    int arr[4];
    int v2 = 88;
    int i;
    
    for ( i = 0; i <= -1; i++)
    {
        arr[i] = 2*i+1;
    }

    for (int i = -1; i < 7; i++)
    {
        printf("%2d  %d\n", i, arr[i]);

    }
    printf("%d  %d\n",value, v2);
    printf("%p\n",&arr[-1]);
    printf("%p\n",&arr[4]);
    printf("%p\n",&arr[5]);
    printf("%p\n",&value);
    printf("%p\n",&v2);
    
    
    
    system("pause");
    return 0;
    
}