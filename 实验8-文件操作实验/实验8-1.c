/*本关任务：参考实验指导书P225-226页内容，功能要求是，通过命令行参数将指定的文本文件内容显示在屏幕上。
给出的源程序中存在一些逻辑错误，对程序进行修改、调试，使之能够正确完成指定任务*/
/*错误分析
while(!feof(fp))             
	putchar(fgetc(fp));
    fclose(fp);   
return 0;
feof是站在光标的位置看后面还有没有内容。读到最后时后面还有个EOF自然就会继续读下去多输出一个乱码
*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	FILE * fp;
    char ch;
	if(argc!=2){
		printf("Arguments error!\n");
		exit(-1);
	}
	if((fp=fopen(argv[1],"r"))==NULL){      /* fp指向filename */
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	while(1){      
		ch=fgetc(fp);
        if (feof(fp)) break;//将判断改到此处，如果读取了一个后面还不是EOF就说明没到头
        printf("%c",ch);
    }
	fclose(fp);                        /* 关闭filename */ 
	return 0;
}
