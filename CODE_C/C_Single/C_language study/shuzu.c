/* 
    2022年9月26日16点37分
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int a[5] = {1, 2, 3, 4, 5}; //只有在定义数组的同时才可以整体赋值。
    // a是数组的名字，5表示数字元素的个数，并且这5个元素分别用a[0]、a[1]....a[4]
    int i;
    for (i = 0; i < 5; i++)
    printf("%d\n",a[i]);
    
    
    system("pause");
    return 0;
}