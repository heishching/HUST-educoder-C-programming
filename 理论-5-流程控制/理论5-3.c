/*输入两个实数和一个四则运算符（ +  -  *  / ），根据运算符执行相应的运算并输出结果，使用if语句完成。保留一位小数。*/
/********** Begin **********/
#include<stdio.h>
int main(){
    float a,b,result;
    char operate;
    scanf("%f %f %c",&a,&b,&operate);
    if (operate=='+')
        result=a+b;
    if (operate=='-')
        result=a-b;
    if (operate=='*')
        result=a*b;
    if (operate=='/')
        result=a/b;
    printf("%.1f",result);
    return 0;
}

/**********  End **********/