#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

// 二分查找函数
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // 未找到
}

// 比较整数的函数
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 生成所有四元组并返回
int** generate_quads(int positions[], int count, int* quad_count) {
    *quad_count = 0;
    int capacity = 100;
    int** quads = malloc(capacity * sizeof(int*));

    for (int a = 0; a < count; a++) {
        for (int b = a + 1; b < count; b++) {
            int diff = positions[b] - positions[a];
            if (diff <= 0) continue;

            int c = positions[b] + diff;
            int c_idx = binary_search(positions, count, c);
            if (c_idx == -1 || c_idx <= b) continue;

            int d = c + diff;
            int d_idx = binary_search(positions, count, d);
            if (d_idx == -1 || d_idx <= c_idx) continue;

            // 确保四元组数量不超过预分配的容量
            if (*quad_count >= capacity) {
                capacity += 100;
                quads = realloc(quads, capacity * sizeof(int*));
            }

            quads[*quad_count] = malloc(4 * sizeof(int));
            quads[*quad_count][0] = positions[a];
            quads[*quad_count][1] = positions[b];
            quads[*quad_count][2] = c;
            quads[*quad_count][3] = d;
            (*quad_count)++;
        }
    }

    return quads;
}

// 回溯法，增加剪枝
bool backtrack(int** quads, int quad_count, int m, bool* used, int start) {
    if (m == 0) {
        return true;
    }

    for (int i = start; i < quad_count; i++) {
        int a = quads[i][0];
        int b = quads[i][1];
        int c = quads[i][2];
        int d = quads[i][3];

        // 如果已经被使用，跳过
        if (used[a] || used[b] || used[c] || used[d]) continue;

        // 如果当前四元组选择后仍然有效，进行回溯
        used[a] = used[b] = used[c] = used[d] = true;
        if (backtrack(quads, quad_count, m - 1, used, i + 1)) {
            return true;
        }
        used[a] = used[b] = used[c] = used[d] = false;
    }
    return false;
}

bool couldDivided(int i, int j, int m) {
    int n = 4 * m + 2;
    int positions[4 * m];
    int count = 0;

    // 构造 positions 数组
    for (int k = 1; k <= n; k++) {
        if (k != i && k != j) positions[count++] = k;
    }

    qsort(positions, count, sizeof(int), compare_ints);

    int quad_count;
    int** quads = generate_quads(positions, count, &quad_count);

    bool* used = calloc(n + 1, sizeof(bool));  // 用于标记已使用的数
    bool result = backtrack(quads, quad_count, m, used, 0);

    free(used);
    for (int k = 0; k < quad_count; k++) {
        free(quads[k]);
    }
    free(quads);

    return result;
}

int main() {
    int max_m;
    printf("Enter max m (m >= 1): ");
    scanf("%d", &max_m);

    // 并行计算变量
    #pragma omp parallel for schedule(dynamic) reduction(+:valid)
    for (int m = 1; m <= max_m; m++) {
        int n = 4 * m + 2;
        int total = n * (n - 1) / 2;  // 计算总的可能组合
        int valid = 0;

        // 对所有 i, j 进行遍历
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (couldDivided(i, j, m)) valid++;
            }
        }

        double probability = (double)valid / total;
        printf("m=%2d | Valid=%4d/%-4d | P=%.4f | %s\n",
               m, valid, total, probability,
               probability > 0.125 ? "P > 1/8 yes" : "P <= 1/8 no");
    }

    return 0;
}
