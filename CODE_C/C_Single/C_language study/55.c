#include <stdio.h>
#include<stdlib.h>
int main()
{
    int sum = 0;int i;
    for ( i = 1; i < 10; i+=2)
    {   
        sum = sum + 1;
        printf("今天我很高兴！\n");
        printf("%d\n", sum);
    }
    printf("i = %d\n",i);
    
    
    system("pause");
    return 0;
}