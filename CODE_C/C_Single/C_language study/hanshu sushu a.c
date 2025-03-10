/* 
  2022年9月30日10点20分   判断是否为素数
 */
#include <stdio.h>
#include<stdlib.h>


int main()
{
    int val, i;
    scanf("%d", &val);
    for ( i = 2; i < val; i++)
    {
        if (val%i == 0)
            break;    
    }
    if (i == val) //如何过不是素数，在中间某一步%i=0了跳出循环，加不到val
    //如果是素数则i会一直加到val
       printf("YES!\n");
    else
       printf("NO!\n");
       

    
    

    system("pause");
    return 0;
}