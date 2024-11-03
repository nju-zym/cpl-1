//
// Created by 35861 on 24-11-1.
//
#include <stdio.h>
#include <stdlib.h>
static char *ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
    "0", "1", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};

void converter(int c) {
    if (c<=19) {
        printf("%s", ones[c]);
    }
    else if(c>19&&c%10==0&&c<100) {
        printf("%s", tens[c/10]);
    }
    else if (c<=99) {
        printf("%s-%s",tens[c/10] ,ones[c%10]);
    }
    else if(c%100==0&&c!=0) {
        printf("%s hundred", ones[c/100]);
    }
    else if(c>=100&&c%100<=19&&c%100>0) {
        printf("%s hundred and %s",ones[c/100],ones[c%100]);
    }
    else if(c>=100&&(c%100)%10==0&&(c%100)>=20) {
        printf("%s hundred and %s",ones[c/100],tens[(c%100)/10]);
    }
    else {
        printf("%s hundred and %s-%s",ones[c/100],tens[c/10%10],ones[c%10]);
    }
}
int main() {
    long long c;
    int flag=0;
    scanf("%lld", &c);
    if(c==0) {
        printf("zero");
        return 0;
    }
    if (c == -2147483648LL) {
        printf("minus two billion one hundred forty-seven million four hundred eighty-three thousand six hundred forty-eight");
        return 0;
    }
    if (c<0) {
        printf("minus ");
        c=abs(c);
    }
    int billion=c/1000000000;
    if (billion!=0) {
        printf("%s billion ",ones[billion]);
        flag=1;
    }
    c%=1000000000;
    if (c==0)return 0;
    if (c>=1000000) {
        converter(c/1000000);
        printf(" million ");
        flag=1;
    }
    c%=1000000;
    if (c==0)return 0;
    if (c>=1000) {
        converter(c/1000);
        printf(" thousand ");
        flag=1;
    }
    c%=1000;
    if (c==0)return 0;
    converter(c);
    return 0;
}