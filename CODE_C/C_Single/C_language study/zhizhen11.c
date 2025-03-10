/* 
   2022年10月21日16点33分
   一定要明白 10行的pArr[3]和15 17行的a[3]是同一个变量
   确定一维数组需要几个参数-2
 */
#include <stdio.h>
#include<stdlib.h>
void f(int * pArr, int len)
{
   pArr[3] = 88; //即*(pArr+3) 即a[3]
}
int main()
{
    int a[6] = {1,2,3,4,5,6};
    printf("%d\n", a[3]);  //4
    f(a, 6);  //a表示a[0]的地址 即a == &a[0]，
   /* 
                    下标： 0  1  2  3  4  5
                 内存空间： 1  2  3  4  5  6


                    a指向空间1  即a[0]      pArr+3指向空间4 即a[3]
   
                    pArr指向空间1
               
                      即a[i]等价于*(a+i)等价于*(&a[0+i])
    */
    printf("%d\n", a[3]);  //88
    int *z = a;
    z[2] = 44;
    printf("%d\n", z[2]);

   //  int* x = malloc(sizeof(int)*6);
   //即：
   int* x;
   x = malloc(sizeof(int)*6);
    *(x + 2) = 10;
    printf("%d\n", x[2]);
    printf("%d\n", *(x + 2));
    system("pause");
    return 0;
}
/* 
ide中结果为
4
88
请按任意键继续. . .
  
 */