/**
 * @file 11.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include<stdlib.h>
#define SIZE 4
int main()
{
    

    short dates[SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double * ptf;
    pti =  dates;
    ptf = bills;
    printf("%23s %15s\n","short","double");
    for ( index = 0; index < SIZE; index++)
    {
        printf("pointer + %d: %10p %10p\n", index, pti+index, ptf+index);
    }
    printf("%d\n",sizeof(pti));
    printf("%d\n",sizeof(dates));
    printf("%d\n",sizeof(dates[0]));
    printf("%d\n",sizeof(bills));
    system("pause");
    return 0;
    
}