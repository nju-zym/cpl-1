//
// Created by 35861 on 24-11-1.
//
#include<stdio.h>

int classrooms[100001];

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&classrooms[i]);
    }
    while(m--) {
        int d,s,j;
        int flag=0;
        scanf("%d %d %d",&d,&s,&j);
        for(int i=s;i<=j;i++) {
            classrooms[i]-=d;
            if(classrooms[i]<0) flag=1;
        }
        if(flag==1) break;
    }
    if(m==0) {
        printf("0\n");
        return 0;
    }
    else {
        printf("-1\n%d\n",m+1);
        return 0;
    }
}