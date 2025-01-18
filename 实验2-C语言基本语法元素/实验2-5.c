//实验教材P63 程序设计第(5)题  取出x从第ｍ位开始向左的ｎ位。
#include<stdio.h>
int main(){
    int x;
    int result,m,n;//中间字符
    scanf("%x %d %d",&x,&m,&n);
    x=x&~(~0<<n)<<(m);//第m位向左的n位为1其他为0
    result=(x&~(~0<<n)<<m)<<(16-m-n);//无符号短整数
    printf("%x",result);
}