# include<stdio.h>
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10];
	int i,m,k=0;
	printf("原始的数组：\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n请输入要移动多少个位置：\n");
	scanf("%d",&m);
	for (i = 10-m; i < 10; i++)
	{
		b[k]=a[i];
		k++;
	}
	for (i = 0; i < 10-m; i++)//将后面未移动的元素放到数组b中
	{
		b[k]=a[i];
		k++;
	}
	for (i = 0; i < 10; i++)//打印出结果
	{
		printf("%5d",b[i]);
	}
	system("pause");
	return 0;
}
