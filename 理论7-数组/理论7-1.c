//使用选择法排序编写一个能为数组进行升序排序的程序
#include<stdio.h>
/*****请在下面补充函数 inArray、selectSort 和 outArray 的定义 *****/
//输入数组的n个元素
void inArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
//使用选择法对数组元素进行升序排序
void selectSort(int arr[], int n) {
    int max = 0;
    int serial_max = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= (n-i-1); j++) {//find the max and its serial num
            if (arr[j] > max) {
                max = arr[j];
                serial_max = j;
            }
        }
        if (serial_max != n - 1 - i) {
            arr[serial_max] = arr[n - 1 - i] + arr[serial_max];//exchange
            arr[n - 1 - i] = arr[serial_max] - arr[n - 1 - i];
            arr[serial_max] = arr[serial_max] - arr[n - 1 - i];
        }
        max = 0;
        serial_max = 0;
    }
}

//输出数组的n个元素
void outArray(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        printf("%d ", arr[i]);
    }
}


/*#include"Step1_stu.h"
#define SIZE 100
void inArray(int arr[],int n);
void selectSort(int arr[],int n);
void outArray(int arr[],int n);
int main()
{
	
	int arr[SIZE],n,i;
	scanf("%d", &n);   // 输入元素个数
	
    inArray(arr,n);  // 输入数组的n个元素
    
	selectSort(arr,n);  //  对数组元素排序
    
    outArray(arr,n);   // 输出数组的n个元素
  
	return 0; 
    }*/

