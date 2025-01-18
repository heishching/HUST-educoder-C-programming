/*输出斐波那契数列的前n项，n由终端输入（n>=20），每行输出8个数，每个数显示的宽度为10列。*/
/********** Begin **********/
#include<stdio.h>
int main(){
    int n;
    long long result[1000];
    scanf("%d",&n);
    result[0]=1;
    result[1]=1;
    if(n>2){
        for(int i=2;i<n;i++){
            result[i]=result[i-1]+result[i-2];
        }
    }
    for(int j=0;j<n;j++){
       printf("%10d",result[j]);
       if (!((j+1)%8)){
            printf("\n");
        }
    }
    return 0;

}
/**********  End **********/