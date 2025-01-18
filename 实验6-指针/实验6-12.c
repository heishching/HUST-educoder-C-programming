/*实验指导书P183 程序设计第（12）题

本关任务：函数调度。*/
#include<stdio.h>
#include<string.h>
void task0(){
    printf("task0 is called!\n");
}
void task1(){
    printf("task1 is called!\n");
}
void task2(){
    printf("task2 is called!\n");
}
void task3(){
    printf("task3 is called!\n");
}
void task4(){
    printf("task4 is called!\n");
}
void task5(){
    printf("task5 is called!\n");
}
void task6(){
    printf("task6 is called!\n");
}
void task7(){
    printf("task7 is called!\n");
}
void scheduler(void){
    char input[100];
    scanf("%s",input);
    int n;
    n=strlen(input);
    void(*fun[n])(void);//定义一个长n的数组，元素是返回void的函数，这个函数输入是void
    for(int i=0;i<n;i++){
        switch(input[i]-'0'){
            case 0:fun[i]=task0;break;
            case 1:fun[i]=task1;break;
            case 2:fun[i]=task2;break;
            case 3:fun[i]=task3;break;
            case 4:fun[i]=task4;break;
            case 5:fun[i]=task5;break;
            case 6:fun[i]=task6;break;
            case 7:fun[i]=task7;break;
        }
    }
    execute(fun,n);//这里把数组名当作指针，即数组名是二级指针
}
void execute(void(**fun)(void),int n){//传递一个指向函数指针的指针
    for(int i=0;i<n;i++){
        fun[i]();
    }
}
int main(){
    scheduler();
    return 0;
}