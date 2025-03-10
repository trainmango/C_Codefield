/* 
   2023年11月16日15点46分
   c语言动态数组案例实现
 */
#include <stdio.h>
#include<stdlib.h>
typedef struct 
{
  int * array;  //定义数组【用指针定义】
  size_t size;   //定义其数组元素个数  size_t 在64位的系统中有8个字节的大小
}dynamic_array;

dynamic_array * create_arary(size_t size)         //定义一个动态数组
{
  dynamic_array * arr = (dynamic_array *)malloc(sizeof(dynamic_array));  
  arr->array = (int *)malloc(size * sizeof(int));  // 定义其数组
  arr->size = size;   //告知其数组元素个数
  return arr;
}

int read_dynamic_array(dynamic_array * arr, size_t index) //读取此数组
{
    if (index < arr->size)
    {
      return arr->array[index];
    }
    else
    {
      printf("error");
      return -1;
    } 
}
void update_array(dynamic_array * arr, size_t index,int value)
{
   if (index < arr->size)
    {
      arr->array[index] = value;
    }
    else
    {
      printf("error");
    } 
}
void delete_array(dynamic_array * arr)
{
    free(arr->array);
    free(arr);
}
void show_array(dynamic_array * arr, size_t index)
{
   for (int i = 0; i <= index; i++)
   {
      printf("%d\n", arr->array[i]);
   }
   
}
int main()
{
    dynamic_array * arr = create_arary(10);
    read_dynamic_array(arr,9);
    show_array(arr,9);
    return 0;
}