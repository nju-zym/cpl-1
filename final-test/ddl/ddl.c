//
// Created by 35861 on 25-1-1.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int t;
    int d;
}task;

task tasks[101];

int cmp(const void *a, const void *b);
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d%d", &t, &d);
        tasks[i].t = t;
        tasks[i].d = d;
    }
    qsort(tasks, n, sizeof(tasks[0]), cmp);
    int flag = 1;
    for (int i = 0; i < n - 1; i++) {
        if (tasks[i].d - tasks[i].t < tasks[i + 1].d) tasks[i + 1].d = tasks[i].d - tasks[i].t;
        if (tasks[i + 1].d - tasks[i + 1].t < 0) flag = 0;
    }
    if (flag) {
        printf ("%d\n", tasks[n - 1].d - tasks[n - 1].t);
        return 0;
    }
    printf("-1\n");
    return 0;
}

int cmp(const void *a, const void *b) {
    int da = (*(task *)a).d;
    int db = (*(task *)b).d;
    return (da < db) - (da > db);
}