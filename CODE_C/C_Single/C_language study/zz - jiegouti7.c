/* 
     2023年2月7日20点41分
     示例：
          发送地址还是发送内容
        目的： 
             指针的优点之一：
                快速传递数据
                耗用内存小
                执行速度快
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
void OutputStudent(struct Student *);
int main(void)
{
    struct Student st;   
    printf("%d\n", sizeof(st));
    InputStudent(&st);   //对结构体变量输入  必须发送st的地址
    OutputStudent(&st);  //对结构体变量输出  可以发送st的地址也可以直接发送st的内容
                         //但为了减少内存的耗费，也为了提高执行速度，推荐发送地址。
 
    
    system("pause");
    return 0;
}
void InputStudent(struct Student *pstu)
    {
    (*pstu).age = 10;
    strcpy(pstu->name, "张三");
    pstu->sex = 'F';
    } 
void OutputStudent(struct Student *pstu) //类比zz - jiegouti6.c，不用指针用发送内容的话，上面占了108个字节，下边也得占108个字节，而指针只发送一个地址耗内存更小
{
     printf("%d %c %s\n", pstu->age, pstu->sex, pstu->name); //因为是输出所以不需要改变它的值，所以不用指针，相当于把st的值拷贝了一份
}