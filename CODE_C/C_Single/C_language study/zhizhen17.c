/* 
      2022年10月31日16点53分
      一个指针变量到底占几个字节的问题
       
 */
#include <stdio.h>
#include<stdlib.h>
int main(void)
{
    
    char ch = 'A';
    int i = 99;
    double x = 66.6;
    char * p = &ch;
    int * q = &i;
    double * r = &x;
    int a[5] = {1,2,3,4,5};//数组中每个存储单元被分配了4个字节的存储空间(因为定义了数组是int类型)
                           //所以sizeof（a）=20 ；若为double a[5]={1,2,3,4,5};则为sizeof（a）=40
    printf("%d %d %d %d %d %d %d\n", sizeof(p), sizeof(q), sizeof(r), sizeof(ch), sizeof(i), sizeof(a), sizeof(x));
       /*在此编译器中  
       8 8 8 1 4 20              不管指针变量指向的原变量的字节大小，此编译器中指针变量占了8个字节
        请按任意键继续. .

        在visual studio中选择64位与上边结果相同
        但在visual studio 中选择32位则为：
        4 4 4 1 4 20 8
        请按任意键继续. . .
        */
    system("pause");
    return 0;
}
