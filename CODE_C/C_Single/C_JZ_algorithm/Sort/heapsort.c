/**
 * @file heapsort.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 10
#define leftchild(i) (2*(i)+1)// 取到左孩子
void heapsort(int*, int);
void heapsort2(int*, int);
void bianli(int*, int);
void percdown(int* , int i, int n);
void swap(int *, int *);
void heapify(int * arr ,int n, int i);
int main()
{
    int arr[SIZE] = {3, 4, 1, 6, 7, 5, 2, 9, 8, 10};
    
    bianli(arr, SIZE);
    heapsort(arr, SIZE);
    bianli(arr, SIZE);
   
    int brr[9] = {22,-22,3,32,56,3345,35,-657,33};
    heapsort2(brr, 9);
    bianli(brr, 9);
    system("pause");
    return 0;
}
void bianli(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    puts(" ");
}
void heapsort(int* a, int n){
    int i;
    //建堆
    for ( i = n/2; i >= 0; i--)//每传一个，下沉维护一次 //为什么n/2，因为前半段有根和有孩子的节点，后半段有些可能都没有孩子节点
    {
        percdown(a, i , n);
       
    }
    puts("变成大根堆后：");
    bianli(a, SIZE);
    //排序
    for ( i = n - 1; i > 0 ; i--)//每删除一个max，下沉维护一次 且数组大小一直减少
    {
        swap(&a[0], &a[i]);//大根堆的首元素为max值，每次将max和最后一个元素互换位置
        percdown(a, 0, i);//并重新在下沉函数中维护剩余的 例：9 8 6， 9到后面和8换位置数组大小减1， 即6 8 9
                          //   在 6 8 中 percdown为8 6，再把8和6位置一换，此时 6 8 |9【9不在减1后的数组中】，即最终为6 8 9完成排序       
    }
    
    
}
/**
 * @brief 这些数的含义
 * 
 * @param A 存储堆的数组
 * @param i 待维护节点下标
 * @param n 数组长度
 */
void percdown(int * A, int i, int n){//维护 //相当于用下沉函数来维护 使他一直保持二叉堆性质 新进来的会下沉到适合它的位置上去
    int child, temp;
    for (temp = A[i]; leftchild(i) < n; i = child)
    {
        child = leftchild(i);
        if (child != n - 1 && A[child] < A[child + 1])//取数组值大的那个
        {
            child++;
        }
        if (temp < A[child])
        {
            A[i] = A[child];
        }
        else
        {
            break;
        }
    }
    A[i] = temp;
}
void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}






















void heapsort2(int* a, int n){
    int i;
    //建堆
    for ( i = n / 2 ; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    //排序
    for ( i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);//维护剩余i个元素  维护的堆顶所以是0
    }
    
}



/**
 * @brief 
 * 
 * @param arr 存储堆的数组
 * @param i 待维护节点下标
 * @param n 数组长度
 */
void heapify(int * arr ,int n, int i){
    int largest = i;
    int lson = i * 2 + 1;//取i节点的左孩子
    int rson = i * 2 + 2; //取i节点的右孩子
    if (lson < n && arr[lson] > arr[largest])//左孩子大于它爹
    {
        largest = lson;
    }
    if (rson < n && arr[rson] > arr[largest])//右孩子大于它爹
    {
        largest = rson;
    }
    if (largest != i)//即说明i节点有比他大的节点        例如：   3     角标分别为 a[0] = 3, a[1] = 6, a[2] = 2
    {                //                                      /  \.
        swap(&arr[largest], &arr[i]);///                    6    2
        heapify(arr, n, largest);//递归的全部维护          则largest 一开始等于i = 0,if中largest = 1 所以 在下面的if中largest != i了
    }                            //                       所以交换了角标为0 和 1的两个，交换后再 递归的维护
}