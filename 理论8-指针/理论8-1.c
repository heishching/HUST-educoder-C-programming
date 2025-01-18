//输入10个数，用指针形式冒泡排序法对其进行升序排序，并输出排序后的结果。
#include<stdio.h>

//冒泡升序排序 ，程序的输入为 int类型数组 和数组长度 
//请在此处编辑您的代码
/**********  Begin  **********/
void bubble_sort(int *a,int n){
    int *add=a;
    int temp=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(*add>*(add+1)){
                temp=*add;
                *add=*(add+1);
                *(add+1)=temp;
            }
            add+=1;
        }
        add=a;
    }

}
/**********  End  **********/
/*#include"Step1_stu.h"
#define SIZE 100
#define N 10
void bubble_sort(int * a,int n); 
int main()
{
	int a[SIZE],i,k;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	bubble_sort(a,N);
	for(k=0;k<N;k++){
		printf("%d ",a[k]);	
	}
	return 0; 
}*/