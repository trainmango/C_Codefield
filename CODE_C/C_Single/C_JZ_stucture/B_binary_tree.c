/**
 * @file B_binary_tree.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-04-14
 *
 * @copyRight CopyRight (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
struct B_binary_tree
{
    struct B_binary_tree *Left;
    struct B_binary_tree *Right;
    int data;
};
struct B_binary_tree *findMin_digui(struct B_binary_tree *T);

struct B_binary_tree *findMax_digui(struct B_binary_tree *T);

struct B_binary_tree *find_digui(struct B_binary_tree *T, int element);

struct B_binary_tree *MakeEmpty_digui(struct B_binary_tree *T); // 把树置空

struct B_binary_tree *Delete_digui(struct B_binary_tree *T, int element);
struct B_binary_tree *deleteNode(struct B_binary_tree *T, int data);

struct B_binary_tree *Insert_digui(struct B_binary_tree *T, int element);
void printTree(struct B_binary_tree *root, int space);
void bianli(struct B_binary_tree *T); // 中序遍历
// 递归方式置空二叉树

int main()
{
    struct B_binary_tree *T; // 声明一个根节点
    T = Insert_digui(NULL, 6);
    T = Insert_digui(T, 4);
    T = Insert_digui(T, 3);
    T = Insert_digui(T, 2);
    T = Insert_digui(T, 1);
    T = Insert_digui(T, 8);

    bianli(T);
    printTree(T, 3);
    puts(" ");
    puts("请输入要找的元素的值：");
    int vc;
    scanf("%d", &vc);
    struct B_binary_tree *node1 = find_digui(T, vc);
    if (node1 == NULL)
    {
        puts("未找到！");
    }
    else
    {
        printf("要找的元素data为：%d\n", node1->data);
    }

    struct B_binary_tree *node2 = findMax_digui(T);
    struct B_binary_tree *node3 = findMin_digui(T);
    printf("最大值为：%d  最小值为：%d\n", node2->data, node3->data);

    Delete_digui(T, 3);
    puts(" ");
    Delete_digui(T, 1);
    puts(" ");
    Delete_digui(T, 2);
    puts(" ");
    Delete_digui(T, 6);
    bianli(T);

    system("pause");
    return 0;
}

struct B_binary_tree *MakeEmpty_digui(struct B_binary_tree *T)
{
    // 以递归的方式实现置空，一路找到底，free 再一路往上返 free 层层free掉 此方法好理解，好写
    if (T != NULL)
    {
        MakeEmpty_digui(T->Left);
        MakeEmpty_digui(T->Right);
        free(T);
    }
    return NULL;
}

struct B_binary_tree *Insert_digui(struct B_binary_tree *T, int element)
{
    if (T == NULL)
    {
        T = (struct B_binary_tree *)malloc(sizeof(struct B_binary_tree)); // 创建第一个节点(即根节点)
        if (T == NULL)
        {
            puts("没有空间了！");
            return NULL;
        }
        else
        {
            T->data = element;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if (element < T->data)
    {
        T->Left = Insert_digui(T->Left, element); // 递归插入  //为什么上边要定义t==null情况，因为要递归插入，例如：第一次插入3再插入2插左边
    } // 所以T->Left【3的左边】 = Insert_digui(T->Left, element);
    else if (element > T->data) // 把3的左边的地址传过来【递归】，3的左边此时为null所以在新的Insert_digui函数中t==null重新创建了一个节点
    {                           // 注：插入3时的T和递归中插入2时的T不是一个T
        T->Right = Insert_digui(T->Right, element);
    }

    return T;
}

void bianli(struct B_binary_tree *T) // 中序遍历， 左中右
{
    if (T == NULL)
    {
        puts("这是一颗空树！");
        return;
    }

    if (T->Left != NULL) // 打印左子树
    {
        bianli(T->Left);
    }

    printf("%d  ", T->data); // 打印根节点

    if (T->Right != NULL)
    {
        bianli(T->Right);
    }
}

struct B_binary_tree *find_digui(struct B_binary_tree *T, int element) // 返回要找的节点的地址
{
    if (T == NULL)
    {
        return NULL;
    }
    if (element < T->data)
    {
        return find_digui(T->Left, element);
    }
    else if (element > T->data)
    {
        return find_digui(T->Right, element);
    }
    else
    {
        return T; // 既不大于，也不小于，即等于 直接返回即可
    }
}

struct B_binary_tree *findMin_digui(struct B_binary_tree *T)
{

    if (T == NULL)
    {
        puts("出错了！树没找到");
        return NULL;
    }
    else if (T->Left == NULL)
    {
        return T;
    }
    else
    {
        return findMin_digui(T->Left);
    }
}

struct B_binary_tree *findMax_digui(struct B_binary_tree *T)
{
    if (T == NULL)
    {
        puts("出错了！");
        return NULL;
    }
    else if (T->Right == NULL)
    {
        return T;
    }
    else
    {
        return findMin_digui(T->Right);
    }
}
/**
 * 非递归的写法：
 * struct B_binary_tree *findMax_digui(struct B_binary_tree *T)
 * {
 *    if(T != NULL)
 *    {
 *      while(T->Right != NULL)
 *      {
 *           T = T->Right;
 *      }
 *
 *    }
 *      retunrn T;
 * }
 *
 *
 */
// Note:
// 由于二叉查找树的性质，如果将当前节点替换为左子树中最大的或者右子树中最小的一定不会破坏二叉查找树的结构。

// 递归中每次调用的这个函数中的T不是一个，按书中的例子，第一次T指的是6，第二次指的是2
struct B_binary_tree *Delete_digui(struct B_binary_tree *T, int element) // 右最小 去替换它  （右子树最小去替换，可以保证比左边大，比右边的小）
{
    struct B_binary_tree *Temp; // 定义一个临时变量
    if (T == NULL)
    {
        puts("出错了！这是一颗空树！");
    }
    else if (element < T->data)
    {
        T->Left = Delete_digui(T->Left, element); // 第一次刚进递归时 T->Left即 6的左子树的第一个元素 2 的地址 ，即delete把这个子树当新树递归调用
    }
    else if (element > T->data)
    {
        T->Right = Delete_digui(T->Right, element);
    }
    else if (T->Left != NULL && T->Right != NULL) // 即当T->Left 和 T->Right 都不为NULL //判断是否有两个孩子
    {
        Temp = findMin_digui(T->Right); // 找右子树的min  临时指针接收min的地址        T->data = Temp->data;//把min的值赋给要删的节点
        T->data = Temp->data;
        T->Right = Delete_digui(T->Right, T->data);
        /***
         *      Temp = findMax_digui(T->Left);          也可以这样找左最大
                T->data = Temp->data;
                T->Left = Delete_digui(T->Left, T->data);
         *
         *
        */
    }
    else // 当只有一个孩子的时候，不需要考虑左右了【 即选择 左最大 还是 右最小 】，直接删掉这个节点，并把后边的 挂载到删除节点的父节点上
    {
        Temp = T;
        if (T->Left == NULL)
        {
            T = T->Right;
        }
        else if (T->Right == NULL)
        {
            T = T->Left;
        }
        free(Temp);
    }
    return T;
}

// 删除节点
struct B_binary_tree *deleteNode(struct B_binary_tree *T, int data)
{
    if (T == NULL)
    {
        return T;
    }
    else if (data < T->data)
    {
        T->Left = deleteNode(T->Left, data);
    }
    else if (data > T->data)
    {
        T->Right = deleteNode(T->Right, data);
    }
    else
    {
        // 找到要删除的节点
        if (T->Left == NULL && T->Right == NULL)
        {
            // 没有子节点的情况
            free(T);
            T = NULL;
        }
        // 当只有一个孩子的时候，不需要考虑左右了【 即选择 左最大 还是 右最小 】，直接删掉这个节点，并把后边的 挂载到删除节点的父节点上
        else if (T->Left == NULL)
        {
            // 只有一个右子节点的情况
            struct B_binary_tree *temp = T;
            T = T->Right;
            free(temp);
        }
        // 当只有一个孩子的时候，不需要考虑左右了【 即选择 左最大 还是 右最小 】，直接删掉这个节点，并把后边的 挂载到删除节点的父节点上
        else if (T->Right == NULL)
        {
            // 只有一个左子节点的情况
            struct B_binary_tree *temp = T;
            T = T->Left;
            free(temp);
        }
        else
        {
            // 有两个子节点的情况 
            struct B_binary_tree *temp = findMin_digui(T->Right);
            T->data = temp->data;
            T->Right = deleteNode(T->Right, T->data);
        }
    }
    return T;
}

void printTree(struct B_binary_tree *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 5;
    printTree(root->Right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->Left, space);
}