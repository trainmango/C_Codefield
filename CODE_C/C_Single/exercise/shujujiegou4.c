#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyStrstr(char* str,char* substr)
{
	int num = 0;
	while (*str != '\0')
	{
		if (*str != *substr)
		{
			str++;
			num++;
			continue;
		}

		//创建临时指针
		char* tmpstr = str;
		char* tmpsubstr = substr;

		while (*tmpsubstr != '\0')
		{
			if (*tmpstr != *tmpsubstr)
			{
				//匹配失败
				str++;
				num++;
				break;
			}
			tmpstr++;
			tmpsubstr++;
		}
		if (*tmpsubstr == '\0')//匹配成功
		{
			return num;
		}
	}
	return -1;
}

void test()
{
	char* str = "abclefglol";
	int ret = MyStrstr(str,"lol");

	if (ret == -1)
	{
		printf("查找失败！\n");
	}
	else
	{
		printf("查找成功！位置为：%d\n",ret);
	}
}

int main()
{
	
	printf("abclefglol\n");
	printf("lol\n");
	test();
    system("pause");
	return 0;
}
