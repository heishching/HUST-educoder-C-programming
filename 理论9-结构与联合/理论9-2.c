/*设有结构体类型声明struct student{int num;char name[12];double score};num,name,score分别是学号、姓名、分数。
现有含N个元素的结构体数组s，请（1）完成函数scan，使用指针参数p依次读入各个元素的各成员值；（2）完成函数print，
使用指针参数p依次输出各个元素的各成员值,成绩保留1位小数。*/
#include<stdio.h>

struct student{
    int num;
    char name[12];
    double score;
};

/****在下面定义函数scan，对结构数组初始化******/
void scan(struct student *p,int n )
{
    /**********  Begin  **********/
    for(int i=0;i<n;i++){
        scanf("%d",&p->num);
        scanf("%s",p->name);
        //scanf("%.1f",&p->score);这是错的，score是double型
        scanf("%lf",&p->score);
        getchar();
        p++;
    }
   /**********  End  **********/
}

/****在下面定义函数print，依次输出结构数组的各成员值******/
void print(struct student *p, int n )
{
	/**********  Begin  **********/
	for(int i=0;i<n;i++){
        printf("%d ",p->num);
        printf("%s ",p->name);
        printf("%.1f",p->score);
        putchar('\n');
        p++;
    }
	/**********  End  **********/
}

/*#include"Step_stu.h"
#define N 3
int main()
{
    struct student s[N];
    scan(s,N);
    print(s,N);
    return 0;
}*/