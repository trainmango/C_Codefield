#include <stdio.h>
#include<stdlib.h>
int main()
{
  float x, y, z, m;
  printf("输入三个数：");
  scanf("%f %f %f", &x, &y, &z);
   if (x<y)
  {
   m = y;
   y = x;
   x = m;

  }
    if (x<z)
  {
    m = z;
    z = x;
    x = m;
  }
   if (y<z)
  {
    m = z;
    z = y;
    y = m;
  }
  printf("从大到小输出：");
  printf("%f   %f  %f\n", x, y, z);
    system("pause");
    return 0;
}