/**
 * @file zzzzzzz_pointer_to_an_array.c
 * @author your name (you@domain.com)
 * @brief 数组指针
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
    int (*p)[10];//这里 p 是一个指向具有 10 个整数的数组的指针。// 声明一个指向包含 10 个整数的数组的指针
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    

    p = &arr;  // p 现在指向数组 arr

    // 使用数组指针访问数组元素
    for (int i = 0; i < 10; i++) {
        printf("%d ", (*p)[i]);
    }
    /*
       我们声明了一个数组 arr 并初始化。
       我们声明了一个指向数组的指针 p。
       我们将 p 指向数组 arr。
       我们使用 (*p)[i] 语法来访问数组中的元素。
    
    */
    printf("\n");
    


    int array[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int (*q)[4];  // 指向包含 4 个整数的数组的指针


   /*
          array 是一个 3x4 的二维数组。
          q 是一个指向包含 4 个整数的数组的指针。
          q = array 使 q 指向 array 的第一行。
          我们可以使用 q[i][j] 语法来访问二维数组的元素。
          通过理解和使用数组指针，可以更高效和灵活地处理数组数据，特别是在处理多维数组和动态分配内存时。     
   
   
   */
    q = array;  // q 指向二维数组的第一行

    // 使用数组指针访问二维数组元素
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }

    
    
    system("pause");
    return 0;
}
