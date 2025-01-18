/*实验课本P86  程序设计第（12）题
输入正整数x(2≤x≤79)，输出所有形如abcde/fghij=x的表达式，其中a-j由不同的数字0~9组成。*/
#include<stdio.h>
int isValid(int x,int y){
    int digit[10]={0};//0 stands for hasn't appear
    while(x>0){
        if(digit[x%10]==1) return 0;
        digit[x%10]=1;
        x=x/10;
    }
    while(y>0){
        if(digit[y%10]==1) return 0;
        digit[y%10]=1;
        y=y/10;
    }
    if((x<10000&&digit[0]==1)||(y<10000&&digit[0]==1)) return 0;
    return 1;
}
int main()
{
    int x,a,b;
    scanf("%d",&x);
    for(b=1234;b*x<100000;b++){
        a=b*x;
        if(isValid(a,b)){
            if(a<10000) printf("0%d/%d=%d\n",a,b,x);
            else if(b<10000) printf("%d/0%d=%d\n",a,b,x);
            else printf("0%d/%d=%d\n",a,b,x);
        }
    }
    return 0;
}