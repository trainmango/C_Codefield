/* 
    2022年10月14日10点38分  
    如何在软件开发中合理的设计函数来解决实际问题
 */

//****只用一个函数实现不好，程序没有可重用性，代码利用率不高****
//********用单独函数实现，代码的可重用性提高********

/* 
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
 */
//上面是判断是否是素数
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h> //调用bool函数得加头文件#include<stdbool.h>
bool Isprime(int val)
{
    int i;
    for ( i = 2; i < val; i++)
    {
        if(0 == val%i)
          break;
    }
    if(i == val)
      return true;
    else
      return false;
    
}
int main(void)
{
    int val;

    scanf("%d",&val);
    if (Isprime(val))
      printf("Yes\n");
    else
      printf("No\n");
    system("pause");
    return 0;
}