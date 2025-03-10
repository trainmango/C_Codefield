/* 
   2022年9月9日16点09分 
   求1到10之间所有的能被3整除的数字之和
*/
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int i;
    int sum = 0;

    for (i = 3; i <= 10; i++)
    {
        if (i%3 == 0) //如果 i能被3整除
        sum = sum + i; 
           printf("sum = %d\n", sum);  
    }
   
    system("pause");
    return 0;
}