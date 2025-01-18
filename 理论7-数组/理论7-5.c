//输入一个十六进制数字串，将其转换成为对应的整数并输出转换结果，遇到非十六进制数字或字符串结束符（'\0'）结束转换
//输入的字符串的长度不会超过100；转换后的值不会超出int类型的范围
#include<stdio.h>
#include<string.h>
#include<math.h>
void conversion(char str[]){
	/**********  Begin  **********/
    int i=0,j=0,num=0,sum=0,len=0;
    while((str[i]>='a'&&str[i]<='f')||(str[i]>='A'&&str[i]<='F')||(str[i]>='0'&&str[i]<='9')){
        len++;
        i++;
    }
    i=0;
    while(str[i]!=0){
        if(str[i]>='0'&&str[i]<='9'){
            num=str[i]-'0';
        }
        else if(str[i]>='a'&&str[i]<='f'){
            num=str[i]-'a'+10;
        }
        else if(str[i]>='A'&&str[i]<='F'){
            num=str[i]-'A'+10;
        }
        else break;
        for(j=0;j<len-1;j++){
            num=num*16;
        }
        sum+=num;
        i++;
        len--;
    }
    printf("%d\n",sum);
	/**********  End  **********/
}


/*#include"Step5_stu.h"
#define SIZE 100
int main()
{
	
	char str[100];
	scanf("%s",str);
	conversion(str);

	return 0; 
}
*/