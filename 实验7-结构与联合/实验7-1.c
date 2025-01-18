/*实验教材P205 7.3.2节 1.表达式求值的程序验证

本关任务：计算并验证实验指导书上表达式的值。*/
/*************************Begin*************************/
#include<stdio.h>
int main(){
    char u[]="UVWXYZ",v[]="xyz";
    struct T{
        int x;
        char c;
        char *t;
    }a[]={{11,'A',u},{100,'B',v}},*p=a;
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("%d",100);break;//(++p)->x
        case 2:printf("B");break;//p++,p->c
        case 3:printf("x");break;//*p++->t.*p->t
        case 4:printf("x");break;//*(++p)->t
        case 5:printf("V");break;//*++p->t
        case 6:printf("V");break;//++*p->t
    }
    return 0;
}/*************************End*************************/