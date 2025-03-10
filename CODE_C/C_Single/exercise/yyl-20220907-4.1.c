#include<stdio.h>
#include<stdlib.h>
struct stud {
int num;
char name[30];
float score[3];
} ;
int main()
{
struct stud stu ;
int i;
float avg ;
printf("input number: "); scanf("%d", &stu.num );
printf("input name: " ); scanf("%s", stu.name );
printf("input 3 score:\n");
avg=0;
for( i=0;i<3;i++ )
{
scanf("%f", &stu.score[i] );
avg += stu.score[i] ;
}
avg /= 3 ;
printf("average score: %f\n", avg );
system("pause");
return 0;

}