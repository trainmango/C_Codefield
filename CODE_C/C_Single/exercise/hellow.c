#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int count = 0;
typedef struct Node
{
    char data;
    struct Node * LChild;
    struct Node * RChild;
}BiTNode,*BiTree;

//创建一个二叉树链表的二叉树
void CreateBiTree(BiTree *root)
{
    char ch;
    ch = getchar();
    if(ch == '#')
        *root = NULL;
    else
    {
        *root = (BiTree)malloc(sizeof(BiTNode));
        (*root)->data = ch;
        CreateBiTree(&((*root)->LChild));
        CreateBiTree(&((*root)->RChild));
    }
}

//先序遍历二叉树
void xianxu(BiTree root)
{
    if(root != NULL)
    {
        printf("%c",root->data);
        xianxu(root->LChild);
        xianxu(root->RChild);
    }
}

//中序遍历二叉树
void zhongxu(BiTree root)
{
    if(root != NULL)
    {
        zhongxu(root->LChild);
        printf("%c",root->data);
        zhongxu(root->RChild);
    }
}
//后序遍历二叉树
void houxu(BiTree root)
{
    if(root != NULL)
    {
        houxu(root->LChild);
        houxu(root->RChild);
        printf("%c",root->data);
    }
}

//用后序遍历输出叶子的片数
void leaf(BiTree root)
{

    if(root != NULL)
    {
        leaf(root->LChild);
        leaf(root->RChild);
        if(root->LChild == NULL&&root->RChild==NULL)
            count++;

    }
}

//求二叉树的高度
int gaodu(BiTree root)
{
    int hr;
    int hl;
    int max;
    if(root != NULL)
    {
        hl = gaodu(root->LChild);
        hr = gaodu(root->RChild);
        max = hl>hr?hl:hr;
        return (max+1);
    }
    return 0;
}
int main()
{
    BiTree T;
    CreateBiTree(&T);
    leaf(T);
    printf("先序遍历：");xianxu(T);
    printf("\n");
    printf("中序遍历：");zhongxu(T);
    printf("\n");
    printf("后序遍历：");houxu(T);
    printf("\n");
    printf("该二叉树的叶子节点个数为：%d",count);
    printf("\n");
    printf("该二叉树的节点总数为：%d",gaodu(T));
    system("pause");
    return 0;
}

