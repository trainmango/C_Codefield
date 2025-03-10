/* 
        2022年9月19日17点38分
        continue用于跳过本次循环余下的语句，专区判断是否需要执行下次循环
        例子 1：for(1;2;3)
              {
                A;
                B；
                continue;   //如果执行该语句，则执行完该语句后，会执行语句3，C和D都会被
                C;          //跳过去，C和D都不会被执行
                D;
              }
        例子 2： while(表达式)
             {
                A;
                B;  
                continue;  //如果执行该语句，则执行完该语句后，会执行表达式，C和D都会被
                C;         //跳过去，C和D都不会被执行
                D;
             }

 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i = 0, s = 0;
    do
    {
      if (i%2)
      {
       i++;
       continue;
      }
      i++;
      s+=i;
      
    } while (i < 5);
    printf("%d\n", s);
    
    system("pause");
    return 0;
}