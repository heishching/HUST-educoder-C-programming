/*实验教材 1.5 实验一 第3题
输入某年某月某日，判断这一天是这一年的第几天（ P34）*/
#include<stdio.h>
int main()
{
      int day,month,year,sum,leap,i;
	   int mdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		scanf("%d%d%d",&year,&month,&day);
		sum=0;
		for(i=1;i<month;i++){
			sum+=mdays[i];
		}
		sum+=day;
		if((year%400==0)||(year%4==0&&year%100!=0))
			leap=1;
		else
			leap=0;
		if(leap==1&&month>2)
			sum++;
		printf("It is the %dth day.",sum);
		return 0;
	}