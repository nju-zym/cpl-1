//
// Created by 35861 on 24-10-25.
//
#include <stdio.h>
#include <string.h>

char str[51];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int a=str[i]-'a'+1;
        a=(a+n)%26;
        str[i]=a+'a'-1;
        if(str[i]=='`')str[i]='z';
    }
    printf("%s", str);
    return 0;
}