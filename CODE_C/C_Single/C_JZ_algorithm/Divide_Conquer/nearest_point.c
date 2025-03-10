/**
 * @file nearest_point.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
typedef struct nearest_point
{
    double X_distance;
    double Y_distance;
} point;
point *init();
void print(point *);
void violentmethod_find_nearest_point(point *);
int main()
{
    point *a = init();

    print(a);
    violentmethod_find_nearest_point(a);
    system("pause");
    return 0;
}
point *init()
{
    int val1 = 0, val2 = 0;
    point *a = malloc(sizeof(point) * 10);
    for (int i = 0; i < 10; i++)
    {

        a[i].X_distance = val1 + i * 10;
        a[i].Y_distance = val2 + i * 6;
    }
    return a;
}
void print(point *a)
{
    for (int i = 0; i < 10; i++)
    {
        printf("第%d个点的x坐标为：%lf  ", i + 1, a[i].X_distance);
        printf("第%d个点的y坐标为：%lf  ", i + 1, a[i].Y_distance);
        puts(" ");
    }
    puts(" ");
}
void violentmethod_find_nearest_point(point *a)
{
    double x, y;
    double min_distance = 99.99, distance = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i != j)
            {
                x = a[i].X_distance - a[j].X_distance;
                y = a[i].Y_distance - a[j].Y_distance;
                double z = x * x + y * y;
                distance = sqrt(z);
                if (min_distance > distance)
                {
                    min_distance = distance;
                }
            }
        }
    }
    printf("所有点中最近两点的距离为：%lf\n", min_distance);
}