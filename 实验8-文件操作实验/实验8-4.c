/*本关任务：参考实验指导书P226,3.(2)。从键盘输入10个单精度浮点数，以二进制形式存入文件float.dat中（将此功能定义成函数）。
再从文件中读出这10个单精度浮点数,把每个单精度浮点数，按每个字节的二进制形式显示在屏幕上（将此功能定义成函数）。

根据提示，在右侧编辑器补充代码。*/
//这个是KIMI写的，再此致谢
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinary(float num) {
    unsigned char *p = (unsigned char *)&num;
    // 从最低有效字节到最高有效字节打印浮点数的二进制表示
    // 注意：这里假设系统是小端字节序
    for (int i = sizeof(float) - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (p[i] >> j) & 1);
        }
    }
    printf("\n");
}

void printfile(FILE *f) {
    float value;
    while (fread(&value, sizeof(float), 1, f) == 1) {
        printBinary(value); // 打印浮点数的二进制表示
    }
    fclose(f);
}

int main() {
    float input[10];
    for (int i = 0; i < 10; i++) {
        scanf("%f", &input[i]);
    }
    FILE *fp = fopen("float.dat", "wb+"); // 以写入模式打开文件
    if (fp == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 10; i++) {
        fwrite(&input[i], sizeof(float), 1, fp);
    }
    rewind(fp); // 重置文件指针到文件开始位置
    printfile(fp); // 打印文件内容
    return 0;
}