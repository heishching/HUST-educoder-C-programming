/*实验教材P206 2.源程序修改替换 第（2）题
本关任务：修改替换create_list函数，将其建成一个后进先出的链表。*/
#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
};
void create_list(struct s_list **headp,int *p);
int main(void){
    struct s_list *head=NULL,*p;//p用于打印时遍历链表
    int s0[100];
    int n=0;
    int c;
    for(n=0;;){
        scanf("%d",&c);
        if(c!=0){ 
            s0[n]=c;
            n++;
        }
        else break;
    }
    s0[n]=0;
    int s[n+1];
    for(int i=0;i<=n;i++) s[i]=s0[i];
    create_list(&head,s);//
    p=head;
    while (p){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;  
}
void create_list(struct s_list **headp,int *p){
    struct s_list *loc_head=NULL,*tail,*temp;
    if(p[0]==0);
    else {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        tail=loc_head;
        while (*p)
        {
            temp=(struct s_list *)malloc(sizeof(struct s_list));
            temp->next=loc_head;
            loc_head=temp;
            temp->data=*p++;
        }
        tail->next=NULL;
    }
    *headp=loc_head;
}
