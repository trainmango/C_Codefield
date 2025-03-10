/* 
        2022年10月24日16点18分

 */
#include <stdio.h>
#include<stdlib.h>
void f(int *pArr, int *len)
{
   pArr[2] = 10; //pArr[2] == *(pArr+2) == *(a+2) == a[2]
}

/* 
    int main()
{ 
    int a[5] = {1,2,3,4,5};      //a == &a[0]
    f(a, 5);                     //即a[i]等价于*(a+i)等价于*(&a[0+i])
   // a = &a[2];                 //error , a是常量不能放在等式左边
    printf("%d %d\n", a, a[0]);  //a是a[0]的地址， a == &a[0] a即指针
    system("pause");
    return 0;
}

 */
int main()
{
    int a[5] = {1,2,3,4,5};
    f(a, 5);
  
    printf("%d\n", a[2]);
    system("pause");
    return 0;
}