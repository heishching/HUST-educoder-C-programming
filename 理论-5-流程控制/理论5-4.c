/*输入两个实数和一个四则运算符（ +  -  *  / ），根据运算符计算结果并输出，使用switch语句。结果保留一位小数。*/
/********** Begin **********/
#include<stdio.h>
int main(){
    float a,b,result;
    char operate;
    scanf("%f %f %c",&a,&b,&operate);
switch(operate){
    case'+':result=a+b;break;
    case'-':result=a-b;break;
    case'*':result=a*b;break;
    case'/':result=a/b;break;
}
    printf("%.1f",result);
    return 0;
}
/**********  End **********/