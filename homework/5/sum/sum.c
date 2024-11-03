//
// Created by 35861 on 24-11-1.
//
#include <stdio.h>
#include <math.h>
int main() {
    int sum = 0;
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++) {
        int temp=0;
        for(int j=1;j<=i;j++) {
            temp+=pow(10,j-1)*t;
        }
        sum+=temp;
    }
    printf("%d",sum);
    return 0;
}