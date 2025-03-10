/* 
   2023年1月28日16点56分
   于zhizhen9~14.c一同观看加深理解
 */
#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
    int a[5];  //静态    //如果int占4个字节的话，则本数组总共包含有20个字节，每个字节被当作了一个int变量来使用
                  //即在内存条中抽取20个字节空间，前4个为a[0],4~8为a[1].........
    int len;
    int * pArr;
    int i;

    //动态的构造一维数组
    printf("请输入你要存放的个数:");
    scanf("%d",&len);
    pArr = (int *)malloc(4 * len);   //动态的构造了一个一维数组   //类似于写了int pArr[len];{但这样是静态的}
    //对一维数组进行操作  如：对一维数组进行赋值   
    //一般来说a[n]是错的（数组的大小不能定义为变量）而采用malloc即可构造出动态的
    for ( i = 0; i < len; i++)
    {
      scanf("%d", &pArr[i]);
    }
    //对一维数组进行输出
    printf("一维数组的内容是：");
    for ( i = 0; i < len; i++)
    {
      printf("%d\n", pArr[i]);
    }
    
    
    system("pause");
    return 0;
}