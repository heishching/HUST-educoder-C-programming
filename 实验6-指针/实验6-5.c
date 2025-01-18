/*本关任务：实验教材P179 6.3.2节 2.程序完善和修改替换 第（2）题第②问
通过函数指针和菜单选择来调用库函数实现字符串操作：串复制strcpy、串连接strcat或串分解strtok。

请使用转移表而不是switch语句重写第4关程序。*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main(void)
{
    char* (*p)(char*, char*);
    char a[80], b[80], * result;
    int choice;
    char* (*fun[3])(char*,char*); 
    fun[0]=strcpy;
    fun[1]=strcat;
    fun[2]=strtok;
    while (1)
    {
        scanf("%d", &choice);
        if(choice==4) goto down;
        getchar();//消除scanf choice 后的分行符
        scanf("%[^\n]", a);
        getchar();//\n依旧留在输入流中，消除scanf后的分行符
        scanf("%[^\n]", b);
        getchar();
        result = fun[choice-1](a, b);
        printf("%s\n", result);
    }
down:
    return 0;
}