/* 
     2022年10月21日14点56分

 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int * p; //等价于 int *p;也等价于int* p;
    int i = 5;
    char ch = 'A';
    p = &i;  //*p表示以p的内容为地址的变量（p保存了i的地址，p指向i）
    *p = 99;
    //p = &ch; //error
    //p = 5; //error
    //p = ch; //error
    printf("i = %d *p = %d\n", i, *p);
    system("pause");
    return 0;
}