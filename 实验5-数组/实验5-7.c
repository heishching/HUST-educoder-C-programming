/*实验指导书 P142 程序设计第（2）题
本关任务：编写一个C程序，要求采用模块化设计思想，将相关功能用函数实现，并提供菜单选项，每次程序运行结束后需通过功能0退出程序。该程序具有以下功能：

退出程序；
输入n个学生的姓名和C语言课程的成绩；
将成绩按从高到低的次序排序，姓名同时进行相应调整（成绩相同的按姓名首字母排序，首字母相同的按第二个字母排序，依次类推）；
输出所有学生的姓名和C语言课程的成绩*/
#include <stdio.h>
#include <string.h>

int inputStudents(char name[200][50], int score[], int *count) {
    scanf("%d", count);
    for(int i = 0; i < *count; i++) {
        scanf("%s", name[i]);
        scanf("%d", &score[i]);
    }
    return *count;
}

void sortStudents(char name[200][50], int score[], int count) {
    int changescore;
    char changename[50];
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - 1 - i; j++) {
            // 降序排列成绩
            if(score[j] < score[j + 1]) {
                changescore = score[j];
                score[j] = score[j + 1];
                score[j + 1] = changescore;
                strcpy(changename, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], changename);
            }
            // 成绩相等时，按姓名升序排序
            else if(score[j] == score[j + 1] && strcmp(name[j], name[j + 1]) > 0) {
                strcpy(changename, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], changename);
            }
        }
    }
}

void printStudents(char name[200][50], int score[], int count) {
    for(int i = 0; i < count; i++) {
        printf("%s %d\n", name[i], score[i]);
    }
}

int main() {
    char name[200][50];
    int score[200];
    int count = 0;
    int choice;

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                return 0;
            case 1:
                inputStudents(name, score, &count);
                break;
            case 2:
                sortStudents(name, score, count);
                break;
            case 3:
                printStudents(name, score, count);
                break;
        }
    }
}