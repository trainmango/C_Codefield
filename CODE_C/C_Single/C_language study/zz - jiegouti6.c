/* 
     2023年2月7日14点48分
     结构体变量和结构体指针变量作为函数参数传递的问题
     通过函数完成对结构体变量的输入和输出
 */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//void InputStudent(struct Student stu);
struct Student
{
    int age;
    char sex;
    char name[100];
};
void InputStudent(struct Student *);   //声明的时候形参名写不写无所谓  【*pstu】与【*】都可 *pstu更好认
void OutputStudent(struct Student ss);
int main(void)
{
    struct Student st;
    InputStudent(&st);   //对结构体变量输入  必须发送st的地址
    OutputStudent(st);  //对结构体变量输出  可以发送st的地址也可以直接发送st的内容
    printf("%d %c %s\n", st.age, st.sex, st.name);
 
 
    
    system("pause");
    return 0;
}
void InputStudent(struct Student *pstu)
    {
    (*pstu).age = 10;
    strcpy(pstu->name, "张三");
    pstu->sex = 'F';
    } 
void OutputStudent(struct Student ss)
{
     printf("%d %c %s\n", ss.age, ss.sex, ss.name); //因为是输出所以不需要改变它的值，所以不用指针，相当于把st的值拷贝了一份
}
/* 

    //本函数无法修改主函数st的值，所以本函数是错误的

    void InputStudent(struct Student stu)
    {
    stu.age = 10;
    strcpy(stu.name, "张三");   //不能写成 stu.name = "张三";   
    stu.sex = 'F';
    } 
*/