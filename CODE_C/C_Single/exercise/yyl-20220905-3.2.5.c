#include <stdio.h>

void sort(int *s, int n, int x);     //定义排序函数

int main()
{
	int n[10], *p, m;
	for (p=n, printf("Please enter 10 numbers: "); p<n+10; scanf("%d", p++));   
	printf("Please enter move number: ");                                      
	scanf("%d", &m);
	for (; m<0||m>10; printf("Error! Retry!\nPlease enter move number: "), scanf("%d", &m));
	sort(n, 10, m);                                                            
	for (p=n, printf("Sort by: "); p<n+10; printf("%d ", *p++));               
	printf("\n");
    system("pause");
	return 0;
}


void sort(int *s, int n, int x)
{
	int *i, j, *k, t[10];								
	for (i=s+n-x, j=0; i<s+n; t[j++]=*i++);				
	for (i=s+n-x-1,  k=s+n-1;k>=s+x; *k--=*i--);		 
	for (j=0; j<x; *s++=t[j++]);	
}				
