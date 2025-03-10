/* 
         2023年2月9日16点53分
          学生管理系统
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Student
{
    int age;
    float score;
    char name[100];
};
  

int main()
{
    int len;
    struct Student * pArr;
    int i, j;
    struct Student t;
    
    printf("请输入学生的个数：\n");
    
  
    scanf("%d", &len);

 
 //动态的构造一维数组
    pArr = (struct Student *)malloc(len * sizeof(struct Student)); //可自己定义长度

    for ( i = 0; i < len; i++)
    {
        printf("请输入第%d个学生的信息：", i+1);
        printf("age = ");
        scanf("%d", &pArr[i].age);
        printf("name = ");
        scanf("%s", pArr[i].name);  //name是数组名，本身就已经是数组首元素地址
                                    //所以pArr[i].name 不能改成&pArr[i].name
        printf("score = ");
        scanf("%f",&pArr[i].score);
        printf("\n");
    }
    //按学生成绩升序排序 冒泡法
    for ( i = 0; i < len-1; i++)
    {
        for ( j = 0; j < len-1-i; j++)
        {
            if (pArr[j].score > pArr[j+1].score)
            {
                t = pArr[j];  //互换的是整体，而不是只把人家成绩换了
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;
            }
            
        }
        
    }
    

    printf("\n\n学生信息是：\n");
    //输出
      for ( i = 0; i < len; i++)
    {
        printf("第%d个学生的信息是：\n", i+1);
        printf("age = %d\n", pArr[i].age);
        printf("name = %s\n", pArr[i].name);
        printf("score = %f", pArr[i].score);
        printf("\n\n");
      
       
    }
    
    system("pause");
    return 0;
}