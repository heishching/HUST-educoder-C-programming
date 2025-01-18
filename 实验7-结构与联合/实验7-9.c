/*实验教材P207 程序设计 第（9）题
本关任务：
利用值栈对逆波兰表达式进行求值。逆波兰表达式从键盘输入，其中的运算符仅包含加、减、乘、除4种运算，
表达式中的数都是十进制数，用换行符结束输入。由于逆波兰表达式的长度不限，所以值栈要用后进先出链表实现。*/
/********************************Begin********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct stack {
	int data;
	struct stack* next;
}StackNode,*Linkstackptr;

typedef struct {
	Linkstackptr top;
	int count;
}Linkstack;
//定义一个栈节点结构体 StackNode 和指向该结构体的指针类型 Linkstackptr。还有一个 Linkstack 结构体，包含一个指向栈顶的指针 top 和一个表示栈中元素数量的 count
void push(Linkstack*s,int n);//用于将一个整数压入栈中
int pop(Linkstack* s);

int main()
{
	Linkstack rpn;
	rpn.count = 0;
	rpn.top = NULL;

	char c[5];
	int a, b;
	char x;
	do {
		scanf("%s", c);
		x = getchar();
			int len = strlen(c);
			int flag = 1;
			if(len == 1)
				if (!isdigit(c[0]))
					flag = 0;
			//printf("%d", flag);
			if (flag)
				push(&rpn, atoi(c));
			else {
				switch (c[0]) {
				case '+':
					push(&rpn, (pop(&rpn) + pop(&rpn)));
					break;
				case '-':
					a = pop(&rpn);
					b = pop(&rpn);
					push(&rpn, (b - a));
					break;
				case '*':
					push(&rpn, (pop(&rpn) * pop(&rpn)));
					break;
				case '/':
					a = pop(&rpn);
					b = pop(&rpn);
					push(&rpn, (b / a));
					break;
				}
			}//程序检查 c 是否是一个单个数字，如果是，则将其转换为整数并压入栈中。如果不是数字，根据 c 中的操作符执行相应的运算，并将结果压入栈中
			//putchar(x);
			//printf("%d\n",(rpn.top)->data);
			//printf("here\t");
	
		
	} while (x != '\n');
	printf("%d", (rpn.top)->data);

	return 0;
}

void push(Linkstack* s,int n)//push 函数定义，它分配一个新的栈节点，将数据 n 存储在节点中，并将节点插入到栈顶。
{
	Linkstackptr temp = (Linkstackptr)malloc(sizeof(StackNode));
	temp->data = n;
	temp->next = s->top;
	s->top = temp;
	s->count++;
	return;
}

int pop(Linkstack* s)// pop 函数定义，它从栈顶移除一个元素并返回其值。
{
	int n = s->top->data;
	Linkstackptr p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return n;
}
/*这是自己写的代码，有问题
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bo{
    char data[10];
    struct bo *next;
};
void findnum(struct bo **p,int *a,int *b);
void creatnode(struct bo **head);
int calculate(struct bo **p);

void creatnode(struct bo **head){
    struct bo *headp,*p;
    char input[10];
    headp=NULL;
    while(1){
        scanf(" %s ",input);
        if(input[0]=='\n') break;
        else{
            p=(struct bo*)malloc(sizeof(struct bo));
            if (headp==NULL) {
                headp=p;
                headp->next=NULL;
            }
            else{
                p->next=headp;
                headp=p;
            }
        }
        strcpy(p->data,input);
    }
    *head=headp;
}

int calculate(struct bo **p){
    struct bo *pt=*p;
    int a,b,result=0;
    if(pt->data[0] >= '0' && pt->data[0] <= '9') {
        result=atoi(pt->data);
        *p = pt->next;
    }
    else{
        findnum(p,&a,&b);
        if(pt->data[0]=='+') result=a+b;
        if(pt->data[0]=='-') result=a-b;
        if(pt->data[0]=='*') result=a*b;
        if(pt->data[0]=='/') result=a/b;
        //*p = pt->next;
    }
    return result;
}

void findnum(struct bo **p,int *a,int *b){
    struct bo *p0=*p;
    p0=p0->next;
    if(p0->data[0] >= '0' && p0->data[0] <= '9'){
        *a=atoi(p0->data);
    }
    else *a=calculate(p0);
    p0=p0->next;
    if(p0->data[0] >= '0' && p0->data[0] <= '9'){
        *b=atoi(p0->data);
    }
    else *b=calculate(p0);
    *p=p0;
}

int main(){
    struct bo *head;
    int result=0;
    creatnode(&head);
    result=calculate(&head);
    printf("%d",result);
    while (head != NULL) {
        struct bo *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}*/
/********************************End********************************/