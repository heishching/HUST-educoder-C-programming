/*实验教材P206 2.源程序修改替换 第（1）题
    给定一批整数，以 0 为结束标志且不作为结点，将其建成一个先进先出的链表，
    先进先出链表的头指针始终指向最先创建的结点（链头），先建结点指向后建结点，后建结点始终是尾结点*/
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
void create_list(struct s_list **headp,int *p){//
    struct s_list *loc_head=NULL,*tail;
    if(p[0]==0);
    else {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));//建立头元素
        loc_head->data=*p++;//头元素赋值
        tail=loc_head;
        while (*p)
        {
            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
            tail=tail->next;
            tail->data=*p++;
        }
        tail->next=NULL;
        
    }
    *headp=loc_head;
}

