#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//成绩结构体
struct score
{
	char snum[9];
	char sname[11];
	int chinese;
	int math;
	int english;
	int sumcj;//成绩总数 
	int rank;//排名 
};

//函数声明 
void showmenu(void);//菜单 
int xg(int);//修改成绩   
void lr(int);//录入成绩 
void cx(int);//查询成绩 
void xhcx(int);//学号查询 
void xmcx(int n);//姓名查询
void allrankcx(int);//排名查询 
void showcxmenu(void);//二级菜单，查询菜单 
void xs(int);//成绩显示 
void jspm(int);//计算排名 
int sc(int);//删除成绩 
void bccj(void);//保存成绩并退出 

//main函数 
int main()
{
	int flag,n=0,count=0;//flag标志位,count计数,当前总人数
	//-------------判断文件里面有多少条记录--------------------//
	FILE *fp;
	fp=fopen("cj.txt","a+");
	if(fp==NULL)
	{
		printf("打开文件失败,请重试！\n");
		getch(); 
		fclose(fp);  
		exit(0);
	} 
	int c = 0;
	while(!feof(fp))
	{
		char cc = fgetc(fp);
		if(cc==EOF)
        {
        	break;
        }
        //输出字符
//        putchar(cc);
		c++;
	}
	count = c/14;
//	printf("%d", count); 
//	getch();
	fclose(fp);
	//---------------------------------//
	do
	{
		showmenu();
		scanf("%d",&flag);//选择操作 
		switch(flag)
		{
			case 1: printf("请输入您要录入的人数：");
					scanf("%d",&n);
				    lr(n);
					count += n;break;
			case 2: count=sc(count);break;
			case 3: xg(count);break;
			case 4: cx(count);break;
			case 5: jspm(count);break;
		    case 6: xs(count);break;
		    case 0: bccj();break; 
		    default:printf("输入错误，请重试！\n");getch(); 
		} 
	}while(flag!=0);
	getch();
	return 0;
}

//0显示菜单
void showmenu()
{
	system("cls"); 
	printf("*----------------------------------------------------*\n");
	printf("*               欢迎使用**成绩管理系统               *\n");
	printf("*----------------------------------------------------*\n"); 
	printf("*               1： 录入学生成绩                         *\n");
	printf("*               2： 删除学生成绩                         *\n");
	printf("*               3： 修改学生成绩                         *\n");
	printf("*               4： 学生成绩查询                         *\n");
	printf("*               5： 排序学生成绩                  *\n");
	printf("*               6： 显示学生成绩                     *\n");
	printf("*               0： 保存信息并退出系统               *\n");
	printf("*----------------------------------------------------*\n");
	printf("选择操作<0-6>                                         \n");
	return;
}
 
//1录入成绩 
void lr(int n)
 {
 	struct score stu[100];
 	FILE *fp;
 	fp=fopen("cj.txt","a+");
 	if(fp==NULL)
 	{
		printf("打开文件失败,请重试！\n");
		getch(); 
		fclose(fp);
		exit(0);
	}
 	printf("请输入全部学生的学号，姓名，语文成绩，数学成绩，英语成绩；\n"); 
 	int i;
 	for(i=0;i<n;i++)
 	{	
 		printf("----第%d个学生----\n", i+1);
		printf("学号:");
		scanf("%s",&stu[i].snum);
		
		printf("姓名：");
		scanf("%s,",&stu[i].sname);
		
		printf("语文成绩：");
		scanf("%d",&stu[i].chinese);
		
		printf("数学成绩：");
		scanf("%d",&stu[i].math);
		
		printf("英语成绩：");
		scanf("%d",&stu[i].english);
		
		stu[i].sumcj=0;
		stu[i].rank=0;	
		//写入数据 
		fprintf(fp,"%s %s %d %d %d %d %d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);} 
	 	fclose(fp);
	 	printf("添加学生成功,请按任意键返回\n");
	 	getch();
 }
	
//2删除成绩                                    
int sc(int n)
{
	struct score stu[100];
	struct score sub[99];//删除后的结构体数组 
	char stnum[9];//学号
	int find=0;
	printf("请输入你要删除的学生学号:"); 
	scanf("%s", &stnum);
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败,请联系管理员\n");
		getch(); 
		return -1;   
	}
	int c=0;
	int index=0;//用于记录目标序号 
	while(!feof(fp))//不为空
	{ 
		fscanf(fp,"%s %s %d %d %d %d %d\n", &stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
		if(strcmp(stnum,stu[c].snum)==0)
		{
			find = 1;//根据学号查找，找到赋值为1 
			index = c;//记录编号
		} 
		c++;
	}
	fclose(fp);
	if(n==0)
	{
		printf("已经没有学生成绩信息了,请按任意键返回\n");
		getch();  
		showmenu();
		return n;
	}
	if(find==0)
	{
		printf("没有该学生成绩信息,请按任意键返回\n");
		getch();  
		showmenu();
		return n;
	}
	else 
	{
		int i;
		//删除 
		for(i=0;i<c;i++)
		{
			if(i < index)
			{
				sub[i] = stu[i];
			}
			else
			{
				sub[i] = stu[i+1];
			}
		}
		
		fp=fopen("cj.txt","w");
		//写入数据 
		for(i=0;i<c-1;i++)
		{
			fprintf(fp,"%s %s %d %d %d %d %d\n",sub[i].snum,sub[i].sname,sub[i].chinese,sub[i].math,sub[i].english,sub[i].sumcj,sub[i].rank); 	
		} 
		fclose(fp);
		printf("学号为%s的学生成绩删除成功,请按任意键返回\n",stnum);
		getch();
		showmenu();
		return n-1;
	}     
}
 
//3修改成绩
int xg(int n) 
{	
	struct score stu[100];
 	FILE *fp;
 	char stnum[9];
 	int find=0;  
 	printf("请输入要修改的学生学号:");
 	scanf("%s",stnum);
 	fp=fopen("cj.txt","r");
 	if(fp==NULL)
 	{
	  	printf("文件打开失败,请联系管理员\n");
	  	getch();
	  	return -1;	
 	}
 	int c=0;
 	while(!feof(fp))
	{
	 	fscanf(fp,"%s %s %d %d %d %d %d\n",&stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
	 	if(strcmp(stnum,stu[c].snum)==0)	
		{
		 	find=1;
		 	//修改操作 
		 	printf("找到你要修改成绩的同学,请输入他的成绩:\n");
		 	printf("语文成绩: %d,新成绩为:",stu[c].chinese);
		 	scanf("%d",&stu[c].chinese);
		 	printf("数学成绩: %d,新成绩为:",stu[c].math); 
		 	scanf("%d",&stu[c].math);
		 	printf("英语成绩: %d,新成绩为:",stu[c].english);
		 	scanf("%d",&stu[c].english);
 		}
  		c++;	
 	}
	fclose(fp);
	if(find==0)
	{
		printf("没有找到要删除的学生记录,请按任意键退出\n");
		getch(); 
	} 
	else
 	{
	  	fp=fopen("cj.txt","w");
	  	int i; 
	   	for(i=0;i<n;i++)
	   	{
	   		//更新数据 
		    fprintf(fp,"%s %s %d %d %d %d %d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);	
	   	}
		fclose(fp);	 
		printf("学号为%s同学的成绩已经修改成功,请按任意键返回",stnum);
 		getch(); 
 	}
  	showmenu();
  	return 1; 
}
   
//4成绩查询
void cx(int n) //n全班人数 
{
	int k;
	do
	{
		showcxmenu();
		scanf("%d",&k); 
		switch(k)
		{ 
			case 1:xhcx(n);break;//学号查询 
			case 2:xmcx(n);break;//姓名查询 
			case 3:allrankcx(n);break;//全班排名查询
			case 0:break;
			default:printf("输入错误，请重新选择\n");getch();
		} 
	}while(k!=0);
	return;		
}

//4.0查询菜单
void showcxmenu() 
{
	system("cls");
	printf("*----------------------------------------------------*\n");
	printf("*                    成绩查询菜单                    *\n");
	printf("*----------------------------------------------------*\n"); 
	printf("*               1： 按学号查询                       *\n");
	printf("*               2： 按姓名查询                       *\n");
	printf("*               3： 全班排名查询                     *\n");
	printf("*               0： 退出查询系统，返回主系统         *\n");
	printf("*----------------------------------------------------*\n");
	printf("选择操作<0-3>                                         \n");
}

//4.1学号查询
void xhcx(int n)
{   
	struct score stu[100];
	char snum[9];
	printf("请输入你要查询学生的学号：");
	scanf("%s",&snum);
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0); 
	}
	int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n",&stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
		c++;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(snum,stu[i].snum)==0)
		{
			printf("学号\t姓名\t语文\t数学\t英语\t总分\t名次\n");
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);
			printf("按任意键返回\n");
			getch();
			fclose(fp);
			return;			
		}
	}
	printf("未找到要查询学生的成绩，请重试！\n");
	getch();
	fclose(fp);
	return;
}  

//4.2姓名查询
void xmcx(int n)
{
  	struct score stu[100];	
	char sname[11];
	printf("请输入你要查询学生的姓名：");
	scanf("%s",&sname);
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0); 
	}
	int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n\n",&stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
		c++;
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(sname,stu[i].sname)==0)
		{
			printf("学号\t姓名\t语文\t数学\t英语\t总分\t名次\n");
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);
			printf("按任意键返回\n");
			getch();
			fclose(fp);
			return;
		}
	}
	printf("未找到要查询学生的成绩，请重试！\n");
	getch();
	fclose(fp);
	return;     
}

//4.3全班排名查询
void allrankcx(int n)
{
  	struct score stu[100];	
  	struct score temp;	
	FILE *fp; 
	fp=fopen("cj.txt ","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0); 
	}
	int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n",&stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
		c++;
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		if(stu[i].rank == 0){
			printf("请先进行成绩计算进行排名！！\n");
			getch();
			fclose(fp);
			return;	
		}
		stu[i].sumcj = stu[i].chinese + stu[i].math + stu[i].english;
		//冒泡排序算法：进行 n-1 轮比较
	    for(i=0; i<n-1; i++){
	        //每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
	        for(j=0; j<n-1-i; j++){
	            if(stu[j].sumcj > stu[j+1].sumcj){
	                temp = stu[j];
	                stu[j] = stu[j+1];
	                stu[j+1] = temp;
	            }
	        }
	    }
	    printf("学号\t姓名\t语文\t数学\t英语\t总分\t名次\n");
	    for(i=0;i<n;i++)
	    {
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);
		}
		printf("按任意键返回\n");
		getch();
		fclose(fp);
		return;
	}
	printf("查询失败，请重试！\n");
	getch();
	fclose(fp);
	return;     
}

//5计算排名函数 
void jspm(int n)
{
	struct score stu[100];
	int i,j,temp;
	int count;
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		getch();
		exit(0);
	}
    int c = 0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %d %d %d\n",&stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
		stu[c].sumcj = stu[c].chinese + stu[c].math + stu[c].english;
		c++;
	}
	fclose(fp);
	//计算排名并存储 
    for(i=0;i<n;i++)
    {
	    temp=1;//第1名 
	    for(j=0;j<n;j++){
	    	if(stu[i].sumcj<stu[j].sumcj) temp++;//如果较小，排名下降1名
		} 
		stu[i].rank=temp;
    }
    //更新记录 
    fp=fopen("cj.txt","w");
   	for(i=0;i<n;i++)
   	{
	    fprintf(fp,"%s %s %d %d %d %d %d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);	
   	}
	fclose(fp);
    printf("数据重新计算和排名成功,请按任意键返回主菜单。\n");
	getch();
    return;       
}

//6显示成绩信息
void xs(int n) 
{
	struct score stu[100];
	int i;	
	printf("成绩信息如下：\n");
	FILE *fp;
	fp=fopen("cj.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败,请重试！\n");
		getch(); 
		fclose(fp);  
		exit(0);
	} 
	printf("学号\t姓名\t语文\t数学\t英语\t总分\t名次\n"); 
	int c = 0;
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d %d %d %d\n",&stu[c].snum,&stu[c].sname,&stu[c].chinese,&stu[c].math,&stu[c].english,&stu[c].sumcj,&stu[c].rank);
		c++;
	}
	if(n!=0){//人数不为0 
		for(i=0;i<c;i++)
		{
			printf("%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].snum,stu[i].sname,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sumcj,stu[i].rank);
		}	
	}
	fclose(fp); 
	printf("显示完毕 ,请按任意键返回\n");
	getch();
	return;
}

//0保存信息并退出系统
void bccj()
{
	printf("感谢您的使用，欢迎下次使用!\n");
	getch();
	system("pause");	 
	return;

}
