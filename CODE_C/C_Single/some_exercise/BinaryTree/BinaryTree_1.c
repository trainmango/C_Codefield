/**
 * @file BinaryTree_1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-07-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
} BinaryTree;

int high(BinaryTree *T)
{
    int h1, h2;
    if (T)
    {
        h1 = high(T->left);
        h2 = high(T->right);
        return h1 > h2 ? h1 + 1 : h2 + 1;
    }
    else
        return -1;
}

void insert(BinaryTree **root, int val);
BinaryTree *find_min_recursion(BinaryTree *root); // 递归（recursion）
BinaryTree *find_min(BinaryTree *root);
BinaryTree *find_max_recursion(BinaryTree *root);
BinaryTree *find_max(BinaryTree *root);

BinaryTree *deleteNode_find_right_min(BinaryTree *root, int val);
BinaryTree *deleteNode_find_left_max(BinaryTree *root, int val);
void deleteNode_find_left_max_Two_pointer(BinaryTree **root, int val);
void deleteNode_find_right_min_Two_pointer(BinaryTree **root, int val);
void insert_lots(BinaryTree **root); // 封装，一次插入多个
void preorder_traversal(BinaryTree *root);
void inorder_traversal(BinaryTree *root);
void postorder_traversal(BinaryTree *root);
void printTree(BinaryTree *root, int space);
void MakeEmpty(BinaryTree **root);
int main()
{
    BinaryTree *root = NULL;
    insert_lots(&root);
    // insert(&root, 9);
    // insert(&root, 4);
    // insert(&root, 15);
    // insert(&root, 6);
    // insert(&root, 12);
    // insert(&root, 16);
    // insert(&root, 2);
    // insert(&root, 1);
    // insert(&root, 3);
    // insert(&root, 5);
    // insert(&root, 7);
    // insert(&root, 44);
    printf("树高为：%d", high(root));
    printf("前序遍历的结果为：");
    preorder_traversal(root);
    puts(" ");

    printf("中序遍历的结果为：");
    inorder_traversal(root);
    puts(" ");

    printf("后序遍历的结果为：");
    postorder_traversal(root);
    puts(" ");

    printf("树状形象的显示为：");
    printTree(root, 4);
    puts(" ");

    printf("以递归的方式找到min：");
    printf("%d  \n", find_min_recursion(root)->data);

    printf("以非递归的方式找到min：");
    printf("%d  \n", find_min(root)->data);

    printf("以递归的方式找到max：");
    printf("%d  \n", find_max_recursion(root)->data);

    printf("以非递归的方式找到max：");
    printf("%d  \n", find_max(root)->data);

    deleteNode_find_left_max_Two_pointer(&root, 4);
    printTree(root, 4);

    puts("+++++++++++++++++++++++++++++++++++++++++++++++++ ");

    deleteNode_find_right_min_Two_pointer(&root, 15);
    printTree(root, 4);

    MakeEmpty(&root);
    inorder_traversal(root);
    return 0;
}

void insert(BinaryTree **root, int val) // 因为用了二级指针了，所以不用return T这种了
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(BinaryTree));
        if (*root == NULL)
        {
            printf("error, out of space!");
            return;
        }

        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = val;
    }

    if (val > (*root)->data) // 右边插入
    {
        insert(&(*root)->right, val);
    }
    else if (val < (*root)->data) // 左边插入
    {
        insert(&(*root)->left, val); // 等价于 &((*tree)->left)，创建左子树
        /*
        在C语言中，表达式 &(*tree)->left 的等价表达可以这样理解：
         (*tree) 先解引用指针 tree，得到指向的结构体对象。
         (*tree)->left 表示访问解引用后的结构体对象的 left 成员。
         &(*tree)->left 表示取 left 成员的地址。

         所以，&(*tree)->left 的等价表达是：先解引用 tree 指针，访问结构体对象的 left 成员，然后取这个成员的地址。
         */
        /*
       在C语言中，表达式 &((*tree)->left) 也可以被理解为以下步骤：
       (*tree) 先解引用指针 tree，得到指向的结构体对象。
       (*tree)->left 表示访问解引用后的结构体对象的 left 成员。
       &((*tree)->left) 表示取 left 成员的地址。

       实际上，这个表达式与 &(*tree)->left 完全等价，它们只是加了额外的括号，但这些括号并不会改变表达式的含义或结果。
       因此，&((*tree)->left) 和 &(*tree)->left 都是等价的表达方式。两者都表示取 tree 指向的结构体对象的 left 成员的地址。
        */
    }
}

void preorder_traversal(BinaryTree *root)
{
    if (root)
    {
        printf("%d  ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(BinaryTree *root)
{
    if (root)
    {
        inorder_traversal(root->left);
        printf("%d  ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(BinaryTree *root)
{
    if (root)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d  ", root->data);
    }
}

void printTree(BinaryTree *root, int space)
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

BinaryTree *find_min_recursion(BinaryTree *root)
{
    if (root == NULL)
    {
        printf("error,its empty tree");
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return find_min_recursion(root->left);
    }
}

BinaryTree *find_min(BinaryTree *root)
{
    if (root == NULL)
    {
        printf("error,its empty tree");
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

BinaryTree *find_min_hisfather(BinaryTree *root)
{
    if (root == NULL)
    {
        printf("error,its empty tree");
        return NULL;
    }
    BinaryTree *temp;
    while (root->left != NULL)
    {
        temp = root;
        root = root->left;
    }
    return temp;
}

BinaryTree *find_max_recursion(BinaryTree *root)
{
    if (root == NULL)
    {
        printf("error,its empty tree");
        return NULL;
    }
    else if (root->right == NULL)
    {
        return root;
    }
    else
    {
        return find_max_recursion(root->right);
    }
}

BinaryTree *find_max(BinaryTree *root)
{
    if (root == NULL)
    {
        printf("error,its empty tree");
        return NULL;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

BinaryTree *deleteNode_find_right_min(BinaryTree *root, int val) // 找右边最小的
{
    if (root == NULL)
    {
        return root;
    }
    if (val > root->data)
    {
        root->right = deleteNode_find_right_min(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = deleteNode_find_right_min(root->left, val);
    }
    else if (root->left && root->right) // 两个孩子
    {
        BinaryTree *temp = find_min(root->right);
        root->data = temp->data;
        root->right = deleteNode_find_right_min(root->right, root->data);
        /***
      *      Temp = findMax_digui(T->Left);          也可以这样找左最大
             T->data = Temp->data;
             T->Left = Delete_digui(T->Left, T->data);
      *
      *
     */
    } // 当只有一个孩子的时候，不需要考虑左右了【 即选择 左最大 还是 右最小 】，直接删掉这个节点，并把后边的 挂载到删除节点的父节点上
    else if (root->left && root->right == NULL) // 只有一个左孩子
    {
        BinaryTree *temp = root;
        root = root->left;
        free(temp);
    }
    else if (root->left == NULL && root->right) // 只有一个右孩子
    {
        BinaryTree *temp = root; // 即 让temp先指向root这块，然后将root指向的位置改为指向root->right，再 free(temp); 即free了root原先的位置
        root = root->right;
        free(temp);
    }
    else if (root->left == NULL && root->right == NULL) // 没有一个孩子
    {
        free(root);
        root = NULL;
    }
    return root;
}

BinaryTree *deleteNode_find_left_max(BinaryTree *root, int val) // 找左最大
{
    if (root == NULL)
    {
        return root;
    }
    if (val > root->data)
    {
        root->right = deleteNode_find_left_max(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = deleteNode_find_left_max(root->left, val);
    }
    else if (root->left && root->right) // 两个孩子
    {
        BinaryTree *temp = find_max(root->left);
        root->data = temp->data;
        root->left = deleteNode_find_left_max(root->left, root->data);
    }
    else if (root->left && root->right == NULL) // 只有一个左孩子
    {
        BinaryTree *temp = root;
        root = root->left;
        free(temp);
    }
    else if (root->left == NULL && root->right) // 只有一个右孩子
    {
        BinaryTree *temp = root; // 即 让temp先指向root这块，然后将root指向的位置改为指向root->right，再 free(temp); 即free了root原先的位置
        root = root->right;
        free(temp);
    }
    else if (root->left == NULL && root->right == NULL) // 没有一个孩子
    {
        free(root);
        root = NULL;
    }
    return root;
}

void deleteNode_find_left_max_Two_pointer(BinaryTree **root, int val)
{
    if ((*root) == NULL)
    {
        return;
    }
    if (val > (*root)->data)
    {
        deleteNode_find_left_max_Two_pointer(&(*root)->right, val);
    }
    else if (val < (*root)->data)
    {
        deleteNode_find_left_max_Two_pointer(&(*root)->left, val);
    }
    else if ((*root)->left && (*root)->right) // 有两个孩子
    {
        BinaryTree *temp = find_max((*root)->left);
        (*root)->data = temp->data;
        deleteNode_find_left_max_Two_pointer(&(*root)->left, (*root)->data);
    }
    else if ((*root)->left && (*root)->right == NULL) // 只有一个左孩子
    {
        BinaryTree *temp = (*root);
        (*root) = (*root)->left;
        free(temp);
    }
    else if ((*root)->right && (*root)->left == NULL) // 只有一个右孩子
    {
        BinaryTree *temp = (*root);
        (*root) = (*root)->right;
        free(temp);
    }
    else if ((*root)->left == NULL && (*root)->right == NULL) // 没有一个孩子
    {
        free(*root);
        (*root) = NULL;
    }
}

void deleteNode_find_right_min_Two_pointer(BinaryTree **root, int val)
{
    if ((*root) == NULL)
    {
        return;
    }
    if (val > (*root)->data)
    {
        deleteNode_find_right_min_Two_pointer(&(*root)->right, val);
    }
    else if (val < (*root)->data)
    {
        deleteNode_find_right_min_Two_pointer(&(*root)->left, val);
    }
    else if ((*root)->left && (*root)->right) // 有两个孩子
    {
        BinaryTree *temp = find_min((*root)->right);
        (*root)->data = temp->data;
        deleteNode_find_right_min_Two_pointer(&(*root)->right, (*root)->data);
    }
    else if ((*root)->left && (*root)->right == NULL) // 只有一个左孩子
    {
        BinaryTree *temp = (*root);
        (*root) = (*root)->left;
        free(temp);
    }
    else if ((*root)->right && (*root)->left == NULL) // 只有一个右孩子
    {
        BinaryTree *temp = (*root);
        (*root) = (*root)->right;
        free(temp);
    }
    else if ((*root)->left == NULL && (*root)->right == NULL) // 没有一个孩子
    {
        free(*root);
        (*root) = NULL;
    }
}

void MakeEmpty(BinaryTree **root)
{
    if ((*root) == NULL)
    {
        return;
    }
    MakeEmpty(&(*root)->left);
    MakeEmpty(&(*root)->right);
    free(*root);
    *root = NULL;
}

void insert_lots(BinaryTree **root)
{
    int nums, val;
    printf("请输入插入个数：");
    scanf("%d", &nums);
    for (int i = 0; i < nums; i++)
    {
        printf("第%d个节点：", i + 1);
        scanf("%d", &val);
        insert(root, val);
    }
}