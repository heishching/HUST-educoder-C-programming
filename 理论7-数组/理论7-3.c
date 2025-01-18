/*编程统计输入的一段文字中每个数字字符、 每个英文字符（不区分大小写）和其他字符出现的次数（要求用数组元素作为每个数字字符、每个英文字符、和其他字符出现的次数的计数器）。
注意：统计每个字符。
如：输入 12L C，统计的结果为：1个1，1个2，1个L，1个C，一个其他字符（空格）。*/
#include<stdio.h>
int main()
{
	/**********  Begin  **********/
	int statis[37]={0};//0-9 for number,10-35 for letter,36 for other
    char c,letter;
    int serial;
    while((c=getchar())!=EOF){
        if(c<='Z'&&c>='A'){
            serial=10+c-'A';
            statis[serial]+=1;
        }
        else if(c<='z'&&c>='a'){
            serial=10+c-'a';
            statis[serial]+=1;
        }
        else if(c<='9'&&c>='0'){
            serial=c-'0';
            statis[serial]+=1;
        }
        else {
            statis[36]+=1;
        }
        serial=0;
    }
    for(int i=0;i<=9;i++){
        if (statis[i]!=0){
            printf("%d:%d\n",i,statis[i]);
        }
    }
    for(int j=0;j<=25;j++){
        if(statis[j+10]!=0){
            letter='A'+j;
            printf("%c:%d\n",letter,statis[j+10]);
        }
    }
    if (statis[36]) printf("others:%d",statis[36]-1);
	/**********  End  **********/
	return 0; 
}