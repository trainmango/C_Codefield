/**
 * @file avl_tree_relizedby_me.c
 * @author your name (you@domain.com)
 * @brief  完美实现  delete将在6.10前完成
 * @version 0.1
 * @date 2024-05-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct avl_tree_relizedby_me
{
    struct avl_tree_relizedby_me *left;
    struct avl_tree_relizedby_me *right;
    int hight;
    int element;
} avl, *Pavl;
void printTree(Pavl root, int space); //按照树的样子打印
int Max(int, int);
int Hight(Pavl);
int high(Pavl);
int getHeight(Pavl);
Pavl Insert_digui(Pavl, int);
Pavl Single_right_rotation(Pavl);//右旋
Pavl Single_left_rotation(Pavl);//左旋
Pavl Left_Right_rotation(Pavl);//左右双旋转
Pavl Right_Left_rotation(Pavl);//右左双旋转
void bianli(Pavl);//中序遍历
int main()
{
    Pavl root = NULL;
    root = Insert_digui(root, 1);//普通二叉树因为不用旋转啥的而即使没把值更新到根节点也没事，因为根不会变了！
    root = Insert_digui(root, 2);//而avl树若没把值更新到根节点上则会丢失【因为旋转了】！！！！！！！！！！！
    root = Insert_digui(root, 3);//因为这个bug折磨了许久，最好更新按左边方式写
    root = Insert_digui(root, 4);
    root = Insert_digui(root, 5);
    root = Insert_digui(root, 6);
    root = Insert_digui(root, 7);
    root = Insert_digui(root, 8);
   
    bianli(root);
    printTree(root, 7);
    printf("高度为%d\n", getHeight(root));//注意，树被旋转了所以高度会小点
    printf("高度为%d\n", high(root));
    printf("高度为%d\n", Hight(root));
   
   
    return 0;
}
// 左边为最普通的递归插入，而avl树还需要堆高度进行判断,且再插入的同时进行旋转来保证符合avl树
Pavl Insert_digui(Pavl T, int val)
{
    if (T == NULL)
    {
        T = malloc(sizeof(avl));
        if (T == NULL)
        {
            puts("error,out of space");
            return NULL;
        }
        else
        {
            T->element = val;
            T->left = NULL;
            T->right = NULL;
            T->hight = 0;
            /*
               若定义空树高度为-1，则有一个节点时，树高为0，所以插入新节点的话，它的高度就为0
               若定义空树的高度为0，则有一个节点时，树高为1，所以插入新节点的话，它的高度就为1
            */
        }
    }
    else if (val > T->element)//要插的元素大，插右边
    {
        T->right = Insert_digui(T->right, val);
       
         if (Hight(T->right) - Hight(T->left) == 2)//判断左右子树，高度差2时，就旋转
        {
            if (val > T->right->element)
            {
                T = Single_left_rotation(T);
            }
            else
            {
                T = Right_Left_rotation(T);
            } 
        }
        
    }
    else if (val < T->element)//要插的元素小，插左边
    {
        T->left = Insert_digui(T->left, val);
        if (Hight(T->left) - Hight(T->right) == 2)//判断左右子树，高度差2时，就旋转
        {                                     //即此T->left是上边的T->left，val为新插入的节点的值，具体点可以这样理解，val为T->left->left的值
            if (val < T->left->element)       //新插入的节点小于父节点，即下图中的2，右单旋转即可，若大于父节点，即下图中的4，则左右双旋转
            {                                 //                  例如      6
                T = Single_right_rotation(T); //                          /   \.
            }                                 //                         5     7
            else                              //                         /
            {                                 //                        3          在次例中（以插入2为例），需要单次右旋
                T = Left_Right_rotation(T);   //                       /  \.       α为5【即以5为根的左子树】，所以此T为5
            }                                 //                      2    4       T->left为3，T->left->left为2        
        }                                    
    }                
    T->hight = Max(Hight(T->left), Hight(T->right)) + 1;                         
    return T;                                 
 }
//普通的二叉树的插入
// Pavl Insert_digui(Pavl T, int val)
// {
//     if (T == NULL)
//     {
//         T = malloc(sizeof(avl));
//         if (T == NULL)
//         {
//             puts("error,out of space");
//             return NULL;
//         }
//         else
//         {
//             T->left = NULL;
//             T->right = NULL;
//             T->element = val;
//         }
//     }
//     else if (T->element < val)
//     {
//         T->right = Insert_digui(T->right, val);
//     }
//     else if (T->element > val)
//     {
//         T->left = Insert_digui(T->left, val);
//     }
//     return T;
// }


Pavl Single_left_rotation(Pavl T){
     Pavl Temp = T->right;//最终要把Temp变成新的根，即把T->right往上提,让Temp先指向T->left以防一会找不到了。    9
     T->right = Temp->left;//左旋左变右,例如右边例子，10的左变9的右 也即T->right = T->right->left;            \.
     Temp->left = T;//Temp的左变为T，即10的左现在是9                                                          10
     T->hight = Max((Hight(T->left)),(Hight(T->right))) + 1;//调整节点【旋转】顺序后重新测高                     \.
     Temp->hight = Max((Hight(Temp->left)),(Hight(Temp->right))) + 1;// 调整节点【旋转】顺序后重新测高             11
     // Temp->hight = Max(T->hight,(Hight(Temp->right))) + 1; 旋转后temp->left的高度即root的高度
     return Temp;
}
Pavl Single_right_rotation(Pavl T){
    Pavl Temp = T->left;//最终要把Temp变成新的根，即把T->left往上提,让Temp先指向T->left以防一会找不到了。 按上边例子理解，Temp->left即T->left->left
    T->left = Temp->right;//右旋右变左，按上边例子理解3的右变5的左
    Temp->right = T;//Temp的右变为T，即3的右现在是5
    T->hight = Max((Hight(T->left)),(Hight(T->right))) + 1;//调整节点【旋转】顺序后重新测高
    Temp->hight = Max((Hight(Temp->left)),(Hight(Temp->right))) + 1;//调整节点【旋转】顺序后重新测高
    // Temp->hight = Max((Hight(Temp->left)), T->hight) + 1; 右旋，temp->right的高度即root的高度
    return Temp;
}
Pavl Left_Right_rotation(Pavl T){
    T->left = Single_left_rotation(T->left);//先左子树左旋
    return Single_right_rotation(T);//再整体右旋
}
Pavl Right_Left_rotation(Pavl T){
    T->right = Single_right_rotation(T->right);//先右子树右旋
    return Single_left_rotation(T);//再整体左旋
}
int Hight(Pavl T)
{/*
        深度通常是从根节点到某个节点的路径上的边数。对于一棵空树（即没有节点的树），深度是定义为0，因为没有路径。
        高度通常是指从某个节点到叶节点的最长路径上的边数。在不同的文献中，空树的高度定义有两种常见的方式：
        -1：这种定义方式使得叶节点的高度为0，因为从叶节点没有任何边到其它节点。
        0：这种定义方式直接将空树的高度定义为0
        
是的，如果对同一棵树分别采用高度为-1和高度为0的定义来计算树的高度，结果会相差1。

定义1：空树高度为-1

根节点的高度为树的高度。
定义2：空树高度为0

根节点的高度为树的高度。
示例分析
我们以一棵具体的树为例来说明这个差异。

假设有如下二叉树：
    1
   / \
  2   3
 / 
4  
计算树高度（空树高度为-1）
节点4：左右子树高度均为-1，高度为max(-1, -1) + 1 = 0
节点2：左子树高度为0，右子树高度为-1，高度为max(0, -1) + 1 = 1
节点3：左右子树高度均为-1，高度为max(-1, -1) + 1 = 0
根节点1：左子树高度为1，右子树高度为0，高度为max(1, 0) + 1 = 2
所以按照定义1，这棵树的高度是2。

计算树高度（空树高度为0）
节点4：左右子树高度均为0，高度为max(0, 0) + 1 = 1
节点2：左子树高度为1，右子树高度为0，高度为max(1, 0) + 1 = 2
节点3：左右子树高度均为0，高度为max(0, 0) + 1 = 1
根节点1：左子树高度为2，右子树高度为1，高度为max(2, 1) + 1 = 3
*/
    if (T == NULL)
    {
        return -1;//在次我选择空树高度定义为-1
    }
    else
    {
        return T->hight;
    }
}
int high(Pavl T)
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

// 计算二叉树的高度
int getHeight(Pavl root)
{
    if (root == NULL)   //空树的高度为-1
    {
        return -1;
    }

    // 计算左子树的高度
    int leftHeight = getHeight(root->left);
    // 计算右子树的高度
    int rightHeight = getHeight(root->right);

    // 高度是左右子树高度的最大值加1
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

void bianli(Pavl T){
    //中序遍历
    if (T == NULL)
    {
        puts("empty tree!");
        return;
    }
    if (T->left)
    {
        bianli(T->left);
    }
    printf("%d  ", T->element);
    if (T->right)
    {
        bianli(T->right);
    }  
}

void printTree(Pavl root, int space) {//按照树的样子打印
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->element);
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