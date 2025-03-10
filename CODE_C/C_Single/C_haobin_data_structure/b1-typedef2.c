/* 
    2023年2月23日21点29分
    typedef的用法——2
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Student
{
  int sid;
  char name[100];
  char sex;
}* PST;  //PST 等价于struct Student *

int main()
{
    struct Student st;
    PST ps = &st;  //即struct Student * ps = &st;
    ps->sid = 99;
    printf("%d\n",ps->sid);
    system("pause");
    return 0;
}