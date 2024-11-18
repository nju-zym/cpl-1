//
// Created by 35861 on 24-11-13.
//
#include <stdio.h>
char rc[102][102];
int r,c;
int sum;
int check(int i, int j);
int main() {
    scanf("%d%d",&r,&c);
    getchar();
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            scanf("%c",&rc[i][j]);
        }
        getchar();
    }
    for(int i=0;i<r-1;i++) {
        for(int j=0;j<c-1;j++) {
            if(rc[i][j]!=0) {
                sum+=check(i,j);
            }
        }
    }
    printf("%d",sum);
    return 0;
}
int check(int i, int j) {
    int num=0;
    if(rc[i][j]=='/'&&rc[i][j+1]=='\\') {
        for(int k=1;i+2*k-1<r&&j-k+1>=0&&j+k<c;k++) {
            int flag=1;
            for(int l=0;l<k;l++) {
                if(rc[i+l][j-l]!='/'||rc[i+l][j+l+1]!='\\') flag=0;
                if(rc[i+2*k-l-1][j-l]!='\\'||rc[i+2*k-l-1][j+l+1]!='/') flag=0;
            }
            if(flag==1) {
                num++;
            }
        }
    }
    return num;
}