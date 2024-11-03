//
// Created by 35861 on 24-10-28.
//
#include <stdio.h>
#include <string.h>

#define N 1000006

char s[N];
int a[N], b[N];

// 判断字符串是否有不连续的 'Z'
int pd(char *s) {
    int flag = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'Z') flag = 1;
        if (flag == 1 && s[i] != 'Z') return 1;
    }
    return 0;
}

int main() {
    // 读取输入字符串
    scanf("%s", s);

    // 判断是否无解
    if (pd(s)) {
        printf("-1\n");
        return 0;
    }

    // 根据 s 的值构造 a 和 b
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'X') {
            a[i] = 1;
            b[i] = 0;
        } else if (s[i] == 'Y') {
            a[i] = 0;
            b[i] = 1;
        } else if (s[i] == 'Z') {
            a[i] = 1;
            b[i] = 1;
        }
    }

    // 输出 a 和 b
    for (int i = 0; i < len; i++) printf("%d", a[i]);
    printf("\n");
    for (int i = 0; i < len; i++) printf("%d", b[i]);
    printf("\n");

    return 0;
}
