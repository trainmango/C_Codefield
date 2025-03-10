#include<stdio.h>
  int main()
  {
    int yyl_num,i,j;
    printf("金字塔层数\n");
    scanf("%d",&yyl_num);
    
    for(i=0;i<yyl_num;i++)
    {
        for(j=1;j<=2*yyl_num-1;j++)
        {
            if (j< yyl_num-i||j > yyl_num+i)
               printf(" ");
            else
               printf("*");
        }
        
    }
    printf("\n");
system("pause");
  }
