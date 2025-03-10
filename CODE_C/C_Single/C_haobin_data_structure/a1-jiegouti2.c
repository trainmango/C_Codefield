/* 
     2023年2月12日19点29分
      结构体复习
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
    int sid;
    char name[100];
    int age;
};           //    ; 不能省略
void f(struct Student * pst);
void g(struct Student st);
void g2(struct Student * pst);
int main()
{
    struct Student st;
    f(&st);
   // printf("%d %s %d\n", st.sid, st.name, st.age);
    g(st);
    g2(&st);  
    system("pause");
    return 0;
}
void g(struct Student st) //这种方式耗内存 耗时间 不推荐
{
    printf("%d %s %d\n", st.sid, st.name, st.age);
}
void g2(struct Student * pst)
{
    printf("%d %s %d\n", pst->sid, pst->name, pst->age);
}
void f(struct Student * pst)
{
    (*pst).sid = 99;
    strcpy(pst->name, "zhangsan");
    pst->age = 22;

}

