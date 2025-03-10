/*
   2023年2月6日15点37分【注zz前缀为想把结构体放在zhizhen的下边】
   结构体
   
 */
#include <stdio.h>
#include<stdlib.h>

struct Student //结构体
{
  int age;
  float score;
  char sex;
};

int main()
{
   
    struct Student st = {80, 66.6, 'F'};   //struct Student st 结构体变量
  
   /*
    int age;
    float score;
    char sex;
    int age2;           //这样写数据是散的，数据多了太复杂了
    float score2;
    char sex2;
    
    */
    system("pause");
    return 0;
}