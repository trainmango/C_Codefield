/**
 * @file 16.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
bool ii(int);

int main()
{   
    int q;
    scanf("%d",&q);
    int o;
    for (int i = 0; i <= q; i++)
    {
         if (ii(i))
    {
        o++;
    }
    
    }
    printf("%d\n",o);
   
    system("pause");
    return 0;
}
bool ii(int b){
    
    int v;
    int sum = 0;
    
    v = b;
    while (v)
    {
        sum = sum * 10  +  v % 10;
        v = v / 10;
    }
    if(sum == b)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}