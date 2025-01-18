 //本关任务：实验教材 1.5 实验一 第2题
//输入一段正文，统计字符数和行数。
 #include<stdio.h>
int main(void)
{
    int c, numchar, numline;
    numchar = 0;
    numline = 0;
    while( (c=getchar()) != EOF){
        numchar++;
        if(c == '\n'){
            numline++;
        }
    }
    printf("字符数:%d,", numchar);
    printf("行数:%d",numline);
    return 0;
}