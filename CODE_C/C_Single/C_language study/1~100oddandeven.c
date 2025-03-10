/*
    2022年9月12日10点14分  1~100的奇数和与偶数和各为多少
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i , sum1=0, sum2=0;
   
    for ( i = 1; i < 101; ++i)
    {
      if(i%2 == 1)
       {
          sum1 += i;
       }
       else
       {
          sum2 += i;
       }
    }
    printf("奇数和为： = %d\n",sum1);
    printf("偶数和为： = %d\n",sum2);
    
   system("pause");
    
    return 0;
}