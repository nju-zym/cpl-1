//
// Created by 35861 on 24-10-25.
//
#include <stdio.h>
#include <string.h>


char str[100002];
char rev[100002];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            rev[len - i - 1] = str[i]-'A'+'a';
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            rev[len - i - 1] = str[i]-'a'+'A';
        }
        else rev[len - i - 1] = str[i];
    }
    rev[len] = '\0';
    printf("%s", rev);
    return 0;
}