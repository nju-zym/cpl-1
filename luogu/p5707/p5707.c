//
// Created by 35861 on 24-10-25.
//
#include<stdio.h>

int main() {
    int s,v;
    scanf("%d",&s);
    scanf("%d",&v);
    int t1;
    if(s%v==0)t1=s/v;
    else
        t1=s/v+1;
    t1+=10;
    int hours=8,minutes=0;
    int hour,min;
    hour=t1/60;
    min=t1%60;
    if(min==0) {
        hours=(hours-hour)%24;
    }
    else {
        hours=(hours-hour-1)%24;
        while(hours<0) {
            hours+=24;
        }
        minutes=60-min;
    }
    printf("%02d:%02d",hours,minutes);
    return 0;
}