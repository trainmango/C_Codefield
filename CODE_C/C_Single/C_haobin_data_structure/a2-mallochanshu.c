/* 
    2023年2月12日19点47分
    malloc函数复习
 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[5] = {4, 10, 2, 8, 6};

    int len;
    printf("请输入你需要分配的数组的长度：len = ");
    scanf("%d", &len);
    int * pArr = (int *)malloc(sizeof(int) * len);
   // *pArr = 4;  //类似于a[0] = 4;
   // pArr[1] = 10; //类似于a[1] = 10;
   // printf("%d %d\n", *pArr, pArr[1]);
   /*
     malloc函数默认返回无类型   malloc只返回第一个字节的地址   默认定义void *malloc(int num); 但可以进行强制类型转换
                 但它只返会了一个地址，而不知道其类型，用强制类型转换来实现与之前定义的 
                 例：int * p = (int *)malloc(sizeof(int)*10); 定义了int * p来接收malloc操纵的空间，所以强制类型转化为了int * 类型
                 且如若不进行强制类型转换，不知道一个数组中一个元素占用的字节大小 
                 用了强制类型转换则知道了返回的第一个字节的地址属于是那种类型的地址，可以更准确的得知数组中每个元素占用字节的大小
                         即知道了是什么类型的指针变量 例 int型的指针变量 (int*)
        malloc函数与数组间的古关联：
         例：malloc(sizeof(int)*10); 与int a[10]; 形式上不同 但是都是申请了一段40字节大小的空间
            而int a[10]; 可以通过使用a这个名称来进行调用这个数组【静态数组】
            但malloc(sizeof(int)*10); 得使用一个变量来接收它 就像 int * p = (int *)malloc(sizeof(int)*10);
                                     强制类型转化成了int * 类型，p就可以操纵这块内存空间了
                                            例： p[0], p[1] 与 *(p+3)之类的来操纵  这就是动态数组的本质
   
   
   */
    //我们可以把pArr当作一个普通数组来使用
    printf("依次输入数组元素：");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &pArr[i]);
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", *(pArr+i));
    }
    
    
    free(pArr); //把pArr多代表的动态分配的20个字节的内存释放
    system("pause");
    return 0;
}

