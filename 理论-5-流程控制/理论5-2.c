/*输入一个日期（年、月、日），计算并输出该日期是这一年的第几天。*/
/********** Begin **********/
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
		printf("%d",sum);
		return 0;
	}
/**********  End **********/