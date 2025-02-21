//
// Created by 35861 on 25-1-2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(char *str, char *ans, int str_len, int ans_len);
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        char *str = (char *)malloc((n + 1) * sizeof(char));
        scanf("%s", str + 1);
        char *ans = (char *)malloc(2 * (n + 1) * sizeof(char));
        scanf("%s", ans + 1);
        int len = strlen(ans + 1);
        if (check(str, ans, n, len)) {
            printf("Correct.\n");
        }
        else {
            printf("Wrong Answer!\n");
        }
        free(str);
        free(ans);
    }
    return 0;
}
int check(char *str, char *ans, int str_len, int ans_len) {
    if ((str_len & 1) != (ans_len & 1)) return 0;
    int arr[100] = {0};
    int ans_point = ans_len % 2 == 0 ? ans_len / 2 : (ans_len + 1) / 2,
        str_point = str_len % 2 == 0 ? str_len / 2 : (str_len + 1) / 2 ;
    while (ans_point > 0 &&str_point > 0) {
        if (str[str_point] == '?' && str[str_len + 1 -str_point] == '?') {
            int num1 = 0, num2 = 0;
            if (ans[ans_point] != ans[ans_len + 1 - ans_point]) return 0;
            num1 += ans[ans_point] - '0';
            num2 += (ans[ans_point] - '0') * 10;
            ans_point--;
            if (ans_point == 0) return 0;
            if (ans[ans_point] != ans[ans_len + 1 - ans_point]) return 0;
            num1 += (ans[ans_point] - '0') * 10;
            num2 += ans[ans_point] - '0';
            if (arr[num1] != 0 && arr[num2] != 0)return 0;
            if (arr[num1] == 0) arr[num1] = 1;
            else arr[num2] = 1;
            ans_point--;
            str_point--;
        }
        else if (str[str_point] == '?') {
            if (ans[ans_point] != ans[ans_len + 1 - ans_point]) return 0;
            if (ans[ans_point] != str[str_len + 1 - str_point]) return 0;
            ans_point--;
            str_point--;
        }
        else if (str[str_len + 1 - str_point] == '?') {
            if (ans[ans_point] != ans[ans_len + 1 - ans_point]) return 0;
            if (ans[ans_point] != str[str_point]) return 0;
            ans_point--;
            str_point--;
        }
        else {
            if (str[str_len + 1 - str_point] != str[str_point]) return 0;
            if (ans[ans_point] != ans[ans_len + 1 - ans_point]) return 0;
            if (ans[ans_point] != str[str_len + 1 - str_point]) return 0;
            ans_point--;
            str_point--;
        }
    }
    if (str_point != 0 || ans_point != 0) return 0;
    return 1;
}