/**
 * @file E-linkedBinarytree.c
 * @author your name (you@domain.com)
 * @brief 最简单的静态创建
 * @version 0.1
 * @date 2024-07-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct E_linkedBinarytree
{
    int data;
    struct E_linkedBinarytree *left;
    struct E_linkedBinarytree *right;
} LBT;

LBT *simpleCreateBTREE();
void preorder_traversal(LBT *root);
void inorder_traversal(LBT *root);
void postorder_traversal(LBT *root);
void printTree(LBT *root, int space);
int main()
{
    LBT *pT = simpleCreateBTREE();
    preorder_traversal(pT);
    printf("\n");

    inorder_traversal(pT);
    printf("\n");

    postorder_traversal(pT);
    printf("\n");

    printTree(pT, 5);

    return 0;
}

LBT *simpleCreateBTREE()
{
    LBT *pa = malloc(sizeof(LBT));
    LBT *pb = malloc(sizeof(LBT));
    LBT *pc = malloc(sizeof(LBT));
    LBT *pd = malloc(sizeof(LBT));
    LBT *pe = malloc(sizeof(LBT));
    pa->data = 'A';
    pb->data = 'B';
    pc->data = 'C';
    pd->data = 'D';
    pe->data = 'E';
    pa->left = pb;
    pa->right = pc;
    pb->left = pb->right = NULL;
    pc->left = pd;
    pc->right = NULL;
    pd->left = NULL;
    pd->right = pe;
    pe->left = pe->right = NULL;
    return pa;
}

void preorder_traversal(LBT *root)
{
    if (root)
    {
        printf("%c  ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(LBT *root)
{
    if (root)
    {
        inorder_traversal(root->left);
        printf("%c  ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(LBT *root)
{
    if (root)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%c  ", root->data);
    }
}

void printTree(LBT *root, int space)
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
    printf("%c\n", root->data);
    printTree(root->left, space);
}