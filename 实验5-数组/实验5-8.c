/*实验指导书 P142 程序设计第（3）题
本关任务：对第（2）题的程序增加查找功能（功能编号4）：输入一个C语言课程成绩值，用二分查找进行搜索。
如果查找到有该成绩，则输出该成绩所有学生的姓名和C语言课程的成绩；否则，输出提示"not found"。*/
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
void findStudent(char name[200][50], int score[], int count){
    int change;
    int find;
    int result[200];
    int find_count=0;
    scanf("%d",&find);
    for(int i=0;i<200;i++){
        if(score[i]==find){
            result[find_count]=i;
            find_count++;
        }
    }
    if(find_count>1){
        for(int i=0;i<find_count-1;i++){
            for(int j = 0; j < find_count - 1 - i; j++){
                if(strcmp(name[result[j]], name[result[j + 1]]) > 0){
                    result[j]=change;
                    result[j]=result[j+1];
                    result[j+1]=change;
                }
            }
        }
    }
    if(find_count==0){
        printf("not found");
    }
    else{
        for(int i=0;i<find_count;i++){
            printf("%s %d\n",name[result[i]],find);
        }
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
            case 4:
                findStudent(name, score, count);
        }
    }
}