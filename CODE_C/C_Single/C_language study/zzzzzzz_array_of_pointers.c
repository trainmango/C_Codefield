/**
 * @file zzzzzzz_array_of_pointers.c
 * @author your name (you@domain.com)
 * @brief 指针数组
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int main()
{
    /**
     * int a[2];
       int a1 = 3;
       int a2 = 4;
       int a3 = 5;
       a[0] = &a1;
       a[1] = &a2;
       a[2] = &a3;
       printf("%d", *a[0]);
       这样写无法存储，因为这是个int类型的指针，不能存储int* 类型的
     * 
     */
    //而这样写就可以了，即指针数组
    int *a[2];
    int a1 = 3;
    int a2 = 4;
    int a3 = 5;
    a[0] = &a1;
    a[1] = &a2;
    a[2] = &a3;
    printf("%d", *a[0]);
    
    system("pause");
    return 0;
}
