//
// Created by 35861 on 24-10-28.
//
#include<stdio.h>
#include <stdlib.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
typedef struct {
    int price;
    int sum;
}milk;
milk M[5001];
int cmp(const void *a, const void *b) {
    milk *milka = (milk *)a;
    milk *milkb = (milk *)b;
    if(milka->price==milkb->price) {
        return milkb->sum-milka->sum;
    }
    return milka->price-milkb->price;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&M[i].price,&M[i].sum);
    }
    qsort(M,m,sizeof(milk),cmp);
    int money=0;
    for(int i=0;i<m;i++) {
        int sumi=min(n,M[i].sum);
        n-=min(n,M[i].sum);
        money+=sumi*M[i].price;
        if(n==0) {
            break;
        }
    }
    printf("%d",money);
    return 0;
}