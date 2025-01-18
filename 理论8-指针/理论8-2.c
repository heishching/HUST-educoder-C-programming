/*从键盘输入n（n<=100）个整数并放到数组x中，编写一个函数，将数组x中的元素颠倒顺序后仍然存放在原数组中。
要求始终只用一个数组， 并且在调用函数中输出颠倒顺序后数组x中的各个元素，且在程序中不能用下标表示数组元素*/
#include<stdio.h>
//函数的输入为 int类型数组 和数组长度 
void reverseOrder(int a[ ],int n){
	//请在此处编辑您的代码
	/**********  Begin  **********/
    int temp;
    int *add1=a;
    int *add2=a;
    add2+=(n-1);
    for(int i=0;i<n/2;i++){
        temp=*add1;
        *add1=*add2;
        *add2=temp;
        add1++;
        add2--;
    }
	/**********  End  **********/
}
/*#include"Step2_stu.h"
#define SIZE 100

int main()
{

	int n,i;
	int arr[SIZE];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]); 
	} 
    
	reverseOrder(arr,n);
	
	for(i=0;i<n;i++){
		printf("%d ",arr[i]); 
	} 
	
	return 0;
}*/