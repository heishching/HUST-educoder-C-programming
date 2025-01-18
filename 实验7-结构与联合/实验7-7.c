/*实验教材P207 程序设计 第（4）题
本关任务：
回文字符串是正读和反读都相同的字符串，例如“abba”和“abcba”是回文字符串。设计程序判断输入的任意长度的字符串是否为回文字符串。
提示：由于要求字符串长度任意，所以用单链表存储字符串，即判断一个单链表是否为回文链表。

编程要求
根据题目要求，在右侧编辑器中两个函数的算法设计。

void createLinkList(C_NODE **headp, char s[]) 根据字符串s构造单链表，得到一个以单链表表示的字符串，单链表结点定义见右侧编辑器。
void judgePalindrome(C_NODE *head) 判断以head为头指针的单链表表示的字符串是否为回文，是则显示true，否则显示false。*/
/*测试程序定义了如下结点类型
typedef struct c_node{
    char data;  struct c_node *next;
} C_NODE;
*******************************/
#include<stdlib.h>
void createLinkList(C_NODE * *headp, char s[]) {
    int n = strlen(s);
    C_NODE* p, * head = NULL, * tail=NULL;
    for (int i = 0; i < n; i++) {
        p = (C_NODE*)malloc(sizeof(C_NODE));
        p->data = s[i];
        if (head == NULL) head = p;
        else tail->next = p;
        tail = p;
    }
    tail->next = NULL;
    *headp = head;
}
//采用快慢指针法判断
void judgePalindrome(C_NODE* head) {
    C_NODE* fast = head, * slow = head, * pre = head, * prepre = NULL;
    if (head == NULL || head->next == NULL) printf("true");
    else {
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }//快指针一次走两个；慢指针一次走一个；同时利用prepre反转前半部分
        if (!fast==NULL) slow = slow->next;//奇数情况下，慢指针后移一位
        while (pre != NULL && slow != NULL) {//pre,slow从中间开始比较
            if (pre->data != slow->data) {
                printf("false");
                return;
            }
            pre = pre->next;
            slow = slow->next;
        }
        printf("true");
    }
}
/*#include "stdio.h"
#include "string.h"
typedef struct c_node{
    char data;
    struct c_node *next;
} C_NODE;    
int main()  
{
char s[1000],*pc=s;
int len=0;
C_NODE *head,*p;
scanf("%[^\n]",s);
createLinkList(&head,s);   
for(p=head;p;p=p->next) len++;
if (len!=strlen(s)) { printf("单链表长度不正确");return 1;}
else for(p=head;p;p=p->next)
        if (p->data!=*pc++) { printf("单链表有错误结点");return 1;}
judgePalindrome(head);
return 1;
}*/