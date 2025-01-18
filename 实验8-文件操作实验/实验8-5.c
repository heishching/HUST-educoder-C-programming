/*本关任务：对实验七程序设计第2题的程序，增加文件保存和文件打开的功能选项，用函数实现这两个功能。在原有功能选项的基础上，增加6、7两项功能。
0.退出
1.输入每个学生的各项信息
2.输出每个学生的各项信息
3.修改指定学生的指定数据项的内容：
    1.修改英语成绩
    2.修改高等数学成绩
    3.修改普通物理成绩
    4.修改C语言成绩
4.统计每个学生的平均成绩（保留2位小数）
5.输出各位学生的学号、姓名、4门课程的总成绩和平均成绩
6.文件保存功能：将链表结点中学生的各项信息保存到二进制文件stu.dat
7.文件打开功能：从文件stu.dat中读取学生信息到内存建立链表。

可以选择原题中的输出功能将这些信息显示在平面上，以验证读写操作的正确性。*/
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
void printnode(struct student *head);
void changescore(struct student *head);
void average(struct student *head);
void sum_aver(struct student *head);
void creatfromfile(struct student **head,struct student **tail);
void storenodefile(struct student *head);
int main(){
    int choice;
    struct student *head=NULL,*tail=NULL;//别忘了初始化
    while(1){
        scanf("%d",&choice);
        getchar();
        if(choice==0) break;
        else{
           switch(choice){
               case 1:creatnode(&head,&tail);break;
               case 2:printnode(head);break;
               case 3:changescore(head);break;
               case 4:average(head);break;
               case 5:sum_aver(head);break;
               case 6:storenodefile(head);break;
               //case 7:creatfromfile(&head,&tail);break;
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
void printnode(struct student *head){
    struct student* p;
    for(p=head;p;p=p->next){
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
void average(struct student *head){
    struct student *p;
    double aver;
    for(p=head;p!=NULL;p=p->next){
        aver=(double)(p->score_c+p->score_e+p->score_p+p->score_m)/4.0;
        printf("%s %s %.2f\n",p->num,p->name,aver);
    }
}
void sum_aver(struct student *head){
    struct student *p;
    double aver;
    int sum;
    for(p=head;p!=NULL;p=p->next){
        sum=p->score_c+p->score_e+p->score_p+p->score_m;
        aver=(double)sum/4.0;
        printf("%s %s %d %.2f\n",p->num,p->name,sum,aver);
    }
}
void creatfromfile(struct student **head, struct student **tail) {
    struct student *t_head, *t_tail, *p;
    int n;
    FILE *fp;
    struct student temp; // 临时结构体用于存储文件中读取的数据

    t_head = *head;
    t_tail = *tail;
    scanf("%d", &n);
    getchar(); // 吸收换行符

    fp = fopen("stu.dat", "rb");
    if (fp == NULL) {
        printf("File opening failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        p = (struct student *)malloc(sizeof(struct student));
        if (fread(&temp, sizeof(struct student), 1, fp) != 1) {
            printf("Error reading file.\n");
            free(p);
            break;
        }
        strcpy(p->num, temp.num);
        strcpy(p->name, temp.name);
        p->score_e = temp.score_e;
        p->score_m = temp.score_m;
        p->score_p = temp.score_p;
        p->score_c = temp.score_c;
        p->next = NULL; // 设置新节点的 next 为 NULL

        if (t_head == NULL) {
            t_head = p; // 如果头节点为空，则设置新节点为头节点
        } else {
            t_tail->next = p; // 将新节点链接到链表的末尾
        }
        t_tail = p; // 更新尾节点为新节点
    }

    if (t_tail != NULL) {
        t_tail->next = NULL; // 确保链表的末尾 next 为 NULL
    }

    *head = t_head;
    *tail = t_tail;
    fclose(fp);
}
void storenodefile(struct student *head){
    struct student* p;
    FILE *fp;
    fp=fopen("stu.dat","wb"); // 修改为 "wb" 模式
    for(p=head; p != NULL; p = p->next){
        fwrite(p, sizeof(struct student), 1, fp); // 正确写入结构体数据
    }
    fclose(fp);
}