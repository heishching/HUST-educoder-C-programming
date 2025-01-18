/*实验教材P208 程序设计 第（7）题
本关任务：
对于程序设计第三题，进一步写出用交换结点指针域的方法升序排序的函数。菜单选项：

输入每个学生的各项信息
输出每个学生的各项信息，结果按平均成绩升序排序
修改指定学生的指定数据项的内容：
修改英语成绩
修改高等数学成绩
修改普通物理成绩
修改C语言成绩
统计每个学生的平均成绩，结果按平均成绩升序排序（保留2位小数）
输出各位学生的学号、姓名、4门课程的总成绩和平均成绩，结果平均成绩升序排序*/
/*******************************Begin*******************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    char num[20];
    char name[20];
    int score_e;
    int score_m;
    int score_p;
    int score_c;
    struct student *next;
};
void creatnode(struct student **head,struct student **tail);
void printnode(struct student **head);
void changescore(struct student *head);
void average(struct student **head);
void sum_aver(struct student **head);
void sort(struct student **head);
int main(){
    int choice,sta=0;//sta统计当前链表总数
    struct student *head=NULL,*tail=NULL;//别忘了初始化
    while(1){
        scanf("%d",&choice);
        getchar();
        if(choice==0) break;
        else{
           switch(choice){
               case 1:creatnode(&head,&tail);break;
               case 2:printnode(&head);break;
               case 3:changescore(head);break;
               case 4:average(&head);break;
               case 5:sum_aver(&head);break;
           }
       }
    }
    return 0;
}
void creatnode(struct student **head,struct student **tail){
    struct student *t_head,*t_tail,*p;
    int n;
    t_head=*head;
    t_tail=*tail;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p=(struct student *)malloc(sizeof(struct student));
        scanf("%s %s %d %d %d %d",p->num,p->name,&p->score_e,&p->score_m,&p->score_p,&p->score_c);
        getchar();
        //if(head==NULL) t_head=p;这里用t_head的目的是防止错误修改，head子啊程序结束前没有更新；程序内部必须用t_head判断
        if(t_head==NULL) t_head=p;
        else t_tail->next=p;
        t_tail=p;
    }
    t_tail->next=NULL;
    *head=t_head;
    *tail=t_tail;
    return;
}
void printnode(struct student **head){
    struct student* p;
    sort(head);
    for(p=*head;p;p=p->next){
        printf("%s %s %d %d %d %d\n",p->num,p->name,p->score_e,p->score_m,p->score_p,p->score_c);
    }
}
void changescore(struct student *head){
    char num_c[20];
    int subject,change;
    struct student *p;
    scanf("%s %d %d",num_c,&subject,&change);
    getchar();
    for(p=head;p!=NULL;p=p->next){
        if(strcmp(num_c,p->num)==0){
            switch(subject){
                case 1:p->score_e=change;break;
                case 2:p->score_m=change;break;
                case 3:p->score_p=change;break;
                case 4:p->score_c=change;break;
            }
        }
    }
}
void average(struct student **head){
    struct student *p;
    double aver;
    sort(head);
    for(p=*head;p!=NULL;p=p->next){
        aver=(double)(p->score_c+p->score_e+p->score_p+p->score_m)/4.0;
        printf("%s %s %.2f\n",p->num,p->name,aver);
    }
}
void sum_aver(struct student **head){
    struct student *p;
    double aver;
    int sum;
    sort(head);
    for(p=*head;p!=NULL;p=p->next){
        sum=p->score_c+p->score_e+p->score_p+p->score_m;
        aver=(double)sum/4.0;
        printf("%s %s %d %.2f\n",p->num,p->name,sum,aver);
    }
}
void sort(struct student **head){
    struct student *t_head,*p,*last,*tail;
    t_head=(struct student *)malloc(sizeof(struct student));//补充一个没有数据域的头节点；方便后面排序
    t_head->next=*head;
    for(tail=NULL;t_head->next!=tail;tail=p){//每次第二层循环结束时；p以及其后的节点都已归位；下一次循环到这里即可
        for(last=t_head,p=t_head->next;p->next!=tail;last=p,p=p->next){
            if((p->score_c+p->score_e+p->score_p+p->score_m)>(p->next->score_c+p->next->score_e+p->next->score_p+p->next->score_m)){
                last->next=p->next;
                p->next=p->next->next;
                last->next->next=p;//交换
                p=last->next;//p回退一个节点，用于衔接第二层for循环的last=p,p=p->next
            }
        }
    }
    *head=t_head->next;
    free(t_head);
}
/*******************************End*******************************/