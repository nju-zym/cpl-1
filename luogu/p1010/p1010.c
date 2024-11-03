//
// Created by 35861 on 24-10-26.
//
#include<stdio.h>
#include<math.h>

void fff(int n);
int main() {
    int n;
    scanf("%d",&n);
    fff(n);
    return 0;
}
void fff(int n) {
    for(int i=14;i>=0;i--) {
        if(i==0&&n==1) {
            printf("2(0)");
            n--;
        }
        else if(i==1&&n>=2) {
            printf("2");
            n-=2;
            if(n==1) {
                printf("+");
            }
        }
        else if(pow(2,i)<=n) {
            printf("2(");
            fff(i);
            printf(")");
            n-=pow(2,i);
            if(n!=0) {
                printf("+");
            }
        }
    }
}