/* 
         2023年11月14日20点57分
         
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int num1, num2, num3, getnum;
    printf("输入层数：");
    scanf("%d", &getnum);
    for ( num1 = 1; num1 <= getnum; num1++)
    {
        for (num3 = 1; num3 <= getnum-num1; num3++)//预留与层数有关的空格  //num3值大 空格数目越小
        {
            printf(" ");
        }
        
        for ( num2 = 1; num2 <= num1; num2++)//有几层，就有几个*
        {
            printf("* ");
        }
          printf("\n");  //循环结束换行
    }
    

    system("pause");
    return 0;
}
