/*
   2023年2月6日16点14分
   结构体变量的赋值和初始化
   
 */
#include <stdio.h>
#include<stdlib.h>

struct Student 
{
  int age;
  float score;
  char sex;
};
int main(void)
{
    struct Student st = {80, 66.6, 'F'}; //初始化 定义的同时赋初值
    struct Student st2;
    st2.age = 10;
    st2.score = 88;
    st2.sex = 'F';  
    struct Student * ddd;
    printf("%d %f %c\n", st.age, st.score, st.sex);
    printf("%d %f %c\n", st2.age, st2.score, st2.sex);
    printf("%d  %d\n",sizeof(st),sizeof(ddd));
    system("pause");
    return 0;
}