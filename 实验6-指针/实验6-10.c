/*实验指导书P183 程序设计第（8）题

本关任务：删除子串。*/
#include <stdio.h>
#include <string.h>

int delSubstr(char *str, const char *substr) {
    int found = 0; // 用于标记是否找到子串
    char *p = str; // 用于遍历主串
    while ((p = strstr(p, substr)) != NULL) {
        memmove(p, p + strlen(substr), strlen(p + strlen(substr)) + 1);
        found = 1; // 找到子串，设置标记为1
    }
    return found;
}

int main() {
    char str[200];
    char substr[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Remove the newline character
    if (delSubstr(str, substr)) {
        printf("%s\n", str);
        printf("1");
    } 
    else {
         printf("%s\n", str);
        printf("0");
    }

    return 0;
}