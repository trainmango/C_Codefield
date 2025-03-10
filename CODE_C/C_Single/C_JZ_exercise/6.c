#include <stdio.h>
#include<stdlib.h>
#include <math.h>
 
int main()
{
    char ax = 'a';
    for (int i = 0; i < 26; i++)
    {
        printf("%c ",ax+i);
    }
    
    printf(" \n");

    for (int j = 0; j < 5 ; j++)
    {
        for (int k = 0; k <= j; k++)
        {
            printf("$ ");
            
        }
        printf("\n");
    }
    
    char ee = 'F';
    for (int ii = 0; ii < 6; ii++)
    {
        for (int kk = 0; kk <= ii; kk++)
        {
            printf("%c", ee-kk);
        }
        printf("\n");
    }

    char we = 'A';
    for (int ui = 0; ui < 6; ui++)
    {
        for (int qi = 0; qi <= ui; qi++)
        {
            
            printf("%c",we);
            we = we + 1;
            
        } 
        printf("\n");
    }
    
    char ch;
    printf("Please enter a upper letter: ");
    scanf("%c", &ch);

    int length = ch - 'A';
    for (int i = 0; i <= length; i++)
    {
        char t = 'A' - 1;
        for (int j = 0; j < length - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%c", ++t);
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c", --t);
        }
        printf("\n");
    }


    
    

    system("pause");
    return 0;
    
}
