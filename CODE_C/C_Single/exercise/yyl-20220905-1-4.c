#include<stdio.h>
int main()
{
 int a[10][10],i,j,m,n;
 scanf("%d %d",&m,&n);
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 
 for(i=0;i<m;i++)
 {
  int lj_sumx=0;
  for(j=0;j<n;j++)
  {
   lj_sumx+=a[i][j];
  }
  printf("%d\n",lj_sumx);
 } 

  for(i=0;j<n;j++)
 {
  int lj_sumy=0;
  for(j=0;j<n;j++)
  {
   lj_sumy=lj_sumy+a[i][j];
  }
  printf("%d\n",lj_sumy);
 } 
 return 0;
}

