/*实验教材P63 程序设计第(3)题
给定n个整数表示一个商店连续n天的销售量，计算出这些天总共有多少个折点*/
#include<stdio.h>
int main(){
    int day,point=0;//day:how many days,
    point=0;
    scanf("%d",&day);
    int sale[day];
    for (int i=0;i<day;i++){
        scanf("%d",&sale[i]);
    }
    for (int i=1;i<day-1;i++)
        {
        if ((sale[i-1]>sale[i])==(sale[i]<sale[i+1])){
            point+=1;
            }
        }
        printf("%d",point);
        return 0;
    }