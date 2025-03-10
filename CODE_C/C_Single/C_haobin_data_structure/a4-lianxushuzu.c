/*
      2023年2月23日16点31分
      连续数组的存储
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <malloc.h>
//定义了一个数据类型，该数据类型的名字叫 struct Arr，该数据类型含有三个成员
struct Arr
{
    int * pBase; //存储的是数组第一个元素的地址
    int len;  // 数组所能容纳的最大元素的个数
    int cnt;  // 当前数组有效元素的个数
};

void init_arr(struct Arr * pArr, int length); //初始化  //希望通过调用此函数完成struct Arr arr;中pBase指向一个有效的数组
bool append_arr(struct Arr * pArr, int val); //追加
bool insert_arr(struct Arr * pArr, int pos, int val); //插入   //pos为位置， val为插入值 //pos的值从1开始 例：pos为3，下标就为2
bool delete_arr(struct Arr * pArr, int pos, int *pVal); //删除                                                                 //即pos = 1是下标pos-1 = 0                         
bool get(); //获取某下标的值
bool is_empty(struct Arr * pArr); //数组为空
bool is_full(struct Arr * pArr);  //数组为满
void sort_arr(struct Arr * pArr);  //排序
void show_arr(struct Arr * pArr);   //显示输出
void inversion_arr(struct Arr * pArr); //倒置


int main()
{
    struct Arr arr;
    int val;
    init_arr(&arr, 6);  //传递的是arr的地址
    show_arr(&arr);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    if(delete_arr(&arr,4, &val))
    {
        printf("删除成功！\n");
        printf("您删除的元素是：%d\n", val);
    }
    else
    {
        printf("删除失败！\n");
    }
    show_arr(&arr);
    inversion_arr(&arr);
    printf("倒置");
    show_arr(&arr);
    sort_arr(&arr);
    show_arr(&arr);
   /* 
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    insert_arr(&arr, 1, 99);
    show_arr(&arr);
     */
    system("pause");
    return 0;
}
void init_arr(struct Arr *pArr, int length) // 如果不是指针变量则会导致传参对实参无影响
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);   //相当于pArr这个指针变量所指向的结构体变量中的pBase这个成员
    if (NULL == pArr->pBase)
    {
        printf("动态内存分配失败！\n");
        exit(-1);  //终止整个程序
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;  
}
bool is_empty(struct Arr * pArr)
{
    if (0 == pArr->cnt)
       return true;
    else
       return false;   
}
bool is_full(struct Arr * pArr)
{
    if (pArr->cnt == pArr->len)
       return true;
    else 
       return false;
    
}
void show_arr(struct Arr * pArr)  //arr的地址赋给了pArr
{   
    if (is_empty(pArr))   //pArr已经是arr的地址了
    {
       printf("数组为空！\n");
    }
    else
    {
        for (int i = 0; i < pArr->cnt; i++)
        {
            printf("%d ", pArr->pBase[i]); //pArr只是一个结构体变量的地址 //int *
            //指的是pArr指向的主函数中的结构体变量中有一个pBase成员它指向的数组里面i那个成员
           
        } 
    } 
    /* 
    if (数组为空)
       提示用户数组为空
    else
        输出数组有效内容
     */
}
bool append_arr(struct Arr * pArr, int val)
{
    //满时返回false
    if (is_full(pArr))
      return false;
    //不满时追加
    pArr->pBase[pArr->cnt] = val;  //末尾插入，cnt刚好就是最后一个数组元素 例：cnt == 3时，pBase[0~2]就表示完了三个元素，所以pBase[3]刚好是要插入的第四个元素
    (pArr->cnt)++;
    return true; 
}
bool insert_arr(struct Arr * pArr, int pos, int val)// 插入元素  即pos等于1是一号位置下标为pos-1 = 0  //pos为位置， val为插入值
{
    int i;
    if(is_full(pArr))
        return false;
    if (pos<1 || pos>pArr->cnt+1)  //pos从1开始
        return false;

    for ( i = pArr->cnt-1; i >= pos-1; i--) //cnt-1即为当前元素下标【当前元素为最后一个元素】 例：pos位置为3，其在数组中下标为2
    {                                       //i>=pos-1 例：当pos为3时，下标为2，也移动
        
       /* 
        pArr->pBase[0] = 1;cnt = 1;
        pArr->pBase[0] = 1;cnt = 1;
        pArr->pBase[0] = 1;cnt = 1; 
        pArr->pBase[cnt] = val;
        ++cnt;
        */
        
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos-1] = val;
    (pArr->cnt)++;
    return true;
    
    //例: 7  -5  2  8  11       数组元素  假设pos值为3， val的值为88 即在-5 和 2 之间插入88
    //                                               所以2，8，11先往后移                                              
    //    0   1  2  3   4   5   下标    cnt-1即为下标
}  
bool delete_arr(struct Arr * pArr, int pos, int *pVal)
{
    if (is_empty(pArr))
       return false;
    if(pos<1 || pos>pArr->cnt)
       return false;

       *pVal = pArr->pBase[pos-1];
       for ( int i = pos; i < pArr->cnt; i++)
       {
          pArr->pBase[i-1] = pArr->pBase[i];
       }
       pArr->cnt--;
       return true;
       
    
}
void inversion_arr(struct Arr * pArr)
{
    int i = 0;
    int j = pArr->cnt-1;
    int t;
    while (i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
    return;
}
void sort_arr(struct Arr * pArr)
{
    int i, j, t;

    for ( i = 0; i < pArr->cnt; i++)
    {
        for ( j = i+1; j < pArr->cnt; j++)
        {
           if (pArr->pBase[i] > pArr->pBase[j])
           {
            t = pArr->pBase[i];
            pArr->pBase[i] = pArr->pBase[j];
            pArr->pBase[j] = t;
           }
           
        }
        
    }
    
}