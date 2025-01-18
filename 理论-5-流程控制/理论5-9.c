/*输入十个整数，统计其中正数的个数，并计算正数的平均值。要求循环中使用continue语句实现。*/
/********** Begin **********/
#include<stdio.h>
int main(){
    int input,count,sum;
    double average;
    sum=0;
    count=0;
    average=0;
    for(int i=0;i<10;i++){
        scanf("%d",&input);
        if(input>0){
            count++;
            sum+=input;
        }
    }
    average=(double)sum/count;
    if(count!=0)
        printf("numbers=%d, average=%f",count,average);
    else
        printf("numbers=0, average=0.000000");
    return 0;
}

/**********  End **********/