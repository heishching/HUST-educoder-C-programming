//输入10个整数，统计其中正数的累加和与平均值。其中累加和输出为整数，平均值保留到小数点后一位。
#include<stdio.h>
int main()
{
	/**********  Begin  **********/
    int numbers[10]; // 存储10个整数的数组
    int sum = 0;     // 正数的累加和
    int count = 0;   // 正数的个数
    float average;  // 正数的平均值

    // 提示用户输入10个整数
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        // 如果输入的数是正数，则累加到sum，并增加正数的个数
        if (numbers[i] > 0) {
            sum += numbers[i];
            count++;
        }
    }

    // 计算平均值
    if (count > 0) {
        average = (float)sum / count;
    } else {
        average = 0; // 如果没有正数，平均值设为0
    }

    // 输出累加和和平均值
    printf("累加和:%d\n", sum);
    printf("平均值:%.1f\n", average);
 /**********  End  **********/
    return 0;
}