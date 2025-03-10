/* 
    2023年2月23日21点15分
    typedef的用法
 */
#include <stdio.h>
#include <stdlib.h>
typedef int ZHANGSAN; // 为int再重新多取一个名字，ZHANGSAN等价于int

typedef struct Student 
{
  int sid;
  char name[100];
  char sex;
}ST;   //即既可以用struct Student 也可以用 ST ，他们是等价的，不是不能用了
       /*即等价于
          struct Student
          {
            int sid;
            char name[100];
            char sex;
          };
          typedef struct Student ST; //typedef相当于为这个结构体新赋予一个叫ST的名字
        */ 
int main()
{
    /* 
    int i = 10; //等价于 ZHANGSAN i = 10;
    ZHANGSAN j = 20;
    printf("%d\n", j);  //输出结果为20
    */
    struct Student st;  //等价于ST st;
    struct Student * ps = &st;  //等价于ST * ps;
    ST st2;
  
  
    st2.sid = 200;
    printf("%d\n", st2.sid);
    system("pause");
    return 0;
}