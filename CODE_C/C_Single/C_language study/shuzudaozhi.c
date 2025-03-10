/* 
    2022年9月26日16点59分 把一个数组的元素倒过来 （数组倒置）
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{   
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int i, j;
    int t;
    i = 0;
    j = 6;
    while (i < j)//注意是倒置不是排序
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
    for ( i = 0; i < 7; i++)
    printf("%d\n",a[i]);
    
   
    
    system("pause");
    return 0;
}