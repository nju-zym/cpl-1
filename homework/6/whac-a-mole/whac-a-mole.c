//
// Created by 35861 on 24-11-18.
//
#include <limits.h>
#include <stdio.h>
#define MAX 600
int n,m,d;
int map[MAX+102][MAX+102];//读入的时候从51开始读，记得把坐标减50
typedef struct maxpositons {
    int x,y;
}maxpositons;
maxpositons max[MAX*MAX];
int maxnumbers;
int maxvalue=INT_MIN;
void compare(int value,int x,int y) {
    if(value >maxvalue) {
        maxnumbers=0;
        maxvalue=value;
        max[maxnumbers].x=x;
        max[maxnumbers].y=y;
        maxnumbers++;
    }
    else if(value == maxvalue) {
        max[maxnumbers].x=x;
        max[maxnumbers].y=y;
        maxnumbers++;
    }
}
void findmax() {
    for(int i=51;i<51+n;i++) {
        int temp=0;
        for(int k=i-d; k<=i; k++) {
           for(int j=51-(k-i+d);j<=51+(k-i+d);j++) {
               temp+=map[k][j];
           }
        }
        for(int k=i+1; k<=i+d; k++) {
            for(int j=51+k-i-d;j<=51-k+i+d;j++) {
                temp+=map[k][j];
            }
        }
        compare(temp,i-50,1);
        int col=52;
        for(;col<51+m;col++) {
            for(int p=0;p<=d;p++) {
                temp+=map[i-d+p][col+p];
                temp-=map[i-d+p][col-p-1];
            }
            for(int q=0;q<d;q++) {
                temp+=map[i+d-q][col+q];
                temp-=map[i+d-q][col-q-1];
            }
            compare(temp,i-50,col-50);
        }
    }
}
int main() {
    scanf("%d %d %d",&n,&m,&d);
    for (int i = 51;i < 51+n;i++) {
        for(int j = 51;j < 51+m;j++) {
            scanf("%d", &map[i][j]);
        }
    }
    findmax();
    printf("%d %d\n",maxvalue,maxnumbers);
    for(int i=0;i<maxnumbers;i++) {
        printf("%d %d\n",max[i].x,max[i].y);
    }
    return 0;
}
