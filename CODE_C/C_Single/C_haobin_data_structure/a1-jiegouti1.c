/* 
      2023年2月12日18点49分
      结构体复习
 */
#include <stdio.h>
#include<stdlib.h>
struct Student
{
    int sid;
    char name[100];
    int age;
};           //    ; 不能省略
int main()
{
    struct Student st = {1000, "zhangsan", 20};
    printf("%d %s %d\n", st.sid, st.name, st.age);
    struct Student * pst;
    pst = &st;
    pst->sid = 99;  // pst->sid等价于(*pst).sid 而(*pst).sid等价于st.sid
  
    system("pause");
    return 0;
}


