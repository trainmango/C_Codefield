#include <stdio.h>
#include <stdlib.h>
const int MAX = 7;

int main()
{
    int  a[] = { 10, 100, 200,4000,80000,1600000,32000000 };
    int  i, * ptr;

    /* 指针中的数组地址 */
    ptr = a;
    for (i = 0; i < MAX; i++)
    {

        printf("存储地址：a[%d] = %p\n", i, ptr);
        printf("存储值：a[%d] = %d\n", i, *ptr);
        //注：每个地址相差4
        /* 指向下一个位置 */
        ptr++;
    }
    system("pause");
    return 0;
}