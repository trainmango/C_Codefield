/**
 * @file A_gongyueshu.c
 * @author your name (you@domain.com)
 * @brief 最大公约数
 * @version 0.1
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
int zuida(int, int);
int main()
{
    int num1,num2;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", zuida(num1,num2));
    system("pause");
    return 0;
}
int zuida(int num1, int num2)
{   
    int max;
    while (num2 > 0)
{
    
    max = num1 % num2;
    num1 = num2;
    num2 = max;
    
}

   
    return num1;
}