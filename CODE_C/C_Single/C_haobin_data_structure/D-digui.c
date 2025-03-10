/**
 * @file D-digui.c
 * @author your name (you@domain.com)
 * @brief  调用其他人
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
void f();
void g();
void k();
int main()
{
    f();
    system("pause");
    return 0;
}
void f()
{
    printf("FFFFFFF\n");
    g();
}
void g()
{
    printf("GGGGGG\n");
    k();
}
void k()
{
    printf("KKKKKK\n");
   
}