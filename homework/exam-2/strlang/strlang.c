//
// Created by 35861 on 24-12-10.
//
#include <stdio.h>
#include <string.h>

char arr[50000002];
char modify1[401], modify2[401];
char command1[401][500002];
char command2[401][500002];
int n;

void process();

void strmove(char *arr, char *temp, char *command1, char *command2);

void headstrmove(char *arr, char *temp, char *command1, char *command2);

void tailstrmove(char *arr, char *temp, char *command1, char *command2);

int main() {
    // freopen("D:/testpoints/t3-half/bracket30.in", "r", stdin);
    // freopen("D:/out.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &modify1[i]);
        getchar();
        scanf("%[^]]", command1[i]);
        getchar();
        scanf("%c", &modify2[i]);
        getchar();
        scanf("%[^]]", command2[i]);
        getchar();
    }
    scanf("%s", arr);
    process();
    printf("%s", arr);
    return 0;
}

void strmove(char *arr, char *temp, char *command1, char *command2) {
    size_t lentemp = strlen(temp), lencommand1 = strlen(command1), lencommand2 = strlen(command2);
    memmove(temp + lencommand2, temp + lencommand1, lentemp - lencommand1 + 1);
    memcpy(temp, command2, lencommand2);
}

void headstrmove(char *arr, char *temp, char *command1, char *command2) {
    size_t lenth = strlen(arr), lentemp = strlen(temp), lencommand1 = strlen(command1), lencommand2 = strlen(command2);
    memmove(temp, temp + lencommand1, lentemp - lencommand1 + 1);
    memmove(arr + lencommand2, arr, lenth + 1);
    memcpy(arr, command2, lencommand2);
}

void tailstrmove(char *arr, char *temp, char *command1, char *command2) {
    size_t lentemp = strlen(temp), lencommand1 = strlen(command1), lencommand2 = strlen(command2);
    memmove(temp, temp + lencommand1, lentemp - lencommand1 + 1);
    if (lencommand2)strcat(arr, command2);
}

void process() {
    int use = 1;
    while (use != 0) {
        use = 0;
        for (int i = 0; i < n; i++) {
            if (modify1[i] == '.') {
                char *temp = NULL;
                temp = strstr(arr, command1[i]);
                if (temp != NULL) {
                    if (modify2[i] == '.') {
                        strmove(arr, temp, command1[i], command2[i]);
                        use = 1;
                        break;
                    }
                    if (modify2[i] == '^') {
                        headstrmove(arr, temp, command1[i], command2[i]);
                        use = 1;
                        break;
                    }
                    if (modify2[i] == '$') {
                        tailstrmove(arr, temp, command1[i], command2[i]);
                        use = 1;
                        break;
                    }
                }
            }
            if (modify1[i] == '^' && strncmp(arr, command1[i], strlen(command1[i])) == 0) {
                char *temp = arr;
                if (modify2[i] == '.') {
                    strmove(arr, temp, command1[i], command2[i]);
                    use = 1;
                    break;
                }
                if (modify2[i] == '^') {
                    headstrmove(arr, temp, command1[i], command2[i]);
                    use = 1;
                    break;
                }
                if (modify2[i] == '$') {
                    tailstrmove(arr, temp, command1[i], command2[i]);
                    use = 1;
                    break;
                }
            }
            if (modify1[i] == '$' && strncmp(arr + strlen(arr) - strlen(command1[i]), command1[i], strlen(command1[i]))
                == 0) {
                char *temp = arr + strlen(arr) - strlen(command1[i]);
                if (modify2[i] == '.') {
                    strmove(arr, temp, command1[i], command2[i]);
                    use = 1;
                    break;
                }
                if (modify2[i] == '^') {
                    headstrmove(arr, temp, command1[i], command2[i]);
                    use = 1;
                    break;
                }
                if (modify2[i] == '$') {
                    tailstrmove(arr, temp, command1[i], command2[i]);
                    use = 1;
                    break;
                }
            }
        }
    }
}
