/**
 * @file 15.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
int main(int argc, char * argcv [])
{
    int x = 30;
    printf("%d %p\n", x, &x);
    while (x++<=33)
    {
        int x = 100;
        x++;
        printf("%d %p\n", x, &x);
        
    }
    printf("%d %p\n", x, &x);
    int i =  time(0);
    int ert = time(0)%6;
    rand();
    printf("%d \n", i);
    printf("%d \n", ert);
    system("pause");
    return 0;
    
}