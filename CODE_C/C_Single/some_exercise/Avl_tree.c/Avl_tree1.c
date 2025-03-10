/**
 * @file Avl_tree1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-07-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Avl_tree1
{
    int data;
    int height;
    struct Avl_tree1 *left;
    struct Avl_tree1 *right;
} Avl_tree1;

void printTree(Avl_tree1 *root, int space);
void insert(Avl_tree1 **root, int val);
void Single_Left_Rotation(Avl_tree1 **root);
void Single_Right_Rotation(Avl_tree1 **root);
void Left_Right_Double_Rotation(Avl_tree1 **root);
void Right_Left_Double_Rotation(Avl_tree1 **root);
int Height(Avl_tree1 *root);        // 在每次的插入时，去改变高度
int currentHeight(Avl_tree1 *root); // 不知道高度的情况下，遍历整个树求高度
int Max(int a, int b);

int main()
{
    Avl_tree1 *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 8);

    printTree(root, 5);
    printf("树的高度为：%d\n", currentHeight(root));
    return 0;
}

void insert(Avl_tree1 **root, int val)
{
    if ((*root) == NULL)
    {
        (*root) = malloc(sizeof(Avl_tree1));
        if ((*root) == NULL)
        {
            printf("error,out of spapce");
            return;
        }
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->height = 0;
        (*root)->data = val;
    }
    else if (val > (*root)->data)
    {
        insert(&(*root)->right, val);
        if (Height((*root)->right) - Height((*root)->left) == 2)
        {
            if (val > (*root)->right->data) //  右边右儿子失衡 左旋
            {
                Single_Left_Rotation(root);
            }
            else //  右变左儿子失衡 右左双旋
            {
                Right_Left_Double_Rotation(root);
            }
        }
    }
    else if (val < (*root)->data)
    {
        insert(&(*root)->left, val);
        if (Height((*root)->left) - Height((*root)->right) == 2)
        {
            if (val < (*root)->left->data)
            {
                Single_Right_Rotation(root);
            }
            else
            {
                Left_Right_Double_Rotation(root);
            }
        }
    }
    (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1;
}

void Single_Left_Rotation(Avl_tree1 **root)
{
    Avl_tree1 *temp = (*root)->right;
    (*root)->right = temp->left; // 即 (*root)->right = (*root)->right->left;
    temp->left = (*root);
    // 旋转后重新测量高度
    (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1; // +1是因为求的是子树的高度，   +1后才是它的高度
    temp->height = Max(Height(temp->left), Height(temp->right)) + 1;
    *root = temp;
}
void Single_Right_Rotation(Avl_tree1 **root)
{
    Avl_tree1 *temp = (*root)->left;
    (*root)->left = temp->right;
    temp->right = (*root);
    (*root)->height = Max(Height((*root)->left), Height((*root)->right)) + 1;
    temp->height = Max(Height(temp->left), Height(temp->right)) + 1;
    *root = temp;
}
void Left_Right_Double_Rotation(Avl_tree1 **root)
{
    Single_Left_Rotation(&(*root)->left);
    Single_Right_Rotation(root);
}
void Right_Left_Double_Rotation(Avl_tree1 **root)
{
    Single_Right_Rotation(&(*root)->right);
    Single_Left_Rotation(root);
}

void printTree(Avl_tree1 *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int currentHeight(Avl_tree1 *root)
{
    if (root == NULL)
    {
        return -1; // 空树的高度为-1
    }
    // 计算左子树的高度
    int leftHeight = currentHeight(root->left);
    // 计算右子树的高度
    int rightHeight = currentHeight(root->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

int Height(Avl_tree1 *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return root->height;
    }
}