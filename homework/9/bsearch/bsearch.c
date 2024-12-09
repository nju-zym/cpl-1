//
// Created by 35861 on 24-12-7.
//
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}
int arr[1000002];
int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    while(q--) {
        int search;
        scanf("%d",&search);
        int* index;
        index = (int*)bsearch(&search,arr,n,sizeof(int),cmp);
        if(index==NULL) {
            printf("-1\n");
        }
        else {
            printf("%lld\n",index-arr);
        }
    }
    return 0;
}