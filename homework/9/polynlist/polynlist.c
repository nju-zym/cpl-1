//
// Created by 35861 on 24-12-8.
//
#include <stdio.h>
long long int p1_nums[100002];
long long int p2_nums[100002];

void print(FILE* file2, long long int temp, long long int position, char *var, int *flag);

int main() {
    FILE *file1, *file2;
    file1 = fopen("D:/cpl-1/homework/9/polynlist/1.in", "r");
    file2 = fopen("D:/cpl-1/homework/9/polynlist/output.txt", "w");
    if (file1 == NULL) {
        perror("Error opening file");
        return 1;
    }
    long long int p1_order, p2_order;
    fscanf(file1 , "%lld %lld", &p1_order, &p2_order);
    char var[12];
    fscanf(file1,"%s", var);
    for (long long int i = p1_order; i >= 0; i--) {
        fscanf(file1,"%lld", &p1_nums[i]);
    }
    for (long long int i = p2_order; i >= 0; i--) {
        fscanf(file1,"%lld", &p2_nums[i]);
    }
    int plus_flag = 0, minus_flag = 0, mult_flag = 0;
    for (long long int i = p1_order > p2_order ? p1_order : p2_order; i >= 0; i--) {
        long long int temp_p1_num = i <= p1_order ? p1_nums[i] : 0;
        long long int temp_p2_num = i <= p2_order ? p2_nums[i] : 0;
        long long int temp = temp_p1_num + temp_p2_num;
        print(file2, temp, i, var, &plus_flag);
    }
    printf("\n");
    for (long long int i = p1_order > p2_order ? p1_order : p2_order; i >= 0; i--) {
        long long int temp_p1_num = i <= p1_order ? p1_nums[i] : 0;
        long long int temp_p2_num = i <= p2_order ? p2_nums[i] : 0;
        long long int temp = temp_p1_num - temp_p2_num;
        print(file2, temp, i, var, &minus_flag);
    }
    printf("\n");
    for (long long int i = p1_order + p2_order; i >= 0; i--) {
        long long int temp = 0;
        for (long long int j = i; j >= 0; j--) {
            long long int temp_p1_num = j <= p1_order ? p1_nums[j] : 0;
            long long int temp_p2_num = i - j <= p2_order ? p2_nums[i - j] : 0;
            temp += temp_p1_num * temp_p2_num;
        }
        print(file2, temp, i, var, &mult_flag);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}

void print(FILE* file2, long long int temp, long long int position, char *var, int *flag) {
    if (position >= 2 && !*flag && temp > 1) {
        fprintf(file2,"%lld%s^%lld", temp, var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && !*flag && temp == 1) {
        fprintf(file2, "%s^%lld", var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && !*flag && temp == -1) {
        fprintf(file2, "-%s^%lld", var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && !*flag && temp < -1) {
        fprintf(file2, "%lld%s^%lld", temp, var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && *flag && temp > 1) {
        fprintf(file2, "+%lld%s^%lld", temp, var, position);
        return;
    }
    if (position >= 2 && *flag && temp == 1) {
        fprintf(file2,"+%s^%lld", var, position);
        return;
    }
    if (position >= 2 && *flag && temp == -1) {
        fprintf(file2, "-%s^%lld", var, position);
        return;
    }
    if (position >= 2 && *flag && temp < -1) {
        fprintf(file2, "%lld%s^%lld", temp, var, position);
        return;
    }
    if (position == 1 && !*flag && temp > 1) {
        fprintf(file2,"%lld%s", temp, var);
        *flag = 1;
        return;
    }
    if (position == 1 && !*flag && temp == 1) {
        fprintf(file2, "%s", var);
        *flag = 1;
        return;
    }
    if (position == 1 && !*flag && temp == -1) {
        fprintf(file2, "-%s", var);
        *flag = 1;
        return;
    }
    if (position == 1 && !*flag && temp < -1) {
        fprintf(file2, "%lld%s", temp, var);
        *flag = 1;
        return;
    }
    if (position == 1 && *flag && temp > 1) {
        fprintf(file2, "+%lld%s", temp, var);
        return;
    }
    if (position == 1 && *flag && temp == 1) {
        fprintf(file2, "+%s", var);
        return;
    }
    if (position == 1 && *flag && temp == -1) {
        fprintf(file2, "-%s", var);
        return;
    }
    if (position == 1 && *flag && temp < -1) {
        fprintf(file2, "%lld%s", temp, var);
        return;
    }
    if (position == 0 && !*flag) {
        fprintf(file2, "%lld", temp);
        *flag = 1;
        return;
    }
    if (position == 0 && *flag && temp > 0) {
        fprintf(file2, "+%lld", temp);
        return;
    }
    if (position == 0 && *flag && temp < 0) {
        fprintf(file2, "%lld", temp);
        return;
    }
}
