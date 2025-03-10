/* 
    2022年9月17日17点12分  do...while为什么适用于人机交互
 */
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double a, b ,c;
    double delta;
    double x1, x2;
    char ch; 
do      //do....while(1);让其一直循环，可以一直输入abc并求一元二次方程的根。
{
  

    printf("请输入一元二次方程的三个系数：\n");
    printf("a = ");
    scanf("%lf", &a);

    printf("b = ");
    scanf("%lf", &b);

    printf("c = ");
    scanf("%lf", &c);

    delta=b*b - 4*a*c;

    if(delta > 0)
    {
      x1 = (-b+sqrt(delta))/(2*a);
      x2 = (-b-sqrt(delta))/(2*a);
      printf("有两个解， x1 = %f, x2 = %lf\n", x1, x2);
    }
    else if(delta == 0)
    {
        x1 = x2 = (-b)/(2*a);
        printf("有唯一解， x1 = x2 = %lf\n", x2);
    }
    else
    {
        printf("无实数解!\n");
    }
    printf("你想继续吗(按y/Y继续)：");
    scanf(" %c", &ch); //%c前面必须得加一个空格 原因略
}while ('y'==ch || 'Y'==ch);

    system("pause");
    return 0;
}