/**
 * @file 19.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
//二进制打印32位 的字符串
#include <limits.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

char * strinng(int, char *); 
void show_four(const char *);
int main()
{   
    int numb;
    char bin[sizeof(int) * CHAR_BIT + 1];   
    while (scanf("%d", &numb))
    {
       
         strinng(numb, bin);
         printf("the numb is :%d\n", numb);
         show_four(bin);
         putchar('\n');
    }
    
    system("pause");
    return 0;
    
}

char * strinng(int s, char * x){
    const static int sizee = (sizeof(int)) * CHAR_BIT;
    for (int i = sizee - 1; i >= 0 ; i--, s>>=1)
    {                                           //从31至0  00000000 00000000 00000000 00000011 (3) 
        x[i] = (01 & s) + '0';                          // 00000000 00000000 00000000 00000001
    }                                                   //                          .....   01
    x[sizee] = '\0';//末尾补‘\0’
    return x;
}
//四位一组显示二进制串
void show_four(const char * z){
    
    
        int i= 0;
        while (z[i]) //判断是否为空  z[i]等价于 *z+i
        {
            putchar(z[i]);
            if(++i%4 == 0 && z[i])
            {
              
                putchar(' '); 
            }
          
        }
        
    
         
}