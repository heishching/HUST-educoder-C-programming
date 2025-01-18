本关任务：编程实现
（1）用一个单向链表接收一个长字符串，且每个节点接收一个字符，遍历输出链表中的所有字符，并将字符串无冗余地存放到一个动态存储分配的的字符数组中，并且输出该字符串。（本题暂不考虑空字符串情况）(结尾以回车结束)
（2）再输入一个字符，如果该字符已在链表中，则删除该结点，否则在输入字符和结点的数据域字符差值最小的结点后面插入包含该字符的结点，输出最后的字符串。

要求：采用模块化设计方法，将创建链表、遍历链表、删除结点、插入结点等功能用函数实现。
#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	char value;
	struct _node* next;
}Node;

typedef struct list {
	Node* head;
}List;

void add(List* plist, char number);
void print(List list);
void print_(List list);
int delete(List* plist, char number);
int compare(List* plist, char number);
void insert(List* plist, int order, char number);
char absolute_value(char a);

int main()
{
	List list = { NULL };
	char c;
	while ((c = getchar()) != '\n') {
		add(&list, c);
		//printf("%c", c);
	}

	print_(list);
	print(list);

	int a;
	char c1;
	scanf("%c", &c1);
	//printf("%c", c1);
	a = delete(&list, c1);
	//printf("%c", c1);

	if (!a) {
		int order;
		order = compare(&list, c1);
		insert(&list, order, c1);
	}
	print(list);

	return 0;
}

void add(List* plist, char number)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->value = number;
	Node* last = plist->head;
	if (!last)
		plist->head = p;
	else {
		while (last->next)
			last = last->next;
		last->next = p;
	}
	return;
}

void print(List list)
{
	for (Node* p = list.head; p; p = p->next) {
		printf("%c", p->value);
	}
	printf("\n");
}

void print_(List list)
{
	for (Node* p = list.head; p; p = p->next) {
		printf("%c ", p->value);
	}
	printf("\n");
}


int delete(List* plist, char number)
{
	Node* p, * q;
	int ret = 0;
	for (q = NULL, p = plist->head; p; q = p, p = p->next) {
		if (p->value == number) {
			if (!q) {
				plist->head = p->next;
				free(p);
			}
			else {
				q->next = p->next;
				free(p);
			}
			ret = 1;
			break;
		}
	}
	return ret;
}

int compare(List* plist, char number)//List* plist头指针
{
	Node* p;
	int mindv = (plist->head)->value;
	int order = 0;
	int i = 0;
	for (p = plist->head; p; p = p->next, i++) {
		if (absolute_value((char)((p->value) - number)) < mindv) {
			mindv = absolute_value((p->value) - number);
			order = i;
		}
	}
	return order;//插入位置
}

void insert(List* plist, int order, char number)
{
	Node* p = plist->head;
	int i;
	for (i = 0; i < order; i++) {
		p = p->next;
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->value = number;
	if (!(p->next))
		p->next = q;
	else {
		q->next = p->next;
		p->next = q;
	}
}

char absolute_value(char a)
{
	a = (a > 0 ? a : (-a));
	return a;
}
/*这是我自己写的，但测试三过不了
#include<stdio.h>
#include<stdlib.h>
struct node {
    char a;
    struct node* next;
};

struct node* creatlist(void) {//先进先出链表
    struct node* head, * tail, * p;
    char x;//临时存储输入
    head = NULL;
    tail = NULL;
    scanf("%c", &x);
    while (x != '\n') {
        //printf("%c ", x);
        p = (struct node*)malloc(sizeof(struct node));
        p->a = x;
        if (head == NULL) head = p;
        else tail->next = p;
        tail = p;
        scanf("%c", &x);
    }
    putchar('\n');
    if (tail != NULL) tail->next = NULL;//尾节点置空
    return head;
}

void printnode(struct node* head) {
    struct node* p = head;
    while (1) {
        printf("%c", p->a);
        if (p->next == NULL) break;
        else p = p->next;
    }
}

int delnode(char d, struct node** headp) {//指向指针的指针；用于在删除首节点时修改首节点；返回的int用于记录是否实施了删除操作
    struct node* p, * temp;
    p = *headp;
    struct node* last = NULL;
    int is_del = 0;
    while (p != NULL) {
        if (p->a == d) {
            if (p == *headp) {
                *headp = p->next;
                p = p->next;
                temp = p;
            }
            else {
                temp = p;
                last->next = p->next;
                p = p->next;
            }
            free(temp);
            is_del = 1;
            //break;
        }
        else {
            last = p;
            p = p->next;
        }
    }
    return(is_del);
}

void insert(char x, struct node* head) {
    struct node* p, * posi, * temp;
    p = head;
    int distance = 0;
    while (p != NULL) {
        if (distance == 0) {
            distance = abs(p->a - x);
        }
        else if (abs(p->a - x) < distance) {
            distance = abs(p->a - x);
        }
        p = p->next;
    }
    p = head;
    while (p != NULL) {
        if (distance == abs(p->a - x)) {
            temp = (struct node*)malloc(sizeof(struct node));
            temp->a = x;
            temp->next = p->next;
            p->next = temp;
            p = temp;
        }
        p = p->next;
        //根据实测，测试集二是有多个位置需要插入的情况，因为我在这里加了break后二就过不了
    }
}

int main() {
    struct node* head;
    char x;
    head = creatlist();
    scanf("%c", &x);
    //printnode(head);
    //putchar('\n');
    if (!delnode(x, &head)) {
        insert(x, head);
    }
    printnode(head);
    return 0;
}*/