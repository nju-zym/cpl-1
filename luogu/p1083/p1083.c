//
// Created by 35861 on 24-11-1.
//
#include<stdio.h>
#include <stdbool.h>
#include <string.h>
int n,m;
long long int rest[100001],need[100001],r[100001],l[100001],d[100001],diff[100001];
bool flag(const long long int x);
int main() {
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&rest[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%lld %lld %lld",&d[i],&l[i],&r[i]);
    }
    long long int begin=1,end=m;
    if(flag(end)) return 0;
    while(begin<end) {
        long long int mid=(begin+end)/2;
        if(flag(mid)) begin=mid+1;
        else end=mid;
    }
    printf("-1\n%lld",begin);
    return 0;
}

bool flag(const long long int x) {
    memset(diff,0,sizeof(diff));
    for(long long int i=1;i<=x;i++) {
        diff[l[i]]+=d[i];
        diff[r[i]+1]-=d[i];
    }
    for(long long int i=1;i<=n;i++) {
        need[i]=need[i-1]+diff[i];
        if(need[i]>rest[i]) return false;
    }
    return true;
}