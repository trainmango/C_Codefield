/* 
  2022年9月30日10点20分
 */
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool Isprime(int val)
{
    int i;
    for ( i = 2; i < val; i++)
    {
        if (val%i == 0)
            break;      
    }
    if (i == val) //如何过不是素数，在中间某一步%i=0了跳出循环，加不到val
    //如果是素数则i会一直加到val
       return true;
    else
       return false;
}
int main()
{
    int m;
    scanf("%d", &m);
    if(Isprime(m))
      printf("Yes!\n");
    else
      printf("No!\n");
       

    
    

    system("pause");
    return 0;
}