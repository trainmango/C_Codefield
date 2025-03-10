/**
 * @file 8.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
void up_and_down(int);
int main()
{
    up_and_down(1);
    system("pause");
    return 0;
    
}
void up_and_down(int n){
    printf("Level %d: nlocation %p\n", n, &n);
    if(n<4)
    {
        up_and_down(n+1);
    }
    printf("Level %d: nlocation %p\n", n, &n);
}