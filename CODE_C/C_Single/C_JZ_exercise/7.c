/**
 * @file 7.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
int main()
{
 

	int n,i,k;
	printf("请输入一个数：\n");
	scanf("%d",&n);
	k = sqrt(n);
	for(i=2;i<=k;i++)
		if(n%i==0)
			break;
	if(i<=k)
		printf("%d不是素数\n",n);
	else
		printf("%d是素数\n",n); 
	

  
    system("pause");
    return 0;
    
}