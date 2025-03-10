/*
   2023年2月6日16点25分
   如何取出结构体变量中的每一个成员
   
 */
#include <stdio.h>
#include<stdlib.h>
struct Student 
{
  int age;
  float score;
  char sex;
};
int main()
{
    struct Student st = {80, 66.6f, 'F'};
    struct Student * pst = &st;   //&st不能改成st
    st.score = 66.6f; //第一种取出方式
    pst->age = 88; //第二种取出方式
    printf("%d %f\n", st.age, pst->score);
    /* 
    注：1. pst->age 在计算机内部会被转化成(*pst).age  这就是->的含义，这也是一种硬性规定  
        2. 所以pst->age等价于(*pst).age也等价于st.age
        3. 我们只所以知道pst->age等价于st.age是因为pst->age是被转化成了(*pst).age来执行
        4. pst->age 的含义：pst所指向的那个结构体变量中的age这个成员
            
    */
    system("pause");
    return 0;
}