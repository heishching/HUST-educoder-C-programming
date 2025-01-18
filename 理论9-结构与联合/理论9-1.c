//设计一个含有年、月、日的日期结构类型，输入一个日期，计算并输出该日期是该年中的第几天。
#include<stdio.h>
/**********  Begin  **********/
struct date{
    int year;
    int day;
    int month;
};
int countday(struct date *p);
int main()
{
	struct date input;
    int num;
    scanf("%d %d %d",&input.year,&input.month,&input.day);
    num=countday(&input);
    if(num==0) printf("不存在这样的日期");
    else printf("%d",num);
    return 0;
}
    
int countday(struct date *p){
    int sum,leap,i;
	int mdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	sum=0;
    if((p->year%4!=0||(p->year%4==0&&p->year%100==0&&p->year%400!=0))&&p->month==2&&p->day>29)
        return 0;
    else{
        if(p->day>mdays[p->month]) return 0;
        else{
            for(i=1;i<p->month;i++){
			    sum+=mdays[i];
		    }
		    sum+=p->day;
		    if((p->year%400==0)||(p->year%4==0&&p->year%100!=0))
		        leap=1;
		    else
		        leap=0;
		    if(leap==1&&p->month>2)
		        sum++;
            return(sum);
        }
    }
}

/**********   End   **********/