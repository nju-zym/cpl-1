//
// Created by 35861 on 24-11-1.
//
#include <stdio.h>

int arr[2001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int m=1;
    for (int i = n-1; i >= 0; i--) {
        int temp = arr[i];
        if(temp<arr[i-1]) {
            m++;
        } else {
            break;
        }
    }
    int temp=arr[n-m-1];
    int min=arr[n-m];
    int loca=n-m;
    for (int i=n-m; i<n; i++) {
        if(arr[i]<min&&arr[i]>temp) {
            min=arr[i];
            loca=i;
        }
    }
    arr[n-m-1]=arr[loca];
    arr[loca]=temp;
    for (int i=n-m; i<=(2*n-m-1)/2; i++) {
        int temp=arr[i];
        arr[i]=arr[2*n-m-1-i];
        arr[2*n-m-1-i]=temp;
    }
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}