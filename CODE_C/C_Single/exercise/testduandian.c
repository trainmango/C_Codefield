# include <stdio.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int bits = sizeof(char*);
    if (bits == 4) printf("32位\n");
    else if (bits == 8) printf("64位\n");
    else printf("others, bits = %d\n", bits);
    system("pause");
    return 0;
}