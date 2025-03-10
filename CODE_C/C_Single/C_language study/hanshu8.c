/* 
    2022年10月14日11点09分  
    用一个函数来判断一个数字是否为素数
       优点 
          代码比 hanshu7.c 更容易理解
          代码可重用性比 hanshu7.c 高
       缺点
          可重用性仍然不是非常高
          比如求1000个数字，它们每个数字从1到它本身的素数
          则for ( i = 2; i <= val; i++)
    {
        if (Isprime(i))
        {
            printf("%d\n", i);
        }
        
    }
    要写1000次
 */
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool Isprime(int m) //本函数的功能是 判断m是否为素数，是 返回true，不是 返回 false
{
    int i;
    for ( i = 2; i < m; i++)
    {
        if (0 == m%i)
        break;
    }
    if (i == m)
       return true;
    else
       return false;
    
}
void TraverseVal(int n)//本函数的功能是把1到n之间的所有素数在显示器上输出
{
         int i;
           for ( i = 2; i <= n; i++)
    {
        if (Isprime(i))
        {
            printf("%d\n", i);
        }
        
    }
}
int main(void)
{
    int val;
    scanf("%d",&val);
    /* 
    int i;
    for ( i = 2; i <= val; i++)
    {
        if (Isprime(i))
        {
            printf("%d\n", i);
        }
        
    } 
    */
   TraverseVal(val);  //用上面的Isprime（i）调用也可以但是TraverseVal（val）更少
    system("pause");
    return 0;
}