
#include <stdio.h>

int main() {
    int a[10];
    int i, *p;
    printf("请输入十个数：\n");

    for (p = a; p < (a + 10); p++) {
        scanf("%d", p);
    }
     for (i = 0; i < 10; i++) {
        
         printf("%3d",*(a+i));
     }

       system("pause");
    return 0;
    }
 
