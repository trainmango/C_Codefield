/**
 * @file A_largestsq.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * @brief 最大子数列
 */
#include <stdio.h>
#include<stdlib.h>
int qiu (int Arr[], int n);
int qiu2 (int Arr[], int n);
int qiu3(int Arr[], int n);
int main()
{
    puts("请输入数组大小");
    int N;
    scanf("%d", &N);
    int Arr[] = {7, -2, 5, 3, -8, 6};
    int * p = (int *)malloc(sizeof(int)*N);
    puts("输入malloc数组");
    for (int zz = 0; zz < N; zz++)
    {
        scanf("%d", &p[zz]);
    }
    puts("自定义的最大子序列和为："); 
    int mm = qiu3(p,N); //更改qiu qiu2 qiu3 可选择某一算法来用
    printf("%d\n", mm);
    puts("定长Arr的最大子序列为：");
    int x = qiu(Arr,6);
    printf("%d\n", x);
    system("pause");
    return 0;
}
int qiu(int Arr[], int n) // 它的算法复杂度为O(N³) ,算完全部的再比较
/*试数：当第一次时：  i==0，j==0，k==0 thissum==7 
         第二次时：  i==0, j==1, k==0, thissum==Arr[0]+Arr[1];
         …………………………………………………………………………………………………………………………………………
         依次选择前6个中的第1，2，3，4，5，6个相加
         …………………………………………………………………………………………………………………………………………
         然后i==1，即依次选择5个……………………………………………………………………………………
         …………………………………………………………………………………………………………
                 
*/
{
    int thissum, maxsum, i, j, k;
    maxsum = 0;
    for ( i = 0; i < n; i++)
    {
        
        for ( j = i; j < n; j++)
        {
            thissum = 0;
            for ( k = i; k <= j; k++)
            {
                
                thissum += Arr[k];
            }
            
            if (thissum > maxsum)
            {
                maxsum = thissum;
            }
            

        }
        
    }
    return maxsum;
}

int qiu2(int Arr[], int n)//  算法复杂度O(N²),边算边比较
{
    int thissum, maxsum, i, j;
    maxsum = 0;
    for ( i = 0; i < n; i++)
    {
        thissum = 0;
        for ( j = i; j < n; j++)
        {
            thissum += Arr[j];

            if (thissum > maxsum)
            {
                maxsum = thissum;
            }
            
        }
       
    }
    return maxsum;
}

int qiu3(int Arr[], int n)//O(N)   即当thissun开始为正数时才有可能为最大子序列
{
    int thissum, maxsum, i;
    thissum = maxsum = 0;
    for ( i = 0; i < n; i++)
    {
        thissum += Arr[i];
        if (maxsum < thissum)
        {
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
        }
        
    }
    return maxsum;
}