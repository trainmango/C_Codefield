/* 
          2023年2月9日16点26分
          冒泡排序
 */
#include <stdio.h>
#include<stdlib.h>
void sort(int * pArr, int len)
{
    int i, j, t;
    for ( i = 0; i < len-1; i++)//一共比较n-1次 例：len=6时，排序5次
    {
        for ( j = 0; j < len-1-i; j++)//在n-1次排序中每次均将这轮的min放在开头  第一轮有6个未排序 j为数组下标所以最大到5
                                     //依次类推 第二轮 有5个 
        {                 //相当于每次的墙（本程序中墙右边未排序，一开始有5个变量未排序）   //墙左边依次增加（即已排序），右边依次减少。
            if (pArr[j] > pArr[j+1])  //>表示升序【由小到大排列】  <表示降序【由大到小排序】
            { 
                t = pArr[j];
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;
            }
            
        }
        
    }
    
}
int main()
{
    int a[6] = {10, 2, 8, -8, 11, 0};  //有n个数，要冒泡比较n-1次
    int i = 0;
    sort(a, 6);  //a存放的a[0]的地址
    for ( i = 0; i <6; i++)
    {
        printf("%d ", a[i]);
    }
    

    system("pause");
    return 0;
}