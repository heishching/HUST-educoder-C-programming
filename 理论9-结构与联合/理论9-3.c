/*现有如表中所示的4个常用的网站网址信息，包括缩略名、全名、url信息。现设计一个结构体struct web,并编写结构体数组获取表中的网址信息，同时将网站信息按照缩略名排序并按照升序输出,最后获取一个缩略名，输出它的URL信息。
要求：将排序定义成函数。

缩略名	全名	URL
hkd	华中科技大学	http://www.hust.edu.cn
bd	百度搜索网站	http://www.baidu.com
gg	谷歌搜索网站	http://www.google.com
wy	网易邮箱登录	https://mail.163.com*/
#include<stdio.h>
#include<string.h>

struct web  /*  设计表示网址的结构  */
{
    /**********  Begin  **********/
    char abb[100];
    char name[1000];
    char side[1000];
	/**********   End   **********/
};
//这里头歌给的初始代码有误，web的定义要在函数声明前面
void sort(struct web webs[],int n);
#define N  4      /*  网址表大小  */

int main()
{
	/**********  Begin  **********/
    struct web input[N];
    char find[100];
    int is_find=0;
    for(int i=0;i<N;i++){
        scanf("%s",input[i].abb);
        scanf("%s",input[i].name);
        scanf("%s",input[i].side);
        getchar();
    }
    scanf("%s",find);
    sort(input,N);
    for(int i=0;i<N;i++){
        printf("%s ",input[i].abb);
        printf("%s ",input[i].name);
        printf("%s",input[i].side);
        putchar('\n');
    }
    for(int i=0;i<N;i++){
        if(strcmp(find,input[i].abb)==0){
            printf("%s",input[i].side);
            is_find=1;
            break;
        }
    }
    if(is_find==0){
        printf("未找到搜寻的网址");
    }
	/**********   End   **********/
	return 0; 
}

void sort(struct web webs[],int n)
{
	/**********  Begin  **********/
    struct web t;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(strcmp(webs[j].abb,webs[j+1].abb)>0){
                t=webs[j];
                webs[j]=webs[j+1];
                webs[j+1]=t;
            }
        }
    }
	/**********   End   **********/
}