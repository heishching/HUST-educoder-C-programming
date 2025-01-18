/*输入n个整数到数组u中，再输入正整数k(0< k < n )，k将数组u的n个元素划分为u[0]，……，u[k-1]和u[k]，……，u[n-1]两段，
将两段元素交换位置但仍然存放在数组u中，输出重新排列后的数组元素。

示例如下：
假设n=7，k=3；
数组元素u[0]，……，u[6]依次为1, 2, 3, 4, 5, 6, 7；
则被交换的两段元素是：u[0]，……，u[6]交换的结果是4, 5, 6, 7, 1, 2, 3。*/
/*#include<stdio.h>
#include"Step2_stu.h"
#define SIZE 100
void move(int arr[],int n,int k);
int main()
{
	int arr[SIZE];
    int n,i,k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d",&k);
    
	move(arr,n,k);   // 交换
    
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}*/

#include<stdio.h>

void move(int arr[],int n,int k){
	/**********  Begin  **********/
    int arrf[k];
    int arrs[n-k];
    for(int i=0;i<k;i++){
        arrf[i]=arr[i];
    }
    for(int i=0;i<n-k;i++){
        arrs[i]=arr[i+k];
    }
    for(int i=0;i<n-k;i++){
        arr[i]=arrs[i];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i]=arrf[i];
    }
	/**********  End  **********/
}
