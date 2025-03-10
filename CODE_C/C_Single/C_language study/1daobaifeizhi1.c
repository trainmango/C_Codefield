/*
    2022年9月12日08点55分   1+1/2+1/3+...+1/100的值
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
   float i;
   float sum=0;
    for ( i = 1; i <= 100; i++)
    {
      sum = sum + 1 /  i;
      
       
    }
    printf("%f\n",sum);

    system("pause");
    return 0;
}