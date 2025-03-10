#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;//金字塔的层数
    int i;//之间有几个空 
    int b;//第几层
    int j;//*
/*构建金字塔 6
     *              五个空（i=n-b）    一个*(n)            0(i=b-1)
    * *             四个孔              两个*              1                     
   * * *            三                  三                 2
  * * * *           二                  四                 3
 * * * * *
* * * * * *
*/
printf("请输入金字塔的层数：");
scanf("%d",&n);
if(n>0){
    //每层循环
    for(b=1;b<=n;b++){
        //循环内层
        //循环
        for(i=1;i<=(n-b);i++){   //空格数比层数少一，会达到输出框的最左边 n-b-3相当于向右整体平移3个
            printf(" ");
        }
        for(j=1;j<=b;j++){
            printf("* ");
        }
        printf("\n");
    }
}else{
    printf("输入非法数据，请输入大于零的数");
}
    system("pause");
    return 0;
}
