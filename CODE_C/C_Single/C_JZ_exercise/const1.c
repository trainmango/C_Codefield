/**
 * @file const1.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 
 * const修饰数组，则数组中的每个元素都不能改 
 * 
 * 
 */
int main()
{
    const int num = 3; // 与编译器有关，尽管声明了const但是还是用指针改了值，直接改num的值会报错
    /*
     warning: initialization discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]
     int *p = &num;
              ^
     编译器会警告，但能运行，最好不要这样写
    */
    int *p = &num;
    *p = 10;
    printf("%d  %d\n", num, *p);

    double arr[3] = {23.3, 42222.33, 56.234};
    const double *pb = arr;       // 这种写法是指pb不能去更改指向地址的值 例子： pb[2] = 32.3;会报错
    double *const pc = arr;       // 这种写法是指pc永远指向arr了，不能指向其他地方了     例子： pc = &num;会出错
    const double *const pa = arr; //这种写法是既不能更改它所指向的地址，也不能修改它指向的值
    pc[2] = 33.3;

    printf("%lf\n", pa[2]);

    system("pause");
    return 0;
}