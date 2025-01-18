/*实验教材 1.5 实验一 第6题
输入一个字符串s，统计字符串的长度，并将字符串反转后输出*/
#include<stdio.h>
void strReverse(char s[]); 
int strLength(char s[]);
int main() 
{
	char s[1000];
	scanf("%s",s);
	printf("串%s的长度为:%d\n",s,strLength(s));
	strReverse(s);  
	printf("反转后:%s",s);
	return 0;
}

int strLength(char s[])  /* 返回字符串的长度（不含串尾）*/ 
{
	int i=0;
	while(s[i++]);//取一次加一，知道去不下去，而i最终是多加加了1
	return i-1; 	
}

void strReverse(char s[])  /* 反转串s */
{
	int i,j;
	for(i=0,j=strLength(s)-1;i<j;i++,j--)  /* 从两头遍历s */
	{
	    char t;
		t=s[i]; 
	    s[i]=s[j]; 
	    s[j]=t; 
    }
}