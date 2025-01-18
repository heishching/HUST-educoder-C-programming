//实验教材P63 程序设计第(4)题  判断输入的字符串是否符合手机号码的格式
//判断条件的优先级规定为：长度合法>每一位都是数字>第1位合法>第2位合法
#include <stdio.h>
#include <string.h>
int main(){
    char phone [12];
    scanf("%s",phone);
    if (strlen(phone)!=11){
        printf("长度不合法");
       return 0; }
    for(int i=0;i<11;++i){
        if(phone[i]!='0'&&phone[i]!='1'&&phone[i]!='2'&&phone[i]!='3'&&phone[i]!='4'&&phone[i]!='5'&&phone[i]!='6'&&phone[i]!='7'&&phone[i]!='8'&&phone[i]!='9'){
               printf("字符串中存在非数字字符"); 
               return 0;}
    }
        if(phone[0]!='1'){
            printf("第1位不合法");
            return 0;
        }
        if(phone[1]!='3'&&phone[1]!='4'&&phone[1]!='5'&&phone[1]!='7'&&phone[1]!='8'){
            printf("第2位不合法"); 
            return 0;
        }
        return 0;
}