/* 

 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int a[10]={};
    for (int i = 0; i < 10; i++)
    {
        a[i] = a[i]+10;
        printf("%d\n",a[i]);
    }
    
    printf("%d\n",&a[3]);
    system("pause");
    return 0;
}