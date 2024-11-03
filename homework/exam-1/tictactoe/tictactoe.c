//
// Created by 35861 on 24-10-25.
//
#include <stdio.h>


int win(int a[10][10],int player,int x,int n);
int play(int a[10][10],int x,int n);
int main() {
    int t,x;
    scanf("%d",&t);
    scanf("%d",&x);
    while(t--) {
        int n;
        scanf("%d",&n);
        int a[10][10];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        switch(play(a,x,n)) {
            case 1:printf("1\n");break;
            case 2:printf("2\n");break;
            case 4:printf("4\n");break;
            case 0:printf("draw\n");break;
        }
    }
    return 0;
}
int win(int a[10][10],int player,int x,int n) {
    int flag=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int count1=1,count2=1,count3=1,count4=1;
            if(a[i][j]!=player) continue;
            for(int k=1;k<x;k++) {
                if(i+k<n) {
                    if(a[i+k][j]==player) count1++;
                }if(j+k<n) {
                    if(a[i][j+k]==player) count2++;
                }if(i+k<n&&j+k<n) {
                    if(a[i+k][j+k]==player) count3++;
                }if(i+k<n&&j-k>=0) {
                    if(a[i+k][j-k]==player) count4++;
                }
            }
            if(count1>=x||count2>=x||count3>=x||count4>=x) {
                flag=1;
            }
        }
    }
    if(flag) return 1;
    else return 0;
}
int play(int a[10][10],int x,int n) {
    int w1=win(a,1,x,n);
    int w2=win(a,2,x,n);
    int w4=win(a,4,x,n);
    if(w1==1&&w2==0&&w4==0) return 1;
    else if(w1==0&&w2==1&&w4==0) return 2;
    else if(w1==0&&w2==0&&w4==1) return 4;
    else return 0;
}