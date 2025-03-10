/**
 * @file relized_tree_by_me.c
 * @author your name (you@domain.com)
 * @brief 自己实现binary tree
 * @version 0.1
 * @date 2024-05-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
struct relized_tree_by_me
{
    struct relized_tree_by_me *Left;
    struct relized_tree_by_me *Right;
    int data;
};
// 注：要是不用递归实现，得使用栈
struct relized_tree_by_me *Insert_digui_binary_tree(struct relized_tree_by_me *, int);
struct relized_tree_by_me *Insert_feidigui_binary_tree(struct relized_tree_by_me *, int);

void bianli_digui(struct relized_tree_by_me *);
void bianli_feidigui(struct relized_tree_by_me *); // 得用到栈
struct relized_tree_by_me *Delete_digui(struct relized_tree_by_me *, int);
struct relized_tree_by_me *Delete_feidigui(struct relized_tree_by_me *);

struct relized_tree_by_me *Find_digui(struct relized_tree_by_me *, int);
struct relized_tree_by_me *Find_feidigui1(struct relized_tree_by_me *, int);
struct relized_tree_by_me *Find_feidigui2(struct relized_tree_by_me *, int);
int BSTreeNodeFindNor(struct relized_tree_by_me *, int); // 查找（非递归）

struct relized_tree_by_me *FindMax_digui(struct relized_tree_by_me *);
struct relized_tree_by_me *FindMax_feidigui(struct relized_tree_by_me *);

struct relized_tree_by_me *FindMin_digui(struct relized_tree_by_me *);
struct relized_tree_by_me *FindMin_feidigui(struct relized_tree_by_me *);

int Hight(struct relized_tree_by_me *);
int high(struct relized_tree_by_me *T);

void printTree(struct relized_tree_by_me* root, int space);

int main()
{
    struct relized_tree_by_me *root = NULL;//普通二叉树因为不用旋转啥的而即使没把值更新到根节点也没事，因为根不会变了！
    root = Insert_digui_binary_tree(root, 6);
    root = Insert_digui_binary_tree(root, 4);//而avl树若没把值更新到根节点上则会丢失【因为旋转了】
    root = Insert_digui_binary_tree(root, 7);//因为这个bug折磨了许久，最好更新按左边方式写
    root = Insert_digui_binary_tree(root, 5);
    root = Insert_digui_binary_tree(root, 3);
    root = Insert_digui_binary_tree(root, 8);
    root = Insert_digui_binary_tree(root, 2);
    root = Insert_digui_binary_tree(root, 1);
    root = Insert_digui_binary_tree(root, 9);
    root = Insert_digui_binary_tree(root, 10);
    
   
    bianli_digui(root);
    puts(" ");
    printTree(root, 0);
    puts(" ");

    struct relized_tree_by_me *node1 = FindMin_digui(root);
    struct relized_tree_by_me *node2 = FindMin_feidigui(root);
    struct relized_tree_by_me *node3 = FindMax_feidigui(root);
    struct relized_tree_by_me *node4 = FindMax_feidigui(root);

    printf("用递归的方式查找到最小值为：%d\n", node1->data);
    printf("用非递归的方式查找到的最小值为：%d\n", node2->data);

    printf("用递归的方式查找到最大值为：%d\n", node3->data);
    printf("用非递归的方式查找到最大值为：%d\n", node4->data);

    int number1;
    puts("请输入要查找的数字：");
    scanf("%d", &number1);

    if (Find_digui(root, number1))
    {
        printf("成功找到数字%d\n", number1);
    }
    else
    {
        printf("未找到数字%d\n", number1);
    }

    int number2;
    puts("请输入要查找的数字：");
    scanf("%d", &number2);
    if (BSTreeNodeFindNor(root, number2))
    {
        printf("成功找到数字%d\n", number2);
    }
    else
    {
        printf("未找到数字%d\n", number2);
    }

    int number3;
    puts("请输入要查找的数字：");
    scanf("%d", &number3);
    if (Find_feidigui1(root, number3))
    {
        printf("成功找到数字%d\n", number3);
    }
    else
    {
        printf("未找到数字%d\n", number3);
    }

    int number4;
    puts("请输入要查找的数字：");
    scanf("%d", &number4);
    if (Find_feidigui2(root, number4))
    {
        printf("成功找到数字%d\n", number4);
    }
    else
    {
        printf("未找到数字%d\n", number4);
    }

    Delete_digui(root, 5);
    bianli_digui(root);
    puts(" ");
    printf("树的高度为%d\n", Hight(root));
    printf("树的高度为%d\n", high(root));
    
    printTree(root, 10);
    system("pause");
    return 0;
}

struct relized_tree_by_me *Insert_digui_binary_tree(struct relized_tree_by_me *T, int element)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct relized_tree_by_me));
        if (T == NULL)
        {
            puts("error");
            return NULL;
        }
        else
        {
            T->data = element;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if (element > T->data)
    {
        T->Right = Insert_digui_binary_tree(T->Right, element);
    }
    else if (element < T->data)
    {
        T->Left = Insert_digui_binary_tree(T->Left, element);
    }
    return T; // 递归的推出条件（必须要有）
}

void bianli_digui(struct relized_tree_by_me *T)
{
    if (T == NULL)
    {
        puts("这是一颗空树");
        return;
    }
    if (T->Left != NULL)
    {
        bianli_digui(T->Left);
    }
    printf("%d ", T->data);
    if (T->Right != NULL)
    {
        bianli_digui(T->Right);
    }
}

struct relized_tree_by_me *FindMin_digui(struct relized_tree_by_me *T)
{
    if (T == NULL)
    {
        return NULL;
    }
    else if (T->Left != NULL)
    {
        return FindMin_digui(T->Left);
    }
    else
    {
        return T;
    }
}
struct relized_tree_by_me *FindMin_feidigui(struct relized_tree_by_me *T)
{

    if (T != NULL)
    {
        while (T->Left != NULL)
        {
            T = T->Left;
        }
    }
    return T;
}
struct relized_tree_by_me *FindMax_digui(struct relized_tree_by_me *T)
{
    if (T == NULL)
    {
        return NULL;
    }
    else if (T->Right != NULL)
    {
        return FindMax_digui(T->Right);
    }
    else
    {
        return T;
    }
}
struct relized_tree_by_me *FindMax_feidigui(struct relized_tree_by_me *T)
{
    if (T != NULL)
    {
        while (T->Right != NULL)
        {
            T = T->Right;
        }
    }
    return T;
}
struct relized_tree_by_me *Find_digui(struct relized_tree_by_me *T, int element)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (element < T->data)
    {
        return Find_digui(T->Left, element);
    }
    else if (element > T->data)
    {
        return Find_digui(T->Right, element);
    }
    else
    {
        return T;
    }
}
struct relized_tree_by_me *Find_feidigui1(struct relized_tree_by_me *T, int element)
{
    if (T == NULL)
    {
        puts("空树");
        return NULL;
    }
    while (T != NULL)
    {
        if (T->data == element)
        {
            return T;
        }
        else if (element < T->data)
        {
            T = T->Left;
        }
        else if (element > T->data)
        {
            T = T->Right;
        }
    }
    return NULL;
}

struct relized_tree_by_me *Find_feidigui2(struct relized_tree_by_me *T, int element)
{
    while (T != NULL && T->data != element)
    {
        if (element < T->data)
        {
            T = T->Left;
        }
        else
        {
            T = T->Right;
        }
    }
    return T;
}

int BSTreeNodeFindNor(struct relized_tree_by_me *T, int element) // 查找（非递归）
{
    if (NULL == T)
    {
        printf("树为空\n");
    }
    while (T)
    {
        if (T->data == element)
        {
            return 1;
        }
        else if (T->data > element)
        {
            T = T->Left;
        }
        else if (T->data < element)
        {
            T = T->Right;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

struct relized_tree_by_me *Delete_digui(struct relized_tree_by_me *T, int element)
{  // 当只有一个孩子的时候，不需要考虑左右了【 即选择 左最大 还是 右最小 】，直接删掉这个节点，并把后边的 挂载到删除节点的父节点上
    struct relized_tree_by_me *temp;
    if (T == NULL)
    {
        puts("empty tree, error");
    }
    else if (element > T->data)
    {
        T->Right = Delete_digui(T->Right, element);
    }
    else if (element < T->data)
    {
        T->Left = Delete_digui(T->Left, element);
    }
    else if (T->Right && T->Left) // 有两个节点
    {
        // 找左子树中最大的或者右子树中最小的  //此处我写的找左最大
        temp = FindMax_feidigui(T->Left);
        T->data = temp->data;
        T->Left = Delete_digui(T->Left, T->data); // 找到最大后移上去，然后把它原来位置删除
    }
    else if (T->Left == NULL) // 只有右节点
    {
        temp = T;
        T = T->Right;
        free(temp);
    }
    else if (T->Right == NULL) // 只有左节点
    {
        temp = T;
        T = T->Left;
        free(temp);
    }

    else // 一个节点都没有
    {
        temp = T;
        free(temp);
    }

    return T;

    /**
     * @brief 也可以把判断只有左节点，只有右节点，没有一个节点的写一起
     *
     *
     * else
    {
        temp = T;
        if (T->Left == NULL)
        {
            T = T->Right;
            free(temp);
        }
        else if (T->Right == NULL)
        {
            T = T->Left;
            free(temp);
        }


    }
     *
     */
}

int Hight(struct relized_tree_by_me *T)
{
    if (T == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(Hight(T->Left), Hight(T->Right));
    }
}

int high(struct relized_tree_by_me *T)
{
    int h1, h2;
    if (T)
    {
        h1 = high(T->Left);
        h2 = high(T->Right);
        return h1 > h2 ? h1 + 1 : h2 + 1;
    }
    else
        return -1;
}

void printTree(struct relized_tree_by_me* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->Right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->Left, space);
}
