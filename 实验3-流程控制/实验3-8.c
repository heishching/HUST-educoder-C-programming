/*实验课本P85  程序设计第（4）题
将输入的正文复制到输出，复制过程中将每行一个以上的空格字符用一个空格代替。*/
#include<stdio.h>
int main(){
    char input[1000];
    char c;
    int i=0;
    while ((c=getchar())!=EOF&&i<999) { // 确保不会超出数组边界
        if (i== 0||input[i-1]!=' '||c!=' ') {
            input[i++] = c; // 只有当c不是空格，或者前一个字符不是空格时，才添加到数组中
        }
    }
    input[i]='\0'; // 添加字符串结束符

    for(int j=0; j<i;j++) { // 打印字符串直到结束符
        printf("%c",input[j]);
    }
    return 0;
}
