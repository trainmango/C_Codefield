/*
   2023年2月10日19点55分
   << 与 >>  【按位左移】和【按位右移】



 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int m = 10;
  int i = 3; // 3的二进制代码0011
  int j = 5; // 5的二进制代码0101
  int k, l, b, a;
  l = j >> 1;
  k = i << 1; // 相当于把i和j二进制的每一位进行或判断
              //            0 0 1 1 左移补零 0 0 1 1 0  即十进制的6
  a = m >> 1;
  b = m << 1;

  printf("%d\n", k);
  printf("%d\n", l);
  printf("%d\n", a);
  printf("%d\n", b);

  int y = 2 > 3 ? 100 : 200;
  printf("%d\n", y);

  char s[] = "abcdefg";
  printf("%s\n", s);

 

  system("pause");
  return 0;
}