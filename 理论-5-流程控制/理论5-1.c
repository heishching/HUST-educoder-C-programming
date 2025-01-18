/*输入A,B,C三位学生的考试分数，输出分数居中的学生的姓名（用A、B或C表示）以及他的分数。如果出现相同分数的情况，按A、B和C的次序输出前面一个学生的姓名。
####相关知识

为了完成本关任务，你需要掌握：

基本的输入输出格式；
if语句。
根据提示，在右侧Begin-End区域编写一个完整满足任务要求的程序*/
/********** Begin **********/
#include<stdio.h>
int main(){
    int score[3];
    char name;
    scanf("%d %d %d",&score[0],&score[1],&score[2]);
    if (score[0]==score[1]&&score[1]==score[2])
        name='A';
    else if (score[0]==score[1]||score[0]==score[2])
        name='A';
    else if (score[1]==score[2])
        name='B';
    else if (score[0]>score[1]){
         if(score[1]>score[2])
            name='B';
         else{
            if(score[0]>score[2])
                name='C';
            if(score[0]<score[2])
                name='A';
         }
    }
    else{
        if(score[1]<score[2])
            name='B';
         else{
            if(score[0]>score[2])
                name='A';
            if(score[0]<score[2])
                name='C';
         }
    }
    printf("%c ",name);
    printf("%d",score[name-'A']);
    return 0;
}
/**********  End **********/