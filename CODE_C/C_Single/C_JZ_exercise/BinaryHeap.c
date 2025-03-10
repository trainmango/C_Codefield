/**
 * @file BinaryHeap.c
 * @author your name (you@domain.com)          
 * @brief 自行实现一编二叉堆          （完美实现）
 *        一颗高为h的完全二叉树有2的h次方个到2的h+1次方-1个节点
 *        使用数组实现二叉堆
 * @version 0.1
 * @date 2024-06-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#define Minelements 5
#define MinData -999
typedef struct BinaryHeap
{
    int capacity; // 容量
    int size;     // 每插入一个数组元素则+1 初始为0 即有效元素个数
    int *array;
} binaryheap;

void insert(binaryheap *, int);
int DeleteMin(binaryheap *);
binaryheap *initialize(int);
bool isFull(binaryheap *);
bool isEmpty(binaryheap *);
void bianli(binaryheap *);
void heap_sort_arr(binaryheap *);
binaryheap * arr_transfer(int *);
int main()
{

    binaryheap * H = initialize(10);
    insert(H, 13);
    insert(H, 14);
    insert(H, 16);
    insert(H, 24);
    insert(H, 21);
    insert(H, 19);
    insert(H, 68);
    insert(H, 65);
    insert(H, 17);
    insert(H, 99);
    insert(H, 677);
    bianli(H);
    DeleteMin(H);
    bianli(H);
    heap_sort_arr(H);
    puts(" ");
    int arr[10] = {3, 4, 1, 6, 7, 5, 2, 9, 8, 10};
    binaryheap * xx = arr_transfer(arr);
    bianli(xx);
    heap_sort_arr(xx);
    bianli(xx);
    system("pause");
    return 0;
}
binaryheap *initialize(int Maxelements) // 选择数组的大小
{
    if (Maxelements < Minelements)
    {
        puts("priority queue is too small");
        return NULL;
    }
    binaryheap *H = malloc(sizeof(binaryheap));
    if (H == NULL)
    {
        puts("out of space");
        return NULL;
    }
    H->array = malloc(sizeof(int) * (Maxelements + 1));
    if (H->array == NULL)
    {
        puts("out of space");
        return NULL;
    }
    H->capacity = Maxelements;
    H->size = 0;
    H->array[0] = MinData;

    return H;
}
void insert(binaryheap *H, int val) // 上浮
{
    int i;
    if (isFull(H))
    {
        puts("数组满了！");
        return;
    }
    /*
        对于数组任意位置i上的元素有：它的左儿子在位置2i上，它的右儿子在左儿子后的单元（2i+1）上。
        它的父亲在⌊i/2⌋【向下取整】上

    */  //                        此处的大于小于将决定是插入成大根堆还是小根堆
    for (i = ++H->size; H->array[i / 2] > val; i /= 2) // 每插入一个元素，H->size都加1;  H->array[i/2]是为了取它的父节点再进行比较
    {                                                  // 若父节点值大于val则交换两个节点的值即父节点下沉，要插入的上浮
        H->array[i] = H->array[i / 2];
    }
    H->array[i] = val;
}
bool isFull(binaryheap *H)
{
    if (H->capacity == H->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty(binaryheap *H)
{
    if (H->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int DeleteMin(binaryheap *H)//相当于删除了最小元后，还要维护二叉堆，再把它转化为一个二叉堆
{ // 下沉
    int i, child;
    int Min, Last;
    if (isEmpty(H))
    {
        puts("error,can't delete empty tree");
        return H->array[0];
    }
    Min = H->array[1];          // 一号位置存放的是完全二叉堆中的最小值
    Last = H->array[H->size--]; // 为什么--， 因为要删除一个，则size减小1

    for (i = 1; i * 2 <= H->size; i = child) // i*2即选到它的左孩子 每乘2则下沉一级
    {
        child = i * 2;                                                 // 选到左孩子
        if (child != H->size && H->array[child + 1] < H->array[child]) // 选取左右两孩子中最小的一个的角标
        {
            child++;
        }
        if (Last > H->array[child]) // 下沉
        {
            H->array[i] = H->array[child]; // 经过多轮往前赋值后，让最后一个元素找到它的位置 数组size 减了1
        }
        else
        {
            break;
        }
    }
    H->array[i] = Last;//注意：此i是经过for循环后的i了，把最后一个元素往前到适合它的位置上去

    return Min;
}
void bianli(binaryheap *H)
{
    for (int i = 1; i <= H->size; i++)
    {
        printf("%d  ", H->array[i]);
    }
    puts(" ");
}
void heap_sort_arr(binaryheap *H)//核心思想是接收deletemin中的元素并用一个新数组来接收它【不考虑空间】
{
    int arr[9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = DeleteMin(H);
    }
    for (int j = 0; j < 9; j++)
    {
        printf("%d  ", arr[j]);
    }
    
}
binaryheap* arr_transfer(int * a){//将数组放进堆中【即已经变为二叉堆】
    binaryheap * H = initialize(10);
    for (int i = 0; i < 10; i++)
    {
        insert(H, a[i]);
    }
    return H;
}