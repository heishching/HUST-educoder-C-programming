/*本关任务（习题5.1）：模拟掷双骰子游戏，游戏规则：每轮投两次骰子，取两次的和，第一轮若和为7或11则获胜，游戏结束。

例一：
和为11，则显示：'Round 1:  Score:11  Success!'
若和为2、3或12则输了，失败结束，

例二：
和为12，则显示：'Round 1:  Score:12  Failed!'
若和为其他数字，则将第一轮两次骰子点数的和（假定为8）作为自己的点数，继续第二轮，第三轮，……，直到某轮两次骰子点数的和等于该点数（第一轮两次投掷点数和）则获胜，若中间某轮两次投掷骰子点数的和为7，则输掉游戏。对应显示：

'Round 1:  Score:8  Continue!'
'Next rounds: Score 8:Success, Score 7:Failed, others:Continue'
'Round 2:  Score:4  Continue!'
'Round 3:  Score:6  Continue!'
'Round 4:  Score:9  Continue!'
'Round 5:  Score:7  Failed!'*/
/***在下面Begin至End间，按原型 void diceGame(int randSeed) 定义函数***/
/********** Begin **********/
void diceGame(int randSeed){
    int a,b,point,state,round;
    round=2;
    state=1;
    srand((int)time(NULL));
    a=rand();
    b=rand();
    point=a+b;
    if(point==7||point==11)
        printf("Round 1: Score:%d Success!",point);
    else if(score==2||score==3||score==12)
        printf("Round 1: Score:%d Failed!",point);
    else{
        printf("Next rounds: Score 8:Success, Score 7:Failed, others:Continue");
        while(state==1){
            a=rand();
            b=rand();
            score=a+b;
            if(score==7){
                printf("Round %d: Score:%d Failed!",round,score);
                state=0;
            else if(score==point)
                printf("Round %d: Score:%d Success!",round,score);
                state=0;
            else
                printf("Round %d: Score:%d Continue!",round,score);
                state=0;
        }
    }
}

#include<stdlib.h>
#include<stdio.h>
#include "step1_stu.h"
int main()
{
	int randSeed;
    scanf("%d",&randSeed);        //输入整数作为随机数种子
    diceGame(randSeed);
    return 0;
}