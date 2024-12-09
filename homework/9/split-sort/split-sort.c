//
// Created by 35861 on 24-12-7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}
char ** strsplit(char *s, char delim,int *count) {
    char *token;
    *count = 0;
    char **p = (char **) malloc(101 * sizeof(char *));
    for (token=strtok(s, &delim); token!=NULL; token=strtok(NULL, &delim)) {
        p[*count]=token;
        (*count)++;
    }
    return p;
}
void freestr(char **s) {
    free(s);
}
char ** strs;
char str[10002];
char delim;
int count;
int main() {
    scanf("%s", str);
    getchar();
    scanf("%c", &delim);
    strs = strsplit(str, delim,&count);
    qsort(strs, count, sizeof(char *), cmp);
    for (int i = 0; i < count; i++) {
        printf("%s\n", strs[i]);
    }
    freestr(strs);
    return 0;
}

