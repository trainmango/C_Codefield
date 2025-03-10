/**
 * @file D-digui1.c
 * @author your name (you@domain.com)
 * @brief
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
void f(int);
void f1(int);
int main()
{
    f(4);
    f1(6);
    system("pause");
    return 0;
}
// void f()
// {
//     printf("haha");   // 没有退出条件会造成无限递归,需要有递归推出条件
//     f();
// }
void f(int num)
{
    printf("hehe    ");
    while (num >= 0)
    {
        f(--num);
    }
}
void f1(int num)
{
    if (num == 1)
    {
        printf("en~");
    }
    else
    {
        f1(--num);
    }
}
