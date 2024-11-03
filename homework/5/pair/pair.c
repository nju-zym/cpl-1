//
// Created by 35861 on 24-11-2.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int a[1000001];
int b[1000001];
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++) {
        scanf("%d",&b[i]);
    }
    qsort(b,m,sizeof(int),cmp);
    bool found = false;
    int min = 2147483647;
    for(int i=0;i<n;i++) {
        int tag=t-a[i];
        if(tag<0) break;

        int left =0,right =m-1;
        while(left<=right) {
            int mid = (left+right)/2;
            if(b[mid]>tag) {
                right = mid-1;
            } else if(b[mid]<tag) {
                left = mid+1;
            }
            else if(b[mid]==tag) {
                printf("0\n");
                return 0;
            }
        }
        if(right >= 0) {
            int sum=a[i]+b[right];
            int diff=t-sum;
            if(diff<min) {
                min = diff;
                found = true;
            }
        }
    }
    if(found)printf("%d\n",min);
    else printf("-1\n");
    return 0;
}