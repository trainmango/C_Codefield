/* 
   2023年2月23日21点36分
    typedef的用法——3
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Student
{
  int sid;
  char name[100];
  char sex;
}* PSTU, STU;  //等价于STU代表了struct Student， PSTU代表了struct Student *

int main()
{
    STU st; //struct Student st;
    PSTU ps = &st; //struct Student * ps = &st;
    ps->sid = 99;
    printf("%d\n",ps->sid);
    system("pause");
    return 0;
}