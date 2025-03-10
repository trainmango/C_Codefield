/**
 * @file forcetransfer.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *);
void test_show_bytes(int val);
void t(int val);
int main()
{
    unsigned char s[] = "sadf";
    float d = 23.4;
    unsigned int f = 123;
    void *x = malloc(sizeof(void *));
    show_bytes(s, sizeof(char *)); //
    show_float(d);
    show_int(f);
    show_pointer(x);
    printf("\n");

    test_show_bytes(12345);
    /*
                    最高位：00 最低位：39
        在十六进制下，12345为0x00003039          浮点数为 0x4640E400
        运行结果为：39  30  00  00
                   00  e4  40  46
                   bc  fd  61  00  00  00  00  00
        由此可知本机器（windows intel）为小端格式
    */
    printf("\n");
    t(0x87654321);
    printf("\n");
    const char * cv = "abcdef";
    show_bytes((byte_pointer)cv,strlen(cv));
    system("pause");
    return 0;
}
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x  ", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}
void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}
void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
void t(int val)
{
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_int(val);
}