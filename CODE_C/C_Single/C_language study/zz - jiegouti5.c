/*
      2023年2月7日14点36分
      结构体复习
 
   
 */
#include <stdio.h>
#include<stdlib.h>
struct Student //定义了一个数据类型struct Student  它是结构体类型
{
  int age;
  char sex;
  char name[100];
};   //分号不能省
int main()
{
    struct Student st = {20, 'F', "小娟"};  //定义了一个变量st，他是结构体变量
   
    struct Student * pst = &st;   //&st不能改成st

 //两种取出方式
    printf("%d %c %s\n", st.age, st.sex, st.name);

    printf("%d %c %s\n", pst->age, pst->sex, pst->name);  //pst->age 转化成了(*pst).age

    system("pause");
    return 0;
}