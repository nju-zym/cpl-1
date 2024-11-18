//
// Created by 35861 on 24-11-17.
//
#include <stdio.h>
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

int count(int x, int y, int z) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        const int x1 = x + vec[i][0];
        const int y1 = y + vec[i][1];
        const int z1 = z + vec[i][2];
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
    int flag1 = 1, flag2 = 1;
    for (int i = 0; i < 6; i++) {
        int x1 = qx + vec[i][0];
        int y1 = qy + vec[i][1];
        int z1 = qz + vec[i][2];
        if (valid(x1, y1, z1) != 1 || map[x1][y1][z1] == '*') continue;
        int sum = count(x1, y1, z1);
        if (sum != map[x1][y1][z1] - '0') flag1 = 0;
        if (sum != map[x1][y1][z1] - '0' - 1) flag2 = 0;
    }
    if (flag1) {
        check();
        int qsum = count(qx, qy, qz);
        map[qx][qy][qz] = qsum + '0';
        if (illegalsum == 0) {
            printf("valid\n");
            printf("%d\n", qsum);
            return 0;
        }
    }
    else if (flag2) {
        map[qx][qy][qz] = '*';
        check();
        if (illegalsum == 0) {
            printf("valid\n*\n");
            return 0;
        }
    }
        map[qx][qy][qz] = '*';
        check();
        printf("invalid\n");
        for (int i = 0; i < illegalsum; i++) {
            printf("%d %d %d\n", illegal[i].x + 1, illegal[i].y + 1, illegal[i].z + 1);
        }
        return 0;

}
