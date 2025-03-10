/**
 * @file quicksort.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define cutoff 3
int media3(int * ,int, int);
void swap(int * , int*);
void Qsort(int * , int, int);
void insertionsort2(int * , int);
void bianli(int *, int);
int main() 
{                  //比较极端的选择全为2时，i j pivot相等时，也让游标i j停止 
    int arr[13] = {-2,-4,-34,3,5,7,34,56754,23,34,33,1,3456};//{-2,-4,-34,3,5,7,34,56754,23,34,33,1,3456};{2,2,2,2,2,2,2,2,2,2,2,2,2};
    Qsort(arr, 0, 12);
    bianli(arr, 13);
    system("pause");
    return 0;
}
void swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int media3(int * a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[left] > a[center])
    {
        swap(&a[left], &a[center]);
    }
    if (a[left] > a[right])
    {
        swap(&a[left], &a[right]);
    }
    if (a[center] > a[right])
    {
        swap(&a[center], &a[right]);
    } 
    //现在，a[left] <= a[center] <= a[right]
    swap(&a[center], &a[right - 1]);//让center和right - 1角标的值互换
    return a[right - 1];//返回pivot【枢纽元】 
}
void Qsort(int * a, int left, int right)
{
    int i, j, pivot;//pivot为枢纽元
    if (left + cutoff <= right)//判断数组长度是否大于3【即最小长度要为4】（因为要用三数中值分割法）
    {
        pivot = media3(a, left, right);//选取枢纽元的值
        i = left; 
        j = right - 1;
        /**
         * 这样是不可以的，两个的逻辑相似，但这样写会导致遇到相等的i j pivot时无限交换而导致死循环。不可以这样
         * i = left + 1; 
           j = right - 2;
         for()
         * while(a[i] < pivot){i++;}
           while(a[j] > pivot){j--;}
         * ……………………
         */
        for ( ; ; )//死循环 用while(1){}也可以
        {
            while(a[++i] < pivot){}//往右滑动，当数组值大于等于pivot时，停止【即等于时也让它停止】
            while(a[--j] > pivot){}//往左滑动，当数组值小于等于pivot时，停止【】
            if (i < j)//若i， j 没有相交，则互换
            {
                swap(&a[i], &a[j]);
            }
            else
            {
                break;//否则跳出for这个死循环
            }   
        }
        swap(&a[i], &a[right - 1]);//分割最后一步将枢纽元和i所指向的元素进行交换
        Qsort(a, left, i - 1);//分治   left ……………… i-1  i  i+1 ……………… right 
        Qsort(a, i + 1, right);//
    }
    else
    {
        insertionsort2(a+left, right - left + 1);//a+left即&a[left]
    }
}

void insertionsort2(int *a, int val)
{
    int pass; // 插入排序的 趟数
    int temp;
    int i;                         //3, 4, 1, 6, 7, 5, 2, 9, 8, 10
  
    for (pass = 1; pass < val; pass++) // n个数的插入排序需要n - 1趟排序  
    {
        temp = a[pass];//临时保存
        for (i = pass; i > 0; i--)//第n趟要和前边n个元素进行排序 
        {
            if (temp < a[i - 1])
            {
                a[i] = a[i - 1];
            }   
            else
            {
                break;//break是为了例如 第二次 3 4 9， 插入9的时候不要进行任何交换，因为9大于4时 一定大于4前边的数
                      //所以用break直接跳出循环【不需要交换】
            }
            
        }
        a[i] = temp;
    }
}

void bianli(int * a, int val)
{
    for (int i = 0; i < val; i++)
    {
        printf("%d  ", a[i]); 
    }
    puts(" ");
}














