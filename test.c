//
// Created by 35861 on 24-11-17.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX 600
int n;
int vec[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
char map[MAX][MAX][MAX];
typedef struct illegallocation {
    int x, y, z;
} illegallocation;
illegallocation illegal[35];
int illegalsum;
int valid(int x, int y, int z) {
    return x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n;
}
int alillegal(int x, int y, int z) {
    for (int i = 0; i < illegalsum; i++) {
        if (illegal[i].x == x && illegal[i].y == y && illegal[i].z == z) {
            return 1;
        }
    }
    return 0;
}
int count(int x, int y, int z) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int x1 = x + vec[i][0], y1 = y + vec[i][1], z1 = z + vec[i][2];
        if (valid(x1, y1, z1) && map[x1][y1][z1] == '*') {
            sum++;
        }
    }
    return sum;
}
void check() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (map[i][j][k] != '*' && map[i][j][k] != '?') {
                    int num1 = count(i, j, k);
                    if (num1 != map[i][j][k] - '0') {
                        illegal[sum].x = i;
                        illegal[sum].y = j;
                        illegal[sum].z = k;
                        sum++;
                    }
                }
            }
        }
    }
    illegalsum = sum;
}
int compare(const void *a, const void *b) {
    illegallocation *ia = (illegallocation *)a;
    illegallocation *ib = (illegallocation *)b;
    if (ia->x != ib->x) return ia->x - ib->x;
    if (ia->y != ib->y) return ia->y - ib->y;
    return ia->z - ib->z;
}
int main() {
    scanf("%d", &n);
    getchar();
    int qx = -1, qy = -1, qz = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                map[i][j][k] = getchar();
                if (map[i][j][k] == '?') {
                    qx = i;
                    qy = j;
                    qz = k;
                }
            }
        }
    }
    check();
    if (illegalsum == 0) {
        int qsum = count(qx, qy, qz);
        map[qx][qy][qz] = qsum + '0';
        printf("valid\n");
        printf("%d\n", qsum);
        return 0;
    }
    map[qx][qy][qz] = '*';
    for (int i = 0; i < 6; i++) {
        int x1 = qx + vec[i][0], y1 = qy + vec[i][1], z1 = qz + vec[i][2];
        if (valid(x1, y1, z1) && map[x1][y1][z1] != '*' && map[x1][y1][z1] != '?') {
            int num1 = count(x1, y1, z1);
            if (num1 != map[x1][y1][z1] - '0') {
                if (!alillegal(x1, y1, z1)) {
                    illegal[illegalsum].x = x1;
                    illegal[illegalsum].y = y1;
                    illegal[illegalsum].z = z1;
                    illegalsum++;
                }
            }
        }
    }
    int flag1 = 1;
    for (int j = 0; j < illegalsum; j++) {
        int tempflag = 0;
        for (int i = 0; i < 6; i++) {
            int x1 = qx + vec[i][0], y1 = qy + vec[i][1], z1 = qz + vec[i][2];
            if (valid(x1, y1, z1) && x1 == illegal[j].x && y1 == illegal[j].y && z1 == illegal[j].z) {
                tempflag = 1;
                break;
            }
        }
        if (tempflag == 0) {
            flag1 = 0;
            break;
        }
    }
    int flag2 = 1;
    for (int i = 0; i < 6; i++) {
        int x1 = qx + vec[i][0], y1 = qy + vec[i][1], z1 = qz + vec[i][2];
        if (valid(x1, y1, z1)) {
            if (map[x1][y1][z1] != '*' && map[x1][y1][z1] != '?') {
                int num1 = count(x1, y1, z1);
                if (num1 != map[x1][y1][z1] - '0') {
                    flag2 = 0;
                    break;
                }
            }
        }
    }
    if (flag1 == 1 && flag2 == 1) {
        printf("valid\n");
        printf("*\n");
    } else {
        printf("invalid\n");
        qsort(illegal, illegalsum, sizeof(illegallocation), compare);
        for (int i = 0; i < illegalsum; i++) {
            printf("%d %d %d\n", illegal[i].x + 1, illegal[i].y + 1, illegal[i].z + 1);
        }
    }
    return 0;
}
