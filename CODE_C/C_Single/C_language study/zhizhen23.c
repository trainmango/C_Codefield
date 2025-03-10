/* 
    2023年1月31日17点53分
    多级指针-1
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
    int i = 10;
    int * p = &i;
    int ** q = &p;
    int *** r = &q;
    
    //r = &p;  //因为r是int ***类型，r只能够存放int **变量的地址所以 error
    printf("i = %d\n", ***r);
    system("pause");
    return 0;
}