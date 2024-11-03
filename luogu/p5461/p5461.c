//
// Created by 35861 on 24-10-25.
//
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void lose(int **a,int *n ,const int m);
int main() {
    int n;
    scanf("%d",&n);
    n=pow(2,n);
    const int m=n;
    int **a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++) {
        a[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            a[i][j]=1;
        }
    }
    while(n>1)lose(a,&n,m);
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    free(a);
    return 0;
}

void lose(int **a,int *n,const int m) {
    int len=*n;
    len/=2;
    for(int i=0;(i+1)*len<m;i+=len) {
        for(int j=0;(j+1)*len<m;j+=len) {
            a[i][j]=0;
        }
    }
    *n=len;
}