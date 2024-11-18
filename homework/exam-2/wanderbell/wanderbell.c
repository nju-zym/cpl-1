//
// Created by 35861 on 24-11-16.
//
#include <stdio.h>
int r,c;
char board[3002][3002];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int change();
int  changecheckU(int i,int j);
int  changecheckD(int i,int j);
int  changecheckL(int i,int j);
int  changecheckR(int i,int j);
int main() {
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++) {
        scanf("%s",board[i]);
    }
    printf("%d\n",change());
    return 0;
}
int change() {
    int sum=0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(board[i][j]=='.') continue;
            if(board[i][j]=='U') {
                int u=changecheckU(i,j);
                if(u>=0) sum+=u;
                else return -1;
            }
            if(board[i][j]=='D') {
                int d=changecheckD(i,j);
                if(d>=0) sum+=d;
                else return -1;
            }
            if(board[i][j]=='L') {
                int l=changecheckL(i,j);
                if(l>=0) sum+=l;
                else return -1;
            }
            if(board[i][j]=='R') {
                int r=changecheckR(i,j);
                if(r>=0) sum+=r;
                else return -1;
            }
        }
    }
    return sum;
}
int  changecheckU(int i,int j) {
    for(int k=i-1;k>=0;k--) {
        if(board[k][j]!='.') return 0;
    }
    for(int k=0;k<4;k++) {
        if(k==3)continue;
        int tempi=i+dir[k][0];
        int tempj=j+dir[k][1];
        while(tempi>=0&&tempi<r&&tempj>=0&&tempj<c) {
            if(board[tempi][tempj]!='.') {
                if(k==0) {
                    board[i][j]='R';
                    return 1;
                }
                if(k==1) {
                    board[i][j]='L';
                    return 1;
                }
                if(k==2) {
                    board[i][j]='D';
                    return 1;
                }
            }
            tempi=tempi+dir[k][0];
            tempj=tempj+dir[k][1];
        }
    }
    return -1;
}
int  changecheckD(int i,int j) {
    for(int k=i+1;k<r;k++) {
        if(board[k][j]!='.') return 0;
    }
    for(int k=0;k<4;k++) {
        if(k==2)continue;
        int tempi=i+dir[k][0];
        int tempj=j+dir[k][1];
        while(tempi>=0&&tempi<r&&tempj>=0&&tempj<c) {
            if(board[tempi][tempj]!='.') {
                if(k==0) {
                    board[i][j]='R';
                    return 1;
                }
                if(k==1) {
                    board[i][j]='L';
                    return 1;
                }
                if(k==3) {
                    board[i][j]='U';
                    return 1;
                }
            }
            tempi=tempi+dir[k][0];
            tempj=tempj+dir[k][1];
        }
    }
    return -1;
}
int  changecheckL(int i,int j) {
    for(int k=j-1;k>=0;k--) {
        if(board[i][k]!='.') return 0;
    }
    for(int k=0;k<4;k++) {
        if(k==1)continue;
        int tempi=i+dir[k][0];
        int tempj=j+dir[k][1];
        while(tempi>=0&&tempi<r&&tempj>=0&&tempj<c) {
            if(board[tempi][tempj]!='.') {
                if(k==0) {
                    board[i][j]='R';
                    return 1;
                }
                if(k==2) {
                    board[i][j]='D';
                    return 1;
                }
                if(k==3) {
                    board[i][j]='U';
                    return 1;
                }
            }
            tempi=tempi+dir[k][0];
            tempj=tempj+dir[k][1];
        }
    }
    return -1;
}
int  changecheckR(int i,int j) {
    for(int k=j+1;k<c;k++) {
        if(board[i][k]!='.') return 0;
    }
    for(int k=0;k<4;k++) {
        if(k==0)continue;
        int tempi=i+dir[k][0];
        int tempj=j+dir[k][1];
        while(tempi>=0&&tempi<r&&tempj>=0&&tempj<c) {
            if(board[tempi][tempj]!='.') {
                if(k==1) {
                    board[i][j]='L';
                    return 1;
                }
                if(k==2) {
                    board[i][j]='D';
                    return 1;
                }
                if(k==3) {
                    board[i][j]='U';
                    return 1;
                }
            }
            tempi=tempi+dir[k][0];
            tempj=tempj+dir[k][1];
        }
    }
    return -1;
}
