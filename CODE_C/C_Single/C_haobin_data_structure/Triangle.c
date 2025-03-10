/* 
   2023年4月26日17点21分
   三角形在c语言中的定义
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int zhouchang(int m,int n,int k)  //函数声明的话，就可以不用加这些 m n k 直接  函数声明 int zhouchang(int ,int ,int ); 
{
   return m + n + k;
}

double area(int m,int n,int k)
{
   double p = (m+n+k)/2;
   return sqrt(p*(p-m)*(p-n)*(p-k));
}

int main()
{
    int a, b, c;
    a = 3;
    b = 4;
    c = 5;
    printf("%d\n %lf\n",zhouchang(a,b,c), area(a,b,c));

    system("pause");
    return 0;
}