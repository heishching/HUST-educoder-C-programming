/*实验教材P179 6.3.2节 2.程序完善和修改替换 第（1）题第②问
strsort用于对字符串进行升序排序，在主函数中输入N个字符串存入通过malloc动态分配的存储空间，然后调用strsort对这N个串按字典序升序排序。

请用二级指针形参重写第2关的strsort函数，并且在该函数体的任何位置都不允许使用下标引用。*/
///* 实验6程序完善与修改替换第（1）题源程序：字符串升序排序 */
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
/* 对指针数组s指向的size个字符串进行升序排序 */
void strsort(char*(*s[]) , int size)
{

    char* temp;
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (strcmp(s[j], s[j + 1]) > 0)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
}

int main()
{
    int i,N;
    scanf("%d",&N);
    char* s[N], t[50];//s是指针数组
    char *p=s;
    //scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s",t);
        s[i] = (char*)malloc(strlen(t) + 1);
        strcpy(s[i], t);
    }
    strsort(s, N);
    for (i = 0; i < N; i++)  puts(s[i]);
    return 0;
}