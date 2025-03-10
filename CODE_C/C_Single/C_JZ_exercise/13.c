/**
 * @file 13.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
    char str1[10] = "abc";
    char str2[10] = "defg";
    char * p = strcat(str1,str2);
    puts(str1);
    puts(str2);
    puts(p);
    system("pause");
    return 0;
    
}