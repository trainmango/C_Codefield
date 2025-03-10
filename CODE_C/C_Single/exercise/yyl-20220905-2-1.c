#include <stdio.h>

int main()
{
    long a, b, c, d, e, y,yyl_x;
    printf("请输入不多于6位的正整数:");
    scanf("%ld", &yyl_x);
    a = yyl_x / 100000 ;        //分解出万位
    b = yyl_x % 100000 / 10000;   //分解出千位
    c = yyl_x % 10000 / 1000;     //分解出百位
    d = yyl_x % 1000 / 100;       //分解出十位
    e = yyl_x % 100 / 10;
    y = yyl_x % 10 ; 
    printf("%ld %ld %ld %ld %ld %ld",a,b,c,d,e,y);         //分解出个位
    if (a != 0) {   //若a不为0，则说明这个数有万位，则为五位数
        printf("为 6 位数\n逆序为: %ld %ld %ld %ld %ld %ld\n", y, e, d, c, b, a);
    }
    else if (b != 0) {  
        printf("为 5 位数\n逆序为: %ld %ld %ld %ld %ld\n", y, e, d, c, b);
    }
    else if (c != 0) {
        printf("为 4 位数\n逆序为:%ld %ld %ld %ld\n", y, e, d, c);
    }
    else if (d != 0) {
        printf("为 3 位数\n逆序为: %ld %ld %ld\n", y, e, d);
    }
    else if (e != 0) {
        printf("为 2 位数\n逆序为:%ld %ld\n", y, e);
    }
    else if (y !=0) {
        printf("为 1 位数\n逆序为:%ld\n", y);
    }
    system("pause");
   
}
