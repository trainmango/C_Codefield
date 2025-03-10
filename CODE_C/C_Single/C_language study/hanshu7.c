/* 
    2022年10月14日10点57分  
      求1到某个数字间的所有素数，并将其输出
      只用main函数实现，有局限性；1代码重用性不高， 2代码不容易理解

 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int val;
    int i;
    int j;
    scanf("%d",&val);
    for ( i = 2; i <= val; ++i)  //i是从2都val
    {
        //判断i是否是素数，是 输出，不是 不输出。
        for ( j = 2; j < i; ++j)  //j是从2到i-1
        {
            if(0 == i%j)
            break;
        }
        if (j == i)
        {
            printf("%d\n", i);
        }
        
        
        
    }
    
    system("pause");
    return 0;
}