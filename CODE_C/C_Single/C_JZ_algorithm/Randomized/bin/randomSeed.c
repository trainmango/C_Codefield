/**
 * @file randomSeed.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define A 48271L
#define M 2147483647L
static unsigned long Seed = 1;
double Random(void)
{
    Seed = (A * Seed) % M;
    return (double)Seed / M;
}
void Init(unsigned long InitVal)
{
    Seed = InitVal;
}
int main()
{
    for (unsigned long i = 0; i <= 10; i++)
    {
        Init(i);
        double x = Random();
        printf("%lf   ", x);
    }

    system("pause");
    return 0;
}
