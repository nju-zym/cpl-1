//
// Created by 35861 on 24-11-2.
//
#include <stdio.h>

int main() {
    int p,q,r;
    scanf("%d %d %d",&p,&q,&r);
    int radix=2;
    for(;radix<=40;radix++) {
        int psingle=p%10;
        int qsingle=q%10;
        int ptens=p/10;
        int qtens=q/10;
        int rsingle=r%10;
        int rtens=r/10;
        if(psingle>=radix||ptens>=radix||qsingle>=radix||qtens>=radix||rsingle>=radix||rtens>=radix)continue;
        int P=psingle+ptens*radix;
        int Q=qsingle+qtens*radix;
        int R=rsingle+rtens*radix;
        if(P*Q==R)break;
    }
    if(radix==41) {
        printf("0");
        return 0;
    } else {
        printf("%d",radix);
        return 0;
    }
}