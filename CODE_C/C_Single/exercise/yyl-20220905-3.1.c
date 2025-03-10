#include<stdio.h>
int mai(int *a,int *b)
{
	int yyl_t;
	if(*a>*b)
	{
		yyl_t=*a;
		*a=*b;
		*b=yyl_t;
	}
}
int main()
{
	int a,b,*qa,*qb;
	scanf("%d %d",&a,&b);
	qa=&a;
	qb=&b;
	mai(qa,qb);
	printf("a=%d,b=%d\n*qa=%d,*qb=%d",a,b,*qa,*qb);
    system("pause");
	return 0;
}

