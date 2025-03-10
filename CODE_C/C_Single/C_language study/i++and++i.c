/* 
   2022年9月16日11点05分
 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i, j, k, m;
    i = j = 3;
    k = i++;
    m = ++j;
    printf("i = %d, j = %d, k = %d, m = %d\n", i, j, k, m);
    system("pause");
    return 0;
}