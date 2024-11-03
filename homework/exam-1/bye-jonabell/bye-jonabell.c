//
// Created by 35861 on 24-10-25.
//
#include <stdio.h>

int main() {
    int a[1502];
    int n, k, b, l;
    scanf("%d %d %d %d", &n, &k, &b,&l);
    int nowb=b;
    for(int i=1;i<=n;i++) {
        a[i]=l;
    }
    int killed=0;
    int count=0;
    for(int i=1;;i++) {
        if(i>n)i-=n;
        if(a[i]>0)count++;

        if(count==k&&nowb>0) {
            a[i]--;
            nowb--;
            count=0;
            if(a[i]==0) {
                killed++;
            }
        }
        else if(count==k&&nowb==0) {
            nowb=b;
            count=0;
        }
        if(killed==n-1) {
            for(int i=1;i<=n;i++) {
                if(a[i]>0) {
                    printf("%d ",i);
                    break;
                }
            }
            break;
        }
    }
}