//
// Created by 35861 on 24-11-17.
//
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! Let's explore strtok.";
    const char *delimiters = " ,!.";

    // 获取第一个子串
    char *token = strtok(str, delimiters);

    // 继续获取其他的子串
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiters); // 注意传递NULL来获取下一个子串
    }

    return 0;
}