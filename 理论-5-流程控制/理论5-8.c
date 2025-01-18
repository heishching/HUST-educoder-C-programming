/*输入一个整数n（n<=10000），打印n以内所有这样的完全平方数y：y=a²=b²x10+c²。例如，361=19²=6²x10+1²，则361是这样的完全平方数。*/
/********** Begin **********/
#include<stdio.h>
#include<math.h>
int main(){
    int n,a,b,c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if (((int)sqrt(i))*((int)sqrt(i))==i){//是完全平方数？
            a=(int)sqrt(i);
            for(b=1;b<=i;b++){
                if(((int)sqrt(i-10*b*b))*((int)sqrt(i-10*b*b))==(i-10*b*b)){
                    c=(int)sqrt(i-10*b*b);
                    printf("%d=%d*%d=%d*%d*10+%d*%d\n",i,a,a,b,b,c,c);
                    break;
                }
            }
        }
    }
    return 0;
}

/**********  End **********/