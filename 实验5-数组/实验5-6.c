/*实验指导书 P142 程序设计第（1）题
本关任务：输入一个整数，将它在内存中的二进制表示的每一位转换成对应的数字字符并且存放到一个字符数组中，然后输出该整数的二进制表示（32位有符号整数，输出每4位用空格分隔）。*/
# include <stdio.h>
//Finding the binary of an integer using bitwise operations
int main() {
    int num;
    char out[32];
    int mask = 0x80000000;
    scanf("%d", &num);
    for (int i =31; i >=0; i--) {
        out[i] = num &(1<<i) ? '1' : '0';//不能直接写out[i]=num&(0x80000000)，这个式子求的是每一位位与运算得到的数
    }
    for (int j = 31; j>=0; j--) {
        printf("%c", out[j]);
        if ((32-j) % 4 == 0)printf(" ");
    }
    return 0;
}