/*本关任务：编写一个程序replace，采用命令行的方式，用给定的字符串替换指定文件中的目标字符串，替换后保存在out.txt中。
  你不需要输出out.txt中的内容，由平台输出。*/
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这题我也不会，抄的
// Function to replace all occurrences of 'target' with 'replacement' in 'haystack'
char* replace_str(const char *haystack, const char *target, const char *replacement) {
    size_t target_len = strlen(target);
    size_t replacement_len = strlen(replacement);
    char *result = NULL;
    const char *tmp;
    char *res;
    size_t count = 0;
    size_t result_len = 0;

    // Count the number of times target appears in the haystack
    tmp = haystack;
    while ((tmp = strstr(tmp, target)) != NULL) {
        count++;
        tmp += target_len; // Move past this occurrence of target
    }

    // Calculate the length of the result
    result_len = strlen(haystack) + count * (replacement_len - target_len);

    // Allocate memory for the result
    result = (char *)malloc(result_len + 1);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    result[result_len] = '\0'; // Null-terminate the result

    // Make a second pass to actually replace the strings
    res = result;
    tmp = haystack;
    while ((tmp = strstr(tmp, target)) != NULL) {
        size_t len = tmp - haystack;
        strncpy(res, haystack, len);
        res += len;
        strcpy(res, replacement);
        res += replacement_len;
        haystack = tmp + target_len;
        tmp = haystack;
    }
    strcpy(res, haystack); // Copy the rest of the string

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <target> <replacement>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *target = argv[2];
    const char *replacement = argv[3];

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    FILE *out_file = fopen("out.txt", "w");
    if (!out_file) {
        perror("Error opening out.txt");
        fclose(file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        char *replaced = replace_str(buffer, target, replacement);
        fputs(replaced, out_file);
        free(replaced); // Free the allocated memory after writing to the file
    }

    fclose(file);
    fclose(out_file);

    return 0;
}