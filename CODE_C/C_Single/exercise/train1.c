#include <stdio.h>
#include<stdlib.h>
int count = 0;
//二叉树结构体
typedef struct BiTNode
{
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
//先序序列建立二叉树 
int BuildBiTree(BiTree *T)
{
    char ch;
    scanf("%c", &ch); //注意：如果用的是devc++，此处scanf_s要改为scanf
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        BuildBiTree(&(*T)->lchild);
        BuildBiTree(&(*T)->rchild);
    }
    return 1;
}

//统计二叉树的叶子结点个数
int LeafNumber(BiTree *T)
{
  
    if((*T)!=NULL)
	{
	        if((*T)->lchild==NULL&&(*T)->rchild==NULL)
	            count++;
	        count=LeafNumber(&(*T)->lchild);
	        count=LeafNumber(&(*T)->rchild);
	}
	return count;
    
    
}
//主函数
int main()
{
	BiTree T;
	if( BuildBiTree(&T) )
	{
		printf("%d", LeafNumber(&T));
	}
	printf("\n");
    system("pause");
	return 0;
}
