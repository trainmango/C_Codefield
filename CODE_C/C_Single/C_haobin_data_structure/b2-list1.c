/* 
   2023年3月21日20点35分
   链表的定义，一个结点的生成（node）
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;  //数据域
    struct Node * pNext;  //指针域
    
}NODE, *PNODE;  //NODE等价于struct Node,  PNODE等价于struct Node *

// 在此编译器中，int 占四个字节 ，  struct Node * 占8个字节 ， 但是
/*
struct 的空间计算遵循的2个原则：
1：整体空间是占用空间最大的成员（的类型）所占字节数的整数倍，但是在32位Linix + gcc环境下，若最大成员类型所占字节数超过4，如double是8，则整体空间是4的倍数即可。
2：数据对齐原则。内存按结构体成员的先后顺序排列，当排到该成员变量时，其前面已摆放的空间大小必须是该成员类型大小的整数倍，如果不够则补齐，依次向后类推。但在Linux + gcc环境下，某成员类型所占字节数超过4，如double是8，则前面已摆放的空间大小是4的整数倍即可，不够则补齐

//所以是16 而不是12

*/
//由规则1，必须是成员中占字节数最大的那个的整数倍。
int main()
{
    printf("%d",sizeof(NODE));
    system("pause");
    return 0;
}