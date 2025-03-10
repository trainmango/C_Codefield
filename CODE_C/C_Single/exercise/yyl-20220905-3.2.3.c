#include <stdio.h>

int main() {
    int a[10];
    int i, *p;
    printf("请输入十个数：\n");
    for ( i = 0; i < 10 ; i++) {

    }
    for (p = a; p < (a + 10); p++) {
        scanf("%d", p);
    }
 

    for (p = a; p < (a + 10); p++) {
        printf("%3d", *p);
    }
    system("pause");
    return 0;
}