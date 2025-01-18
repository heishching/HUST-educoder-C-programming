/*教材P109跟踪调试第（4）题。
本关任务：调试计算圆面积。题目要求详见教材，线下完成跟踪调试任务后，
提交满足任务要求程序(去掉原题中的输入提示语句)进行评测。要求必须使用断言，否则计0分。*/
/******************  begin *********************/
#include<stdio.h>
#include<assert.h>
#define R
int integer_fraction(float x);
int main(void){
    float r,s;
    int s_integer=0;
    scanf("%f",&r);
    #ifdef R 
        s=3.14159*r*r;
        s_integer=integer_fraction(s);//s取整
        assert(((float)(s-s_integer))<=0.5);//如果s与s取证差<0.5，错误
        printf("The integer fraction of area is %d",s_integer);
    #endif
    return 0;    
}
int integer_fraction(float x){
    int i=x;
    if(((float)(x-i))<0.5) return i;
    else return i+1;
}


/******************   end  *********************/