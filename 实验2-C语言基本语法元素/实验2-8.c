//实验教材P64 程序设计第(10)题
//输入一段含西文字符和中文字符的正文，统计字数、字符数和行数
#include <stdio.h>
int main() {
    char c,b;
    int wordnum,charnum,linenum,chinese,ischinese;//ischinese means the last word is or isnot a chinese
    wordnum=0;
    charnum=0;
    linenum=1;
    b=0;
    ischinese=0;
    while((c=getchar())!=EOF){
      if(c=='\n'){
        linenum++;
        if((b>='a'&&b<='z')||(b>='A'&&b<='Z'))
          wordnum++;
        b=c;
        continue;
        }
      if (c>127||c<0){
        chinese++;
        ischinese=1;
      }
      else if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
        charnum++;
        ischinese=0;
      }
      else if ((c==' '||c=='\t')&&((b!='\t')&&(b!='\n')&&(b!=' '))&&ischinese==0)
        wordnum++;
      b=c;
    }
    wordnum+=chinese/3;
    charnum+=chinese/3;   
    if ((b!='\t')&&(b!='\n')&&(b!=' '))
      wordnum++;
    if (b=='\n')
      linenum--;
    printf("字数 %d\n", wordnum);
    printf("字符数 %d\n",charnum);
    printf("行数 %d", linenum);
    return 0;
}