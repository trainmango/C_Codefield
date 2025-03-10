/**
 * @file D-digui4.c
 * @author your name (you@domain.com)
 * @brief  汉诺塔问题
 * @version 0.1
 * @date 2024-06-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
/*
       A   B   C  三个柱子
       即要解决n个问题，只需解决前n - 1个问题
       即n个盘子借助B移动到C 和 n - 1个盘子借助C移动到B是同一种思路
       B上的n - 1个盘子借助A移动到C上
    if(n>1)
    {
        先把A柱子上的前n-1个盘子从A借助C移到B
        将A柱子上的第n个盘子直接移到C
        再将B柱子上的n-1个盘子借助A移到C
    }
*/
void hannuota(int n, char A, char B, char C);
int main()
{
    // 定义三个柱子
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    int n;
    printf("请输入要移动的盘子的个数：");
    scanf("%d", &n);
    hannuota(n, ch1, ch2, ch3); // 即把 n个在A上的盘子借助 B 移动到 C 上

   
    return 0;
}
void hannuota(int n, char A, char B, char C)//参数 一：盘子个数 二：放盘子的柱子 三：借助的柱子 四：要移动过去的柱子
{
    /*
       如果是1个盘子
            直接将A柱子上的盘子从A移到C
       否则
            先将A柱子上的n-1个盘子借助C移到B
            直接将A柱子上的盘子从A移到C
            最后将B柱子上的n-1个盘子借助A移到d
    */
    if (n == 1) // 一个的话直接移动
    {
        printf("直接将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, A, C);
        //注：下printf同 形参 A  C 并不代表A C两柱子
    }
    else // 两个及以上
    {
        hannuota(n - 1, A, C, B);   // 先把A柱子上的前n-1个盘子从A借助C移到B 【大问题转化为小问题】
        printf("直接将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, A, C); // 即A上的第n个盘子直接移动到C上去
        hannuota(n - 1, B, A, C);   // 把B上的n - 1个盘子借助A移动到C上
        //即 第一个参数是盘子个数 二：放盘子的柱子 三：借助的柱子 四：要移动过去的柱子
    }
}
