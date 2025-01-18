/*实验教材P63 程序设计第(6)题
读入无符号长整型数表示的互联网IP地址，对其译码，以常见的点分十进制形式输出。*/
#include <stdio.h>

// 函数声明
void decodeIP(unsigned long ip);

int main() {
    unsigned long ip;   
    // 循环读取和解码IP地址，直到输入Ctrl+Z
    while (scanf("%lu", &ip) != EOF) {
        decodeIP(ip);
    }
    
    return 0;
}

// 函数定义：解码IP地址
void decodeIP(unsigned long ip) {
    unsigned char bytes[4];
    bytes[0] = (ip >> 24) & 0xFF; // 提取最高8位
    bytes[1] = (ip >> 16) & 0xFF; // 提取次高8位
    bytes[2] = (ip >> 8) & 0xFF;  // 提取次低8位
    bytes[3] = ip & 0xFF;         // 提取最低8位

    // 输出点分十进制形式的IP地址
    printf("%u.%u.%u.%u\n", bytes[0], bytes[1], bytes[2], bytes[3]);
}