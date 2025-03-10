/* 
     2022年9月19日17点04分
    break如果用于循环是用来终止循环的
    break如果用于switch，则是用于终止switch的
    break不能直接用于if，除非if属于循环的一个句子  
    break虽然是if内部的语句，但break终止的却是外部的for循环
    在多层循环中，break只能终止最里面包裹它的那个循环
    在多层switch中，break只能终止距离他最近的switch
    例子：for(i=0; i<3 ; ++i)
          {
            if( 3>2 )   
               break;       \\break虽然是if内部的语句，但break终止的却是外部的for循环
               printf("嘿嘿！\n");  \\永远不会输出
          }

 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i, j;

    for ( i = 0; i < 6; i++)
    {
        for ( j = 1; j < 12; j++)
       
           
          break; 
          printf("同志们好！\n");   //在多层循环中，break只能终止距离它最近的循环，把for ( j = 1; j < 4; j++)这句话终止了
          

    }
       
    system("pause");
    return 0;
}