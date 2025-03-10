/*

*/
 
#include <stdio.h>
#include<stdlib.h>

int main()
{   
    int sum = 0;
    int i = 0;
    while (i <= 100)
    {
        sum = sum+i;
      
        printf("%d\n", sum);
        i++;
    }
    printf("%d\n", sum);
    
    system("pause");
    return 0;
}