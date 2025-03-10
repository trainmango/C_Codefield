/*
   2023年2月10日19点38分
   |运算符
   ~运算符
   
   
 */
#include <stdio.h>
#include<stdlib.h> 
int main()
{
    int i = 3;  //3的二进制代码0011
    int j = 5;  //5的二进制代码0101
    int k;
               
    k = i | j;  //相当于把i和j二进制的每一位进行或判断
                //           0 0 1 1
                //           0 1 0 1
                //          ——————————
                //           0 1 1 1      即十进制的7
    printf("%d\n", k);
   

    k = ~i;  //32位的int  0000....0011按位取反1111....1100为 -4 //1100 取反加1为4
          
    printf("%d\n", k);
    printf("%d\n", ~i+1);


 
    system("pause");
    return 0;
}