/*本关任务：修改2.(1)的程序，在显示文本的过程中对每一行加一个行号，
同时，设计一个显示控制参数/p，使得每显示5行（一屏）就暂停，当用户按下任何一个键，例如"q"就继续显示下一屏。*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	FILE * fp;
    char ch,c;
    int n=1;
	if(argc!=2&&argc!=3){
		printf("Arguments error!\n");
		exit(-1);
	}
	if((fp=fopen(argv[1],"r"))==NULL){      /* fp指向filename */
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
    printf("1 ");
    if(argc==2){
	    while(1){      
		    ch=fgetc(fp);
            if (feof(fp)) break;//将判断改到此处，如果读取了一个后面还不是EOF就说明没到头
            printf("%c",ch);
            if(ch=='\n') printf("%d ",++n);
        }
    }
    else{        
        while(1){      
		    ch=fgetc(fp);
            if (feof(fp)) break;//将判断改到此处，如果读取了一个后面还不是EOF就说明没到头
            if(ch=='\n'){
                n++;
                if(n%5==1&&n>5) while((c=getchar())=='q');
                printf("%c",ch);
                printf("%d ",n);
            }
            else printf("%c",ch);
        }
    }
	fclose(fp);                        /* 关闭filename */ 
	return 0;
}
