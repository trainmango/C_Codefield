#include <stdio.h>


/*主串S,模式串T*/
int navie_string_matcher(SString s,int pos,SString t)
{
    int i,j,start;
    start = pos; i = start; j = 0;/*主串从pos开始，模式串从头开始*/
    if (t.len==0) return 0; /*模式串为空串时，是任意串的匹配串*/
    while (i < s.len && j < t.len )
        if (s.ch[i]==t.ch[j])/*当前对应字符相等时推进*/
        {
            i++;
            j++;
        }
        else
        {
            start++;  /*对应字符不等时回溯*/
            i = start;/*主串从start+1开始，模式串从头(0)开始*/
            j =0;
        }
        if (j >= t.len) return(start); /*匹配成功时返回匹配起始位置*/
        else return -1;    /*匹配不成功时，返回-1*/

}
