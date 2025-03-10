/* 
  2022年9月30日09点43分  
  return和break的区别
 */
#include <stdio.h>
#include<stdlib.h>
void f(void)
{
    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("大家辛苦了！\n");
        return;
    }
    printf("同志们好！\n");
    /* 
      return表达式的含义：
      1>终止被调函数，向主调函数返回表达式
      2>如果表达式为空，则只终止函数，不想被函数返回任何值
      return是终止函数的，break是用来终止循环和switch的。
      例：void f()
          {
            return;  //return只用来终止函数，不向被调函数返回任何值
          }
          int f()
          {
            return 10;  //第一：终止函数， 第二：向主调函数返回10
          }
      
     */
    
}
int main()
{
    f();
    system("pause");
    return 0;
}