/*定义枚举类型enum month，一月（Jan），二月（Feb）、......、十二月（Dec）。
编写一个程序，能根据输入的年份值，输出对应该年份各月的英文名称及天数，
（注：此题没有特别限制，没有学到后续章节的同学，可以逐月顺序处理，
使用条件运算符完成判断是否为闰年处理）。
根据提示，在右侧编辑器Begin-End中编写程序，
编写一个能根据年份输出对应年份各月的英文名称及天数的函数。输出要求为：各月份英文名称需要输出全称，
并且月份首字母大写。然后月份后面跟上冒号（:）,然后跟上一个空格，后面是对应月份的天数，
每月输出一行，具体格式见测试用例
*/
#include <stdio.h>

int main() {
	/**********Begin**********/
    int year;
    scanf("%d",&year);
    printf("Jan: 31\n");
    if((year%4==0&&year%100!=0)||year%400==0)
        printf("Feb: 29\n");
    else
        printf("Feb: 28\n");
    printf("Mar: 31\n");
    printf("Apr: 30\n");
    printf("May: 31\n");
    printf("Jun: 30\n");
    printf("Jul: 31\n");
    printf("Aug: 31\n");
    printf("Sep: 30\n");
    printf("Oct: 31\n");
    printf("Nov: 30\n");
    printf("Dec: 31\n");


	/**********End**********/
	return 0;
}