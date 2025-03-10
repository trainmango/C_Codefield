/*
   2023年2月9日17点43分
   枚举
   
 */
#include <stdio.h>
#include<stdlib.h> 
//只定义了一个数据类型  并没有定义变量  该数据类型的名字是enum WeekDay
enum WeekDay
{
    MonDay, TuesDay, WednesDay, ThursDay, FriDay, SaturDay, SunDay
};//第一个是0 往后依次1 2 3 4 5 6

int main()
{
  
    //int day;   //day定义成int类型不合适
    enum WeekDay day = WednesDay;
    printf("%d\n", day);
    
    system("pause");
    return 0;
}