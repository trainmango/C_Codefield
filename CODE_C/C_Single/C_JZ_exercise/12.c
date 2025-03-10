/**
 * @file 12.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int zippo[4][2]={{2,4},{6,8},{1,3},{5,7}};
    printf("%p\n",zippo);
    printf("%p\n",&zippo[0]);
    printf("%p\n",zippo[0]);
    printf("%p\n",&zippo[0][0]);
    
    system("pause");
    return 0;
    
}