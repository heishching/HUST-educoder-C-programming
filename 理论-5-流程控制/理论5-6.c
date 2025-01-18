/*求Π的近似值。输入精度e，根据计算公式：Π/4=1-1/3+1/5-1/7+...，直到最后一项的绝对值小于e为止（该项需要加上去）。结果保留6位小数。*/
/********** Begin **********/
#include<stdio.h>
#include<stdio.h>
#include<math.h>
int main(){
    double n,e;
    int add;
    scanf("%lf",&e);
    n=0;
    add=1;
    while(e*(add+2)<1){
        if(!((add+3)%4))
            n+=(1.0/add);
        else
            n-=(1.0/add);
        add+=2;
    }
    n=n*4;
    printf("%.6f",n);
    return 0;
}
/**********  End **********/