/*实验指导书 P140~141 程序完善与修改替换第（1）题
请通过空间换时间的方法对第2关去掉重复字符的程序进行改进，使算法的时间复杂度由O(n^2)降低为O(n)。*/
#include<stdio.h>
#include<string.h>
void RemoveDuplicate(char *);
int main()
{
    char str[200];
   while(fgets(str, 200, stdin) != NULL)
   {
   		RemoveDuplicate(str);
      printf("%s", str);
   }
   return 0;
}

void RemoveDuplicate(char *s)
{
	int r, w, i, len;
    int has_dealt[256]={0};
    len = strlen(s);
    for (r = w = 0; r < len; r++){//r read  w write
        if(has_dealt[(int)s[r]]==0){
            s[w]=s[r];
            w++;
            has_dealt[(int)s[r]]=1;
        }
    }
    s[w]='\0';
}