//
// Created by 35861 on 24-10-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2147483647
#define maxn 10000001
int n,temp[maxn];
typedef struct {
    double x,y;
}point;
point s[maxn];
int cmp(const void* a,const void* b) {
    point *pointA = (point *)a;
    point *pointB = (point *)b;
    if (pointA->x == pointB->x) {
        return (pointA->y < pointB->y) ? -1 :1;
    }
    return (pointA->x < pointB->x) ? -1 :1;

}
int cmps(const void* a ,const void* b) {
    int indexA = *(int *)a;
    int indexB = *(int *)b;
    return (s[indexA].y < s[indexB].y) ? -1 :1;
}
double min(double a,double b) {
    return a<b?a:b;
}
double dist(int i,int j) {
    double x=(s[i].x-s[j].x)*(s[i].x-s[j].x);
    double y=(s[i].y-s[j].y)*(s[i].y-s[j].y);
    return sqrt(x+y);
}
double merge(int left ,int right) {
    double d=INT_MAX;
    if(left==right) return d;
    if(left+1==right) {
        return  dist(left,right);
    }
    int mid=(left+right)/2;
    double d1=merge(left,mid);
    double d2=merge(mid+1,right);
    d= min(d1,d2);
    int i,j,k=0;
    for(i=left;i<=right;i++) {
        if(fabs(s[mid].x-s[i].x)<d) {
            temp[k++]=i;
        }
    }
    qsort(temp,k,sizeof(int),cmps);
    for(i=0;i<k;i++) {
        for(j=i+1;j<k&&s[temp[j]].y-s[temp[i]].y<d;j++) {
            double d3=dist(temp[i],temp[j]);
            if(d3<d) {
                d=d3;
            }
        }
    }
    return d;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lf%lf",&s[i].x,&s[i].y);
    }
    qsort(s,n,sizeof(point),cmp);
    return !printf("%.4lf\n",merge(0,n-1));
}