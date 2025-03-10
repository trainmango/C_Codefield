/**
 * @file 17.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
void ff(int *);
int main(void)
{
    void (*pf) (int *);
    pf = ff;
    printf("%p  %p   %p   %p\n", pf, ff, &ff, &pf);//类似数组ff和&ff值一致。 *pf如今等价于ff
    /**
     * @brief 结果为：00000000004015A6  00000000004015A6   00000000004015A6   000000000061FE18
     * 
     */
  
    system("pause");
    return 0;
    
}
void ff(int * pp){
    
}
