/*编写程序，设置指令type_c与type_c /p来获取.c文件中的内容，获取type_c+文件名指令时，显示文件中的C语言程序，
并为每一行开头加上行号（行号从1开始标注）；获取type_c /p+文件名指令时，为每一行开头加上行号的同时，每10行显示一屏，再次获取字母q，则显示下一屏。
（为简化程序，本次测试使用测试文件超过10行，且不用考虑文件格式错误）
文件路径为：src/step1_1/test1.c。*/
#include<stdio.h>
#include<string.h>
int main()
{
	// 请在此处编辑您的代码
	/********** Begin **********/
    char mode0[10],mode[100],filename[100];
    FILE *fp;
    char ch;
    int i=1;
    scanf("%s ",mode0);
    if(strcmp(mode0,"type_c")!=0){
        printf("指令错误");
        return 0;
    }
    scanf("%s ",mode);
    if(strcmp(mode,"/p")==0) {
        scanf("%s",filename);
        if((fp=fopen("src/step1_1/test1.c","r"))==NULL){
            printf("指令错误");
            return 0;
        }
        printf("%d  ",i);
        while((ch=fgetc(fp))!=EOF) {
            putchar(ch);
            if(ch=='\n'){ 
                i++;
                printf("%d  ",i%10==0?10:i%10);
            }
        }
    }
    else{ 
        strcpy(filename,mode);
        if((fp=fopen("src/step1_1/test1.c","r"))==NULL){
            printf("指令错误");
            return 0;
        }
        printf("%d  ",i);
        while((ch=fgetc(fp))!=EOF) {
            putchar(ch);
            if(ch=='\n'){
                i++;
                printf("%d  ",i);
            }
        }
    }
	/********** End **********/
	return 0; 
}