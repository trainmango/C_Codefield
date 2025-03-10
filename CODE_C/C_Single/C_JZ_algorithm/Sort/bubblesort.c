/**
 * @file bobsort.c
 * @author your name (you@domain.com)
 * @brief  冒泡排序
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define Size 10
void bobsort(int * , int);
void bianli(int * , int);
int main()
{
    int a[Size] = {-12,214,425,56,34,-23,-343443,23,543,78};
    
    
    bianli(a, Size);
    bobsort(a, Size);
    bianli(a, Size);
    system("pause");
    return 0;
}
void bianli(int * a, int val)
{
    for (int i = 0; i < val; i++)
    {
        printf("%d  ", a[i]); 
    }
    puts(" ");
}




/**
 * 一共比较n - 1次，
 * 数组被分为了已排序和未排序两个子列表
 * 未排序中最大的冒泡上来到已排序中，墙向前移动一位 已排增加1，未排减少1
 * 
 */
void bobsort(int * a, int len)
{
    int i, j, temp;
    for ( i = 0; i < len - 1; i++)//n个数 一共需要n - 1次比较  本例中 len = 10 则len-1为9  要比较9次  i最小为0 最大为8
    {                                    //循环中j 最小为0 最大为8 但是a[j + 1] 可以选到9
        for ( j = 0; j < len - 1 - i; j++)//从未排序中选择最大 第一次中，全都未排序10个数中选择最大的放最后【注：a[9]为最大值】，墙往前一位 【即每轮已排+1，所以要多减去轮次i】
        {    //注：j每次都要从0开始重新走循环             //i取最大时 i == 8，此时j < len - 1 - i == 1 
            if (a[j] > a[j + 1])//第一次中： a[0] 和 a[1] 再然后 a[1] 和 a[2]…………………………最终会把最大的放在最后面
            {                   //若这里改成a[j] < a[j + 1]则会让 小的放到最后面，墙往前【即数组大小缩小】最终从大到小排列
                temp = a[j];      
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            
        }
        
    }
    
}