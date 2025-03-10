/* 
  2022年9月26日20点54分
  函数返回值的类型也称为函数的类型，因为如果函数名前的返回值类型和函数执行体中的
  return表达式中表达式的类型不同的话，则最终函数返回值的类型以函数名前的返回值类
  型为准
 */
#include <stdio.h>
#include<stdlib.h>
int f()  //返回值以函数名前的int 为准    
{        //例如  double sqrt(double x); double是返回值类型 sqrt是函数名 x是形式参数
    return 10.5;  //因为函数的返回值类型是int 所以最终f返回的是10而不是10.5
}
int main()
{
    int i = 99;
   double x = 6.6;
    x = f();
    
    printf("%lf\n", x); 
    system("pause");
    return 0;
}