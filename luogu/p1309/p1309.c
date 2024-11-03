//
// Created by 35861 on 24-10-25.
//
#include<stdio.h>
#include<stdlib.h>

 struct player {
     int point;
     int power;
     int id;
 };
struct player players[200002];
int cmp(const void *a, const void *b) {
    struct player *p1 = (struct player *)a;
    struct player *p2 = (struct player *)b;
    if(p1->point != p2->point) {
        return p2->point - p1->point;
    } else {
        return p1->id - p2->id;
    }
}
void match(struct player *p1, struct player *p2) {
    if (p1->power > p2->power) {
        p1->point++;
    }
    else {
        p2->point++;
    }
}
void totalmatch(int n) {
    for (int i = 0; i < n; i+=2) {
        match(&players[i], &players[i+1]);
    }
}
int main() {
    int n,r,q;
    scanf("%d %d %d",&n,&r,&q);
    n*=2;
    for(int i=0;i<n;i++) {
        scanf("%d",&players[i].point);
        players[i].id=i+1;
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&players[i].power);
    }
    while(r--) {
        qsort(players,n,sizeof(struct player),cmp);
        totalmatch(n);
    }
    qsort(players,n,sizeof(struct player),cmp);
    printf("%d",players[q-1].id);
    return 0;
}