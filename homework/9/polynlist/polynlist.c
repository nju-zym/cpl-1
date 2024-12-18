//
// Created by 35861 on 24-12-8.
//
#include <stdio.h>
long long int p1_nums[100002];
long long int p2_nums[100002];

void print(long long int temp, long long int position, char *var, int *flag);

int main() {
    freopen("D:/cpl-1/homework/9/polynlist/1.in", "r", stdin);
    //freopen("D:/cpl-1/homework/9/polynlist/output.txt", "w", stdout);
    long long int p1_order, p2_order;
    scanf("%lld %lld", &p1_order, &p2_order);
    char var[12];
    scanf("%s", var);
    for (long long int i = p1_order; i >= 0; i--) {
        scanf("%lld", &p1_nums[i]);
    }
    for (long long int i = p2_order; i >= 0; i--) {
        scanf("%lld", &p2_nums[i]);
    }
    int plus_flag = 0, minus_flag = 0, mult_flag = 0;
    for (long long int i = p1_order > p2_order ? p1_order : p2_order; i >= 0; i--) {
        long long int temp_p1_num = i <= p1_order ? p1_nums[i] : 0;
        long long int temp_p2_num = i <= p2_order ? p2_nums[i] : 0;
        long long int temp = temp_p1_num + temp_p2_num;
        print(temp, i, var, &plus_flag);
    }
    printf("\n");
    for (long long int i = p1_order > p2_order ? p1_order : p2_order; i >= 0; i--) {
        long long int temp_p1_num = i <= p1_order ? p1_nums[i] : 0;
        long long int temp_p2_num = i <= p2_order ? p2_nums[i] : 0;
        long long int temp = temp_p1_num - temp_p2_num;
        print(temp, i, var, &minus_flag);
    }
    printf("\n");
    for (long long int i = p1_order + p2_order; i >= 0; i--) {
        long long int temp = 0;
        for (long long int j = i; j >= 0; j--) {
            long long int temp_p1_num = j <= p1_order ? p1_nums[j] : 0;
            long long int temp_p2_num = i - j <= p2_order ? p2_nums[i - j] : 0;
            temp += temp_p1_num * temp_p2_num;
        }
        print(temp, i, var, &mult_flag);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void print(long long int temp, long long int position, char *var, int *flag) {
    if (position >= 2 && !*flag && temp > 1) {
        printf("%lld%s^%lld", temp, var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && !*flag && temp == 1) {
        printf("%s^%lld", var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && !*flag && temp == -1) {
        printf("-%s^%lld", var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && !*flag && temp < -1) {
        printf("%lld%s^%lld", temp, var, position);
        *flag = 1;
        return;
    }
    if (position >= 2 && *flag && temp > 1) {
        printf("+%lld%s^%lld", temp, var, position);
        return;
    }
    if (position >= 2 && *flag && temp == 1) {
        printf("+%s^%lld", var, position);
        return;
    }
    if (position >= 2 && *flag && temp == -1) {
        printf("-%s^%lld", var, position);
        return;
    }
    if (position >= 2 && *flag && temp < -1) {
        printf("%lld%s^%lld", temp, var, position);
        return;
    }
    if (position == 1 && !*flag && temp > 1) {
        printf("%lld%s", temp, var);
        *flag = 1;
        return;
    }
    if (position == 1 && !*flag && temp == 1) {
        printf("%s", var);
        *flag = 1;
        return;
    }
    if (position == 1 && !*flag && temp == -1) {
        printf("-%s", var);
        *flag = 1;
        return;
    }
    if (position == 1 && !*flag && temp < -1) {
        printf("%lld%s", temp, var);
        *flag = 1;
        return;
    }
    if (position == 1 && *flag && temp > 1) {
        printf("+%lld%s", temp, var);
        return;
    }
    if (position == 1 && *flag && temp == 1) {
        printf("+%s", var);
        return;
    }
    if (position == 1 && *flag && temp == -1) {
        printf("-%s", var);
        return;
    }
    if (position == 1 && *flag && temp < -1) {
        printf("%lld%s", temp, var);
        return;
    }
    if (position == 0 && !*flag) {
        printf("%lld", temp);
        *flag = 1;
        return;
    }
    if (position == 0 && *flag && temp > 0) {
        printf("+%lld", temp);
        return;
    }
    if (position == 0 && *flag && temp < 0) {
        printf("%lld", temp);
        return;
    }
}