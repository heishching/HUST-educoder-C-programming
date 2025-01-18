/*实验教材P179 6.3.2节 2.程序完善和修改替换 第（2）题第①问
通过函数指针和菜单选择来调用库函数实现字符串操作：串复制strcpy、串连接strcat或串分解strtok。请完善该程序
( 函数strtok的实现和使用参见理论课教材例8.19)*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void)
{
    char* (*p)(char*, char*);
    char a[80], b[80], * result;
    int choice;
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            p = strcpy; break;
        case 2:
            p = strcat; break;
        case 3:
            p = strtok; break;
        case 4:
            goto down;
        }
        getchar();//消除scanf choice 后的分行符
        scanf("%[^\n]", a);
        getchar();
        scanf("%[^\n]", b);
        getchar();
        result = p(a, b);
        printf("%s\n", result);
    }
down:
    return 0;
}