/* 

 */
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
             printf("$");
        }
        
        printf("\n");
    }
    
    system("pause");
    return 0;
}