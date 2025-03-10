/* 
    2023年1月6日19点28分
    动态内存分配举例_ 动态数组的构造
    malloc函数的使用     malloc是memory（内存） allocate（分配）的缩写
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{          //malloc作用为申请一段空间，并返回该空间的首地址。
           //甚至可以因为malloc是默认void*返回的可塑性强，可返回任意的类型（甚至指针型）
           //比如int(*ptr)[10] = (int(*)[10])malloc(sizeof(int) * 10);      【比如定义此指针数组】
           //用的时候，类似a[n];把【*ptr当a用】即类似(*ptr)[2] = 10;
    int i = 5; //分配了4个字节 静态分配 第11行
    int * p = (int*)malloc(4); //第12行
    int * x = (int*)malloc(40);
    x[1] = 10;//可以把x[n]当数组用了（注：n为数组中的某个下标）
    /* 
       1. 要使用malloc函数，必须添加malloc.h头文件
       2. malloc函数只有一个形参，并且形参是整型
       3.（4）表示请求系统为本程序分配4个字节
       4. malloc函数只能返回第一个字节的地址
       5. 12行分配了16个字节，p变量占了8个字节(此编译器中，指针变量占8个字节)，p指向的内存也占8个字节
       6. p本身所占的内存是静态分配的，p所指向的内存是动态分配的
     */
    * p = 19;//* p代表的就是一个int变量，只不过* p这个整型变量的内存分配方式和第11行的i变量的分配方式不同
    printf(" %d %d %d %d %d\n",sizeof(p),sizeof((int*)malloc(100)),sizeof((double*)malloc(4)),sizeof((char*)malloc(1)),sizeof(x[1]));
             
    free(p); //表示把p所指向的内存所释放掉，p本身的内存是静态的，不能由程序员手动释放
             //p本身的内存只能在p变量所在的函数运行终止时由系统自动释放
    printf("同志们好！\n");
    
    system("pause");
    return 0;
}