/**
 * @file Secondpointer.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct moban
{
    int name;
    int value;
};
/**
 在init函数中，head是一个指向指针的指针，*head是指向struct moban的指针，而h是一个
 struct moban类型的指针。我们通过*head = h;将head指向的内容（即main函数中的a指
 针）设置为h，从而使得a指向新分配的内存区域。
 
 
 解释为什么 *head = h; 和 **head = *h; 不能互换
 *head = h;

 head是struct moban**类型的变量。
 *head是struct moban*类型的变量，指向main中的变量a。
 h是struct moban*类型的变量。 
 通过*head = h;，我们将*head的值（即a的值）设置为h，使得a指向新分配的内存区域。
 **head = *h;

 *head是struct moban*类型的变量，指向main中的变量a。
 **head是struct moban类型的变量，表示*head指向的struct moban对象的值。
 *h是struct moban类型的变量，表示h指向的struct moban对象的值。 
 通过**head = *h;，我们试图将**head（即a指向的struct moban对象的值）设置为*h（即h指向的struct moban对象的值）。
 但这只有在a已经指向一个有效的struct moban内存区域时才有意义。否则，**head = *h;
 可能会导致未定义行为，因为在main函数中，a最初指向的内存区域并未被正确初始化。
 */
void init(struct moban **head) //传过来的时*a的地址，即&a，**(&a)即*a 即**head == *a
{
    struct moban *h = malloc(sizeof(struct moban));
    h->name = 10;
    h->value = 99;
    *head = h; // 把struct moban *类型的h给*head【*head即a】
}
int main()
{

    struct moban *a = malloc(sizeof(struct moban));//即当a未指向malloc(sizeof(struct moban));时，用**head = *h会出错
    init(&a);
    printf("%d  %d", a->name, a->value);
    system("pause");
    return 0;
}
/*
   具体地，这两个操作的根本区别在于：

*head = h;是改变head指向的指针的值，使其指向新分配的内存。
**head = *h;是改变head指向的内存内容，但要求head指向的指针本身已经指向有效的内存区域。
为了进一步说明这一点，可以看一下错误使用**head = *h;会导致什么问题。假设a没有被正确初始化：

c
复制代码
int main()
{
    struct moban *a;  // 未初始化
    init(&a);         // 这时a是未定义的指针，**head = *h;会崩溃
    printf("%d  %d", a->name, a->value);
    system("pause");
    return 0;
}
这里，a未初始化，指向一个不确定的内存区域。当你调用init(&a)时，如果init中使用**head = *h;，程序可能会崩溃，因为它试图将值赋给一个未定义的内存位置。

综上所述，*head = h; 是正确的用法，而 **head = *h; 不能替代它使用。



*/