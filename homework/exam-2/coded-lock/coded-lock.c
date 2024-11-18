//
// Created by 35861 on 24-11-16.
//
#include <stdio.h>
int W,N,D;
int nums[1002];
int rollpostive(int i,int j);
int rollnegative(int i,int j);
int main() {
    scanf("%d %d %d",&W,&N,&D);
    for(int i=1;i<=W;i++) {
        scanf("%d",&nums[i]);
    }
    int sum=0;
    for(int i=1;i<=W/2;i++) {
        int temp1=rollpostive(i,W-i+1);
        int temp2=rollnegative(i,W-i+1);
        if(temp1==-1 || temp2==-1) {
            printf("Impossible\n");
            return 0;
        }
        sum+=temp1<temp2?temp1:temp2;
    }
    printf("%d",sum);
    return 0;
}
int rollpostive(int i,int j) {
    int times=0;
    int temp=nums[i];
    while(temp!=nums[j]) {
        temp+=D;
        while(temp>N)temp-=N;
        if(temp==nums[i])return -1;
        times++;
    }
    return times;
}
int rollnegative(int i,int j) {
    int times=0;
    int temp=nums[i];
    while(temp!=nums[j]) {
        temp-=D;
        while(temp<1)temp+=N;
        if(temp==nums[i])return -1;
        times++;
    }
    return times;
}