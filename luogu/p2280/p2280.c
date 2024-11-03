//
// Created by 35861 on 24-10-31.
//
#include<stdio.h>
int map[5002][5002];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y,v;
    for(int i=0;i<n;i++) {
        scanf("%d %d %d",&x,&y,&v);
        map[x+1][y+1]+=v;
    }
    for(int i=1;i<=5001;i++) {
        for(int j=1;j<=5001;j++) {
            map[i][j]=map[i-1][j]+map[i][j-1]-map[i-1][j-1]+map[i][j];
        }
    }
    int ans=0;
    for(int i=m;i<=5001;i++) {
        for(int j=m;j<=5001;j++) {
            int sum=map[i][j]-map[i-m][j]-map[i][j-m]+map[i-m][j-m];
            if(sum>ans)ans=sum;
        }
    }
    printf("%d",ans);
    return 0;

}