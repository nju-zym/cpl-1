//
// Created by 35861 on 24-11-11.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int sum;}wine;
wine wines[10002];
int cmp(const void *a, const void *b) {
    wine *p1 = (wine *)a;
    wine *p2 = (wine *)b;
    return p2->value - p1->value;}
int main() {
    int n,L;
    scanf("%d %d", &n,&L);
    for(int i=0;i<n;i++) {
        scanf("%d",&wines[i].value);}
    for(int i=0;i<n;i++) {
        scanf("%d",&wines[i].sum);}
    qsort(wines,n,sizeof(wine),cmp);
    int val=0;
    for(int i=0;i<n;i++) {
        if(wines[i].sum<=L) {
            val+=wines[i].sum*wines[i].value;
            L-=wines[i].sum;} else {
            val+=wines[i].value*L;
            break;}}
    printf("%d",val);
    return 0;}