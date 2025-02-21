#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include <stdint.h>

// 比较整数的函数
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


// 结构体存储四元组信息
typedef struct {
    int a;
    int b;
    int c;
    int d;
} Quad;

// 生成所有四元组函数（优化版本）
int generate_quads(int positions[], int count, Quad** quads) {
    int quad_count = 0;
    for (int a = 0; a < count; a++) {
        for (int b = a + 1; b < count; b++) {
            int diff = positions[b] - positions[a];
            if (diff <= 0) continue;
            int c = positions[b] + diff;
            int d = c + diff;

            int c_idx = -1;
            for (int i = b + 1; i < count; i++) {
              if(positions[i] == c){
                 c_idx = i;
                 break;
              }
            }
            if (c_idx == -1) continue;

             int d_idx = -1;
            for (int i = c_idx + 1; i < count; i++) {
               if(positions[i] == d){
                   d_idx = i;
                    break;
                }
            }
             if(d_idx == -1) continue;

            quads[quad_count]->a = positions[a];
            quads[quad_count]->b = positions[b];
            quads[quad_count]->c = c;
            quads[quad_count]->d = d;
            quad_count++;
        }
    }
    return quad_count;
}

// 优化后的回溯函数，使用位运算
bool backtrack(Quad* quads, int quad_count, int m, uint64_t used, int start) {
    if (m == 0) {
        return true;
    }

    for (int i = start; i < quad_count; i++) {
        int a = quads[i].a;
        int b = quads[i].b;
        int c = quads[i].c;
        int d = quads[i].d;

        // 检查是否已使用
        if (used & (1ULL << a) || used & (1ULL << b) || used & (1ULL << c) || used & (1ULL << d)) continue;

        // 设置当前使用的数
        uint64_t next_used = used | (1ULL << a) | (1ULL << b) | (1ULL << c) | (1ULL << d);
        if (backtrack(quads, quad_count, m - 1, next_used, i + 1)) {
            return true;
        }
    }
    return false;
}



//  函数用于检查特定 i 和 j 是否可以分割
bool couldDivided(int i, int j, int m, Quad* quads, int quad_count) {
     int n = 4 * m + 2;
     int positions[4*m];
    int count = 0;
      for (int k = 1; k <= n; k++) {
        if (k != i && k != j) positions[count++] = k;
      }
    qsort(positions, count, sizeof(int), compare_ints);


    return backtrack(quads, quad_count, m, 0, 0);
}


int main() {
    int max_m;
    printf("Enter max m (m >= 1): ");
    scanf("%d", &max_m);

    #pragma omp parallel
    {

        #pragma omp for schedule(dynamic)
        for (int m = 1; m <= max_m; m++) {
            int n = 4 * m + 2;
            int total = n * (n - 1) / 2;
            int valid = 0;
            int positions[4*m];
            int count = 0;
            for (int k = 1; k <= n; k++) {
                positions[count++] = k;
            }
            qsort(positions,count,sizeof(int), compare_ints);


            int capacity = 100000;
            Quad* quads = malloc(capacity * sizeof(Quad));


           int quad_count = generate_quads(positions, count, &quads);
           if(quad_count == -1) continue;


             #pragma omp critical
            {
             for (int i = 1; i <= n; i++) {
                    for (int j = i + 1; j <= n; j++) {
                      if(couldDivided(i,j,m, quads, quad_count)){
                          valid++;
                       }
                    }
                 }
               double probability = (double)valid / total;
               printf("m=%2d | Valid=%4d/%-4d | P=%.4f | %s\n",
                       m, valid, total, probability,
                       probability > 0.125 ? "P > 1/8 yes" : "P <= 1/8 no");
             }
             free(quads);
        }
    }
    return 0;
}