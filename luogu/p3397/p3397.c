//
// Created by 35861 on 24-10-31.
//
#include <stdio.h>

int square[1001][1001];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int x1,y1,x2,y2;
    while(m--) {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++) {
            for(int j=y1;j<=y2;j++) {
                square[i][j]++;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d ",square[i][j]);
        }
        printf("\n");
    }
    return 0;
}