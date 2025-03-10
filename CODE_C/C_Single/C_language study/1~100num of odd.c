/*
    2022年9月9日17点08分   1~100的奇数相加
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i , p=0;
   
    for ( i = 1; i <= 100; i++)
    {
      if(i % 2 != 0)
      p++; 
    }
    
    printf("奇数总共有：%d个\n", p);
   system("pause");
    
    return 0;
}