//
// Created by 35861 on 24-12-20.
//
#include <stdio.h>
#include <string.h>

int arr[1002];
void sort(int x) {
    int temp = arr[x];
    for (int i = x; i >= 2; i--) {
        arr[i] = arr[i - 1];
    }
    arr[1] = temp;
}
int sorted(int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i + 1])return 0;
    }
    return 1;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 1; i <= m; i++) {
            int x;
            scanf("%d", &x);
            sort(x);
        }
        if (sorted(n)) {
            printf("I love C programming language\n");
        }
        else {
            printf("mayi is a good teacher\n");
        }
        //memset (arr, 0, sizeof (arr));
    }
    return 0;
}