/*本关任务：使用条件编译方法编写程序。输入一行英文字符串，使用#define命令控制是否变换字母的大小写。
#define CHANGE 1，则将字符串中的小写英文字母变为大写字母后、大写英文字母变为小写字母后输出；
#define CHANGE 0，则输出原文，本关检测的是当#define CHANGE 1的输出。

编程要求
根据提示，在右侧编辑器编写程序，使用条件编译控制输出，本关完成#define CHANGE 1对应的功能，要求本关和下一关的源程序除宏的定义不同外，其它部分完全相同。*/
#include<stdio.h>
#define CHANGE1
int main(void)
{
    char input[1000]={0};
    int i=0;
    char c=0;
    while((c=getchar())!=EOF){
        #ifdef CHANGE1
        if(c>='a'&&c<='z'){
            input[i]=c-'a'+'A';
        }
        else if(c>='A'&&c<='Z'){
            input[i]=c-'A'+'a';
        }
        else input[i]=c;
        #endif
        #ifdef CHANGE0
            input[i]=c;
        #endif
        i++;
    }
        input[i]='\0';
        printf("%s",input);
        return 0;
}