//
// Created by 35861 on 25-1-25.
//
#include<stdio.h>

int arr[1001];
int bool_arr[1001];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (i > 0) {
            int temp = arr[i] - arr[i-1] > 0 ? arr[i] - arr[i - 1] : arr[i - 1] - arr[i];
            if (temp > 1000) {
                printf("Not jolly\n");
                return 0;
            }
            bool_arr[temp] = 1;
        }
    }
    int flag = 1;
    for (int i = 1; i < n; i++) {
        if (!bool_arr[i]) flag = 0;
    }
    if (flag) {
        printf("Jolly\n");
    }
    else {
        printf("Not jolly\n");
    }
    return 0;
}