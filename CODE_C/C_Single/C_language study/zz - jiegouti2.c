/*
   2023年2月6日16点01分
   结构体的定义方式
   
 */
#include <stdio.h>
#include<stdlib.h>
//第一种定义方式  这只是定义了一个新的数据类型，并没有定义变量
struct Student 
{
  int age;
  float score;
  char sex;
};
//第二种定义方式  
struct Student2 
{
  int age;
  float score;
  char sex;
} st2;
//第三种定义方式
struct 
{
  int age;
  float score;
  char sex;
} st3;
int main()
{
    
    
    
    system("pause");
    return 0;
}