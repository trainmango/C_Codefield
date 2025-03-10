/**
 * @file 18.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int values[] = {88, 56, 100, 2, 25};
int cmpfunc(const void *a, const void *b)
{
   return (*(int *)a - *(int *)b);
}

int main(void)
{
   int n;

   printf("排序之前的列表：\n");
   for (n = 0; n < 5; n++)
   {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), cmpfunc);

   printf("\n排序之后的列表：\n");
   for (n = 0; n < 5; n++)
   {
      printf("%d ", values[n]);
   }
   system("pause");
   return 0;
}