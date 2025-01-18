/*输入两个正整数，输出它们的最小公倍数和最大公约数。*/
/********** Begin **********/
#include<stdio.h>
int main(){
    int a,b,gcd,lcm,max,min;//gcd Greatest common divisor,lcm least common multiple
    scanf("%d %d",&a,&b);
    if (a==b){
        lcm=a;
        gcd=b;
    }
    else{
    if(a>b){
        max=a;
        min=b;
    }
    else{
        max=b;
        min=a;
    }
//Greatest common divisor
    for (int i=min;i>0;i-=1){
        if ((a%i==0)&&(b%i==0)){
            gcd=i;
            break;
        }
    }
//least common multiple
    for (int j=max;j<=a*b;j++){
        if ((j%a==0)&&(j%b==0)){
            lcm=j;
            break;
        }
    }
}
printf("%d %d",gcd,lcm);
return 0;
}
/**********  End **********/