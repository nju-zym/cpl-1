//
// Created by 35861 on 25-1-1.
//
#include <stdio.h>

int map[51][51];
int out[51];
int stuck(int i, int j);
int m, n;
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int row = 0, col = i;
        while (row < m && col < n) {
            if (stuck(row, col)) {
                out[i] = -1;
                break;
            }
            col += map[row][col];
            row++;
        }
        if (out[i] == 0) out[i] = col;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    return 0;
}
int stuck(int i, int j) {
    if (map[i][j] == 1 && j + 1 == n) return 1;
    if (map[i][j] == -1 && j == 0)  return 1;
    if (map[i][j] == 1 && map[i][j + 1] == -1) return 1;
    if (map[i][j] == -1 && map[i][j - 1] == 1) return 1;
    return 0;
}