/*实验教材P182，程序设计第（1）题
本关任务：编写一个程序，从整形变量的高字节开始，依次取出每字节的高4位和低4位并以十六进制数字字符的形式进行显示，要求通过指针取出每字节。

平台中long为8字节，所以将书中题目的长整形改为整形。*/
//这题需要注意大小端模式
#include<stdio.h>
int main(){
    int n,high,low;
    char *b;
    union{
        int num;
        char a[4];
    } x;
    scanf("%d",&x.num);
    b=x.a;
    b+=3;//小端
    //for(int i=3;i>=0;i--)别发疯了，这样改根本没用，你用的是指针不是下标
    for(int i=0;i<4;i++){
        high=((*b)&0xf0)>>4;
        low=(*b)&0x0f;
        if(high<=9) printf("%d ",high);
        else{
            switch(high-10){
                case 0:printf("a ");break;
                case 1:printf("b ");break;
                case 2:printf("c ");break;
                case 3:printf("d ");break;
                case 4:printf("e ");break;
                case 5:printf("f ");break;
            }
        }
        if(low<=9) printf("%d ",low);
        else{
            switch(low-10){
                case 0:printf("a ");break;
                case 1:printf("b ");break;
                case 2:printf("c ");break;
                case 3:printf("d ");break;
                case 4:printf("e ");break;
                case 5:printf("f ");break;
            }
        }
        b--;
       // b++; 在这个系统中采用的大小端模式中，高字节在后（小端），这句被注释的代码是大端的情况
    }
    return 0;
}